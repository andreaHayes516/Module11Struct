/************************************************
** Author: Andrea Hayes
** Date: Sept 23, 2020
** Module 11 - Structures
*************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Declare Sturcture
struct PlayerInfo
{
    string name;
    int number = 0;
    int points = 0;
};
bool isValid(string);

int main() {
    // Declare Variables
    int most = 0, total = 0;
    const int SIZE = 12;
    PlayerInfo info[SIZE];

    string numberPlaceholder;

    // Get user input
    for (int i = 0; i < SIZE; i++) {

        cout << "Player " << i + 1 << endl;
        cout << "Player Name: ";
        getline(cin, info[i].name);
        cout << "Player Number: ";
        //cin >> info[i].number;
        getline(cin, numberPlaceholder);
           
        while (!isValid(numberPlaceholder)) {

            //cout << isValid(info[i].number) << endl;
            cout << "Enter a number greater than zero." << endl;
            cout << "Player Number: ";
            getline(cin, numberPlaceholder);

        }
         
        info[i].number = stoi(numberPlaceholder);
       
        cout << "Points scored: ";
        getline(cin, numberPlaceholder);
        while (!isValid(numberPlaceholder)) {

            //cout << isValid(info[i].number) << endl;
            cout << "Enter a number greater than zero." << endl;
            cout << "Player Number: ";
            getline(cin, numberPlaceholder);

        }

        info[i].points = stoi(numberPlaceholder);

        //string nothing;
        //getline(cin, nothing);
    }

    cout << setw(20) << "Player Name ";
    cout << setw(20) << "Player Number ";
    cout << setw(20) << "Points Scored ";
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        
        cout << setw(15) << info[i].name << setw(17) << info[i].number << setw(20) << info[i].points;
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (info[i].points >= most)
        {
            most = info[i].points;
        }
        total += info[i].points;
    }
    cout << endl;
    cout << "The most points scored was " << most << " by " << endl;
    for (int i = 0; i < SIZE; i++) {
        if (info[i].points==most)
        cout << " : " << info[i].name << " " << endl;
    }
    cout << endl;
    cout << "Great Job Player(s)!" << endl;
    cout << endl;
    cout << "The team scored a total of " << total << " points." << endl;
    return 0;
}
bool isValid(string num) {

    for (int i = 0; i < num.length(); i++) {

        if (!isdigit(num[i])) {

            return false;
        }
    }
    
    return true;
}