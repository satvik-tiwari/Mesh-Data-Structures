#include "Face2FaceIndex.h"
#include "FaceIndex.h"

/*
char * GenerateFileName(const char *name)
{

}*/ 

int main(int argc, char **argv)
{
	
	if(argc == 2) 
	{
		FileHandler triangleSoup;
		
		std::vector<Vertex> vertices = triangleSoup.ReadFile(argv[1]);
		
		/*for(int vertex = 0; vertex < vertices.size(); vertex++)
		{
		
			std::cout << "Vertex " <<
			std::setw(2) << std::right << vertex << " " << 
			std::setw(4) << std::right << vertices[vertex].x << " " <<
			std::setw(4) << std::right << vertices[vertex].y << " " << 
			std::setw(4) << std::right << vertices[vertex].z <<
			std::endl;
		
		
		}*/
		
		//if time permits convert faceIndices to actual Face IDs instead of edge IDs
		std::vector<int> faceIndices = CalculateFaceIndex(vertices);
		
		/*int face = 0;
		for(int edge = 0; edge < faceIndices.size(); )
		{
			std::cout << "Face " <<
			std::setw(2) << std::right << face++ << " " << 
			std::setw(2) << std::right << faceIndices[edge++] << " " << 
			std::setw(2) << std::right << faceIndices[edge++] << " " << 
			std::setw(2) << std::right << faceIndices[edge++] << " " << 
			std::endl;			
		}
		*/
		
		//char [100] = triangleSoup.(argv[1], true);
		
		
		//if time permits generate proper file name
		//std::ofstream MyFile("MyFile.face");
		std::string objectFileName = "";
		std::string fileName = argv[1];
		std::size_t endPos = fileName.find_first_of(".tri");
		std::size_t startPos = fileName.find_last_of('/');
		
    if( startPos != std::string::npos && endPos != std::string::npos)
    {
        // Get substring from before the '.'
        objectFileName = fileName.substr(startPos+1, endPos);
    }
    std::cout << "File name : " << objectFileName << " Realname : " << fileName;
		triangleSoup.WriteFaceFileFormat("MyFile.face", argv[1], faceIndices);
	}
	
	
	else
	{
	
			std::cout<< "Usage : " << argv[0] << " <Filename>" << std::endl;
	
	}


return 0;
}
