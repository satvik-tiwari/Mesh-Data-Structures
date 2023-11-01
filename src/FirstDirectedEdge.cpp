#include "FirstDirectedEdge.h"

std::vector<int> CalculateFirstDirectedEdge(std::vector<int> &edge_ID, long vertices)
{
	 //intitialize the first directed edge array with -1 
	 std::vector<int> FirstDirectedEdge(vertices, -1);
	 
	 //iterate over edges
	 long numEdges = edge_ID.size();
	 
	 /*
	 //std::cout << "number of edges = " << edge_ID.size() << std::endl;
		int face = 0;
		for(int edge = 0; edge < edge_ID.size(); edge++)
		{
			std::cout << "e" << edge << " v" << edge_ID[edge] << std::endl;
		}*/
		
	 
	 
	 for(int e = 0; e < numEdges; e++)
	 {
	 		//get the Vertex id  at each and edge and at that vertex id
	 		//write that edge
	 		
	 		//if ther is time, look into optimazation here
	 		/*std::cout << "Before checking e" << e << ":\n";
	 		for(int i = 0; i < vertices; i++)
	 		{
	 			
	 			std::cout << FirstDirectedEdge[i];
	 		}
	 		
	 		std::cout<<std::endl; */
	 		
	 		int v_ID = edge_ID[e];  
	 		FirstDirectedEdge[v_ID] = e;
	 		
	 		/*std::cout << "After checking e" << e << ":\n";
	 		for(int i = 0; i < vertices; i++)
	 		{
	 			
	 			std::cout << FirstDirectedEdge[i];
	 		}
	 		
	 		std::cout<<std::endl << std::endl;*/
	 }
	 
	 //write code for manifold test here
	 
	 
	 //loop through all the firstDirected Edges, 
	 //and if a vertex column is empty,
	 //not manifold
	 
	 return FirstDirectedEdge;
}
