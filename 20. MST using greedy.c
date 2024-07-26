#include <stdio.h>
#include <stdlib.h>

// A structure to represent a weighted edge in the graph
typedef struct {
    int src, dest, weight;
} Edge;

// A structure to represent a connected, undirected and weighted graph
typedef struct {
    int V, E;
    Edge* edges;
} Graph;

// A structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Function to create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(graph->E * sizeof(Edge));
    return graph;
}

// A utility function to find the set of an element i (uses path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights
int compareEdges(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

// Function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    int e = 0;  // Index variable for result[]
    int i = 0;  // Index variable for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for creating V subsets
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
        Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does not cause a cycle, include it in result
        // and increment the index of result for next edge
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);

    // Free allocated memory
    free(subsets);
}

int main() {
    /* Example graph:
           10
       0--------1
       |  \     |
      6|   5\   |15
       |      \ |
       2--------3
           4       */

    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    Graph* graph = createGraph(V, E);

    // Add edges 0-1, 0-2, 0-3, 1-3, 2-3
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    KruskalMST(graph);

    // Free allocated memory
    free(graph->edges);
    free(graph);

    return 0;
}
