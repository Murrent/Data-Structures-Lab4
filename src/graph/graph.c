//
// Created by Martin on 2021-03-07.
//

#include "graph.h"
#include <stdlib.h>

Graph *createGraph(int n) {
    if (n == 0) return NULL;
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->size = n;
    graph->vert = (int**)malloc(n * sizeof(int*));
    graph->edge = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        graph->vert[i] = (int*)malloc(n * sizeof(int));
        graph->edge[i] = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; ++j) {
            graph->vert[i][j] = 0;
            graph->edge[i][j] = 0;
        }
    }
    return graph;
}

int getNumVertices(Graph *graph) {
    if (!graph) return 0;
    return graph->size;
}

int getNumEdges(Graph *graph) {

}

List *getNeighbors(Graph *graph, int v) {

}

List *getInNeighbors(Graph *graph, int v) {

}

List *getOutNeighbors(Graph *graph, int v) {

}

void addDirectedEdge(Graph *graph, int v1, int v2) {

}

void addUndirectedEdge(Graph *graph, int v1, int v2) {

}

void hasEdge(Graph *graph, int v1, int v2) {

}
