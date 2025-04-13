#pragma once
#include <string>

class Card {
public:
    enum Suit { Hearts, Diamonds, Clubs, Spades };
    enum Rank {
        Two = 2, Three, Four, Five, Six, Seven, Eight,
        Nine, Ten, Jack, Queen, King, Ace
    };

    Card(Rank r, Suit s);
    std::string toString() const;

    Rank getRank() const;
    Suit getSuit() const;

private:
    Rank rank;
    Suit suit;
};