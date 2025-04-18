팀 구성원
서윤찬 (20240945)

이 게임은 플레이어가 카드를 주고받으며, 
각 플레이어가 최종 손패를 평가하여 승패를 결정하는 방식으로 진행됨 
게임은 2명부터 4명까지 지원

주요 기능
    카드 덱 생성 및 셔플: Deck 클래스에서 카드 덱을 관리하고, 카드를 셔플

    플레이어 클래스: Player 클래스를 사용하여 각 플레이어의 손패를 관리하며, 카드 받기, 버리기 등의 기능을 제공

    핸드 평가: HandEvaluator 클래스에서 각 플레이어의 손패를 평가하고, 족보에 따른 승패를 결정

    다양한 족보 및 비교: 핸드를 평가하여 One Pair, High Card 등의 다양한 족보를 지원


파일 구조

Deck.h           - 카드 덱 관리 클래스 정의

Deck.cpp         - 카드 덱 관리 클래스 구현

HandEvaluator.h  - 핸드 평가 클래스 정의

HandEvaluator.cpp - 핸드 평가 클래스 구현

Player.h         - 플레이어 클래스 정의

Player.cpp       - 플레이어 클래스 구현

PokerHandRank.h  - 족보 종류 정의

PokerHandRank.cpp - 족보 종류 구현

main.cpp         - 게임 실행 코드

클래스 설명

Deck
    역할: 카드 덱을 관리하는 클래스. 카드의 셔플 및 카드 뽑기(deal) 기능을 제공

    주요 함수:

        shuffle(): 덱 섞기

        deal(): 덱에서 한 장의 카드를 뽑기

        isEmpty(): 덱에 카드가 남아있는지 확인

Card
    역할: 카드 객체를 관리하는 클래스. 카드의 랭크(숫자/문자)와 슈트(♠, ♥, ♣, ♦) 정보를 제공

    주요 함수:

        toString(): 카드 정보를 문자열로 반환

Player
    역할: 플레이어 클래스. 각 플레이어의 이름, 손패, 카드 버리기 및 교환 기능을 제공

    주요 함수:

        receiveCard(): 카드를 한 장 받기

        showHand(): 플레이어의 손패를 출력하기

        discardAndDraw(): 플레이어가 카드를 버리고 새 카드를 받기

HandEvaluator

    역할: 플레이어의 손패를 평가하여 족보를 결정

    주요 함수:

        evaluate(): 손패의 족보를 평가하여 반환

        getHighCardValue(): 최고 카드를 반환

PokerHandRank

    역할: 포커 게임에서 사용되는 족보를 정의하는 열거형

        HighCard, OnePair, TwoPair, ThreeOfAKind, FourOfAKind, 등

게임 흐름

    게임 시작: 카드 덱을 셔플하고, 각 플레이어에게 5장의 카드가 주어짐

    카드 버리기 및 교환: 플레이어는 자신의 손패를 보고 카드를 버릴 번호를 선택

    손패 평가: 모든 플레이어의 손패가 완성되면, 핸드 평가가 이루어지고 족보에 따라 승자가 결정

    결과 출력: 게임 결과가 출력

플레이 전 필요사항

    솔루션 탐색기에서 프로젝트 우클릭 → 속성(Properties)

    왼쪽 트리에서: C/C++ → 언어(Language)

    C++ 언어 표준 → C++17 (/std:c++17) 또는 그 이상으로 설정

    확인 → 다시 빌드
