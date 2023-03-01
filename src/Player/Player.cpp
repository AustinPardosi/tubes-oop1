// File: Player.cpp
// Berisi implementasi dari kelas Player

#include "Player.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Player::Player() : currentPoin(0), alreadyPlayed(false), abilityUsed(false), abilityless(false) {}

// still not done
Player::Player(const Player& other) : currentPoin(other.currentPoin), alreadyPlayed(other.alreadyPlayed), abilityUsed(other.abilityUsed), abilityless(other.abilityless) {
    this->listOfCard = other.listOfCard;
}

// still not done
Player::~Player() {
    delete this->action;
    delete this->ability;
}

// still not done
Player Player::operator=(const Player& other) {
    delete this->action;
    delete this->ability;

    this->action = other.action;
    this->ability = other.ability;
    this->currentPoin = other.currentPoin;
    this->alreadyPlayed = other.alreadyPlayed;
    this->abilityUsed = other.abilityUsed;
    this->abilityless = other.abilityless;

    return *this;
}

/*--------------------------------------------------------------------*/
/*---------------------GETTER AND SETTER SEGMENT----------------------*/

bool Player::getAlreadyPlayed() const {
    return this->alreadyPlayed;
}

void Player::setAlreadyPlayed(bool alreadyPlayer) {
    this->alreadyPlayed = alreadyPlayed;
}

bool Player::getAbilityUsed() const {
    return this->abilityUsed;
}

void Player::setAbilityUsed(bool abilityUsed) {
    this->abilityUsed = abilityUsed;
}

bool Player::getAbilityless() const {
    return this->abilityless;
}

void Player::setAbilityless(bool abilityless) {
    this->abilityless = abilityless;
}

/*--------------------------------------------------------------------*/
/*------------------------ADDING CARDS SEGMENT------------------------*/
        
void Player::addCards(const InventoryHolder& other) {
    *this = *this + other.getCard(0);
    *this = *this + other.getCard(1);
}

Player Player::operator+(const Card& other) {
    Player temp(*this);
    temp.listOfCard.push_back(other);
    return Player(temp);
}

/*--------------------------------------------------------------------*/
/*-----------------------REMOVING CARDS SEGMENT-----------------------*/

void Player::removeCards(int cardsRemoved) {
    *this = *this - cardsRemoved;
}

Player Player::operator-(int cardsRemoved) {
    Player temp(*this);
    temp.listOfCard.erase(temp.listOfCard.begin()+cardsRemoved);
    return Player(temp);
}

/*--------------------------------------------------------------------*/
/*---------------------POINT MANAGEMENT SEGMENT-----------------------*/
Player Player::operator+(int poinHadiah) {
    Player temp(*this);
    temp.currentPoin += poinHadiah;
    return Player(temp);
}