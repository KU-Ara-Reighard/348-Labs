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
    bool subtraction = false;
    bool subtractionSign = false;

    // block to handle subtraction and addition and the signs
    if (num1[0] == '-' && num2[0] == '-') {
        subtractionSign = true;
        num1.erase(0,1);
        num2.erase(0,1);
    }

    if (num2[0] == '+') {
        // cout << 1 << endl;
        num2.erase(0,1);
    }
    else if (num2[0] == '-') {
        // cout << 2 << endl;
        subtraction = !subtraction;
        num2.erase(0,1);
    }

    if (num1[0] == '+') {
        // cout << 3 << endl;
        num1.erase(0,1);
    }
    else if (num1[0] == '-') {
        // cout << 4 << endl;
        num1.erase(0,1);
        string tempString = num2;
        num2 = num1;
        num1 = tempString;
        subtraction = !subtraction;
    }
    
    // block to split them by decimal
    vector<string> num1Split = split(num1, '.');
    vector<string> num2Split = split(num2, '.');
    string num1Characteristic = num1Split.at(0);
    string num1Mantissa = (num1Split.size() == 2) ? num1Split.at(0) : "0";
    string num2Characteristic = num2Split.at(0);
    string num2Mantissa = (num2Split.size() == 2) ? num2Split.at(0) : "0";

    
    // block to make them all the same size
    // while (num1Characteristic.size() < num2Characteristic.size()) {
    //     num1Characteristic = "0" + num1Characteristic;
    //     // cout << num1Characteristic << endl;
    // }
    // while (num1Characteristic.size() > num2Characteristic.size()) {
    //     num2Characteristic = "0" + num2Characteristic;
    //     // cout << num2Characteristic << endl;
    // }
    while (num1Mantissa.size() < num2Mantissa.size()) {
        num1Mantissa = "0" + num1Mantissa;
        // cout << num1Characteristic << endl;
    }
    while (num1Mantissa.size() > num2Mantissa.size()) {
        num2Mantissa = "0" + num2Mantissa;
        // cout << num2Characteristic << endl;
    }

    // cout << "num1Char: " << num1Characteristic << endl;
    // cout << "num2Char: " << num2Characteristic << endl;
    // cout << "num1Man: " << num1Mantissa << endl;
    // cout << "num2Man: " << num2Mantissa << endl;
    // cout << num1Characteristic + '.' + num1Mantissa << endl;
    // cout << num2Characteristic + '.' + num2Mantissa << endl;

    int mantissaLength = num1Mantissa.size();

    string mantissaSum = "help";
    string characteristicSum = "help2";

    if (!subtraction) {
        mantissaSum = to_string(stoi(num1Mantissa) + stoi(num2Mantissa));
        characteristicSum = to_string(stoi(num1Characteristic) + stoi(num2Characteristic));

        if (mantissaSum.size() > mantissaLength) {
            characteristicSum = to_string(stoi(characteristicSum) + 1);
            mantissaSum.erase(0,1);
        }
    }

    else {
        mantissaSum = to_string(stoi(num1Mantissa) - stoi(num2Mantissa));
        characteristicSum = to_string(stoi(num1Characteristic) - stoi(num2Characteristic));

        bool mantissaNegative = (mantissaSum[0] == '-') ? true : false;
        if (mantissaNegative) mantissaSum.erase(0,1);

        if (mantissaNegative) {
            if (mantissaSum.size() > mantissaLength) {
                characteristicSum = to_string(stoi(characteristicSum) - 2);
                mantissaSum.erase(0,1);
            }
            else {
                characteristicSum = to_string(stoi(characteristicSum) - 1);
                mantissaSum = to_string(1 - stoi(mantissaSum));
            }
        }
    }

    if (subtractionSign) characteristicSum = ('-' + characteristicSum);

    return characteristicSum + '.' + mantissaSum;
}

string recAdd(string num1, string num2) {
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
            // cout << ":O " << i << endl;
            cout << i + 1 << ": " << add(nums.at(0), nums.at(1)) << endl;
            // add(nums.at(0), nums.at(1));
        }
        else {
            cout << "Equation contains invalid numbers." << endl;
        }

        // using https://stackoverflow.com/questions/30921932/understanding-c-regex-by-a-simple-example
        // for(auto v: m) cout << i << ": " << v << endl;

        // string summation = add(nums.at(0), nums.at(1));

    }



    return 0;
}