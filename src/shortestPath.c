#include <stdio.h>
#include "graph/graph.h"

int main() {
    Graph *graph = createGraph(3);
    addUndirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 1);
    setWeight(graph, 2, 1, 3);
    setWeight(graph, 1, 2, 2);
    setWeight(graph, 3, 1, 1);
    setWeight(graph, 2, 3, 1);

    List *neighbors = getNeighbors(graph, 2);
    printf("neighbors 2:\n");
    if (neighbors) {
        for (Node *tmp = neighbors->head; tmp; tmp = tmp->next) {
            printf("%d\n", tmp->key);
        }
    }
    List *neighborsIn = getInNeighbors(graph, 3);
    printf("neighborsIn 3:\n");
    if (neighborsIn) {
        for (Node *tmp = neighborsIn->head; tmp; tmp = tmp->next) {
            printf("%d\n", tmp->key);
        }
    }
    List *neighborsOut = getOutNeighbors(graph, 1);
    printf("neighborsOut 1:\n");
    if (neighborsOut) {
        for (Node *tmp = neighborsOut->head; tmp; tmp = tmp->next) {
            printf("%d\n", tmp->key);
        }
    }

    PathTable *pathTable = createPathTable(graph->size);

    printf("bellman %d\n", shortestPath(graph, pathTable, 2));

    for (int i = 0; i < pathTable->size; ++i) {
        printf("bellman shortest 2 to %d: shortest: %d - previous: %d\n",
               i + 1, pathTable->shortest[i], pathTable->previous[i]);
    }

    printf("edges\n");
    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->size; ++j) {

            printf("%d", graph->edge[i][j]);
        }
        printf("\n");
    }
    return 0;
}
