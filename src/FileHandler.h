#include <fstream>
#include <vector>
#include "Vertex.h"
#include <iomanip>
#include <string>
#include <stdio.h>
#include <iostream>

class FileHandler
{
	private:
				//to store all the vertices of the mesh only once without repeating
				std::vector<Vertex> v_ID;
	
	public:
	
				FileHandler();
				
				std::vector<Vertex> ReadFile(char *file);  //if time is remaining, make it const
				
				
				
				void ObjectName(const char *fileName,
																	     std::ofstream &destination);
				
				void WriteFaceFileFormat(const char *file, const char *object,
											const std::vector<Vertex> &v_ID,
											const std::vector <int> &faceIndices);
											
		   	void WriteDirectedEdgeFormat(const char *file, const char *object,
		   															std::vector<int> &edge_ID,
		   															std::vector<int> &first_DirectedEdge, 
									 									std::vector<int> &ohter_Half);

											
				void HeaderBlock(std::ofstream &destination);	
				
				void ObjectBlock(std::ofstream &destination,
															const char *object,
															int faceIndicesSize);
															
        void VertexBlock(std::ofstream &destination);
        
        void FaceBlock(std::ofstream &destination,
        							 const std::vector <int> &faceIndices);
        							 
        void FirstDirectedEdgeBlock(std::ofstream &destination,
																					const std::vector <int> &first_DirectedEdge);
																					
				void OtherHalfBlock(std::ofstream &destination,
																				 const std::vector <int> &other_Half);																							
											
				std::vector<int> GetEdgeID(char *file);
				
				
};

