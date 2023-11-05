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
		long numVert = 0; //number of vertices defining our mesh, without any duplication
		
		//extract the faces from the "Mesh.face" file int the form of edges
		//where each face is represented by 3 consecutive edges
		std::vector<int> edge_ID = file.GetEdgeID(argv [1], numVert);
		
		//create other half data structure based on edge array
		std::vector<int> other_Half = CalculateOtherHalf(edge_ID); 
		
		//generate first directed edge data structure
		std::vector<int> first_DirectedEdge = CalculateFirstDirectedEdge(edge_ID, numVert);
		
		//generate the file name in the format of "Mesh.diredge"
		std::string objectFileName = "";
		std::string fileName = argv[1];
		std::size_t endPos = fileName.find(".face");
		std::size_t startPos = 0;
		
		
    if( startPos != std::string::npos && endPos != std::string::npos)
    {
        
        
        objectFileName = fileName.substr(startPos, endPos - startPos);
    }
    
    std::string meshName = objectFileName; //storing the name with .tri suffix for later use
    meshName += ".tri";
    
    objectFileName += ".diredge";
    
		//write other half and first directed edges along with other stuff
		//to the "Mesh.diredge" file
		file.WriteDirectedEdgeFormat(objectFileName.data(), argv[1], edge_ID,         
																	first_DirectedEdge, other_Half);
		
		//if the mesh is manifold
		if(isManifold)
		{
				std::cout << "The given mesh " << meshName << " is Manifold." << std::endl;	
				
				//code to determine genus of the surface
				int genus = CalculateGenus(numVert, (edge_ID.size()) / 2, (edge_ID.size()) / 3);
				
				std::cout << "Genus of the surface = " << genus << std::endl;
			  
			  
		}
		
		//if the mesh isn't manifold
		else
		{
				std::cout << "The given mesh " << meshName << " is NOT Manifold." << std::endl;
				
				//code to print which of the edges fail
				if(isEdgeFail)
				{
					std::cout << "IDs of Failed Edges :" << std::endl;
					for(int i = 0; i < edgeFail.size(); i++)
					{
					  std::cout << "e " << edgeFail[i] << std::endl;
					}
				}
				
				//code to print which of the vertics fail
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
