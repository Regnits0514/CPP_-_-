#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "Deck.h"
#include "Player.h"
#include "HandEvaluator.h"
#include "PokerHandRank.h"

int main() {
    Deck deck;
    deck.shuffle();

    int playerCount = 0;
    while (playerCount < 2 || playerCount > 4) {
        std::cout << "플레이어 수를 입력하세요 (2~4명): ";
        std::cin >> playerCount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<Player> players;
    for (int i = 0; i < playerCount; ++i) {
        std::string name;
        std::cout << "플레이어 " << (i + 1) << "의 이름을 입력하세요: ";
        std::getline(std::cin, name);
        players.emplace_back(name);
    }

    // 카드 배분
    for (int i = 0; i < 5; ++i) {
        for (Player& player : players) {
            player.receiveCard(deck.deal());
        }
    }

    std::cout << "\n플레이어들의 손패:\n";
    for (const Player& player : players) {
        player.showHand();
    }

    std::cout << "\n엔터를 입력하여 플레이어의 패 버리기로 넘어가시오...\n";
    std::cin.ignore();

    for (Player& player : players) {
        player.discardAndDraw(deck);
    }

    std::vector<std::pair<Player*, PokerHandRank>> results;
    for (Player& player : players) {
        auto rank = HandEvaluator::evaluate(player.getHand());
        results.emplace_back(&player, rank);
    }

    auto winner = std::max_element(results.begin(), results.end(),
        [](const auto& a, const auto& b) {
            return static_cast<int>(a.second) < static_cast<int>(b.second);
        });

    std::vector<Player*> tiedPlayers;
    for (auto& [player, rank] : results) {
        if (rank == winner->second) {
            tiedPlayers.push_back(player);
        }
    }

    std::cout << "\n--- 결과 ---\n";
    for (auto& [player, rank] : results) {
        std::cout << player->getName() << ": " << HandEvaluator::rankToString(rank) << "\n";
    }

    if (tiedPlayers.size() == 1) {
        std::cout << tiedPlayers[0]->getName() << " 승리!\n";
    }
    else {
        // 하이 카드 비교
        int bestHigh = 0;
        std::vector<Player*> highCardWinners;
        for (auto* p : tiedPlayers) {
            int high = HandEvaluator::getHighCardValue(p->getHand());
            if (high > bestHigh) {
                bestHigh = high;
                highCardWinners = { p };
            }
            else if (high == bestHigh) {
                highCardWinners.push_back(p);
            }
        }

        if (highCardWinners.size() == 1) {
            std::cout << highCardWinners[0]->getName() << " 승리!\n";
        }
        else {
            std::cout << "무승부입니다! 승자: ";
            for (auto* p : highCardWinners) std::cout << p->getName() << " ";
            std::cout << "\n";
        }
    }

    return 0;
}
