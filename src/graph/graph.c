//
// Created by Martin on 2021-03-07.
//

#include "graph.h"
#include <stdlib.h>

int isInRange(int size, int index) {
    if (index < size && index >= 0) return 1;
    return 0;
}

PathTable *createPathTable(int n) {
    if (n == 0) return NULL;
    PathTable *pathTable = (PathTable *) malloc(sizeof(PathTable));
    pathTable->shortest = (int *) malloc(n * sizeof(int));
    pathTable->previous = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        pathTable->shortest[i] = 0;
        pathTable->previous[i] = 0;
    }
    pathTable->size = n;
    return pathTable;
}

Graph *createGraph(int n) {
    if (n == 0) return NULL;
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->size = n;
    graph->edge = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        graph->edge[i] = (int *) malloc(n * sizeof(int));

        for (int j = 0; j < n; ++j) {
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

List *getNeighbors(Graph *graph, int v) {
    v--;
    if (graph == NULL || !isInRange(graph->size, v)) return NULL;
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

List *getInNeighbors(Graph *graph, int v) {
    v--;
    if (graph == NULL || !isInRange(graph->size, v)) return NULL;
    List *list = createList();
    for (int i = 0; i < graph->size; ++i) {
        if (graph->edge[i][v] != 0) {
            Node *node = createNode(i + 1);
            insert(list, node);
        }
    }
    return list;
}

List *getOutNeighbors(Graph *graph, int v) {
    v--;
    if (graph == NULL || !isInRange(graph->size, v)) return NULL;
    List *list = createList();
    for (int i = 0; i < graph->size; ++i) {
        if (graph->edge[v][i] != 0) {
            Node *node = createNode(i + 1);
            insert(list, node);
        }
    }
    return list;
}

void addDirectedEdge(Graph *graph, int v1, int v2) {
    if (!graph) return;
    v1--;
    v2--;
    if (!isInRange(graph->size, v1) || !isInRange(graph->size, v2)) return;
    graph->edge[v1][v2] = 1;
}

void addUndirectedEdge(Graph *graph, int v1, int v2) {
    addDirectedEdge(graph, v1, v2);
    addDirectedEdge(graph, v2, v1);
}

int hasEdgeDirected(Graph *graph, int from, int to) {
    from--;
    to--;
    if (graph != NULL &&
        isInRange(graph->size, from) &&
        isInRange(graph->size, to) &&
        graph->edge[from][to] != 0)
        return 1;
    return 0;
}

int hasEdgeUndirected(Graph *graph, int v1, int v2) {
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

void setWeight(Graph *graph, int from, int to, int weight) {
    if (!hasEdgeDirected(graph, from, to)) return;
    from--; to--;
    graph->edge[from][to] = weight;
}

void relax(Graph *graph, PathTable *pathTable, int u, int v) {
    if (graph == NULL || pathTable == NULL) return;
    if (pathTable->shortest[v] > pathTable->shortest[u] + graph->edge[u][v]) {
        pathTable->shortest[v] = pathTable->shortest[u] + graph->edge[u][v];
        pathTable->previous[v] = u + 1;
    }
}

void initializeSingleSource(PathTable *pathTable, int s) {
    if (pathTable == NULL) return;
    for (int i = 0; i < pathTable->size; ++i) {
        pathTable->shortest[i] = 99999;
        pathTable->previous[i] = -1;
    }
    pathTable->shortest[s - 1] = 0;
}

int shortestPath(Graph *graph, PathTable *pathTable, int s) {
    if (graph == NULL || pathTable == NULL) return 0;
    initializeSingleSource(pathTable, s);
    int length = getNumVertices(graph);
    for (int i = 1; i < length - 1; ++i) {
        for (int x = 0; x < length; ++x) {
            for (int y = 0; y < length; ++y) {
                if (graph->edge[x][y] != 0)
                    relax(graph, pathTable, x, y);
            }
        }
    }
    for (int x = 0; x < length; ++x) {
        for (int y = 0; y < length; ++y) {
            if (graph->edge[x][y] != 0) {
                if (pathTable->shortest[y] > pathTable->shortest[x] + graph->edge[x][y])
                    return 0;
            }
        }
    }
    return 1;
}
