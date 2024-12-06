#include <iostream>
#include <vector>

int main() {
    int vertices = 5; // Number of vertices
    std::vector<std::vector<int>> adjList(vertices); // Adjacency list

    // Add edges for a directed graph
    adjList[0].push_back(1); // Edge 0 -> 1
    adjList[0].push_back(4); // Edge 0 -> 4
    adjList[1].push_back(2); // Edge 1 -> 2
    adjList[1].push_back(3); // Edge 1 -> 3
    adjList[3].push_back(4); // Edge 3 -> 4

    // Print adjacency list
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Node " << i << ": ";
        for (int neighbor : adjList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
