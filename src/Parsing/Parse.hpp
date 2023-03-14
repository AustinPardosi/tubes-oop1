#ifndef __PARSE_H
#define __PARSE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

#include "../ExceptionHandling/BaseException.hpp"
#include "../ExceptionHandling/InvalidFileException.hpp"
#include "../ExceptionHandling/CardFileException.hpp"

using namespace std;

class Parse {
    private:
        vector<pair<int,int>> cards;
        int totalLine;
        bool safe;

    public:
        // Constructor
        Parse();

        // Getter and setter section
        vector<pair<int,int>> getCards() const;
        int getTotalLine() const;
        bool getSafe() const;

        // Main method
        void parsing(string);
};

#endif