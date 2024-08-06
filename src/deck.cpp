#include "deck.h"
#include "card.h"

#include <algorithm>
#include <random>

// Kaardipakki kaardi lisamise funktsioon
void Deck::addCard(Card card)
{
    deck.push_back(card);
}

// Konstruktor, loob 52 standard kaardipaki
Deck::Deck()
{

    std::vector<Card> deck;

    char suits[4] = {'c', 'd', 'h', 's'};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            addCard(Card(suits[i], j));
        }
    }
}

// Kaardipaki segamine
void Deck::shuffleDeck()
{
    for (int i = 0; i < 5; i++)
    {
        std::random_device rd;
        std::shuffle(deck.begin(), deck.end(), rd);
    }

    /**
    auto rd = std::random_device;
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(deck), std::end(deck), rng);
    */
}

// Kaardipakist eemaldamine
Card Deck::removeCard(Card card)
{

    if (std::find(deck.begin(), deck.end(), card) != deck.end())
    {
        // Erase-remove idiom
        deck.erase(std::remove(deck.begin(), deck.end(), card), deck.end());
        return card;
    }
    else
    {
        return Card('c', 0);
    }

    return card;
}

// Kaardipaki pealt võtmise funktsioon
Card Deck::takeCard()
{
    Card last = deck.back();

    deck.pop_back();
    return last;
}

Deck::~Deck()
{
}
