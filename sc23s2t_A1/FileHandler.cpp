#include "FileHandler.h"

//constructor
FileHandler::FileHandler()
{
	//resizing because i am paranoid
	v_ID.resize(0);
}

//write the object name to the destination file
void FileHandler::ObjectName(const char *file,
														std::ofstream &destination,
														bool isFaceFile)
{

	  std::string objectName = "";
	  std::string fileName = file;
		
		std::size_t endPos, startPos = 0;
		
		//code for writing the name to .face file for given .tri file 
		if(isFaceFile)
		{
			endPos = fileName.find(".tri");
			startPos = fileName.find_last_of('/');
			
			if( startPos != std::string::npos && endPos != std::string::npos)
    	{ 
        objectName = fileName.substr(startPos+1, endPos - 1 - startPos);
    	}
		}
		
		//code for writing the name to .diredge file for given .face file 
		else
		{
			endPos = fileName.find(".face");
			
			if( startPos != std::string::npos && endPos != std::string::npos)
    	{
        objectName = fileName.substr(startPos, endPos);
   	  }
		
		}
	
	//if first letter in lowerecase, convert to uppercase
	if(objectName[0] >= 'a' && objectName[0] <= 'z') 
		objectName[0] = objectName[0] - 32;		
		
	destination << objectName;
}

//extract the edgeIDs from the given face file
std::vector<int> FileHandler::GetEdgeID(char *file, long &numVert)
{
	//read face 2 face file 		
	std::ifstream source;
	source.open(file);
	

	std::vector<int> edge_ID;
	std::string line;
	int lineCount = 1;
	long numVertices, numFaces;
	numVertices = numFaces = 0;
	
	//as the number of faces and vertices are at line 7 in every face file
	//we will skip everyting until then
	while(getline(source,line) && lineCount < 8)
	{
		//extract number of vertices and faces from line number 7
		if(lineCount == 7)
		{
		
			for(int idx = 0; idx < line.size(); idx++)
			{
				//skip everthing until we encounter numbers
				if(line[idx] == '=')
				{
					
					idx++;
					
					//extract the number of vertices
					while(line[idx] != ' ')
					{
						
						numVertices = numVertices*10 + (line[idx] - 48);
						idx++;
						
					}
					
					 idx++;
					while(line[idx] != '=')
					{
						idx++;		
					}
					
					idx++;
					
					//extract the number of faces
					while(idx < line.size())
					{
						numFaces = numFaces*10 + (line[idx] - 48);
						idx++;
					}
					
					break;
				}	
			}
	
		}
		
		lineCount++;
	}
	
	//already skipped 1 empty line
	//now store all the vertices for later use, to write the same 
	v_ID.resize(numVertices);
	std::string temp;     //dump variable
	
	//iterating over lines containing vertieces
	//and dumping unnecessary stuff to temp
	//and only storing the vertices
	for(int vertex = 0; vertex < numVertices; vertex++)
	{
		source >> temp;
		source >> temp;
		source >> v_ID[vertex].x >> v_ID[vertex].y >> v_ID[vertex].z;	
	}
	
	
	//now we are on first face line
	//if time permits optimize vectors
	edge_ID.resize(numFaces * 3);
	
	//going through lines containing faces and storing them
	for(int edge = 0; edge < numFaces * 3; )
	{
		//dumping "face" and face index in temp
		source >> temp;
		source >> temp;
		
		source >> edge_ID[edge++];
		source >> edge_ID[edge++];
		source >> edge_ID[edge++];	
	}

	source.close();
	
	//storing number of vertieces in the reference variable
	//from faceindedx2directedge file
	numVert = numVertices;
	return edge_ID;
}

std::vector<Vertex> FileHandler::ReadFile(char *file)
{
	std::ifstream source;
	
	std::vector<Vertex> vertices; //to store all vertices given in the triangle file
	vertices.resize(0);
	
	long num_faces;
	long verticesSize;  
	
	source.open(file);
	
	source >> num_faces;
	verticesSize = 3 * num_faces;
	vertices.resize(verticesSize);
	
	//also see later if we wwant to use traingle array instead of vertex, meaning vector of vector
	
	//extract vertices from .face file
	for(int vertex = 0; vertex < verticesSize; vertex++)
	{
		source >> vertices[vertex].x >> vertices[vertex].y >> vertices[vertex].z;
		
	}
	
	source.close();
	
	return vertices;
}

void FileHandler::HeaderBlock(std::ofstream &destination)
{
	//write the header block of the file
	destination << "# University of Leeds 2023-2024 \n"
							<< "# COMP 5812M Assignment 1 \n"
							<< "# Satvik Tiwari \n"
							<< "# 201791342 \n"
							<< "# \n";
							
}

void FileHandler::ObjectBlock(std::ofstream &destination,
															const char *object,
															int faceIndicesSize,
															bool isFaceFile)
{
	//write the object name and its information on the file
	
	destination << "# Object Name: ";	
							//object name
	ObjectName(object, destination, isFaceFile);
	
		destination	<< "\n" 
							  << "# Vertices=" << v_ID.size() 
							  << " Faces=" << faceIndicesSize
							  << "\n"
							  << "# \n";
	
}


void FileHandler::VertexBlock(std::ofstream &destination)
{
	//write the vertex block of the file
	
	for(int vertex = 0; vertex < v_ID.size(); vertex++)
	{
		
		destination << "Vertex " <<
		std::setw(2) << std::right << vertex << " " << 
		std::setw(4) << std::right << v_ID[vertex].x << " " <<
		std::setw(4) << std::right << v_ID[vertex].y << " " << 
		std::setw(4) << std::right << v_ID[vertex].z << " \n";
				
  }
	
}

void FileHandler::FaceBlock(std::ofstream &destination,
														const std::vector <int> &faceIndices)
{
	//write the face block of the file
	int face = 0;
	for(int edge = 0; edge < faceIndices.size(); )
	{
		destination << "Face " <<
	  std::setw(2) << std::right << face++ << " " << 
		std::setw(2) << std::right << faceIndices[edge++] << " " << 
		std::setw(2) << std::right << faceIndices[edge++] << " " << 
 		std::setw(2) << std::right << faceIndices[edge++] << "\n";			
	}
	
	
}

void FileHandler::FirstDirectedEdgeBlock(std::ofstream &destination,
																					const std::vector <int> &first_DirectedEdge)
{
	//write the first directed edge block of the file
	
	int numVertex = first_DirectedEdge.size();
	for(int v_ID = 0; v_ID < numVertex; v_ID++)
	{
		destination << "FirstDirectedEdge " <<
		std::setw(2) << std::right << v_ID << " " <<
		std::setw(2) << std::right << first_DirectedEdge[v_ID] << "\n"; 
		
	}
}

void FileHandler::OtherHalfBlock(std::ofstream &destination,
																				 const std::vector <int> &other_Half)
{
	//write the Other Half block of the file
	
	int numOtherHalf = other_Half.size();
	for(int e_ID = 0; e_ID < numOtherHalf; e_ID++)
	{
		destination << "OtherHalf " <<
		std::setw(2) << std::right << e_ID << " " <<
		std::setw(2) << std::right << other_Half[e_ID] << "\n";	
	}
}
										

//write contents to .face file
void FileHandler::WriteFaceFileFormat(const char *file, const char *object, 
														const std::vector<Vertex> &v_ID, 
														const std::vector <int> &faceIndices)
{
	this->v_ID = v_ID;
	
	std::ofstream destination;
	
	//writing all the blocks one by one to .face file
	destination.open(file);
	
	HeaderBlock(destination);
	
	ObjectBlock(destination, object, faceIndices.size()/3, true);
	
	VertexBlock(destination);
	
	FaceBlock(destination, faceIndices);
																	
	destination.close();						
}




//write contents to .directedge file
void FileHandler::WriteDirectedEdgeFormat(const char *file, const char *object,
																					std::vector<int> &edge_ID,
																					std::vector<int> &first_DirectedEdge, 
														 							std::vector<int> &other_Half)
{
	std::ofstream destination;
	
	destination.open(file);
	
	//writing all the block one by one to the .diectedge file
	
	HeaderBlock(destination);
	
	ObjectBlock(destination, object, other_Half.size() / 3, false);
	
	VertexBlock(destination);
	
	FirstDirectedEdgeBlock(destination, first_DirectedEdge);
	
	FaceBlock(destination, edge_ID);
	
	OtherHalfBlock(destination, other_Half);
	
	destination.close();
}														 




