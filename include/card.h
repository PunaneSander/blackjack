#ifndef CARD_H
#define CARD_H

#include <iostream>
using std::ostream;

// Kaardi klass
class Card
{
public:
    // suit: c-Clubs  d-Diamonds  h-Hearts  s-Spades
    // value: 1 = Ace, 2-10 = normal, 11 = Jack, 12 = Queen, 13 = King, 0 = empty
    char suit = 'c';
    int value = 1;
    Card() = default;
    Card(char newSuit, int newValue);
    ~Card();
};

ostream &operator<<(ostream &out, const Card &c);
// Võrdlemisoperaator
bool operator==(const Card &c1, const Card &c2);

#endif