#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// gotten from https://favtutor.com/blogs/split-string-cpp
// splits a string into a vector of strings with a delimeter
vector<string> split(string str, char separator) {
    // specifies the start and end of the string
    int startIndex = 0, endIndex = 0;
    // the vector of strings
    vector<string> strings;
    // loops through the entire string adding each delimeted string to the vector
    for (int i = 0; i <= str.size(); i++) {
        
        // if a seperator is found or it's the end of the string
        if (str[i] == separator || i == str.size()) {
            // set the end index to current i
            endIndex = i;
            // create a temp string
            string temp;
            // append the values from str to the temp string
            temp.append(str, startIndex, endIndex - startIndex);
            // add the temp string to the vector
            strings.push_back(temp);
            // creates a new start index
            startIndex = endIndex + 1;
        }
    }
    // returns the list of strings
    return strings;
}



vector<vector<vector<int>>> readFile() {
    cout << "Please enter a file: ";
    string fileName;
    cin >> fileName;
    // string fileName = "matrix.txt";
    ifstream file(fileName);

    string line;
    getline(file, line);
    int n = stoi(line);
    getline(file, line);
    vector<vector<vector<int>>> matrices;

    vector<vector<int>> newMatrix;
    for (int row = 0; row < n; row++) {
        vector<int> newRow;
        getline(file, line);
        vector<string> nums = split(line, ' ');
        for (int col = 0; col < n; col++) {
            newRow.push_back(stoi(nums.at(col)));
        }
        newMatrix.push_back(newRow);
    }
    matrices.push_back(newMatrix);

    vector<vector<int>> newerMatrix;
    for (int row = 0; row < n; row++) {
        vector<int> newRow;
        getline(file, line);
        vector<string> nums = split(line, ' ');
        for (int col = 0; col < n; col++) {
            newRow.push_back(stoi(nums.at(col)));
        }
        newerMatrix.push_back(newRow);
    }

    file.close();
    return matrices;
}

void printMatrix(vector<vector<int>> matrix) {
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix.size(); col++) {
            // adds an extra 0 to the word if needed
            if (matrix.at(row).at(col) <= 9) cout << 0;
            cout << matrix.at(row).at(col) << " ";
        }
        cout << "\n";
    }
}

void addMatrices(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    vector<vector<int>> sumMatrix;

    for (int row = 0; row < matrix1.size(); row++) {
        vector<int> newRow;
        for (int col = 0; col < matrix1.size(); col++) {
            newRow.push_back(matrix1.at(row).at(col) + matrix2.at(row).at(col));
        }
        sumMatrix.push_back(newRow);
    }
    printMatrix(sumMatrix);
}

void diagonalSum(vector<vector<int>> matrix1) {
    int sum1 = 0;
    for (int i = 0; i < matrix1.size(); i++) {
        sum1 += matrix1.at(i).at(i);
    }
    cout << "Main Diagonal Sum: " << sum1 << endl;

    int sum2 = 0;
    for (int i = 0; i < matrix1.size(); i++) {
        sum2 += matrix1.at(i).at(matrix1.size() - 1 - i);
    }
    cout << "Secondary Diagonal Sum: " << sum2 << endl;

    cout << "Sum of Diagonal Sums: " << sum1 + sum2 << endl;
}

void swapRows(vector<vector<int>> matrix, int index1, int index2) {
    vector<int> oldRow = matrix.at(index1);
    matrix.at(index1) = matrix.at(index2);
    matrix.at(index2) = oldRow;

    printMatrix(matrix);
}

void swapColumns(vector<vector<int>> matrix, int index1, int index2) {
    vector<int> oldRow;
    for (int row = 0; row < matrix.size(); row++) {
        oldRow.push_back(matrix.at(row).at(index1));
        matrix.at(row).at(index1) = matrix.at(row).at(index2);
    }

    for (int row = 0; row < matrix.size(); row++) {
        matrix.at(row).at(index2) = oldRow.at(row);
    }

    printMatrix(matrix);
}

void changeValue(vector<vector<int>> matrix, int row, int col, int value) {

    matrix.at(row).at(col) = value;
    printMatrix(matrix);
}

int main() {

    vector<vector<vector<int>>> matrices;
    matrices = readFile();
    vector<vector<int>> matrix1 = matrices.at(0);
    vector<vector<int>> matrix2 = matrices.at(0);

    printMatrix(matrix1);
    cout << endl;
    printMatrix(matrix2);
    cout << endl;

    cout << "1. Add two matrices and display the result" << endl;
    cout << "2. Multiply two matrices and display the result" << endl;
    cout << "3. Get the sum of matrix diagonal elements" << endl;
    cout << "4. Swap matrix rows and display the result" << endl;
    cout << "5. Swap matrix columns and display the result" << endl;
    cout << "6. Update matrix rows and display the result" << endl;
    cout << "Choose option: ";
    string choice;
    cin >> choice;

    switch(stoi(choice)) {
        case 1:
            addMatrices(matrix1, matrix2);
            break;
        case 2:
            cout << "not implemented yet :P" << endl;
            break;
        case 3:
            diagonalSum(matrix1);
            break;
        case 4:
            cout << "Please enter matrix index 1: ";
            int rowIndex1;
            cin >> rowIndex1;
            cout << "Please enter matrix index 2: ";
            int rowIndex2;
            cin >> rowIndex2;
            if (rowIndex1 < matrix1.size() && rowIndex1 >= 0 && rowIndex2 < matrix1.size() && rowIndex2 >= 0) swapRows(matrix1, rowIndex1, rowIndex2);
            else cout << "Please enter valid indeces." << endl;
            break;
        case 5:
            cout << "Please enter matrix index 1: ";
            int colIndex1;
            cin >> colIndex1;
            cout << "Please enter matrix index 2: ";
            int colIndex2;
            cin >> colIndex2;
            if (colIndex1 < matrix1.size() && colIndex1 >= 0 && colIndex2 < matrix1.size() && colIndex2 >= 0) swapColumns(matrix1, colIndex1, colIndex2);
            else cout << "Please enter valid indeces." << endl;
            break;
        case 6:
            cout << "Please enter row: ";
            int row;
            cin >> row;
            cout << "Please enter column: ";
            int col;
            cin >> col;
            cout << "Please enter value: ";
            int value;
            cin >> value;
            if (row < matrix1.size() && row >= 0 && col < matrix1.size() && col >= 0) changeValue(matrix1, row, col, value);
            else cout << "Please enter valid indeces." << endl;
            break;
        default:
            cout << "Please select a different number." << endl;
    }



    return 0;
}
