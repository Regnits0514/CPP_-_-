#pragma once
#include "Card.h"
#include "PokerHandRank.h"
#include <vector>
#include <map>

class HandEvaluator {
public:
    static PokerHandRank evaluate(const std::vector<Card>& hand);
    static int getHighCardValue(const std::vector<Card>& hand);
    static std::string rankToString(PokerHandRank rank);
};

