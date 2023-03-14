#include "Parse.hpp" 
#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabek
    Parse p1;
    string inputfile;
    bool checkdone = false;

    // Proses validating
    while(!checkdone) {
        cout << "Input the file name" << endl;
        cin >> inputfile;
        ifstream inputFile(inputfile);
        try {
            if(!inputFile.is_open()) {
                throw new InvalidFileException;
            }
            checkdone = true;
        } catch (BaseException *e) {
            e->printMessage();
        }
    }

    p1.parsing(inputfile);
    vector<int,int> result = p1.getCards();
    for(const auto &i : result) {
        cout << i.first << " " << i.second << endl;
    }
}