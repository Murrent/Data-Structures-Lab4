#include <stdio.h>
#include "graph/graph.h"

/**
 * Testing the implemented graph functions.
 * @return
 */
int main() {
    Graph *graph = createGraph(5);
    addDirectedEdge(graph, 1, 5);
    addUndirectedEdge(graph, 1, 3);
    addUndirectedEdge(graph, 3, 4);
    addDirectedEdge(graph, 4, 2);
    addDirectedEdge(graph, 3, 5);

    printf("hasEdgeUndirected 1 - 5: %d\n", hasEdgeUndirected(graph, 1, 3));
    printf("hasEdgeUndirected 2 - 5: %d\n", hasEdgeUndirected(graph, 2, 3));
    printf("hasEdgeDirected 2 - 5: %d\n", hasEdgeDirected(graph, 2, 5));
    printf("hasEdgeDirected 5 - 1: %d\n", hasEdgeDirected(graph, 5, 1));
    printf("hasEdgeDirected 1 - 5: %d\n", hasEdgeDirected(graph, 1, 5));
    printf("total vertices: %d\n", getNumVertices(graph));
    printf("total edges: %d\n", getNumEdges(graph));

    List *neighbors = getNeighbors(graph, 1);
    printf("neighbors:\n");
    if (neighbors) {
        for (Node *tmp = neighbors->head; tmp; tmp = tmp->next) {
            printf("1 - %d\n", tmp->key);
        }
    }
    List *neighborsIn = getInNeighbors(graph, 1);
    printf("neighborsIn:\n");
    if (neighborsIn) {
        for (Node *tmp = neighborsIn->head; tmp; tmp = tmp->next) {
            printf("1 - %d\n", tmp->key);
        }
    }
    List *neighborsOut = getOutNeighbors(graph, 1);
    printf("neighborsOut:\n");
    if (neighborsOut) {
        for (Node *tmp = neighborsOut->head; tmp; tmp = tmp->next) {
            printf("1 - %d\n", tmp->key);
        }
    }

    printf("edges:\n");
    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->size; ++j) {

            printf("%d", graph->edge[i][j]);
        }
        printf("\n");
    }
    return 0;
}
