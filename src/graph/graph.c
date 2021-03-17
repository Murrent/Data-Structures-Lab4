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
 * The amount of edges
 * @param graph
 * @return int of edges amount
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
 * Returns a list of all vertices associated with v with an edge.
 * @param graph
 * @param v
 * @return
 */
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
/**
 * Returns a list to all vertices with an edge pointing to v.
 * @param graph
 * @param v
 * @return
 */
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
/**
 * Returns a list to all vertices with an edge pointing from v.
 * @param graph
 * @param v
 * @return
 */
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
/**
 * Adds an edge from v1 to v2 and sets it's weight to 1.
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
 * Adds 2 directed edges:
 * v1 -> v2.
 * v2 -> v1.
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
 * @param from
 * @param to
 * @return 1 if theres an edge in the graph between "from" and "to", else it returns 0.
 */
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
/**
 *
 * @param graph
 * @param v1
 * @param v2
 * @return 1 if theres an edge in the graph between v1 - v2 and v2 - v1, else it returns 0.
 */
int hasEdgeUndirected(Graph *graph, int v1, int v2) {
    v1--;
    v2--;
    if (graph != NULL &&
        isInRange(graph->size, v1) &&
        isInRange(graph->size, v2) &&
        graph->edge[v1][v2] != 0 &&
        graph->edge[v2][v1] != 0)
        return 1;
    return 0;
}
/**
 * Sets a "weight" at the edge between "from" and "to".
 * @param graph
 * @param from
 * @param to
 * @param weight
 */
void setWeight(Graph *graph, int from, int to, int weight) {
    if (!hasEdgeDirected(graph, from, to)) return;
    from--; to--;
    graph->edge[from][to] = weight;
}
/**
 * Relax algorithm to set value at v in the PathTable.
 * @param graph
 * @param pathTable data table
 * @param u source
 * @param v destination
 */
void relax(Graph *graph, PathTable *pathTable, int u, int v) {
    if (graph == NULL || pathTable == NULL) return;
    if (pathTable->shortest[v] > pathTable->shortest[u] + graph->edge[u][v]) {
        pathTable->shortest[v] = pathTable->shortest[u] + graph->edge[u][v];
        pathTable->previous[v] = u + 1;
    }
}
/**
 * Sets all default values of PathTable.
 * Shortest = infinity for all vertices != s - 1.
 * Previous is set to -1 for all vertices.
 * @param pathTable data table
 * @param s source vertex
 */
void initializeSingleSource(PathTable *pathTable, int s) {
    if (pathTable == NULL) return;
    for (int i = 0; i < pathTable->size; ++i) {
        pathTable->shortest[i] = 99999;
        pathTable->previous[i] = -1;
    }
    pathTable->shortest[s - 1] = 0;
}
/**
 * Calculates the shortest path from s to every other node using Bellman-Ford algorithm.
 * @param graph
 * @param pathTable data table
 * @param s source vertex
 * @return 0 if negative weight cycles exists, 1 if no negative weight cycles exists.
 */
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
