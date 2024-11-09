#ifndef BELLMAN_H
#define BELLMAN_H
 
#include <iostream>
#include <cstring>

using namespace std;

void BF(int graph[][20], int num_vertices, char start_vertex, int *BFValues, int *BFPrev);
string BF_Path(int graph[][20], int num_vertices, char start_vertex, char goal_vertex);

#endif /*BELLMAN_H*/