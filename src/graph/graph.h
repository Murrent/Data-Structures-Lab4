//
// Created by Martin on 2021-03-07.
//

#ifndef LAB4_GRAPHS_GRAPH_H
#define LAB4_GRAPHS_GRAPH_H

#include "../list/list.h"

typedef struct graph_ {
    int** vert;
    int** edge;
    int size;
} Graph;

Graph *createGraph(int n);

int getNumVertices(Graph *graph);

int getNumEdges(Graph *graph);

List *getNeighbors(Graph *graph, int v);

List *getInNeighbors(Graph *graph, int v);

List *getOutNeighbors(Graph *graph, int v);

void addDirectedEdge(Graph *graph, int v1, int v2);

void addUndirectedEdge(Graph *graph, int v1, int v2);

void hasEdge(Graph *graph, int v1, int v2);

#endif //LAB4_GRAPHS_GRAPH_H
