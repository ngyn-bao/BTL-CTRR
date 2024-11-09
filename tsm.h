#ifndef TSM_H
#define TSM_H

#include "bellman.h"

void Backtracking(int graph[20][20], int num_vertices, int current_pos, int count, int cost, int &min_cost, int path[], int best_path[], int start_index, bool visited[]);

string Traveling(int graph[20][20], int nums_vertices, char start_vertex);

#endif /*TSM_H*/