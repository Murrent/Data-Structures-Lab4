//
// Created by Martin on 2021-03-07.
//

#include "graph.h"
#include <stdlib.h>

/**
 *
 * @param n
 * @return
 */
Graph *createGraph(int n) {
    if (n == 0) return NULL;
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->size = n;
    graph->vert = (int **) malloc(n * sizeof(int *));
    graph->edge = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        graph->vert[i] = (int *) malloc(n * sizeof(int));
        graph->edge[i] = (int *) malloc(n * sizeof(int));

        for (int j = 0; j < n; ++j) {
            graph->vert[i][j] = 0;
            graph->edge[i][j] = 0;
        }
    }
    return graph;
}

/**
 *
 * @param graph
 * @return
 */
int getNumVertices(Graph *graph) {
    if (!graph) return 0;
    return graph->size;
}

/**
 *
 * @param graph
 * @return
 */
int getNumEdges(Graph *graph) {
    if (!graph) return 0;
    int size = 0;
    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->size; ++j) {
            if (graph->edge[i][j] != 0)
                size++;
        }
    }
    return size;
}

/**
 *
 * @param graph
 * @param v
 * @return
 */
List *getNeighbors(Graph *graph, int v) {

}

/**
 *
 * @param graph
 * @param v
 * @return
 */
List *getInNeighbors(Graph *graph, int v) {

}

/**
 *
 * @param graph
 * @param v
 * @return
 */
List *getOutNeighbors(Graph *graph, int v) {

}

/**
 *
 * @param graph
 * @param v1
 * @param v2
 */
void addDirectedEdge(Graph *graph, int v1, int v2) {

}

/**
 *
 * @param graph
 * @param v1
 * @param v2
 */
void addUndirectedEdge(Graph *graph, int v1, int v2) {

}

/**
 *
 * @param graph
 * @param v1
 * @param v2
 */
void hasEdge(Graph *graph, int v1, int v2) {

}
