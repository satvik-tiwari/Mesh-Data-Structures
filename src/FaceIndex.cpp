#include "FaceIndex.h"

//can use pass by reference here
std::vector <int> CalculateFaceIndex(std::vector <Vertex> &vertices,
																		 std::vector <Vertex> &v_ID)
{
	//calculate face index format
	//std::vector <Vertex> v_ID;
	std::vector <int> edge_ID;
	
	v_ID.resize(0);
	edge_ID.resize(0);
	
	
	
	//look into maps and hashing for optimization if time permits
	for(int i = 0; i < vertices.size(); i++)
	{
	
		Vertex currVertex = vertices[i];
		/*std::cout << "Current vertex : " << currVertex.x << " " << currVertex.y << " " << currVertex.z << std::endl;*/
		bool vertexFound = false;
		
		//check if current vertex is in the V_ID or not	
		
		int pos = 0;
		for(; pos < v_ID.size(); pos++)
		{
			if(v_ID[pos] == currVertex)
			{
				vertexFound = true;
				break;
			}
		}
		
		
		if(!vertexFound)
		{
			v_ID.push_back(currVertex);
		}
		
		
		edge_ID.push_back(pos);
		
	}
	
	//return face index format
	
	return edge_ID;
}
