#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>
using namespace std;

const int marbleNum = 10;
int computerNum = marbleNum;
int playerNum = marbleNum;

void displayHalf(int num) {
    for (int i = 0; i < (num / 2); i++) {
        cout << "o  ";
    }
}

void displayMarble(int num) {
    displayHalf(num);
    cout << endl;
    displayHalf(num);
    if (num % 2 != 0) {
        cout << "o  " << endl << endl;
    }
    else {
        cout << endl << endl;
    }
}

bool checkChoice(char inp) {
    return (tolower(inp) == 'o' || tolower(inp) == 'e') ? true : false;
}

bool checkNumberInput(int numb) {
    return (numb > 0 && numb <= playerNum);
}

void printMarbleState(string name) {
    cout << "\n📊 Marble Count\n";
    cout << "--------------------------\n";
    cout << name << "'s marbles: " << playerNum << "\n";
    cout << "Opponent's marbles: " << computerNum << "\n";
    cout << "--------------------------\n\n";
}

bool updateStatus(char inp, int number, int& player, int& opponent) {
    if (inp == 'o' && number % 2 != 0) { 
        opponent -= number;
        player += number; 
    }
    if (inp == 'e' && number % 2 == 0) { 
        opponent -= number; 
        player += number;
    }
    if (opponent == 0) { return true; }
    return false;
}

int main() {
    srand(time(nullptr));
    string name;
    cout << "🎲================== Marble Guessing Game ==================🎲\n\n";

    cout << "👥 Players:\n";
    cout << "Each player starts with " << marbleNum << " marbles.\n\n";

    cout << "🧠 How to Play:\n";
    cout << "1️⃣ On each turn, one player secretly places a number of marbles in their hand.\n";
    cout << "2️⃣ The opponent must guess whether that number is *odd* or *even*.\n";
    cout << "3️⃣ If the guess is correct, they win all the marbles in their opponent's hand.\n";
    cout << "4️⃣ If the guess is wrong, the marbles stay with the one who hid them.\n\n";

    cout << "🏁 Objective:\n";
    cout << "Keep guessing wisely and win marbles from your opponent.\n";
    cout << "The game ends when one player has no marbles left.\n\n";

    cout << "\n============================================================\n\n";

    cout << "📝 Please enter your name:\n";
    getline(cin, name);
    cout << "\n👋 Welcome, " << name << "! You will go first.\n\n";

    while (true) {
        char inp;
        int playerInp;
        int number = (rand() % computerNum) + 1;

        printMarbleState(name);
        cout << name << ", the moment of truth is yours...\n";
        cout << "🤔 The marbles are clenched tight in their hand...\n";
        cout << "Your move: Will you call **odd** or **even**?\n";
        cin >> inp;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (!checkChoice(inp)) {
            cout << "That's not a valid move. Choose wisely this time...\n";
            cin >> inp;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "\n 🕵️ The opponent reveals their hand...\n";
        cout << "They were holding " << number << " marble" << (number == 1 ? "" : "s") << "!\n";
        cout << "That's " << ((number % 2 == 0) ? "even." : "odd.") << "\n";

        if (updateStatus(tolower(inp), number, playerNum, computerNum)) { break; }

        printMarbleState(name);
        cout << "\nIt's your opponent turn to guess.\n";
        cout << "Pick a number between 1 and your current amount of marbles (" << playerNum << ").\n";
        cin >> playerInp;

        while (!checkNumberInput(playerInp)) {
            cout << "❌ " << playerInp << " isn't a valid move — you don't have that many marbles.\n";
            cout << "Try again. How many will you hold in your hand?\n";
            cin >> playerInp;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        number = rand() % 2;
        (number == 0) ? inp = 'o' : inp = 'e';
        if (computerNum == 19) { inp = 'o'; }
        cout << "🪙 You've hidden " << playerInp << " marbles in your hand.\n";
        cout << "Your opponent guessed the number is " << ((inp == 'o') ? "odd" : "even") << ".\n";

        if (updateStatus(tolower(inp), playerInp, computerNum, playerNum)) { break; }
    }

    if (computerNum == 0) {
        cout << "\n🎉 Congratulations, " << name << "! You've taken all your opponent's marbles.\n";
    } else {
        cout << "\n💀 " << name << ", your opponent has claimed all your marbles. Better luck next time.\n";
    }

    return 0;
}