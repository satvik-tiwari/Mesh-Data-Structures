#include "FaceIndex.h"

std::vector <int> CalculateFaceIndex(std::vector <Vertex> &vertices,
																		 std::vector <Vertex> &v_ID)
{
	//calculate face index format
	//i am doing so by maintaing a edge array, where each face is represented
	//by three consecutive edges
	std::vector <int> edge_ID;
	
	//resizing to 0, because i am paranoid
	//v_ID is the vertex array without any duplication
	v_ID.resize(0);
	edge_ID.resize(0);
	
	//look into maps and hashing for optimization if time permits
	//iterating over the vertices provided in the "mesh.tri" file
	for(int i = 0; i < vertices.size(); i++)
	{
		
		//storing the current vertex from the vertices array
		Vertex currVertex = vertices[i];
		
		bool vertexFound = false;
		
		//check if current vertex is in the V_ID or not	
		
		int pos = 0;
		for(; pos < v_ID.size(); pos++)
		{
			//if found, no need to search further
			if(v_ID[pos] == currVertex)
			{
				vertexFound = true;
				break;
			}
		}
	
		if(!vertexFound)
		{
		//if not found then add the vertex to v_ID array
			v_ID.push_back(currVertex);
		}	
		
		//add the id of the vertex to the edges
		edge_ID.push_back(pos);
		
	}
	
	//return face index format
	
	return edge_ID;
}
