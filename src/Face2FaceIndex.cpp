#include "Face2FaceIndex.h"
#include "FaceIndex.h"
 
//argc for number of arguments
//argv for storing the arguments
int main(int argc, char **argv)
{
	
	if(argc == 2) 
	{
		FileHandler triangleSoup;
		
		//read triangle soup and generate VIDs i.e, vertex array
		std::vector<Vertex> vertices = triangleSoup.ReadFile(argv[1]);
	
		//if time permits convert convert code 
		//from edge IDs to faceIDs format instead of using edge IDs for faces
		
		//genertae the face indices in the form of half edges, where each face is determined by three consecutive half edges.
		std::vector<Vertex> v_ID;
		std::vector<int> faceIndices = CalculateFaceIndex(vertices, v_ID);
		
		//generate name of the mesh in "mesh.face" format
		std::string objectFileName = "";
		std::string fileName = argv[1];
		std::size_t endPos = fileName.find(".tri");
		std::size_t startPos = fileName.find_last_of('/');
		
		
    if( startPos != std::string::npos && endPos != std::string::npos)
    {
        
        
        objectFileName = fileName.substr(startPos+1, endPos - 1 - startPos);
    }
    
    objectFileName += ".face";
    
    //write the faces to the file
    triangleSoup.WriteFaceFileFormat(objectFileName.data(), argv[1],
    																 v_ID, faceIndices);
	}
	
	
	else
	{
			//if file name isn't provided, tell the user how to do so
			std::cout<< "Usage : " << argv[0] << " <Filename>" << std::endl;
	
	}


return 0;
}
