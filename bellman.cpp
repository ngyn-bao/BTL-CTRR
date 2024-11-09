#include "bellman.h"

int count1 = 0, count2 = 0;

void BF(int graph[][20], int num_vertices, char start_vertex, int BFValue[], int BFPrev[])
{
    const int INF = 1000000;
    int copyValue[20];
    int copyPrev[20];
    int start_index = start_vertex - 'A';
    if (count1 == 0)
    {
        for (int i = 0; i < num_vertices; i++)
        {
            if (i != start_index)
            {
                if (graph[start_index][i] != 0)
                {
                    BFValue[i] = graph[start_index][i];
                    BFPrev[i] = start_index;
                }
            }
            else
            {
                BFValue[i] = 0;
                BFPrev[i] = -1;
            }
        }
        count1++;
        return;
    }
    for (int i = 0; i < num_vertices; i++)
    {
        if (BFValue[i] == -1 && BFPrev[i] == -1)
        {
            BFValue[i] = INF;
        }
    }

    for (int i = 0; i < num_vertices; i++)
    {
        copyValue[i] = BFValue[i];
        copyPrev[i] = BFPrev[i];
    }

    for (int u = 0; u < num_vertices; u++)
    {
        for (int v = 0; v < num_vertices; v++)
        {
            if (((BFValue[u] + graph[u][v]) < copyValue[v]) && graph[u][v] != 0)
            {
                copyValue[v] = BFValue[u] + graph[u][v];
                copyPrev[v] = u;
            }
        }
    }

    for (int i = 0; i < num_vertices; i++)
    {
        BFValue[i] = copyValue[i];
        BFPrev[i] = copyPrev[i];
    }
    count1++;
    if (count1 == num_vertices && count2 < 9)
    {
        count1 = 0;
        count2++;
    }
}


string BF_Path(int graph[20][20], int num_vertices, char start_vertex, char goal_vertex)
{
    int BFValue[20], BFPrev[20];
    int start_index = start_vertex - 'A';
    int goal_index = goal_vertex - 'A';
    const int INF = 999999999;
    // Initialization Step
    for (int i = 0; i < num_vertices; ++i)
    {
        BFValue[i] = INF;
        BFPrev[i] = -1;
    }

    BFValue[start_index] = 0;

    // Iteration Step
    for (int i = 0; i < num_vertices - 1; ++i)
    {
       BF(graph, num_vertices, start_vertex, BFValue, BFPrev);
    }

    // Check circuit of negative weight
    /*    for (int u = 0; u < num_vertices; u++)
        {
            for (int v = 0; v < num_vertices; v++)
            {
                if (BFValue[u] + graph[u][v] < BFValue[v])
                    cerr << "Contains circuit of negative weight";
                return "";
            }
        }
    */
    int path[20], current_index = goal_index, path_length = 0;

    while (current_index != start_index)
    {
        path[path_length++] = current_index;
        current_index = BFPrev[current_index];
    }
    path[path_length++] = start_index;

    string outpath = "";
    for (int i = path_length - 1; i > 0; --i)
    {
        outpath += 'A' + path[i];
        outpath += ' ';
    }
    outpath += 'A' + path[0];

    return outpath;
}