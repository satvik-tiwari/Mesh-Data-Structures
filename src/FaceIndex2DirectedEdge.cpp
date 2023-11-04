#include "FaceIndex2DirectedEdge.h"

bool isManifold = true;
bool isVertexFail = false;
bool isEdgeFail = false;
std::vector<int> edgeFail;
std::vector<int> vertexFail;

int main(int argc, char **argv)
{
	
	if(argc == 2)
	{
		//read a .face file and compute half edge and first directed edge
		//data structures and output them in a file with ".diredge"
		
		FileHandler file;
		long numVert = 0;
		extern bool isManifold;
		
		std::vector<int> edge_ID = file.GetEdgeID(argv [1], numVert);
		
		/*
		std::cout << "number of Edges = " << edge_ID.size() << std::endl;
		int face = 0;
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
		
		 //wont be same for legman and hexahedron, look into it later
		std::vector<int> first_DirectedEdge = CalculateFirstDirectedEdge(edge_ID, numVert);
		
		/*std::cout << "Directed Edges : " << std::endl;
		
		for(int v_ID = 0; v_ID < first_DirectedEdge.size(); v_ID++)
		{
			std::cout << "v" << v_ID << " e" << first_DirectedEdge[v_ID] << std::endl;
			
		}*/
		
		std::string objectFileName = "";
		std::string fileName = argv[1];
		std::size_t endPos = fileName.find(".face");
		std::size_t startPos = 0;
		
		
    if( startPos != std::string::npos && endPos != std::string::npos)
    {
        
        
        objectFileName = fileName.substr(startPos, endPos - startPos);
    }
    
    std::string meshName = objectFileName; //storing the name with .tri suffix
    meshName += ".tri";
    
    objectFileName += ".diredge";
    //std::cout << objectFileName << std::endl;
		
		file.WriteDirectedEdgeFormat(objectFileName.data(), argv[1], edge_ID,         
																	first_DirectedEdge, other_Half);
		
		
		if(isManifold)
		{
				std::cout << "The given mesh " << meshName << " is Manifold." << std::endl;	
				
				//code to determine genus of the surface
		}
		
		else
		{
				std::cout << "The given mesh " << meshName << " is NOT Manifold." << std::endl;
				
				if(isEdgeFail)
				{
					std::cout << "IDs of Failed Edges :" << std::endl;
					for(int i = 0; i < edgeFail.size(); i++)
					{
					  std::cout << "e " << edgeFail[i] << std::endl;
					}
				}
				
				
				if(isVertexFail)
				{
					std::cout << "IDs of Failed Vertices :" << std::endl;
					for(int i = 0; i < vertexFail.size(); i++)
					{
					  std::cout << "v " << vertexFail[i] << std::endl;
					}
					
			  }
			  
			  
		}
		
		
	}
	
	
	else
	{
		//if file name isn't provided, tell the user how to do so
		std::cout<< "Usage : " << argv[0] << " <Filename>" << std::endl;
	}
	
	return 0;
}
