#include "FaceIndex.h"

//can use pass by reference here
std::vector <int> CalculateFaceIndex(std::vector <Vertex> &vertices)
{
	//calculate face index format
	std::vector <Vertex> v_ID;
	std::vector <int> edge_ID;
	
	v_ID.resize(0);
	edge_ID.resize(0);
	
	
	
	//use maps and hashing for optimization
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
		/*std::cout << "Position Before: " << pos << std::endl;
		std::cout << "Vertex found : " << vertexFound << std::endl;*/
		
		if(!vertexFound)
		{
			v_ID.push_back(currVertex);
		}
		
		/*std::cout << "VID" << std::endl;
		for (int k = 0; k < v_ID.size(); k++)
		{
			Vertex curVertex = v_ID[k];
			std::cout << curVertex.x << " " << curVertex.y << " " << curVertex.z << std::endl;
		}			
		*/
		
		//generate face index format array
		//std::cout << "Position After 1 : " << pos << std::endl;
		edge_ID.push_back(pos);
		//std::cout << "Position After 2 : " << pos << std::endl;
		
		/*std::cout << "Edge ID" << std::endl;
		for (int k = 0; k < edge_ID.size(); k++)
		{
			
			std::cout << edge_ID[k] << " ";
		}			
		
		std::cout << std::endl;
		std::cout << std::endl;*/
	}
	
	//return face index format
	
	return edge_ID;
}
