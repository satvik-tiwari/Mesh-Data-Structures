#include <fstream>
#include <vector>
#include "Vertex.h"
#include <iomanip>
#include <string>

class FileHandler
{
	private:
				
				std::vector<Vertex> vertices;
	
	public:
	
				FileHandler();
				
				std::vector<Vertex> ReadFile(char *file);  //if time is remaining, make it const
				
				
				
				void ExtractObjectName(const char *object,
																	     std::ofstream &destination);
				
				void WriteFile(const char *file, const char *object,
											const std::vector <int> &faceIndices);
											
				std::vector<int> GetEdgeID(char *file);
				
				
};

