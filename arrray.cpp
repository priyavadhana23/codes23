#include<iostream>
using namespace std;

int main()
{
    int array[10];
    for(int i=1;i<10;i++)
    {
        cout << " enter the number";
        cin >> array[i];
    }
    for(int i=1;i<10;i++)
    {
        cout << array[i];
    }
     // 2d array

     int rows = 2, cols = 3;  // Define the number of rows and columns
    int matrix[2][3];        // Declare a 2D array (2 rows and 3 columns)

    // Input: Ask the user to enter values for the 2D array
    cout << "Enter 6 integers for a 2x3 matrix:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];  // Store each element in the matrix
        }
    }

    // Output: Display the 2D array (matrix)
    cout << "You entered:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";  // Print each element
        }
        cout << endl;  // Move to the next row
    }

}
