#include "FaceIndex2DirectedEdge.h"

int main(int argc, char **argv)
{
	
	if(argc == 2)
	{
		//read a .face file and compute half edge and first directed edge
		//data structures and output them in a file with ".diredge"
		
		FileHandler file;
		
		std::vector<int> edge_ID = file.GetEdgeID(argv [1]);
		
		//std::cout << "number of edges = " << edge_ID.size() << std::endl;
		/*int face = 0;
		for(int edge = 0; edge < edge_ID.size(); )
		{
			std::cout <<
			std::setw(2) << std::right << face++ << " " << 
			std::setw(2) << std::right << edge_ID[edge++] << " " << 
			std::setw(2) << std::right << edge_ID[edge++] << " " << 
			std::setw(2) << std::right << edge_ID[edge++] << " " << 
			std::endl;			
		}
		*/
		
		//create other half data structure based on edge array
		std::vector<int> other_Half = CalculateOtherHalf(edge_ID); 
		
		/*std::cout << "Other Halves : " << std::endl;
		
		for(int edge = 0; edge < other_Half.size(); edge++)
		{
			std::cout << "e" << edge << " e" << other_Half[edge] << std::endl;
			
		}*/
		
		long numVertices = edge_ID.size()/3; //wont be same for legman and hexahedron, look into it later
		std::vector<int> first_DirectedEdge = CalculateFirstDirectedEdge(edge_ID, numVertices);
		
		/*std::cout << "Directed Edges : " << std::endl;
		
		for(int v_ID = 0; v_ID < first_DirectedEdge.size(); v_ID++)
		{
			std::cout << "v" << v_ID << " e" << first_DirectedEdge[v_ID] << std::endl;
			
		}*/
		
		//file.WriteDirectedEdgeFormat(first_DirectedEdge, other_Half);
		
		
	}
	
	
	else
	{
		//if file name isn't provided, tell the user how to do so
		std::cout<< "Usage : " << argv[0] << " <Filename>" << std::endl;
	}
	
	return 0;
}
