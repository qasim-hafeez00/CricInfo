#include "Match.h"
#include "player.h"
#include "Team.h"
#include "News.h"
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include<stdexcept>

using namespace std;

int main()
{
    try {
        // Declare variables to store login credentials
        string hello;
        string email;
        string temp;
        string password;

        // Declare pointers to objects of Player and Team classes
        Player* p;
        Team t;
        p = &t;

        // Declare objects of Match and News classes
        Match m;
        News n;

        // Declare other variables
        int choice = 0;
        char option = 'a';
        fstream pak;
        int x = 0;

        // Open the login file and read email and password
        pak.open("login.txt");
        if (!pak.is_open()) {
            throw runtime_error("Failed to open login.txt");
        }
        getline(pak, email);
        getline(pak, password);
        pak.close();

        // Change console text color to green and display the login screen
        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
        while (email != " ")
        {
            cout << endl << endl << endl << endl << endl;
            SetConsoleTextAttribute(color, 2);
            cout << "                   ***  ** *   ***   ***   ***  *     *  ****   ***  " << endl;
            cout << "                  *     *   *   *  *        *   * *   *  ****  *   * " << endl;
            cout << "                  *     ** *    *  *        *   *   * *  *     *   * " << endl;
            cout << "                   ***  *   *  ***   ***   ***  *     *  *      ***  " << endl;
            SetConsoleTextAttribute(color, 9);
            cout << " Enter the user name or Email to login " << endl;
            getline(cin >> ws, temp);
            // Check if the entered email matches the stored email
            if (temp == email)
            {
                string pass;
                cout << " Enter your Password " << endl;
                getline(cin >> ws, pass);

                // Check if the entered password matches the stored password
                while (pass != " ")
                {
                    if (pass == password)
                    {
                        x++;
                        break;
                    }
                    else
                    {
                        cout << " wrong password enter password again " << endl;
                        system("pause");
                        system("cls");
                    }
                }

                // If both email and password are correct, break out of the login loop
                if (x == 1)
                {
                    system("cls");
                    break;
                }
            }
            else
            {
                cout << " wrong Email enter password again " << endl;
                system("pause");
                system("cls");
            }
        }

        // Display the main menu and prompt the user for input
        while (option != 'E')
        {
            cout << " WELCOME TO CRIC INFO " << endl << endl;
            cout << " select the facility you want to use " << endl;
            cout << " 1:Display Team" << endl;
            cout << " 2:Add player to the team" << endl;
            cout << " 3:Remove player from the team " << endl;
            cout << " 4:Search player " << endl;
            cout << " 5:Update player" << endl;
            cout << " 6:Update captian" << endl;
            cout << " 7:Update coach" << endl;
            cout << " 8:Display matches" << endl;
            cout << " 9:View stats " << endl;
            cout << " 10:Conduct match" << endl;
            cout << " 11:Conduct Tornament " << endl;
            cout << " 12:Display upcomming matches " << endl;
            cout << " 13:Display recent matches " << endl;
            cout << " 14:View Rankings" << endl;
            cout << " 15:exit" << endl;
            cout << endl;
            cin >> choice;
            system("cls");
            int i = 0, j = 0, k = 0;

            // Use switch statements to handle user input
            switch (choice)
            {
            case 1:
                cout << " which team you want to see " << endl;
                cout << "1:Pakistan" << endl;
                cout << "2:India" << endl;
                cout << "3:England" << endl;
                cout << "4:Austrailia" << endl;
                cout << "5:South Africa" << endl;
                cout << "6:New Zeland" << endl;
                cin >> choice;

                // Open the file for the selected team
                if (choice == 1)
                {
                    t.teamName = "PAKISTAN";
                    pak.open("pak.txt");
                }
                if (choice == 2)
                {
                    t.teamName = "INDIA";
                    pak.open("india.txt");
                }
                if (choice == 3)
                {
                    t.teamName = "ENGLAD";
                    pak.open("eng.txt");
                }
                if (choice == 4)
                {
                    t.teamName = "AUSTRALIA";
                    pak.open("aus.txt");
                }
                if (choice == 5)
                {
                    t.teamName = "SouthAfrca";
                    pak.open("sa.txt");
                }
                if (choice == 6)
                {
                    t.teamName = "NEW ZEALAND";
                    pak.open("nz.txt");
                }

                // Read and display the team data
                if (pak.is_open()) {
                    while (!pak.eof()) {
                        getline(pak, hello);
                        cout << hello << endl;
                    }
                    pak.close();
                }
                else {
                    throw runtime_error("Failed to open team file");
                }
                break;

            case 2:
                // Add a player to the team

                p->addPlayer();
                system("pause");
                system("cls");
                break;
            case 3:

                // Remove a player from the team

                p->removePlayer();
                system("pause");
                system("cls");
                break;
            case 4:

                // Search for a player

                p->searchPlayer();
                system("pause");
                system("cls");
                break;
            case 5:

                // Update a player's information

                p->updatePlayer();
                system("pause");
                system("cls");
                break;
            case 6:

                // Update the team's captain

                t.updateCaptain();
                system("pause");
                system("cls");
                break;
            case 7:

                // Update the team's coach

                t.updateCoach();
                system("pause");
                system("cls");
                break;
            case 8:

                // Display the team's matches

                t.displayMatches();
                system("pause");
                system("cls");
                break;
            case 9:

                // View player stats

                t.ViewStats();
                system("pause");
                system("cls");
                break;
            case 10:

                // Conduct a match

                m.conductMatch();
                system("pause");
                system("cls");
                break;
            case 11:

                // Conduct a tournament

                m.conductTournament();
                system("pause");
                system("cls");
                break;
            case 12:

                // Display the upcoming matches

                m.displayUpcomingMatches();
                system("pause");
                system("cls");
                break;
            case 13:

                // Display the recent matches

                m.displayRecentMatches();
                system("pause");
                system("cls");
                break;
            case 14:

                // View rankings

                n.Rankings();
                system("pause");
                system("cls");
                break;

            case 15:
                // Exit the program
                option = 'E';
                break;

            default:
                // Handle invalid input
                cout << "Invalid choice! Please enter a number between 1 and 15." << endl;
                break;
            }
        }

        return 0;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
