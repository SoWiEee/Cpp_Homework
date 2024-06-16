#include <iostream>
#include <cstdlib>
#include <time.h>

// declare namespace
namespace GamePlayer {
	// parent class
	class Player {
	public:
		virtual int getGuess() { return 0; }
	};

	// child class
    class HumanPlayer: public Player {
	public:
		// 讀取玩家猜測的數字並回傳
		int getGuess(){
            int number;
            cin >> number;
            return number;
        }
	};

	// child class
    class ComputerPlayer: public Player {
	public:
		// 電腦猜測 0~99 的數字並回傳
		int getGuess(){
            int number;
            number = rand() % 100;
            return number;
        }
	};
}

using namespace std;
using namespace GamePlayer;

bool checkForWin(int guess, int answer){
	if (answer == guess){
		cout << "You're right! You Win!" << endl;
		return true;
	}
	else if (answer < guess)
		cout << "Your guess is too high." << endl;
	else
		cout << "Your guess is too low." << endl;
	return false;
}

// playing process
void play(Player &player1, Player &player2){
	int answer = 0, guess = 0;
	answer = rand() % 100;
	bool win = false;
	
	while (!win){
		cout << "[*] Player 1's turn to guess=> " << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win) return;
		cout << "[*] Player 2's trun to guess=> " << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}

int main() {
	int choice = 0;
	// 建立 2 個人類玩家和 2 個電腦
	HumanPlayer hPlayer1, hPlayer2;
	ComputerPlayer cPlayer1, cPlayer2;

	srand(time(NULL));

	do{
		// 選擇遊戲模式
		cout << "[0] Human vs Human \n[1] Human vs Computer  \n[2] Computer vs Computer \n[3] Exit" << endl;
		cout << "Choose 1 of the above: ";
		cin >> choice;

		switch (choice){
		case 0: 
			play(hPlayer1, hPlayer2);
			break;
		case 1:
			play(hPlayer1, cPlayer2);
			break;
		case 2:
			play(cPlayer1, cPlayer2);
			break;
		case 3:
			break;
		default:
			cout << "[X] Invaild choice!" << endl;
			break;
		}	

		cout << endl;
	} while (choice != 3);
	
	system("pause");
	return 0;
}