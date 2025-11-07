#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

using namespace std;


// utilized code from https://favtutor.com/blogs/split-string-cpp, comments are my own
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


string add(string num1, string num2) {
    
    return "none";
}


int main() {
    cout << "Enter a file: ";
    string fileName;
    cin >> fileName;
    ifstream file(fileName);

    string line;
    string expressions[30][2];

    for (int i = 0; i < 30; i++) {
        getline(file, line);
        vector<string> nums = split(line, ' ');
        // cout << i << ": " << nums.at(0) << ", " << nums.at(1) << endl;

        regex r(R"((^(\+|\-)?\d+(\.\d+)?\s(\+|\-)?\d+(\.\d+)?))");
        smatch m;
        if (regex_search(line, m, r)) {
            cout << i + 1 << ": " << add(nums.at(0), nums.at(1)) << endl;
        }
        else cout << "Equation contains invalid numbers." << endl;

        // using https://stackoverflow.com/questions/30921932/understanding-c-regex-by-a-simple-example
        // for(auto v: m) cout << i << ": " << v << endl;

        string sum = add(nums.at(0), nums.at(1));

    }



    return 0;
}