#include "Genus.h"

//calculate genus based on number of vertex, edges and faces
int CalculateGenus(int v, int e, int f)
{
	// Euler's formula : v-e+f = 2 -2g
	int genus = abs(1 - ((v - e + f) / 2));
	
	return genus;
}
