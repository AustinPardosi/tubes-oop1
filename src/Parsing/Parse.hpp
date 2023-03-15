// File: Parse.hpp
// Berisi deklarasi dari kelas Parse

#ifndef __PARSE_H
#define __PARSE_H

#include <fstream>
#include <vector>
#include <utility>
#include <sstream>

#include "../ExceptionHandling/BaseException.hpp"
#include "../ExceptionHandling/InvalidFileException.hpp"
#include "../ExceptionHandling/CardFileException.hpp"

class Parse {
    private:
        vector<pair<int,int>> cards;
        int totalLine;
        bool safe;

    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        Parse();

        /*--------------------------------------------------------------------*/
        /*---------------------GETTER AND SETTER SEGMENT----------------------*/

        // get the vector of cards code
        vector<pair<int,int>> getCards() const;

        // get the total line parsed
        int getTotalLine() const;

        // get the validity of parsing
        bool getSafe() const;

        /*--------------------------------------------------------------------*/
        /*--------------------------PARSING SEGMENT---------------------------*/
        
        // do the parsing of file
        void parsing(string);
};

#endif