#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Matt Zindler, CS-300 10/17/2021


int main()
{
    std::vector<string> courses;
    char userInput = 0;
    cout << "Welcome to the course Planner. \n";

    while (userInput != 9){  // user input menu
        string input2;
        cout << "1.Load Data Structure.\n";
        cout << "2.Print Course List.\n";
        cout << "3.Print Course.\n";
        cout << "9.Exit.\n";
        cout << "What would you like to do?\n";
        cin >> userInput;  // gathers user input

        if (userInput == '9'){  // closes the program if 9 is entered
            cout << "Thank you for using the course planner!";
            break;
        }

        else if (userInput == '1') {  // loads the data structure with the file contents
            fstream f("CourseInformation.txt", ios::in);  // opens the course information file
            string currLine;
            if (f.is_open()) {  // checks that the file is open
                getline(f, currLine);
                while (f) {
                    courses.push_back(currLine);  // adds the line to the vector
                    getline(f, currLine);
                }
                f.close();  // closes the file when finished
                cout << "File successfully added!\n";
            }
            else {  // outputs error message if file did not open
                cout << "Error reading file...";
            } 
            sort(courses.begin(), courses.end()); // sorts courses numerically
        }

        else if (userInput == '2'){  // prints the courses from the file
            for (int i = 0; i < courses.size(); i++) {
                std::cout << courses.at(i) << "\n";
            }
            cout << "\n";
        }

        else if (userInput == '3'){  // searches for a course based on input
            cout << "What course do you want to know about? (case sensitive)\n";
            cin >> input2;
            cout << "\n";

            if (input2 == "csci400") {
                cout << "CSCI400, Large Software Development\nPrerequisites:CSCI301, CSCI350\n\n";
            }
            else if (input2 == "csci350") {
                cout << "CSCI350, Operating Systems.\nPrerequisites:CSCI300\n\n";
            }
            else if (input2 == "csci301") {
                cout << "CSCI301, Advanced Programming in C++.\nPrerequisites:CSCI101\n\n";
            }
            else if (input2 == "csci300") {
                cout << "CSCI300, Introduction to Algorithms\nPrerequisites:CSCI200, MATH201\n\n";
            }
            else if (input2 == "csci200") {
                cout << "CSCI200, Data Structures.\nPrerequisites:CSCI101\n\n";
            }
            else if (input2 == "csci101") {
                cout << "CSCI101, Introduction to Programming in C++.\nPrerequisites:CSCI100\n\n";
            }
            else if (input2 == "csci100") {
                cout << "CSCI100, Introduction to Computer Science.\n\n";
            }
            else if (input2 == "csci201") {
                cout << "MATH201, Descrete Mathematics.\n\n";
            }
            else {
                cout << "Invalid course ID...\n\n";
            }
        }

        else{  // error message on invalid input
            cout << userInput << " is not a valid option.\n\n";
        }
    }

    return 0;
}