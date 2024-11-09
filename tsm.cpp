#include "tsm.h"

const int INF = 100000000;

void Backtracking(int graph[20][20], int num_vertices, int current_pos, int count, int cost, int &min_cost, int path[], int best_path[], int start_index, bool visited[], int minc)
{
    {
        if (count == num_vertices && graph[current_pos][start_index])
        {
            if (cost + graph[current_pos][start_index] < min_cost)
            {
                min_cost = cost + graph[current_pos][start_index];
                for (int i = 0; i < num_vertices; i++)
                    best_path[i] = path[i];
            }
            return;
        }

        for (int i = 0; i < num_vertices; ++i)
        {
            if (!visited[i] && graph[current_pos][i])
            {
                visited[i] = true;
                path[count] = i;
                count++;
                cost += graph[current_pos][i];
                if(cost + (num_vertices - count + 1) * minc <= min_cost) Backtracking(graph, num_vertices, i, count, cost, min_cost, path, best_path, start_index, visited, minc);
                visited[i] = false;
                count--;
                cost -= graph[current_pos][i];
            }
        }
    }
}

string Traveling(int graph[20][20], int num_vertices, char start_vertex)
{
    int start_index = start_vertex - 'A';
    if (start_index >= num_vertices)
        return "";
    bool visited[20] = {false};
    visited[start_index] = true;
    int min_cost = INF;
    int path[20];
    int best_path[20];
    path[0] = start_index;
    int minc = INF;

    for (int i = 0; i < num_vertices; i++){
        for(int j = 0; j < num_vertices; j++){
            if(graph[i][j] < minc)
                minc = graph[i][j];
        }
    }


    Backtracking(graph, num_vertices, start_index, 1, 0, min_cost, path, best_path, start_index, visited, minc);

    string result = "";

    for (int i = 0; i < num_vertices; i++)
    {
        result = result + static_cast<char>(best_path[i] + 'A') + " ";
    }
    result += start_vertex;

    return result;
}
