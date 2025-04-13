// Player.h
#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"

class Player {
public:
    Player(const std::string& name);

    void receiveCard(const Card& card);
    void showHand() const;
    void clearHand();

    std::string getName() const;

    void discardAndDraw(Deck& deck);

    const std::vector<Card>& getHand() const;


private:
    std::string name;
    std::vector<Card> hand;
};