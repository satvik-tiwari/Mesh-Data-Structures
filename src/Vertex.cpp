#include "Vertex.h"

bool Vertex::operator ==(const Vertex& other)const
{
	//check if can be optimized later
	
	return x == other.x ? (y == other.y ? (z == other.z ? true : false) : false) : false;	
	
}
