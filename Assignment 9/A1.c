#include <stdio.h>
#include <limits.h>
#define V 10
int bfs(int rGraph[V][V], int s, int t, int parent[])
{
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;
    while (front < rear)
    {
        int u = queue[front++];
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return visited[t];
}
int fordFulkerson(int graph[V][V], int source, int sink)
{
    int rGraph[V][V];
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    int parent[V];
    int maxFlow = 0;
    while (bfs(rGraph, source, sink, parent))
    {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            if (rGraph[u][v] < pathFlow)
                pathFlow = rGraph[u][v];
        }
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}
void main()
{
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 10, 12, 0, 0, 0, 0, 0, 0},
        {0, 4, 0, 0, 14, 0, 0, 0, 0, 0},
        {0, 0, 9, 0, 0, 20, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 4, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 10, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 15},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 10},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int source = 0;
    int sink = 9;
    int maxFlow = fordFulkerson(graph, source, sink);
    printf("Maximum Flow = %d\n", maxFlow);
}