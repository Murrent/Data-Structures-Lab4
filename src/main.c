#include <stdio.h>
#include "graph/graph.h"

int main() {
    Graph *graph = createGraph(10);
    addUndirectedEdge(graph, 2, 5);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 2, 4);
    addDirectedEdge(graph, 4, 3);
    addDirectedEdge(graph, 3, 8);
    printf("%d\n", hasEdgeUndirected(graph, 2, 5));
    printf("%d\n", hasEdgeDirected(graph, 5, 2));
    printf("%d\n", hasEdgeDirected(graph, 5, 1));
    printf("%d\n", getNumVertices(graph));
    printf("%d\n", getNumEdges(graph));
    List *list = getNeighbors(graph, 2);
    if (list) {
        for (Node *tmp = list->head; tmp; tmp = tmp->next) {
            printf("4 - %d\n", tmp->key);
        }
    }

    printf("edges\n");
    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->size; ++j) {

            printf("%d", graph->edge[i][j]);
        }
        printf("\n");
    }
    printf("Hello, World!\n");
    return 0;
}
