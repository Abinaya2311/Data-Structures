#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Graph {
    int nodes;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
};

bool visited[MAX_NODES];

void bfs(struct Graph *graph, int startNode) {
    int queue[MAX_NODES];
    int front = -1;
    int rear = -1;

    visited[startNode] = true;
    queue[++rear] = startNode;

    while (front != rear) {
        int currentNode = queue[++front];
        printf("%d ", currentNode);
		int i;
        for (i = 0; i < graph->nodes; i++) {
            if (!visited[i] && graph->adjacencyMatrix[currentNode][i] == 1) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    struct Graph graph = {
        .nodes = 5,
        .adjacencyMatrix = {
            {0, 1, 1, 0, 0},
            {1, 0, 0, 1, 1},
            {1, 0, 0, 0, 1},
            {0, 1, 0, 0, 0},
            {0, 1, 1, 0, 0}
        }
    };
	int i;
    for (i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
    }

    printf("BFS traversal: ");
    bfs(&graph, 0);
    printf("\n");

    return 0;
}

