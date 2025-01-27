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
void calculator();
void todoLists();
void displayTodos();
void createTodo();
void updateTodo();
void deleteTodo();
int findUserLocation();

// DECLARE PARALLEL ARRAYS TO STORE USER DATA (USERNAMES & PASSWORDS)
string userNamesArr[10] = {"basit"};
string userPasswordsArr[10] = {"basitbasit"};
string todoNameArr[10][10];
bool todoStatusArr[10][10];
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
        exit(0);
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
        case 2: // Todo List
            todoLists();
            break;
        case 3: // Calculator
            calculator();
            break;
        case 4: // Exit
            cout << "\nThank you for using our services. Goodbye!\n";
            exit(0);
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
        {
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

// FUNCTION FOR THE CALCULATOR
void calculator()
{
    int userChoice, firstNum, secondNum, results;

    do
    {
        cout << "\nWhat operation would you like to perform? \n1) Addition\n2) Subtraction\n3) Division\n4) Multiplication\n5) Back" << endl;
        cin >> userChoice;

        if (userChoice >= 1 && userChoice <= 4)
        {
            cout << "\nEnter first number and second number: " << endl;
            cin >> firstNum >> secondNum;

            switch (userChoice)
            {
            case 1: // Addition
                results = firstNum + secondNum;
                cout << "\nResult is: " << results << endl;
                break;
            case 2: // Subtraction
                results = firstNum - secondNum;
                cout << "\nResult is: " << results << endl;
                break;
            case 3: // Division
                if (secondNum != 0)
                {
                    results = firstNum / secondNum;
                    cout << "\nResult is: " << results << endl;
                }
                else
                {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case 4: // Multiplication
                results = firstNum * secondNum;
                cout << "\nResult is: " << results << endl;
                break;
            default:
                cout << "Invalid operation. Please try again." << endl;
                break;
            }
        }
        else if (userChoice == 5)
        {
            showMenu2GetInput(); // Go back to the previous Step
            return;
        }
        else
            cout << "Invalid Choice. Please try again." << endl;

    } while (true);
}

// FUNCTION TO MANAGE CREATE DELETE UPDATE THE TODOS
void todoLists()
{
    int userChoice;

    do
    {
        cout << "\nWhat operation would you like to perform? \n1) View Todos\n2) Create Todo\n3) Update Todo\n4) Delete Todo\n5) Back" << endl;
        cin >> userChoice;

        if (userChoice > 0 && userChoice < 5)
        {
            switch (userChoice)
            {
            case 1:
                displayTodos();
                break;
            case 2:
                createTodo();
                break;
            case 3:
                updateTodo();
                break;
            case 4:
                deleteTodo();
                break;
            default:
                cout << "Invalid operation. Please try again." << endl;
                break;
            }
        }
        else if (userChoice == 5)
        {
            showMenu2GetInput();
            return;
        }
        else
            cout << "Invalid Choice. Please try again." << endl;

    } while (true);
}

// FUNCTION TO DISPLAY ALL THE TODOS
void displayTodos()
{
    int userLocation = findUserLocation();
    bool isTodoFound = false;

    cout << "\n"
         << "Mr/Ms "
         << activeUser << " todos: " << endl;

    for (int i = 0; i < 10; i++)
    {
        if (!todoNameArr[userLocation][i].empty())
        {
            isTodoFound = true;
            cout << todoNameArr[userLocation][i] << ": " << (todoStatusArr[userLocation][i] == 1 ? "Done" : "Pending") << endl;
        }
    }
    if (!isTodoFound)
    {
        cout << "Empty!" << endl;
    }
}

// FUNCTION TO CREATE TODO
void createTodo()
{
    int userLocation = findUserLocation();
    string newTodoName;

    for (int i = 0; i < 10; i++)
    {
        if (todoNameArr[userLocation][i].empty())
        {
            cout << "Todo name: ";
            cin >> newTodoName;
            todoNameArr[userLocation][i] = newTodoName;
            cout << "Successfully created todo." << endl;
            return;
        }
    }
    cout << "\nSorry we don't have enough space to create this todo!" << endl;
}

// FUNCTION TO UPDATE THE TODO
void updateTodo()
{
    int userLocation = findUserLocation();
    string todoName;

    cout << "Name of todo(you want to update)? ";
    cin >> todoName;

    for (int i = 0; i < 10; i++)
    {
        if (todoNameArr[userLocation][i] == todoName)
        {
            todoStatusArr[userLocation][i] = !todoStatusArr[userLocation][i];
            cout << "Successfully updated!" << endl;
            return;
        }
    }
    cout << "Todo not found!" << endl;
}

// FUNCTION TO DELETE THE TODO
void deleteTodo()
{
    int userLocation = findUserLocation();
    string todoName;

    cout << "Name of todo(you want to delete)? ";
    cin >> todoName;

    for (int i = 0; i < 10; i++)
    {
        if (todoNameArr[userLocation][i] == todoName)
        {
            todoStatusArr[userLocation][i] = false;
            todoNameArr[userLocation][i] = "";
            cout << "Successfully deleted!" << endl;
            return;
        }
    }
    cout << "Todo not found!" << endl;
}

// FUNCTION TO FIND LOCATION OF USER IN USERS ARRAY
int findUserLocation()
{
    int userLocation;

    for (int i = 0; i < 10; i++)
    {
        if (userNamesArr[i] == activeUser)
        {
            userLocation = i;
            break;
        }
    }
    return userLocation;
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