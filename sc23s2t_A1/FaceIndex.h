#include <stdio.h>
#include <iostream>
#include <vector>
#include "Vertex.h"

//include guard
#ifndef FACEINDEX_H
#define FACEINDEX_H

std::vector <int> CalculateFaceIndex(std::vector <Vertex> &vertices, 
													std::vector <Vertex> &v_ID);                               

#endif
