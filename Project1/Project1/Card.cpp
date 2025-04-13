// Card.cpp
#include "Card.h"

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

Card::Rank Card::getRank() const { return rank; }
Card::Suit Card::getSuit() const { return suit; }

std::string Card::toString() const {
    static const char* RANKS[] = {
        "", "", "2", "3", "4", "5", "6", "7", "8",
        "9", "10", "J", "Q", "K", "A"
    };
    static const char* SUITS[] = { "H", "D", "C", "S" };

    return std::string(RANKS[rank]) + SUITS[suit];
}
