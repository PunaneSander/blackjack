#include "play.h"
#include "functions.h"
#include <iostream>
#include <random>
using namespace std;

void printHand(Hand hand)
{
    if (hand.cardsInHand.empty())
    {
        cout << "0 cards" << endl;
    }
    else
    {
        cout << "|";
        for (Card card : hand.cardsInHand)
        {
            cout << card << " | ";
        }
        cout << endl;
    }
}

int displayTurn(int bet, Deck deck, Hand playerHand, Hand hostHand, int cash)
{
    int input = 0;
    cout << "Bet = " << bet << " | Cash = " << cash << endl;
    cout << "--------------------------------" << endl;
    cout << "\tCards in hand:" << endl;
    printHand(playerHand);
    cout << "Hosts cards:" << endl;
    printHand(hostHand);
    cout << "\nHit [0] | Stand [1] | Double down [2]" << endl;

    input = numericalInput();
    if (input == 2 && bet > cash)
    {
        cin.sync();
        cout << "Insufficient funds!" << endl;
        getchar();
        system("clear");
        cin.sync();
        return displayTurn(bet, deck, playerHand, hostHand, cash);
    }
    else
    {
        system("clear");
        cin.sync();
        return input;
    }
}

int betScene(int cash)
{
    int bet = 50;
    cash = cash - bet;
    int input = 0;

    while (true)
    {
        system("clear");
        cin.sync();
        cout << "Place your bet!" << endl;
        cout << "Minimum = 50, raise bet = +50" << endl;
        cout << "\nCurrent: " << bet << endl;
        cout << "Balance: " << cash << endl;
        cout << "Confirm [0]";

        if (bet + 50 <= cash)
        {
            cout << " | Raise bet [1]";
        }
        cout << endl;
        input = numericalInput();

        switch (input)
        {
        case 0:
            return bet;
        case 1:
            if (cash >= 50)
            {
                bet += 50;
                cash = cash - 50;
            }
            else
            {
                cin.sync();
                cout << "Bet can't be larger than your balance! [enter]" << endl;
                getchar();
            }
            break;
        default:
            cin.sync();
            cout << "Incorrect input! [enter]" << endl;
            getchar();
        }
    }
}

void playScene()
{

    cin.sync();
    int cash = 500;

    int decision = 0;
    while (cash > 0)
    {
        // true = mäng käib
        bool game = true;
        int round = 1;
        // Paneme laua ja mängija "käed" valmis
        Hand playerHand;
        Hand hostHand;

        // Teeme ning segame kaardipaki
        Deck deck;
        deck.shuffleDeck();

        // Paneme aluspanuse paika
        int bet = betScene(cash);
        system("clear");
        cin.sync();

        cash = cash - bet;

        playerHand.addCard(deck.takeCard());
        playerHand.addCard(deck.takeCard());

        hostHand.addCard(deck.takeCard());

        // Ühe mängu tsükkel
        while (game)
        {
            decision = displayTurn(bet, deck, playerHand, hostHand, cash);

            switch (decision)
            {
            // Hit
            case 0:
                playerHand.addCard(deck.takeCard());
                break;

            // Stand
            default:
            case 1:
                break;

            // Double DOwn
            case 2:
                cash = cash - bet;
                bet = bet * 2;
                playerHand.addCard(deck.takeCard());
                break;
            }

            // Kontrollime, kas mängija on kaotanud
            if (playerHand.min > 21)
            {
                system("clear");
                cout << "Cards: " << endl;
                printHand(playerHand);
                cout << "That's a bust...." << endl;
                getchar();
                cin.sync();
                system("clear");
                game = false;
                bet = bet * -1;
            }
            else
            {
                if (playerHand.min == 21 || playerHand.max == 21)
                {
                    cin.sync();
                    system("clear");
                    cout << "BLACKJACK!" << endl;
                    cout << "You won " << bet * 1.5 << "!!" << endl;
                    bet = bet * 1.5;
                    game = false;
                }

                // Juhul, kui mängija pole võitnud, ega kaotanud, on laua mängukord
                else
                {
                    // Laua mängukord:
                    if (round == 1)
                    {
                        hostHand.addCard(deck.takeCard());
                    }
                    else
                    {
                        if (hostHand.max < 17)
                        {
                            hostHand.addCard(deck.takeCard());
                        }
                        else
                        {
                            if (playerHand.min < hostHand.min)
                            {
                                cout << "Host won!" << endl;
                                game = false;
                                bet = bet * -1;
                            }
                            else
                            {
                                if (playerHand.min == hostHand.min)
                                {
                                    cout << "It's a tie!" << endl;
                                    cout << "Your bet will be returned" << endl;
                                }
                                else
                                {
                                    cin.sync();
                                    system("clear");
                                    cout << "You've won!" << endl;
                                    cout << "Your bet was bigger!" << endl;
                                    bet = bet * 1.5;
                                }
                            }
                        }
                    }

                    // Kontrollime, kas laud on võitnud või kaotanud

                    if (hostHand.max == 21 || hostHand.min == 21)
                    {
                        cout << "Host hit BLACKJACK!" << endl;
                        cout << "You lost.." << endl;
                        game = false;
                    }
                    else
                    {
                        if (hostHand.min > 21)
                        {
                            cout << "Host got a bust! You win double the bet!" << endl;
                            bet = bet * 2;
                            game = false;
                        }
                    }
                }
            }

            if (!game)
            {
                getchar();
                system("clear");
                cin.sync();

                cash = cash + bet;
                if (cash >= 50)
                {

                    cout << "Do you want to play another round? [1]" << endl;
                    cout << "Balance = " << cash << endl;
                    int input = numericalInput();

                    if (input != 1)
                    {
                        cash = 0;
                        break;
                    }
                }
                else
                {
                    cout << "Unfortunately, you're out of money" << endl;
                    cout << "Thanks for playing!" << endl;
                }
            }

            round++;
        }

        getchar();
        system("clear");
    }
}
