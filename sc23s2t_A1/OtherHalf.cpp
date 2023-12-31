#include "OtherHalf.h"

extern bool isManifold;
extern std::vector<int> edgeFail;
extern bool isEdgeFail;

//calculate end vertex of an edge in a face
int CalculateNext(int idx)
{
	/*int local_idx = idx % 3;
	
	int base = idx - (idx % 3);
	
	int result = base + ((local_idx + 1) % 3);*/
	
	return idx - (idx % 3) + (((idx % 3) + 1) % 3);
}

std::vector<int> CalculateOtherHalf(std::vector<int> &edge_ID)
{
  //initialize the other half array with -1 to denote that cells
  //are empty
	std::vector<int> otherHalf(edge_ID.size(), -1);
	edgeFail.resize(0);
	int numEdges = edge_ID.size(); 
	
	//iterating over other half array
	for(int idx = 0; idx < numEdges; idx++)
	{
		//store the starting and ending vertex of an edge
		Edge edge;
		
		//if the cell in the OtherHalf array is empty, only then calculate other half
		 if(otherHalf[idx] == -1)
     {
				 edge.prev = edge_ID[idx];  //prev has the first vertex of edge
				 edge.next = edge_ID[CalculateNext(idx)]; //what if next is not valid??
					
				 //we have the start and end vertices of edge prev -> next
				
				 Edge otherH;
				
				 otherH.next = edge.prev;
				 otherH.prev = edge.next;
				
				 int found = 0;
				 //now we iterate over faces to find the other half of the edge next -> prev		
				
						 for(int e = 0; e  < numEdges; e++)
						 {
							 //if first vertex of other half edge is found, find the second vertex on the same
							 	if(edge_ID[e] == otherH.prev)
							 	{
										 if(edge_ID[CalculateNext(e)] == otherH.next)
										 {
												 // if found that we got our half edge
												 //check if we are not overwriting
												 found = 1;
												 otherHalf[idx] = e;
												 
												 if(otherHalf[e] == -1)
													 otherHalf[e] = idx;
												
												 else
													{
													//not manifold	
													//code for telling not manifold
													//storing failed edges
													
													isManifold = false;
													isEdgeFail = true;
													edgeFail.push_back(e);
													}
													
												break;
										}
								
										//otherwise keep looking
							 	}
						 }
				
				if(!found)
				{
			 		//if found = 0, not manifold
			 		//code for telling not manifold and storing failed edges
			 		isManifold = false;
			 		isEdgeFail = true;
			 		edgeFail.push_back(idx);
			 	}
				
    }
  }
  
  return otherHalf;
}
