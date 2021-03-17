// Martin Vickgren, Samson Tesfalem

#ifndef LAB4_GRAPHS_GRAPH_H
#define LAB4_GRAPHS_GRAPH_H

#include "../list/list.h"

typedef struct graph_t {
    int **edge;
    int size;
} Graph;

typedef struct pathTable_t {
    int *shortest;
    int *previous;
    int size;
} PathTable;

int isInRange(int size, int index);

PathTable *createPathTable(int n);

Graph *createGraph(int n);

int getNumVertices(Graph *graph);

int getNumEdges(Graph *graph);

List *getNeighbors(Graph *graph, int v);

List *getInNeighbors(Graph *graph, int v);

List *getOutNeighbors(Graph *graph, int v);

void addDirectedEdge(Graph *graph, int v1, int v2);

void addUndirectedEdge(Graph *graph, int v1, int v2);

int hasEdgeDirected(Graph *graph, int from, int to);

int hasEdgeUndirected(Graph *graph, int v1, int v2);

void setWeight(Graph *graph, int v1, int v2, int weight);

void relax(Graph *graph, PathTable *pathTable, int u, int v);

void initializeSingleSource(PathTable *pathTable, int s);

int shortestPath(Graph *graph, PathTable *pathTable, int s);

#endif //LAB4_GRAPHS_GRAPH_H
