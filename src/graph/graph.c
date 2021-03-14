//
// Created by Martin on 2021-03-07.
//

#include "graph.h"
#include <stdlib.h>

/**
 *
 * @param size
 * @param index
 * @return
 */
int isInRange(int size, int index) {
    if (index < size && index >= 0) return 1;
    return 0;
}

/**
 *
 * @param n
 * @return
 */
Graph *createGraph(int n) {
    if (n == 0) return NULL;
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->size = n;
    graph->edge = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        graph->edge[i] = (int *) malloc(n * sizeof(int));

        for (int j = 0; j < n; ++j)
            graph->edge[i][j] = 0;
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
    v--;
    if (graph == NULL && !isInRange(graph->size, v)) return NULL;
    List *list = createList();
    for (int i = 0; i < graph->size; ++i) {
        if (graph->edge[v][i] != 0) {
            Node *node = createNode(i + 1);
            insert(list, node);
        }
        if (graph->edge[i][v] != 0) {
            Node *node = createNode(i + 1);
            insert(list, node);
        }
    }
    return list;
}

/**
 *
 * @param graph
 * @param v
 * @return
 */
List *getInNeighbors(Graph *graph, int v) {
    v--;
    if (graph == NULL && !isInRange(graph->size, v)) return NULL;
    List *list = createList();
    for (int i = 0; i < graph->size; ++i) {
        if (graph->edge[i][v] != 0) {
            Node *node = createNode(i + 1);
            insert(list, node);
        }
    }
    return list;
}

/**
 *
 * @param graph
 * @param v
 * @return
 */
List *getOutNeighbors(Graph *graph, int v) {
    v--;
    if (graph == NULL && !isInRange(graph->size, v)) return NULL;
    List *list = createList();
    for (int i = 0; i < graph->size; ++i) {
        if (graph->edge[v][i] != 0) {
            Node *node = createNode(i + 1);
            insert(list, node);
        }
    }
    return list;
}

/**
 *
 * @param graph
 * @param v1
 * @param v2
 */
void addDirectedEdge(Graph *graph, int v1, int v2) {
    if (!graph) return;
    v1--;
    v2--;
    if (!isInRange(graph->size, v1) || !isInRange(graph->size, v2)) return;
    graph->edge[v1][v2] = 1;
}

/**
 *
 * @param graph
 * @param v1
 * @param v2
 */
void addUndirectedEdge(Graph *graph, int v1, int v2) {
    addDirectedEdge(graph, v1, v2);
    addDirectedEdge(graph, v2, v1);
}

/**
 *
 * @param graph
 * @param v1
 * @param v2
 */
int hasEdge(Graph *graph, int v1, int v2) {
    v1--;
    v2--;
    if (graph != NULL &&
        isInRange(graph->size, v1) &&
        isInRange(graph->size, v2) &&
        graph->edge[v1][v2] != 0 ||
        graph->edge[v2][v1] != 0)
        return 1;
    return 0;
}
