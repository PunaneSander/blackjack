#ifndef DECK_H
#define DECK_H
#include <vector>
#include "card.h"

// Kaardipaki klass
class Deck
{
public:
    std::vector<Card> deck;
    Deck();

    void shuffleDeck();
    ~Deck();
    Card removeCard(Card card);
    Card takeCard();

private:
    void addCard(Card card);
};
#endif