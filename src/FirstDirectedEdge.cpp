#include "FirstDirectedEdge.h"

std::vector<int> CalculateFirstDirectedEdge(std::vector<int> &edges, long vertices)
{
	 //intitialize the first directed edge array with -1 
	 std::vector<int> FirstDirectedEdge(vertices, -1);
	 
	 //iterate over edges
	 long numEdges = edges.size();
	 for(int e = 0; e < numEdges; e++)
	 {
	 		//get the Vertex id  at each and edge and at that vertex id
	 		//write that edge
	 		
	 		//if ther is time, look into optimazation here
	 		int v_ID = edges[e];  
	 		FirstDirectedEdge[v_ID] = e;
	 }
	 
	 //write code for manifold test here
	 
	 
	 //loop through all the firstDirected Edges, 
	 //and if a vertex column is empty,
	 //not manifold
	 
	 return FirstDirectedEdge;
}
