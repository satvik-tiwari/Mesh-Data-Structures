#file extension to be cleaned
EXT = *.face *.diredge *.o


#put the source folder at the same level of hierarchy as the handout models folder

first : face2faceindex directededge



face2faceindex : Face2FaceIndex.o \
                 FaceIndex.o \
                 FileHandler.o \
                 Vertex.o
								 echo "Linking and producing Face2Face executable."
								
										g++ -o face2faceindex Face2FaceIndex.o FaceIndex.o FileHandler.o Vertex.o
										

directededge : FaceIndex2DirectedEdge.o \
               FileHandler.o \
               OtherHalf.o \
               Genus.o 
							 echo "Linking and producing Directed Edge executable."							
										
										g++ -o directededge FaceIndex2DirectedEdge.o FileHandler.o OtherHalf.o FirstDirectedEdge.o Genus.o
			   
Face2FaceIndex.o : Face2FaceIndex.cpp Face2FaceIndex.h \
									 Vertex.o \
									 FileHandler.o \
									 FaceIndex.o			  
									 
									 echo "Compiling the Face2FaceIndex file."
			   								g++ -c Face2FaceIndex.cpp

FaceIndex2DirectedEdge.o : FaceIndex2DirectedEdge.cpp FaceIndex2DirectedEdge.h \
													 FileHandler.o \
													 OtherHalf.o \
													 FirstDirectedEdge.o \
													 Genus.o
													
									 echo	"Compiling FaceIndexDirectedEdge File."
									 			 g++ -c FaceIndex2DirectedEdge.cpp			
																				   
			   
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
			   							

OtherHalf.o : OtherHalf.cpp OtherHalf.h
							
							echo "Compiling Other Half File."
	                  g++ -c OtherHalf.cpp	

FirstDirectedEdge.o : FirstDirectedEdge.cpp FirstDirectedEdge.h
											
											echo "Compiling	First Directed Edge File."
											
											g++ -c FirstDirectedEdge.cpp
											
Gensu.o : Genus.cpp Genus.h
											
				 echo "Compiling	Genus File."
											
					 g++ -c Genus.cpp
					 											
clean : 

			echo "Removing everything but the source files"
			
			for i in $(EXT); do find . -name "$$i" -delete; done
			
			rm face2faceindex directededge
			
			
			#rm face2faceindex directededge Face2FaceIndex.o FaceIndex2DirectedEdge.o FaceIndex.o FileHandler.o Vertex.o OtherHalf.o FirstDirectedEdge.o 
			

