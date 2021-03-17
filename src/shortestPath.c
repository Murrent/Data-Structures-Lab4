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
