#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
#define INF 9999

struct Graph {
    int nodes;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
};

int minKey(int key[], bool mstSet[], int nodes) {
    int min = INF, minIndex;
	int v;
    for (v = 0; v < nodes; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void prim(struct Graph *graph) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    bool mstSet[MAX_NODES];
	int i;
    for (i = 0; i < graph->nodes; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
	int count;
    for (count = 0; count < graph->nodes - 1; count++) {
        int u = minKey(key, mstSet, graph->nodes);
        mstSet[u] = true;
		int v;
        for (v = 0; v < graph->nodes; v++) {
            if (graph->adjacencyMatrix[u][v] && !mstSet[v] && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

        printf("Edge \tWeight\n");
    for (i = 1; i < graph->nodes; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph->adjacencyMatrix[i][parent[i]]);
    }
}

int main() {
    struct Graph graph = {
        .nodes = 5,
        .adjacencyMatrix = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        }
    };

    prim(&graph);

    return 0;
}
