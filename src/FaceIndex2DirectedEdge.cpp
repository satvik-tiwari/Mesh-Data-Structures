#include "FaceIndex2DirectedEdge.h"

int main(int argc, char **argv)
{
	
	if(argc == 2)
	{
		//read a .face file and compute half edge and first directed edge
		//data structures and output them in a file with ".diredge"
		
		FileHandler face2face;
		
		std::vector<int> edge_ID = face2face.GetEdgeID(argv [1]);
		
		int face = 0;
		for(int edge = 0; edge < edge_ID.size(); )
		{
			std::cout << "Face " <<
			std::setw(2) << std::right << face++ << " " << 
			std::setw(2) << std::right << edge_ID[edge++] << " " << 
			std::setw(2) << std::right << edge_ID[edge++] << " " << 
			std::setw(2) << std::right << edge_ID[edge++] << " " << 
			std::endl;			
		}
		
	}
	
	
	else
	{
		std::cout<< "Usage : " << argv[0] << " <Filename>" << std::endl;
	}
	
	return 0;
}
