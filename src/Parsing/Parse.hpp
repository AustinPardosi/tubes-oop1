#ifndef __PARSE_H
#define __PARSE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

#include "../ExceptionHandling/InvalidFileException.hpp"
#include "../ExceptionHandling/CardFileException.hpp"

using namespace std;

class Parse {
private:
    vector<int,int> validateCards;
    vector<int,int> cards;
    int totalLine;
    int cardNumber;
    int cardColor;
    bool safe;

public:
    Parse();
    vector<int,int> getAllCards();
};

#endif