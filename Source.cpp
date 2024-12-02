#include<iostream>
#include"Header.h"
#include<string.h>
using namespace std;
int main() {
	string turn;
	srand(time(0));
	const int rows = 8;
	const int cols = 8;
	int toss = Toss();
	string chess[rows][cols];
	FirstInput(chess, rows, cols);
	Start_Display(chess, rows, cols);
	bool flag = false;


	while (1) {
		string move;
		int r_find=0, c_find=0;
		// This is The Move Of the player )ne
		if (toss == 1) {
			cout << "\n\t\t ********************************" << endl;
			cout << "\t\t * This is The Move Of Player 1 *" << endl;
			cout << "\t\t ********************************" << endl;
			Turn(r_find, c_find);
		    flag=	CheckPlayer(chess,r_find, c_find, "p1", "r1", "n1","b1", "q1", "k1");
		while (!flag) {
			cout << " You Enter The Turn Of opposite Player" << endl;
			cout << " Kindly Enter Your Turn Thank You" << endl;
			Turn(r_find, c_find);
			flag = CheckPlayer(chess,r_find, c_find, "p1", "r1", "n1", "b1", "q1", "k1");
			}		    
		if (Move(chess, r_find, c_find)) {
			toss += 1;
			}
		/*if (!Result(chess, r_find, c_find, "k2")) {
			cout << " player One Win the MAtch " << endl;
			break;
		 }
		if (checkmate(chess, r_find, c_find, "k2")) {
			cout << " Check MAte  So Player One win th match " << endl;
		}*/
		}
		// This is TRhe move of player Two 
		 if (toss == 2) {
			cout << "\n\t\t ********************************" << endl;
			cout << "\t\t * This iS the Move Of player 2 *" << endl;
			cout << "\t\t ********************************" << endl;
			Turn( r_find,  c_find);
		    flag = CheckPlayer(chess,r_find, c_find, "p2", "r2", "n2", "b2", "q2", "k2");
			while (!flag) {
				cout << " You Enter The Turn Of opposite Player" << endl;
				cout << " Kindly Enter Your Turn Thank You" << endl;
				Turn(r_find, c_find);
				flag = CheckPlayer(chess,r_find, c_find, "p2", "r2", "n2", "b2", "q2", "k2");
			}

			if (Move(chess, r_find, c_find)) {
				toss-=1;
			}
			/*if (!Result(chess, r_find, c_find, "k1")) {
				cout << " player Two Win the MAtch " << endl;
				break;
			}/*
			if (checkmate(chess, r_find, c_find, "k1")) {
				cout << " Check MAte  So Player Two win th match " << endl;
			}*/
		}
	}
	return 0;
}