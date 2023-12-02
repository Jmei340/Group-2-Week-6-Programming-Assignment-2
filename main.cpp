// World Series Program
// Programmers: Fadi Jameel, Joey Mei.
// This program will read and output the list of World Series winners from 1903 to 2022.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
// Add any other header files here

// This function takes a char to print and a message and prints a nice introduction 
// surrounded by the characters char. See pic in assignment.
void Introduction(char c, string message)
{
    // Initial Outputs
    cout << "*" << setw(39) << setfill('*') << right << "*" << endl;
    cout << "** Welcome To My World Series Program **" << endl;
    cout << "*" << setw(39) << setfill('*') << right << "*" << endl;
    cout << endl;

    // Output Choices
    cout << "'c' to invoke 'GetCountOfTeams()'" << endl;
    cout << "'w' to invoke 'GetMostWinningTeam()'" << endl;
    cout << "'d' to invoke 'GetTeamForDate()'" << endl;
    cout << "'v' to invoke 'ConvertTeamNameCase()'" << endl;
    cout << "'x' to exit the program" << endl;
    cout << endl;
    cout << endl;

    // Getting User Inputs
    cout << "Please enter an operation to perform:";
    cin >> c;
}

// This function takes a file name and reads in data, storing it in a string array that is used 
// by the rest of the program. Use this function to read the team names or the corresponding dates. 
// The function should return true on success or false on failure.
bool ReadFile(string fileName, string data[], const int maxArraySize)
{
    // Work here.
}

// This function gets the number of occurrences of a team name in the array of teams 
// and returns the count of the teams as a constant integer.
const int GetCountOfTeam(string teamName, const string teams[], const int maxArraySize)
{
    // Work here.
}

// This function searches the team's array for the team's name that won the world series 
// the most times and returns it as a constant string.
const string GetMostWinningTeam(const string teams[], const int maxArraySize)
{
    // Work here.
}

// This function returns the team that won the world series on the "date".
const string GetTeamForDate(const string date, const string teams[], const string dates[], const int maxArraySize)
{
    // Declaring Variables
    int found = 0;
    int index = 0;

    // Finding Teams From Dates
    while (found != 1) {

        if (date != dates[index]) {
            index++;
        }
        else {
            found = 1;
        }
    }

    // Outputting Team
    cout << "The team that won the world series on '" << date << "' is '" << teams[index] << "'.";

    return 0;
}

// This function changes all of the team names to either upper or lower case depending on the value of "to_upper".
void ConvertTeamNameCase(bool to_upper, string teams[], const int maxArraySize)
{
    // Declaring Variables
    char choice = 'a';
    int index = 0;

    // Getting User Input
    cout << "Please enter the case to change ('u' = upper and 'l' = lower):";
    cin >> choice;

    // Upper or Lower Case
    if (choice == 'u' || choice == 'U') {
        for (index = 0; index < maxArraySize; index++) {
            transform(teams[index].begin(), teams[index].end(), teams[index].begin(), ::toupper);
        }

        cout << "The case for all team names has been changed to 'upper'.";
    }
    else if (choice == 'l' || choice == 'L') {
        for (index = 0; index < maxArraySize; index++) {
            transform(teams[index].begin(), teams[index].end(), teams[index].begin(), ::tolower);
        }

        cout << "The case for all team names has been changed to 'lower'.";
    }
}

// This function provides the menu and calls the other functions according to what the user inputs. 
// See pic in assignment for more details.
int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Error! Not enough file names. Expecting 2!" << endl;
        return -1;
    }

    // Const representing the number of lines of data in both files.
    const int SIZE_DATA = 120;

    // Declaring Variables
    string data[SIZE_DATA];
    string filename;
    string dates[SIZE_DATA];
    string date;
    string message;
    string teamNames;
    string teams[SIZE_DATA];
    char c = 'a';
    bool to_upper = false;



    do {
        // Getting Introduction
        Introduction(c, message);               // Function works
        ReadFile(filename, data, SIZE_DATA);    // In Progress

        // Calling Functions
        if (c == 'c' || c == 'C') {
            GetCountOfTeam(teamNames, teams, SIZE_DATA);        // In Progress
        }
        else if (c == 'w' || c == 'W') {
            GetMostWinningTeam(teams, SIZE_DATA);               // In Progress
        }
        else if (c == 'd' || c == 'D') {
            cout << "Please enter the date:";
            cin >> date;

            GetTeamForDate(date, teams, dates, SIZE_DATA);      // Function needs testing
        }
        else if (c == 'v' || c == 'V') {
            ConvertTeamNameCase(to_upper, teams, SIZE_DATA);    // Function needs testing
        }


    }

    while (c != 'x' && c != 'X');

    // Outputting Ending Statement
    cout << "Good bye" << endl;

    // Return 0 to indicate success.
    return 0;
}

// Place any unused code here so that the instructor can follow your problem solving thoughts.