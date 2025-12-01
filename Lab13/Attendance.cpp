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

class Matrix {

    private:
        vector<vector<int>> matrix;
    public:
        

        Matrix(vector<vector<int>> newGrid) {
            matrix = newGrid;
        }

        void printMatrix() {
            for (int row = 0; row < this->matrix.size(); row++) {
                for (int col = 0; col < this->matrix.size(); col++) {
                    // adds an extra 0 to the word if needed
                    if (this->matrix.at(row).at(col) <= 9) cout << 0;
                    cout << this->matrix.at(row).at(col) << " ";
                }
                cout << "\n";
            }
        }

        int size() {
            return matrix.size();
        }

        vector<vector<int>> getMatrix() {
            return this->matrix;
        }

        void operator+(Matrix other) {
            vector<vector<int>> sumMatrix;
    
            for (int row = 0; row < this->matrix.size(); row++) {
                vector<int> newRow;
                for (int col = 0; col < matrix.size(); col++) {
                    newRow.push_back(matrix.at(row).at(col) + other.getMatrix().at(row).at(col));
                }
                sumMatrix.push_back(newRow);
            }
            Matrix newMatrix(sumMatrix);
            newMatrix.printMatrix();
        }

        void operator*(Matrix other) {
            vector<vector<int>> productMatrix;
            
            for (int row = 0; row < matrix.size(); row++) {
                vector<int> newRow;
                for (int col = 0; col < matrix.size(); col++) {
                    int product = 0;
                    for (int i = 0; i < matrix.size(); i++) {
                        product += matrix.at(i).at(col) * other.getMatrix().at(row).at(i); 
                    }
                    newRow.push_back(product);
                }
                productMatrix.push_back(newRow);
            }
            
            Matrix newMatrix(productMatrix);
            newMatrix.printMatrix();
        }

        void diagonalSum() {
            int sum1 = 0;
            for (int i = 0; i < matrix.size(); i++) {
                sum1 += matrix.at(i).at(i);
            }
            cout << "Main Diagonal Sum: " << sum1 << endl;
            
            int sum2 = 0;
            for (int i = 0; i < matrix.size(); i++) {
                sum2 += matrix.at(i).at(matrix.size() - 1 - i);
            }
            cout << "Secondary Diagonal Sum: " << sum2 << endl;
            
            cout << "Sum of Diagonal Sums: " << sum1 + sum2 << endl;
        }

        void swapRows(int index1, int index2) {
            vector<int> oldRow = matrix.at(index1);
            matrix.at(index1) = matrix.at(index2);
            matrix.at(index2) = oldRow;
            
            printMatrix();
        }

        void swapColumns(int index1, int index2) {
            vector<int> oldRow;
            for (int row = 0; row < matrix.size(); row++) {
                oldRow.push_back(matrix.at(row).at(index1));
                matrix.at(row).at(index1) = matrix.at(row).at(index2);
            }
            
            for (int row = 0; row < matrix.size(); row++) {
                matrix.at(row).at(index2) = oldRow.at(row);
            }
            
            printMatrix();
        }

        void changeValue(int row, int col, int value) {
            
            matrix.at(row).at(col) = value;
            printMatrix();
        }
};










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
    matrices.push_back(newerMatrix);

    file.close();
    return matrices;
}

int main() {

    vector<vector<vector<int>>> matrices;
    matrices = readFile();
    Matrix matrix(matrices.at(0));
    Matrix other(matrices.at(1));

    matrix.printMatrix();
    cout << endl;
    other.printMatrix();
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
            matrix + other;
            break;
        case 2:
            matrix * other;
            break;
        case 3:
            matrix.diagonalSum();
            break;
        case 4:
            cout << "Please enter matrix index 1: ";
            int rowIndex1;
            cin >> rowIndex1;
            cout << "Please enter matrix index 2: ";
            int rowIndex2;
            cin >> rowIndex2;
            if (rowIndex1 < matrix.size() && rowIndex1 >= 0 && rowIndex2 < matrix.size() && rowIndex2 >= 0) matrix.swapRows(rowIndex1, rowIndex2);
            else cout << "Please enter valid indeces." << endl;
            break;
        case 5:
            cout << "Please enter matrix index 1: ";
            int colIndex1;
            cin >> colIndex1;
            cout << "Please enter matrix index 2: ";
            int colIndex2;
            cin >> colIndex2;
            if (colIndex1 < matrix.size() && colIndex1 >= 0 && colIndex2 < matrix.size() && colIndex2 >= 0) matrix.swapColumns(colIndex1, colIndex2);
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
            if (row < matrix.size() && row >= 0 && col < matrix.size() && col >= 0) matrix.changeValue(row, col, value);
            else cout << "Please enter valid indeces." << endl;
            break;
        default:
            cout << "Please select a different number." << endl;
    }



    return 0;
}
