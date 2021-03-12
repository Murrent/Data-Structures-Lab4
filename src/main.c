#include <stdio.h>
#include "graph/graph.h"

int main() {
    Graph* graph = createGraph(10);

    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->size; ++j) {

            printf("%d", graph->vert[i][j]);
        }
        printf("\n");
    }
    printf("Hello, World!\n");
    return 0;
}
