#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Structure to hold 4 coordinates (x1, y1, x2, y2)
struct CoordinateSet {
    double x1, y1, x2, y2;
};

int main() {
    // Open the CSV file (you will need to adjust the path)
    std::ifstream inputFile("/Users/priyavadhanam/placements/c++coding/CareAreas.csv");

    // Check if the file is opened successfully
    if (!inputFile) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    std::vector<CoordinateSet> coordinates;  // Vector to store coordinate sets
    std::string line;

    // Read the file line by line
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);  // Stream the line
        std::string field;
        CoordinateSet coordSet;  // Temporary variable to hold the set of coordinates

        // Skip the first field (index value)
        std::getline(ss, field, ',');  // Read until the comma separator (skip the index)

        // Extract the x1, y1, x2, and y2 values
        std::getline(ss, field, ',');
        coordSet.x1 = std::stod(field);  // Convert to double for x1
          // coordSet.x1 = std::stof(field);  Convert to float for y2
        std::getline(ss, field, ',');
        coordSet.y1 = std::stod(field);  // Convert to double for y1
        std::getline(ss, field, ',');
        coordSet.x2 = std::stod(field);  // Convert to double for x2
        std::getline(ss, field, ',');
        coordSet.y2 = std::stod(field);  // Convert to double for y2
      
        // Store the coordinate set
        coordinates.push_back(coordSet);
    }

    // Close the input file
    inputFile.close();

    // Output the coordinates stored in the vector
    for (int i = 0; i < coordinates.size(); ++i) {
        const CoordinateSet& coordSet = coordinates[i];
        std::cout << "x1: " << coordSet.x1 << ", y1: " << coordSet.y1
                  << ", x2: " << coordSet.x2 << ", y2: " << coordSet.y2 << std::endl;
    }

    return 0;
}
