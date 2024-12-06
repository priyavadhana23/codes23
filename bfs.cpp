#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

// Structure to represent a care area
struct CareArea {
    double x_min, y_min, x_max, y_max;
};

// Check if two care areas are adjacent or overlapping
bool isAdjacentOrOverlapping(const CareArea &a, const CareArea &b) {
    // Care areas are adjacent if their boundaries touch or overlap
    return !(a.x_max < b.x_min || a.x_min > b.x_max || 
             a.y_max < b.y_min || a.y_min > b.y_max);
}

int main()
 {
    // List of care areas
    std::vector<CareArea> careAreas = {
        {6040.444017, 6150.444017, 6765.762124, 6875.762124}, // Example care area
        {6766.0, 6876.0, 7400.0, 7500.0},                    // Another example
        {5000.0, 5000.0, 5500.0, 5600.0}                     // Add more as needed
    };

    int n = careAreas.size();
    std::vector<std::vector<int>> adjList(n); // Adjacency list for the graph

    // Build adjacency list
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isAdjacentOrOverlapping(careAreas[i], careAreas[j])) {
                adjList[i].push_back(j);
                adjList[j].push_back(i); // Undirected graph
            }
        }
    }

    // BFS traversal
    std::vector<bool> visited(n, false); // To track visited care areas
    std::queue<int> q;

    // Start BFS from the first care area
    q.push(0);
    visited[0] = true;

    std::cout << "BFS Traversal of Care Areas:\n";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Process current care area
        std::cout << "Visiting Care Area " << current << ": "
                  << "{" << careAreas[current].x_min << ", " 
                  << careAreas[current].y_min << ", " 
                  << careAreas[current].x_max << ", " 
                  << careAreas[current].y_max << "}\n";

        // Visit all adjacent care areas
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return 0;
}
