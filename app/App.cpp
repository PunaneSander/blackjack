#include <iostream>
#include "functions.h"

using namespace std;

void errorScene()
{
    cin.sync();
    system("clear");
    cout << "Something went wrong.... Try again!" << endl;
    getchar();
    system("clear");
}

// Programmi algmenüü
void printMenu()
{
    cin.sync();
    system("clear");
    cout << "\t\tBLACKJACK v0.1\n\n\n";
    cout << "\t\t  PLAY(1)\n\t\t  ABOUT(2)\n\t\t  EXIT(3)" << endl;
}

// 'about' vaade, programmi kirjeldus
void aboutScene()
{
    cin.sync();
    cout << "BLACKJACK\nCreated by: Sander Lääts" << endl;
    cout << "This game was created for a c++ course." << endl;
    cout << "How to play blackjack?" << endl;
    cout << "At the start of the game, you will have to place a bet.\nAfter that, you will be given a choice, to hit, stand or double down.\nHit - take one extra card,\nStand - don't take a card,\nDouble down - take a card and raise the bet two times.\nThe winner wil be the player who has the biggest score and which is closest to 21.\nIf you go over 21 points, you get a bust and lose the game.\nEach standard number gives the same amount of points as the number.\nEvery card with a 'face' gives 10 points, with the exception of ace, which will give 10 OR 1.\nIf you have 11 points and get an Ace, then you will have won the game, because it can be either 10 or 1.\nHave fun!";
    getchar();
    system("clear");
}

int main()
{

    int userOption = 0;
    while (true)
    {

        printMenu();
        userOption = numericalInput();
        system("clear");

        switch (userOption)
        {
        // Alusta mängu
        case 1:
            playScene();
            break;
        // 'About' vaade
        case 2:
            aboutScene();
            break;
        // Välju
        case 3:
            exit(0);
            break;
        // Muul juhul küsime uuesti
        default:
            errorScene();
            break;
        }
    }

    return 0;
}
