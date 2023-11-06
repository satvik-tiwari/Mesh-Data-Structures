#include "Vertex.h"

bool Vertex::operator ==(const Vertex& other)const
{
	//check if can be optimized later
	
	//to calculate if two vertices are equal or not
	float epsilon = 1.0e-9f ;
	
	return fabs(x - other.x) <= epsilon ? (fabs(y - other.y) <= epsilon ? (fabs(z- other.z) <= epsilon ? true : false) : false) : false;
	
	
}
