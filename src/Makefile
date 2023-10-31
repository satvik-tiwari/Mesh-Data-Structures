all: face2faceindex directededge



face2faceindex : Face2FaceIndex.o \
                 FaceIndex.o \
                 FileHandler.o \
                 Vertex.o
								 echo "Linking and producing Face2Face executable."
								
										g++ -o face2faceindex Face2FaceIndex.o FaceIndex.o FileHandler.o Vertex.o
										

directededge : FaceIndex2DirectedEdge.o FileHandler.o OtherHalf.o
							 echo "Linking and producing Directed Edge executable."							
										
										g++ -o directededge FaceIndex2DirectedEdge.o FileHandler.o OtherHalf.o
			   
Face2FaceIndex.o : Face2FaceIndex.cpp Face2FaceIndex.h \
									 Vertex.o \
									 FileHandler.o \
									 FaceIndex.o			  
									 
									 echo "Compiling the Face2FaceIndex file."
			   								g++ -c Face2FaceIndex.cpp

FaceIndex2DirectedEdge.o : FaceIndex2DirectedEdge.cpp FaceIndex2DirectedEdge.h \
													 FileHandler.o \
													 OtherHalf.o
													
									 echo	"Compiling FaceIndexDirectedEdge File."
									 			 g++ -c FaceIndex2DirectedEdge.cpp			

OtherHalf.o : OtherHalf.cpp OtherHalf.h
							
							echo "Compiling Other Half File."
	                  g++ -c OtherHalf.cpp						
 							    
															   
			   
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
			rm Face2FaceIndex.o FaceIndex.o FileHandler.o Vertex.o FaceIndex2DirectedEdge.o OtherHalf.o face2faceindex directededge MyFile.txt MyFile.face MyFile
