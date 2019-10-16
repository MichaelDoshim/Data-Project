#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <sstream>
#include "project.h"

using namespace std;
void Project::readFile() {
    ifstream inFile;
    string fileName, tmp;
    vector<string> word;
    cout << "Enter the stocks file name: ";
    cin >> fileName;
    inFile.open(fileName);
    while(getline(inFile, tmp)) {
        // Converting all the strings to upper case
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
        // Removes the ',' in the instructions
        tmp.erase(remove(tmp.begin(), 
            tmp.end(), ','), tmp.end());
        // Adds all the strings into the vector
        word.push_back(tmp);
    }
    for(int i = 0; i < word.size();i++) {
        cout << word[i] << endl;
    }
    inFile.close();
}

int main(int argc, char * argv[]) {
    Project p1;
    p1.readFile();
}