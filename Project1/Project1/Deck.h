// Deck.h
#pragma once
#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    void shuffle();
    Card deal();
    bool isEmpty() const;

private:
    std::vector<Card> cards;
    int currentIndex;
};
