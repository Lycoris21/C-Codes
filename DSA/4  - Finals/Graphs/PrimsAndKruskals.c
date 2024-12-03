#include <stdio.h>
#define MAX 10 //maximum number of vertices
#define infinity 999
#define MAX_EDGES 20 //maximum number of edges nxn

typedef int LabelAdjMat[MAX][MAX];

typedef struct{
	int u, v; //representing edge (u,v)
	int weight;
}edgetype;

typedef struct{
	edgetype edges[MAX_EDGES];
	int lastNdx;
}minHeapOrList;

typedef struct{	
	minHeapOrList List;
	int cost;
}MST; //prim's or kruskal's

// createMinHeap()
	// Given the labeled adjacency matrix of an undirected graph, function createMinHeap() 
	// will create a minheap of edges based on weights. Newly created min heap will be 
	// returned to the calling function. Write the code of the function createMinHeap()
		// helper functions:
			// initMinHeap()
			// insertMinHeap()
		// 2 ways to make a POT: 
			// 1) insert all the data first them heapify // Insert all elements in an initially empty POT
			// 2) heapify every insertion  //Heapify -> calls heapifySubtree
	

// deleteMinHeap()
	// deletes and returns the smallest element (edgetype) found at the root
	// helper functions:
		// minHeapifySubtree - given minheap and index of the root of the subtree to be heapified
		
		
// Prim's:
	// -additional Data Structure: bit-vector or computer word
	// MST Prims(LabelAdjMat A, vertex startV)
	// Given: 
		// 1) Graph G = (V, E)
		// 2) V = {0, 1, 2, 3, 4, 5}
	//Step of Prim's Algorithm
		// 1) Initialize set U to contain {0}
		// 2) While (U!=V)
				// 1) Find the minimum cost edge (u,v) such that u is an element of U and v is an element of V-U
				// 2) Add v to U
				//
				
				
//Kruskal's
	// -additional Data Structure: array of components
	// MST Kruskals(LabelAdjMat A)
	// Given:
		// 1) Graph G = (V, E)
		// 2) V = {0, 1, 2, 3, 4, 5}
	// Steps of Kruskal's Algorithm
		// 1) Initialize Graph T = (V, NULL) consisting of:
				// a) the vertices in V and having no edges
				// b) each vertex in a connected component by itself
			// 2) While (all the vertices are NOT yet in 1 component)
				// Find the edge (u,v) with the minimum cost
				
				//

// fuction prototypes:
minHeapOrList createMinHeap();
void initMinHeap(minHeapOrList *);
void insertMinHeap(minHeapOrList *, edgetype);

edgetype deleteMinHeap(minHeapOrList *);
void minHeapifySubtree(minHeapOrList *, int);
		
				
				
int main(){
	minHeapOrList Heap = createMinHeap();
	return 0;
}   

minHeapOrList createMinHeap(){
	minHeapOrList h = createMinHeap(&h);
		
	return h;
}

void initMinHeap(minHeapOrList *H){
	H->lastNdx = -1;
}


