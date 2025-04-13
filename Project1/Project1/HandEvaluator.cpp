#include <algorithm>
#include "HandEvaluator.h"
#include "Card.h"
#include <unordered_map>

PokerHandRank HandEvaluator::evaluate(const std::vector<Card>& hand) {
    std::unordered_map<int, int> rankCount;
    std::unordered_map<int, int> suitCount;

    std::vector<int> ranks;
    for (const Card& card : hand) {
        int r = static_cast<int>(card.getRank());
        rankCount[r]++;
        suitCount[card.getSuit()]++;
        ranks.push_back(r);
    }

    std::sort(ranks.begin(), ranks.end());

    // 스트레이트 체크
    bool isStraight = true;
    for (int i = 1; i < 5; ++i) {
        if (ranks[i] != ranks[i - 1] + 1) {
            isStraight = false;
            break;
        }
    }

    // 특수 케이스: A-2-3-4-5 스트레이트 (A = 14)
    if (!isStraight && ranks == std::vector<int>{2, 3, 4, 5, 14}) {
        isStraight = true;
    }

    // 플러시 체크
    bool isFlush = false;
    for (const auto& suit : suitCount) {
        if (suit.second == 5) {
            isFlush = true;
            break;
        }
    }

    // 스트레이트 플러시 / 로얄 플러시
    if (isStraight && isFlush) {
        if (ranks[0] == 10) return PokerHandRank::RoyalFlush;
        return PokerHandRank::StraightFlush;
    }

    // 4카드 / 풀하우스 / 트리플 / 투페어 / 원페어
    std::vector<int> countValues;
    for (const auto& pair : rankCount) {
        countValues.push_back(pair.second);
    }

    std::sort(countValues.begin(), countValues.end(), std::greater<>());

    if (countValues[0] == 4) return PokerHandRank::FourOfAKind;
    if (countValues[0] == 3 && countValues[1] == 2) return PokerHandRank::FullHouse;
    if (isFlush) return PokerHandRank::Flush;
    if (isStraight) return PokerHandRank::Straight;
    if (countValues[0] == 3) return PokerHandRank::ThreeOfAKind;
    if (countValues[0] == 2 && countValues[1] == 2) return PokerHandRank::TwoPair;
    if (countValues[0] == 2) return PokerHandRank::OnePair;

    return PokerHandRank::HighCard;
}

int HandEvaluator::getHighCardValue(const std::vector<Card>& hand) {
    int maxRank = 0;
    for (const Card& card : hand) {
        // Rank를 정수로 변환하여 비교
        int rankValue = static_cast<int>(card.getRank()); // 🔽 중요한 부분
        maxRank = std::max(maxRank, rankValue);
    }
    return maxRank;
}

std::string HandEvaluator::rankToString(PokerHandRank rank) {
    switch (rank) {
    case PokerHandRank::HighCard: return "High Card";
    case PokerHandRank::OnePair: return "One Pair";
    case PokerHandRank::TwoPair: return "Two Pair";
    case PokerHandRank::ThreeOfAKind: return "Three of a Kind";
    case PokerHandRank::Straight: return "Straight";
    case PokerHandRank::Flush: return "Flush";
    case PokerHandRank::FullHouse: return "Full House";
    case PokerHandRank::FourOfAKind: return "Four of a Kind";
    case PokerHandRank::StraightFlush: return "Straight Flush";
    case PokerHandRank::RoyalFlush: return "Royal Flush";
    default: return "Unknown Rank";
    }
}
