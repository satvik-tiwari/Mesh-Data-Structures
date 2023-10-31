#include "FileHandler.h"
#include <stdio.h>

FileHandler::FileHandler()
{

	vertices.resize(0);

}

//if not the name of texte file
void FileHandler::ExtractObjectName(const char *object,
																						 std::ofstream &destination)
{
	//calculating the length of the object name
	int len = sizeof(object)/sizeof(object[0]);
	char buffer[len];
	
	
	if(object[0] >= 'a' && object[0] <= 'z') 
		buffer[0] = object[0] - 32;		
		
	else
		buffer[0] = object[0];
		
	int i;
	for(i = 1; i < len ; i++)
	{
		if(object[i] == '.')
		{
			buffer[i] = '\0';
			break;
		}
			
		buffer[i] = object[i];	
	}	
		
	destination.write(buffer, i);
}

std::vector<int> FileHandler::GetEdgeID(char *file)
{
	//read face 2 face file 		
	std::ifstream source;
	source.open(file);
	
	
	/*
	while (std::getline(input_file, line))
	{
    if (line[0] != "#" )
    {
        std::istringstream iss(line);
        float num; // The number in the line

        //while the iss is a number 
        while ((iss >> num))
        {
            //look at the number
        }
    }
	}
	*/
	std::vector<int> edge_ID;
	std::string line;
	int lineCount = 1;
	long numVertices = 0;
	
	while(getline(source,line) && lineCount < 8)
	{
		//extract number of vertices 
		if(lineCount == 7)
		{
			for(int idx = 0; idx < line.size(); idx++)
			{
				if(line[idx] == '=')
				{
					idx++;
					while(line[idx] != ' ')
					{
						numVertices = numVertices*10 + line[idx];
						idx++;
						
					}
					
					break;
				}
				
			
			}
			
			//break;
		}
		
		lineCount++;
	}
	
	//already skipped 1 line
	//now skip number of vertices lines
	lineCount = 1;
	while(getline(source, line) && lineCount < numVertices)
	{
		lineCount++;
	}
	
	//now we are on first face line
	//if time permits optimize vectors
	edge_ID.resize(numVertices);
	std::string temp;
	for(int edge = 0; edge < numVertices; )
	{
		//dumping "face" and face index in temp
		source >> temp;
		source >> temp;
		source >> edge_ID[edge++];
		source >> edge_ID[edge++];
		source >> edge_ID[edge++];
	}

	source.close();
	return edge_ID;
}

std::vector<Vertex> FileHandler::ReadFile(char *file)
{
	std::ifstream source;
	
	long num_faces;
	long verticesSize;  
	
	source.open(file);
	
	source >> num_faces;
	verticesSize = 3 * num_faces;
	vertices.resize(verticesSize);
	
	//also see if we wwant to use traingle array instead of vertex, meaning vector of vector
	//see if we need to use long here
	for(int vertex = 0; vertex < verticesSize; vertex++)
	{
		source >> vertices[vertex].x >> vertices[vertex].y >> vertices[vertex].z;
		
	}
	
	source.close();
	
	return vertices;
}

//change file to actual name, rithgt now it takes "MyFile.txt" for every object and remove object
void FileHandler::WriteFile(const char *file, const char *object, 
														const std::vector <int> &faceIndices)
{
	std::ofstream destination;//(file);
	
	destination.open(file);
	
	destination << "# University of Leeds 2023-2024 \n"
							<< "# COMP 5812M Assignment 1 \n"
							<< "# Satvik Tiwari \n"
							<< "# 201791342 \n"
							<< "# \n"
							<< "# Object Name: ";
							
							//object name
	ExtractObjectName(object, destination);
	//destination.write(buffer, sizeof(buff_)/sizeof(buff_[0]));
	//delete[] buffer;
							
	destination	<< "\n" 
							<< "# Vertices= " << vertices.size() 
							<< " Faces= " << faceIndices.size()/3 
							<< "\n"
							<< "# \n";
							
	for(int vertex = 0; vertex < vertices.size(); vertex++)
	{
		
		destination << "Vertex " <<
		std::setw(2) << std::right << vertex << " " << 
		std::setw(4) << std::right << vertices[vertex].x << " " <<
		std::setw(4) << std::right << vertices[vertex].y << " " << 
		std::setw(4) << std::right << vertices[vertex].z << " \n";
				
  }
  
  int face = 0;
	for(int edge = 0; edge < faceIndices.size(); )
	{
		destination << "Face " <<
	  std::setw(2) << std::right << face++ << " " << 
		std::setw(2) << std::right << faceIndices[edge++] << " " << 
		std::setw(2) << std::right << faceIndices[edge++] << " " << 
		std::setw(2) << std::right << faceIndices[edge++] << "\n";			
	}
							
																	
	destination.close();						
}


