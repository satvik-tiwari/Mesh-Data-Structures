

all: face2faceindex



face2faceindex : Face2FaceIndex.o FaceIndex.o FileHandler.o Vertex.o
								echo "Linking and producing Face2Face format executable."
								
										g++ -o face2faceindex Face2FaceIndex.o FaceIndex.o FileHandler.o Vertex.o
			
			   
Face2FaceIndex.o : Face2FaceIndex.cpp Face2FaceIndex.h \
									 Vertex.o \
									 FileHandler.o \
									 FaceIndex.o			  
									 
									 echo "Compiling the Face2FaceIndex file."
			   								g++ -c Face2FaceIndex.cpp
			   
			   
FaceIndex.o : FaceIndex.cpp FaceIndex.h \
							Vertex.o
							
							echo "Compiling the FaceIndex file."
			   								g++ -c FaceIndex.cpp

FileHandler.o : FileHandler.cpp FileHandler.h \
								Vertex.o
						
								echo "Compiling the FileHandler file."
			   								g++ -c FileHandler.cpp

Vertex.o : Vertex.cpp Vertex.h
					
					echo "Compiling the Vertex file."
			   								g++ -c Vertex.cpp


clean : 

			echo "Removing everything but the source files"
			rm Face2FaceIndex.o FaceIndex.o FileHandler.o Vertex.o face2faceindex MyFile.txt MyFile.face MyFile
