#include "hand.h"
#include "card.h"

Hand::~Hand()
{
}

void Hand::addCard(Card card)
{
    cardsInHand.push_back(card);
    switch (card.value)
    {
    // Äss on nii 1 kui ka 10
    case 1:
        max += 10;
        min += 1;
        break;
    case 11:
        max += 10;
        min += 10;
        break;
    case 12:
        max += 10;
        min += 10;
        break;
    case 13:
        max += 10;
        min += 10;
        break;
    default:
        max += card.value;
        min += card.value;
        break;
    }
}
