#include "card.h"
#include <stdexcept>

// Kaardi konstruktor
Card::Card(char newSuit, int newValue)
{

    if (newValue > 13 || newValue < 1)
    {
        throw std::invalid_argument("Card value can't be less than 1 or greater than 13");
    }

    if (newSuit != 'c' || newSuit != 'd' || newSuit != 'h' || newSuit != 's')
    {
        suit = newSuit;
        value = newValue;
    }
    else
    {
        throw std::invalid_argument("Unknown card suit");
    }
}

Card::~Card()
{
}

ostream &operator<<(ostream &out, const Card &c)
{
    if (c.value == 1 || c.value > 10)
    {
        switch (c.value)
        {
        case 1:
            out << "Ace of ";
            break;
        case 11:
            out << "Jack of ";
            break;
        case 12:
            out << "Queen of ";
            break;
        case 13:
            out << "King of ";
            break;
        }
    }
    if (c.suit == 'c')
    {
        out << "Clubs";
    }
    if (c.suit == 'd')
    {
        out << "Diamonds";
    }
    if (c.suit == 'h')
    {
        out << "Hearts";
    }
    if (c.suit == 's')
    {
        out << "Spades";
    }

    if (c.value != 1 && c.value <= 10)
    {
        out << " " << c.value;
    }

    return out;
}

// Kui pilt ja väärtus on samad, siis on kaardid võrdsed
bool operator==(const Card &c1, const Card &c2)
{
    if (c1.suit == c2.suit && c1.value == c2.value)
    {
        return true;
    }
    else
    {
        return false;
    }
}
