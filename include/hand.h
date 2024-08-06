#ifndef HAND_H
#define HAND_H
#include <vector>
#include "card.h"

// 'Käe' klass, ehk mängija käes olevad kaardid, sarnane kaardipakile - deck'ile
class Hand
{
public:
    std::vector<Card> cardsInHand;
    int max = 0;
    int min = 0;
    Hand() = default;

    ~Hand();
    void addCard(Card card);
};

#endif