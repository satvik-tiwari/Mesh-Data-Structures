#include "FirstDirectedEdge.h"

extern bool isManifold;
extern bool isVertexFail;
extern std::vector<int> vertexFail;

std::vector<int> CalculateFirstDirectedEdge(std::vector<int> &edge_ID, long vertices)
{
	 //intitialize the first directed edge array with -1 
	 std::vector<int> FirstDirectedEdge(vertices, -1);
	 vertexFail.resize(0);
	 
	 //iterate over edges
	 long numEdges = edge_ID.size();
	
	 for(int e = 0; e < numEdges; e++)
	 {
	 		//get the Vertex id  at each and edge and at that vertex id
	 		//write that edge
	 		
	 		//if ther is time, look into optimazation here
	 		
	 		int v_ID = edge_ID[e];  
	 		FirstDirectedEdge[v_ID] = e;
	 }
	 
	 //write code for manifold test here
		 
	 //loop through all the firstDirected Edges, 
	 //and if a vertex cell is empty,
	 //not manifold
	 
	 long numV_ID = FirstDirectedEdge.size();
	 for(int v_ID = 0; v_ID < numV_ID; v_ID++)
	 {
	 		if(FirstDirectedEdge[v_ID] == -1)
	 		{
	 			isManifold = false;
	 			isVertexFail = true;
	 			vertexFail.push_back(v_ID);
	 		}
	 }
	 
	 return FirstDirectedEdge;
}
