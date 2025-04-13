// Player.cpp
#include <sstream>
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <limits>  // std::numeric_limits

Player::Player(const std::string& name) : name(name) {}

void Player::receiveCard(const Card& card) {
    hand.push_back(card);
}

void Player::showHand() const {
    std::cout << name << "의 카드: ";
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << "[" << i + 1 << "]" << hand[i].toString() << " ";
    }
    std::cout << "\n\n";
}


void Player::clearHand() {
    hand.clear();
}

std::string Player::getName() const {
    return name;
}

void Player::discardAndDraw(Deck& deck) {
    std::vector<int> indicesToDiscard;
    std::string line;
    int index;

    while (true) {
        std::cout << name << ", 버릴 카드 번호를 입력하세요 (1~5, 띄어쓰기 구분, 없으면 엔터):\n";
        showHand();

        indicesToDiscard.clear();
        std::getline(std::cin, line);
        std::istringstream iss(line);

        bool valid = true;
        while (iss >> index) {
            if (index < 1 || index > 5) {
                std::cout << "⚠️ 1부터 5 사이 숫자만 입력하세요.\n";
                valid = false;
                break;
            }
            indicesToDiscard.push_back(index - 1); // 내부 처리는 0부터
        }

        if (valid) break; // 정상 입력이면 루프 탈출
    }

    // 큰 인덱스부터 삭제
    std::sort(indicesToDiscard.begin(), indicesToDiscard.end(), std::greater<>());
    for (int i : indicesToDiscard) {
        hand.erase(hand.begin() + i);
    }

    while (hand.size() < 5 && !deck.isEmpty()) {
        Card newCard = deck.deal();
        std::cout << "\n" << name << " 새 카드: " << newCard.toString() << std::endl;
        hand.push_back(newCard);
    }

    showHand();
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}
