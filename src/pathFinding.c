#include <stdio.h>
#include "graph/graph.h"

int main() {
    Graph *graph = createGraph(5);
    addDirectedEdge(graph, 1, 5);
    addDirectedEdge(graph, 1, 3);
    addUndirectedEdge(graph, 3, 4);
    addDirectedEdge(graph, 4, 2);
    addDirectedEdge(graph, 3, 5);
    setWeight(graph, 1, 3, 3);

    PathTable *pathTable = createPathTable(graph->size);

    printf("bellman %d\n", shortestPath(graph, pathTable, 1));

    for (int i = 0; i < pathTable->size; ++i) {
        printf("bellman shortest 1 to %d: short %d - prev %d\n", i + 1, pathTable->shortest[i], pathTable->previous[i]);
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
