#include "Parse.hpp"

Parse::Parse(){
    string fileName = "card.txt";
    string line;
    this->totalLine = 0;
    this->safe = true;

    // Checking if the file can be opened
    ifstream inputFile(fileName);
    if(!inputFile.is_open()) {
        throw new InvalidFileException;
        this->safe = false;
    }

    // Read card from txt file
    while (getline(inputFile, line)) {
        this->totalLine++;

        // Validate every line must have 2 values
        istringstream iss(line):
        if(!(iss >> this->cardNumber >> this->cardColor) || (iss >> this->cardColor)) {
            throw new CardFileException(0);
            this->safe = false;
        }

        // Validate value of cardNumber and cardColor
        // 1 <= cardNumber <= 13 dan 0 <= cardColor <= 3
        if (this->cardNumber < 1 || this->cardValue > 13 || this->cardColor < 0 || this->cardColor > 3) {
            throw new CardFileException(1);
            this->safe = false;
        }

        this->validateCards.push_back(make_pair(this->cardNumber, this->cardColor));
    }

    // Validate totalLine must be 52
    if (this->totalLine != 52) {
        throw new CardFileException(2);
        this->safe = false;
    }
    
    // Validate every card unique
    if (this->safe) {
        for(int i=0; i<this->validateCards.size(); i++) {
            for(int j=i+1; j<this->validateCards.size(); j++) {
                if(this->validateCards[i] == this->validateCards[j]) {
                    throw new CardFileException(3);
                    this->safe = false;
                }
            }
        }
    }

    // Insert into cards
    if (this->safe) {
        for(const auto& i : this->validateCards) {
            this->cards.emplace_back(i);
        }
    }

    inputFile.close()
}

vector<int,int> Parse::getAllCards() {
    return this->cards;
}