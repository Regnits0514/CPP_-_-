// Deck.cpp
#include "Deck.h"
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck() {
    for (int s = 0; s < 4; ++s) {
        for (int r = 2; r <= 14; ++r) {
            cards.emplace_back(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s));
        }
    }
    currentIndex = 0;
}

void Deck::shuffle() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::random_shuffle(cards.begin(), cards.end());
    currentIndex = 0;
}

Card Deck::deal() {
    if (currentIndex < cards.size()) {
        return cards[currentIndex++];
    }
    else {
        throw std::out_of_range("No more cards in the deck!");
    }
}

bool Deck::isEmpty() const {
    return currentIndex >= cards.size();
}
