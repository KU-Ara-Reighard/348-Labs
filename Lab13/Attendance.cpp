/**
 * 1) There is a fault, in fail_lecture, the for loop starts at i=1, which skips the first value i=0 of the vector.
 * 2) Executes the faulty code without it affecting the program or causing internal issues
 * 3) Executes the faulty code which causes the number of absences to go up an incorrect amount, but it has no external effect.
 * 4) Executes the faulty code, causing an incorrect number of absences, which produce incorrect output.
 */


#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool fail_lecture(const vector<int> &attendancerecords) {
    int absentcount = 0;
    for (int i = 1; i < attendancerecords.size(); ++i) {
        absentcount += attendancerecords[i] == 0;
    }
    return absentcount >= 3;
}

bool correct_fail_lecture(const vector<int> &attendancerecords) {
    int absentcount = 0;
    for (int i = 0; i < attendancerecords.size(); ++i) {
        absentcount += attendancerecords[i] == 0;
    }
    return absentcount >= 3;
}

void print_vector(vector<int> records) {
    cout << "Test Values: " << records.at(0);
    for (int i = 1; i < records.size(); ++i) {
        cout << ", " << records.at(i);
    }
    cout << endl;
}

int main() {
    
    vector<int> records1 = {1,1,1,1,1,1,1,1,0,0};
    vector<int> records2 = {1,1,1,1,1,1,0,0,0,0};
    vector<int> records3 = {0,1,1,1,1,1,1,0,0,0};
    vector<int> records4 = {0,1,1,1,1,1,1,1,0,0};

    cout << endl;
    print_vector(records1);
    cout << "2) Expected output: " << correct_fail_lecture(records1) << "\n   Actual Output: " << fail_lecture(records1) << "\n" << endl;
    print_vector(records2);   
    cout << "3) Expected output: " << correct_fail_lecture(records2) << "\n   Actual Output: " << fail_lecture(records2) << "\n" << endl;
    print_vector(records3);   
    cout << "4) Expected output: " << correct_fail_lecture(records3) << "\n   Actual Output: " << fail_lecture(records3) << "\n" << endl;
    print_vector(records4);   
    cout << "5) Expected output: " << correct_fail_lecture(records4) << "\n   Actual Output: " << fail_lecture(records4) << "\n" << endl;
    
    // cout << fail_lecture(records2) << endl;
    // cout << fail_lecture(records3) << endl;
}