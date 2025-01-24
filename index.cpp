#include <iostream>

using namespace std;

// FUNCTION PROTOTYPING
void mainHandlerFunc();
int showMenu1GetInput();
void showMenu2GetInput();
void signUpNewUser();
string loginUser();
string inputPasswordValidator();
int movesLevelInput();
void playGame();

// DECLARE PARALLEL ARRAYS TO STORE USER DATA (USERNAMES & PASSWORDS)
string userNamesArr[10] = {"basit"};
string userPasswordsArr[10] = {"basitbasit"};
string activeUser;

// MAIN FUNCTION
int main()
{
    mainHandlerFunc();
    return 0;
}

// FUNCTION TO HANDLE MAIN MENU
void mainHandlerFunc()
{
    int userChoice = showMenu1GetInput();

    switch (userChoice)
    {
    case 1: // Login
        activeUser = loginUser();
        if (activeUser != "back")
            showMenu2GetInput();
        break;
    case 2: // Signup
        signUpNewUser();
        mainHandlerFunc(); // Go back to the main menu
        break;
    case 3: // Exit
        cout << "\nThank you for visiting us. Goodbye!\n";
        break;
    default:
        cout << "\nInvalid choice. Please try again.\n";
        mainHandlerFunc();
        break;
    }
}

// FUNCTION TO SHOW THE FIRST MENU AND GET USER CHOICE
int showMenu1GetInput()
{
    int userChoice;

    do
    {
        cout << "\nAuthenticate yourself to start using our services:\n";
        cout << "1) Login\n2) Signup\n3) Exit\n";
        cin >> userChoice;

        if (userChoice >= 1 && userChoice <= 3)
            return userChoice;

        cout << "\nInvalid selection. Please try again.\n";
    } while (true);
}

// FUNCTION TO SHOW THE SECOND MENU AND HANDLE USER CHOICES
void showMenu2GetInput()
{
    int userChoice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1) Gamification\n2) Todo List \n3) Calculator\n4) Exit\n5) Logout\n";
        cin >> userChoice;

        switch (userChoice)
        {
        case 1: // Gamification
            playGame();
            break;
        case 2: // Library Management System placeholder
            cout << "\nLibrary Management System is under construction.\n";
            break;
        case 3: // Calculator placeholder
            cout << "\nCalculator is under construction.\n";
            // calculator();
            break;
        case 4: // Exit
            cout << "\nThank you for using our services. Goodbye!\n";
            return;
        case 5: // Logout
            cout << "\nLogged out successfully.\n";
            mainHandlerFunc();
            return;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    } while (true);
}

// FUNCTION TO SIGN UP A NEW USER
void signUpNewUser()
{
    for (int i = 0; i < 10; i++)
    {
        if (userNamesArr[i].empty())
        { // Check for empty space
            cout << "\nEnter your details to sign up.\n";
            cout << "Username: ";
            cin >> userNamesArr[i];
            userPasswordsArr[i] = inputPasswordValidator();
            cout << "\nSuccessfully signed up!\n";
            return;
        }
    }
    cout << "\nSorry! We can't register you. The database is full.\n";
}

// FUNCTION TO LOGIN A USER
string loginUser()
{
    string username, password;
    bool userFound = false;

    do
    {
        cout << "\nEnter username (type 'back' to return to the main menu): ";
        cin >> username;

        if (username == "back")
        {
            mainHandlerFunc();
            return "back";
        }

        for (int i = 0; i < 10; i++)
        {
            if (userNamesArr[i] == username)
            {
                userFound = true;
                do
                {
                    password = inputPasswordValidator();
                    if (userPasswordsArr[i] == password)
                    {
                        cout << "\nLogin successful!\n";
                        return username;
                    }
                    else
                    {
                        cout << "\nIncorrect password. Please try again.\n";
                    }
                } while (true);
            }
        }

        if (!userFound)
        {
            cout << "\nUser not found. Please try again.\n";
        }
    } while (true);
}

// FUNCTION TO PLAY THE GAME
void playGame()
{
    srand(time(0));
    int randomNumber = (rand() % 50) + 1; // Random number between 1 and 50
    int userGuess, moves = movesLevelInput();

    cout << "\nGuess🫣 the number (1 to 50). You have " << moves << " moves.\n";

    while (moves > 0)
    {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess == randomNumber)
        {
            cout << "\n🎉 Congratulations! You guessed the number!\n";
            break;
        }
        else if (userGuess > randomNumber)
        {
            cout << "Hint: The number is lower.\n";
        }
        else
        {
            cout << "Hint: The number is higher.\n";
        }

        moves--;
        if (moves == 0)
        {
            cout << "\n😞 You ran out of moves. The number was " << randomNumber << ".\n";
        }
    }

    int replayChoice;
    cout << "\nWould you like to play again? (1) Yes, 2) No): ";
    cin >> replayChoice;

    if (replayChoice == 1)
        playGame();
}

// FUNCTION TO SELECT GAME MODE AND RETURN MOVES
int movesLevelInput()
{
    int choice;
    do
    {
        cout << "\nSelect game mode:\n";
        cout << "1) 🤠Easy (10 moves)\n2) 💀Hard (5 moves)\n";
        cin >> choice;

        return choice == 1 ? 10 : 5;

        cout << "\nInvalid choice. Please try again.\n";
    } while (true);
}

// FUNCTION TO VALIDATE PASSWORD INPUT
string inputPasswordValidator()
{
    string password;
    do
    {
        cout << "\nEnter password (minimum 8 characters): ";
        cin >> password;

        if (password.length() >= 8)
        {
            return password;
        }
        else
        {
            cout << "\nPassword is too short. Please try again.\n";
        }
    } while (true);
}










// #include <iostream>

// using namespace std;

// // FUNCTION PROTOTYPING
// void mainHandlerFunc();
// int showMenu1GetInput();
// void showMenu2GetInput();
// void signUpNewUser();
// string loginUser();
// string inputPasswordValidator();
// int movesLevelInput();
// void playGame();

// // DECLARE PARALLEL ARRAYS TO STORE USER DATA (USERNAMES & PASSWORDS)
// string userNamesArr[10] = {"basit"};
// string userPasswordsArr[10] = {"basitbasit"};

// string activeUser;

// // MAIN FUNCTION THAT WILL EXECUTE BY DEFAULT
// int main()
// {

//     mainHandlerFunc();

//     return 0;
// }

// void mainHandlerFunc()
// {
//     // FIRST MENU
//     int userChoice = showMenu1GetInput();
//     int userChoice2;

//     switch (userChoice)
//     {
//     case 1: // FOR LOGIN
//         activeUser = loginUser();
//         showMenu2GetInput(); // SHOW SECOND MENU TO USE OUR SERVICES
//         break;
//     case 2: // FOR SIGNUP
//         signUpNewUser();
//         mainHandlerFunc();
//         break;
//     }
// }

// // FUNCTION BODY TO: SHOW 1st MENU TO USER, GET HIS CHOICE/INPUT, VALIDATE THE INPUT, RETURN THE CHOICE
// int showMenu1GetInput()
// {
//     int userChoice = 0;

//     cout << "\nAuthenticate your self to start using our services." << endl;
//     cout << "\n1) Login\n2) Signup\n3) Exit" << endl;
//     cin >> userChoice;

//     do
//     {

//         if (userChoice == 3)
//             cout << "\nExit Successful, Thank You for visiting us!\n"
//                  << endl;
//         else if (userChoice == 0 || userChoice > 2)
//         {
//             cout << "\nInvalid selection.\nPlease choice a correct one from menu:" << endl;
//             cout << "\n1) Login\n2) SignUp\n3) Exit" << endl;
//             cin >> userChoice;
//         }
//         else
//             break;

//     } while (userChoice != 3);

//     return userChoice;
// }

// // FUNCTION BODY TO: SHOW 2nd MENU TO USER, GET HIS CHOICE/INPUT, VALIDATE THE INPUT
// void showMenu2GetInput()
// {
//     int userChoice = 0;

//     cout << "\nMenu." << endl;
//     cout << "\n1) Gamification\n2) Library Management System\n3) Calculator\n4) Exit\n5) Logout" << endl;
//     cin >> userChoice;

//     do
//     {

//         if (userChoice == 4)
//             cout << "\nExit Successful, Thank You for using our services!\n"
//                  << endl;
//         else if (userChoice == 5)
//         {
//             cout << "\nSigned Out successfully!" << endl;
//             mainHandlerFunc();
//             break;
//         }
//         if (userChoice == 0 || userChoice > 5)
//         {

//             cout << "\nInvalid selection.\nPlease choice a correct one from menu:" << endl;
//             cout << "\n1) Gamification\n2) Library Management System\n3) Exit" << endl;

//             cin >> userChoice;
//         }
//         else
//             break;

//     } while (userChoice != 3);

//     switch (userChoice)
//     {
//     case 1: // FOR GAMIFICATION
//         playGame();
//         break;
//     case 2:

//         break;
//     }
// }

// // FUNCTION BODY TO SIGNUP NEW USER
// void signUpNewUser()
// {
//     bool isAvailableSpace = false;

//     // CHECK FOR SPACE AVAILABILITY TO STORE NEW USER DATA
//     for (int i = 0; i < 10; i++)
//     {
//         if (userNamesArr[i] == "")
//         {
//             isAvailableSpace = true;
//             cout << "\nEnter your details to SignUp." << endl;
//             cout << "\nUsername: ";
//             cin >> userNamesArr[i];
//             userPasswordsArr[i] = inputPasswordValidator();
//             break;
//         }
//     }

//     // LET THE USER KNOW IF IT'S FULL
//     if (isAvailableSpace)
//         cout << "\nSuccessfully Signed Up!" << endl;
//     else
//         cout << "\nSorry! We can't register you. Db space is now full." << endl;
// }

// // FUNCTION BODY TO LOGIN THE USER
// string loginUser()
// {
//     string userNameInput, userPasswordDb, userEnteredPass;
//     bool isFound = false;

//     do
//     {
//         cout << "\nType \'back\' to go back: ";
//         cout << "\nEnter username: ";
//         cin >> userNameInput;

//         for (int i = 0; i < 10; i++)
//         {
//             if (userNamesArr[i] == userNameInput)
//             {
//                 isFound = true;
//                 userPasswordDb = userPasswordsArr[i];
//             }
//         }

//         if (userNameInput == "back")
//             mainHandlerFunc();
//         else if (!isFound)
//             cout << "\nUser not found." << endl;
//     } while (!isFound);

//     do
//     {
//         userEnteredPass = inputPasswordValidator();

//         if (userPasswordDb != userEnteredPass)
//             cout << "\nIncorrect password!" << endl;

//     } while (userPasswordDb != userEnteredPass);

//     return userNameInput;
// }

// // FUNCTION BODY TO PLAY GAME
// void playGame()
// {
//     srand(time(0));

//     int randomNumber = (rand() % 50) + 1, userGuess, moves = movesLevelInput(), userEndChoice;

//     cout << "\nYou'll be playing number guessing game🫣. The number will be between 1 to 50 and you have " << moves << " total moves." << endl;
//     // cout << randomNumber << endl;

//     cout << "\nEnter Number(1-50): ";
//     cin >> userGuess;
//     moves--;

//     do
//     {
//         if (userGuess > randomNumber)
//             cout << "\nWrong Guess! \nHint: It's high." << endl;
//         else
//             cout << "\nWrong Guess! \nHint: It's low." << endl;

//         cout << "\nEnter Number(1-50): ";
//         cin >> userGuess;
//         moves--;
//     } while (randomNumber != userGuess && moves != 0);

//     if (randomNumber == userGuess)
//         cout << "\n😊Hurry! You won the game.\n"
//              << endl;
//     else
//         cout << "\n😔Oops! You ended up with your moves. It was " << randomNumber << "." << endl;

//     cout << "\nWould you like to play it again? (1) Yes 2) Not)" << endl;
//     cin >> userEndChoice;

//     if (userEndChoice == 1)
//         playGame();
//     else
//         showMenu2GetInput();
// }

// int movesLevelInput()
// {
//     int choice;

//     cout << "\nPlease choice game mode:" << endl;

//     do
//     {
//         cout << "\n1) 🤠Easy\n2) 💀Hard\n"
//              << endl;
//         cin >> choice;
//     } while (choice != 1 && choice != 2);

//     return choice == 1 ? 10 : 5;
// }

// // UTILITY FUNCTIONS
// string inputPasswordValidator()
// {
//     string userPassword;

//     do
//     {

//         cout << "\nPassword (Should have one upper latter, lower latter, number, min 8 characters): ";
//         cin >> userPassword;

//     } while (userPassword.length() < 8);

//     return userPassword;
// }
