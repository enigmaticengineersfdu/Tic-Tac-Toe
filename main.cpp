#include <iostream>
#include <string>
#include "board.hpp"
#include "player.cpp"
using namespace std;


int main()
{
    board b;
    string name1, name2;
    coord cd;
    string rematch;
    bool replay;
    int score1 = 0, score2 = 0;    // player's score

    cout << "Instructions on how to play..." << endl;

    cout << "Enter both player's first name" << endl;
    cin >> name1 >> name2;

    player p1(name1, marker::X);
    player p2(name2, marker::O);

    
    while ((!b.has_won(p1.getMarker())) && (!b.has_won(p2.getMarker())) && (!b.are_tied()))
    {
        cout << endl << b.to_string();
        cd = p1.getMove();
        while (!b.add_marker(cd, p1.getMarker()))
        {
            cout << "Invalid move. Try again" << endl;
            cd = p1.getMove();
        }
        b.add_marker(cd, p1.getMarker());
        cout << b.to_string();
        if (b.has_won(p1.getMarker()) || (b.are_tied())) break;
        cd = p2.getMove();
        while (!b.add_marker(cd, p2.getMarker()))
        {
            cout << "Invalid move. Try again" << endl;
            cd = p2.getMove();
        }
        b.add_marker(cd, p2.getMarker());
        cout << b.to_string();
    }

    cout << endl;
    if (b.has_won(p1.getMarker()))
        cout << p1.getName() << " is the winner!" << endl;
    else if (b.has_won(p2.getMarker()))
        cout << p2.getName() << " is the winner!" << endl;
    else if (b.are_tied())
        cout << "It's a tie!" << endl;
    else
        cout << "Woah what happened?" << endl;

    // score stuff
    if (b.has_won(p1.getMarker()))
        score1 += 1;
    else if (b.has_won(p2.getMarker()))
        score2 += 1;
    cout << p1.getName() << "\'s score: " << score1 << endl;
    cout << p2.getName() << "\'s score: " << score2 << endl;

    return 0;
}