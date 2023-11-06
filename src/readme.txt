# University of Leeds 2023-24
# COMP 5812M Assignment 1 Triangle Soup Renderer
# Satvik Tiwari
# 201791342
#

##########################################################################

First put the "src"(source code) folder at the same level in the hierarchy as the "handout_models" folder.

##########################################################################

- To compile everything all at onece and perform linking:

[userid@src]$ make all

This will compile all the cpp files and link them accordingly to produce individual ".o" files and two executables in the "src" folder:
  1. face2faceindex 
  2. directededge

##########################################################################

- To execute "face2faceindex" program do the following:

[userid@src]$ ./face2faceindex ../handout_models/mesh_name.tri

where, mesh_name is the name of the mesh of the .tri present in "handout_models" folder 

eg -

[userid@src]$ ./face2faceindex ../handout_models/tetrahedron.tri

This will generate a "mesh_name.face" file in the "src" directory itself.
 
##########################################################################

- To execute "directededge" program do the following:

[userid@src]$ ./directededge mesh_name.face

where, mesh_name is the name of the mesh of the .face file present in "src" folder 

eg -

[userid@src]$ ./tetrahedron.face

This will generate a "mesh_name.diredge" file in the "src" directory itself.

- If the mesh is Manifold, the program will print so on the terminal, followed by the genus of the given mesh.

- If the mesh is not Manifold, the program will print so on the terminal, followed by ids of edges or vertices where it fails.

###########################################################################

- to clean all the intermediates, excutables, .face, .diredge, basically everything except for cpp and header files :

[userid@src]$ make clean

###########################################################################

The Analysis of the algorithmic complexity of the code is in the "Algorithmic_Complexity_Analysis.txt" file in "src" folder.

###########################################################################

- Note 

I have not implemented the pinch point test for manifold test and calculation of handles for a mesh with 2 polyhedra with air gap between them, because of shortage of time. 

If it works, its a mere coincidence :)

Will look into it later.
