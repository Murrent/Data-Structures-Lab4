#include <stdio.h>
#include "graph/graph.h"

void attachAround(Graph* graph, int v) {
    v--;
    if (!graph) return;
    if (isInRange(v+1, graph->size))
        addUndirectedEdge(graph, v, v+1);
    if (isInRange(v+10, graph->size))
        addUndirectedEdge(graph, v, v+10);
    printf("%d\n", v);
}

int main() {
    Graph *graph = createGraph(100);

    for (int i = 0; i < graph->size; ++i) {
        attachAround(graph, i);
    }


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
