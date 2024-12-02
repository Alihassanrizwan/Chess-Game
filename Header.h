#pragma once
#include<iostream>
#include<string.h>
using namespace std;


// This is used For Insert Starting VAlues 
void FirstInput(string chess[][8], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0) {
				if ((j == 0) || (j == 7))
					chess[i][j] = "r1";
				else if ((j == 1) || (j == 6))
					chess[i][j] = "n1";
				else if ((j == 2) || (j == 5))
					chess[i][j] = "b1";
				else if (j == 3)
					chess[i][j] = "q1";
				else if (j == 4)
					chess[i][j] = "k1";
			}
			else if (i == 1)
				chess[i][j] = "p1";
			else if (i == 6)
				chess[i][j] = "p2";
			else if (i == 7) {
				if ((j == 0) || (j == 7))
					chess[i][j] = "r2";
				else if ((j == 1) || (j == 6))
					chess[i][j] = "n2";
				else if ((j == 2) || (j == 5))
					chess[i][j] = "b2";
				else if (j == 3)
					chess[i][j] = "q2";
				else if (j == 4)
					chess[i][j] = "k2";
			}
			else
				chess[i][j] = "..";
		}
	}
}
// This is used For Display 
void Start_Display(string chess[][8], int rows, int cols) {
	char c = 'A';
	cout << "     1      2      3      4      5      6      7      8" << endl;
	cout << "   _______________________________________________________" << endl;
	for (int i = 0; i < 8; i++) {
		cout << c << " ";
		c++;
		for (int j = 0; j < 8; j++) {
			cout << "|  " << chess[i][j] << "  ";
		}
		cout << "| " << "\n  |______|______|______|______|______|______|______|______|" << endl;

	}
}
// This is USed For toss Of the player which one Play first Turn 
int Toss() {

	cout << "********************* This is Chess Game ***********************" << endl;
	int toss=1+rand() % 2;
	if (toss == 1) {
		cout << "\n         ****************************" << endl;
		cout << "         * Player One Won the Toss  *" << endl;
		cout << "         * Player One Move First    *" << endl;
		cout << "         ****************************" << endl;
	}
	else {
		cout << "\n         *****************************" << endl;
		cout << "         * Player Two Won the Toss  *" << endl;
		cout << "         * Player Two Move First    *" << endl;
		cout << "         *****************************" << endl;
	}
	return toss;
}
// Chek any turn between the Range Of the Box 
bool isvlid_Turn(int r_find, int c_find) {
	if ((r_find >= 0 && r_find < 8) && (c_find >= 0 && c_find < 8)) {
		return true;
	}
	else {
		return false;
	}
}
// This si Check The Turn Of opposite player 
bool CheckPlayer(string chess[][8],int r_find, int c_find, string p, string r, string n, string b, string q, string k) {
	string index = chess[r_find][c_find];
	if ((index[1] == p[1]) || (index[1] == r[1]) || (index[1] == n[1]) || (index[1] == b[1]) || (index[1] == q[1]) || (index[1] == k[1])) {
		return true;
	}
	else {
		return false;
	}

}
// This is convert Turn Path into Find Colums and Rows 
void findColumAndRows(string turn ,int &r_find, int &c_find ) {
	int t = 0;
	for (int i = 0; turn[i] != '\0'; i++) {
		if (turn[i] > '0' && turn[i] < '9') {
			t = (turn[i]-48);
			c_find= t-1;
		}
		else {
r_find = toupper(turn[i]) - 65;
		}
	}

}
// This is used to check The Turn IS true or Not 
void CheckTurn(string turn, int& r_find, int& c_find) {

	findColumAndRows(turn, r_find, c_find);
	while (!isvlid_Turn(r_find, c_find)) {
		cout << " Your Turn is Not True(A7, B3, C8) " << endl;
		cout << " Kindly Enter AGin: ";
		cin >> turn;
		findColumAndRows(turn, r_find, c_find);
	}
}
// Enter Start Turn Of Player 
void Turn(int& r_find, int& c_find) {
	string turn;
	cout << " Enter Your Turn(A7, B3, C2): ";
	cin >> turn;
	CheckTurn(turn, r_find, c_find);
}
// Tis is Used At Last Of the Turn convert values on The Specific Index
void ValueReplace(string chess[][8], int r_find, int c_find, int mr_find, int mc_find) {
	string temp;
	temp = chess[r_find][c_find];
	chess[mr_find][mc_find] = temp;
	chess[r_find][c_find] = "..";

}
// This is used To check The lAst Turn that is True or Not 
bool check_last_index(string chess[][8], int r_find, int c_find, int mr_find, int mc_find) {
	bool flag = false;
	string token = chess[r_find][c_find];
	if ((token.compare("n1") == 0) && (chess[mr_find][mc_find] != "..")) {
		if (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"))
			flag = true;
		}
	else if ((token.compare("n1") == 0) && (chess[mr_find][mc_find] == "..")) {
		flag = true;
	}
	else if ((token.compare("n2") == 0) && (chess[mr_find][mc_find] != "..")) {
		if (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"))
			flag = true;
	}
	else if ((token.compare("n2") == 0) && (chess[mr_find][mc_find] == "..")) {
		flag = true;
	}
	if ((token.compare("r1") == 0) && (chess[mr_find][mc_find] != "..")) {
		if (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"))
			flag = true;
	}
	else if ((token.compare("r1") == 0) && (chess[mr_find][mc_find] == "..")) {
		flag = true;
	}
	else if ((token.compare("r2") == 0) && (chess[mr_find][mc_find] != "..")) {
		if (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"))
			flag = true;
	}
	else if ((token.compare("r2") == 0) && (chess[mr_find][mc_find] == "..")) {
		flag = true;
	}
	if ((token.compare("b1") == 0) && (chess[mr_find][mc_find] != "..")) {
		if (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"))
			flag = true;
	}
	else if ((token.compare("b1") == 0) && (chess[mr_find][mc_find] == "..")) {
		flag = true;
	}
	else if ((token.compare("b2") == 0) && (chess[mr_find][mc_find] != "..")) {
		if (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"))
			flag = true;
	}
	else if ((token.compare("b2") == 0) && (chess[mr_find][mc_find] == "..")) {
		flag = true;
	}
	if ((token.compare("q1") == 0) && (chess[mr_find][mc_find] != "..")) {
		if (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"))
			flag = true;
	}
	else if ((token.compare("q1") == 0) && (chess[mr_find][mc_find] == "..")) {
		flag = true;
	}
	else if ((token.compare("q2") == 0) && (chess[mr_find][mc_find] != "..")) {
		if (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"))
			flag = true;
	}
	else if ((token.compare("q2") == 0) && (chess[mr_find][mc_find] == "..")) {
		flag = true;
	}
	return flag;
}
// This is Used To check The validity Of the Pawn 
bool isValid_Rotation_of_pawn(string chess[][8], int r_find, int c_find, int mr_find, int mc_find) {
	bool flag = false;
	string pawn = chess[r_find][c_find];
	if (pawn.compare("p1") == 0) {
		if (r_find == 1) {
			if ((c_find == mc_find) && ((r_find + 1 == mr_find) || (r_find + 2 == mr_find))) {
				flag = true;
			}
			else if ((r_find + 1 == mr_find) && ((c_find - 1 == mc_find) || (c_find + 1 == mc_find))) {
				flag = CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2");
			}
			else {
				cout << " Your Move IS Invalid" << endl;
				flag = false;
			}
		}
		else if (r_find > 1 && r_find < 8) {
			if ((c_find == mc_find) && (r_find + 1 == mr_find)) {
				flag = true;
			}
			else if ((r_find + 1 == mr_find) && ((c_find - 1 == mc_find) || (c_find + 1 == mc_find))) {
				flag = CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2");
			}
			else {
				cout << " Your Move IS Invalid" << endl;
				flag = false;
			}
		}
	}
	else if (pawn.compare("p2") == 0) {
		if (r_find == 6) {
			if ((c_find == mc_find) && ((r_find - 1 == mr_find) || (r_find - 2 == mr_find))) {
				flag = true;
			}
			else if ((r_find - 1 == mr_find) && ((c_find - 1 == mc_find) || (c_find + 1 == mc_find))) {
				flag = CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1");
			}
			else {
				cout << " Your Move IS Invalid" << endl;
				flag = false;
			}
		}
		else if (r_find < 6 && r_find > 0) {
			cout << " Ali Mola" << endl;
			if ((c_find == mc_find) && (r_find - 1 == mr_find)) {
				flag = true;
			}
			else if ((r_find - 1 == mr_find) && ((c_find - 1 == mc_find) || (c_find + 1 == mc_find))) {

				flag = CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2");
			}
			else {
				cout << " Your Move IS Invalid" << endl;
				flag = false;
			}
		}
	}
	return flag;
}
// This is Used To check The path Of Rock Is Empty or Not 
bool check_Obstructing_Path_of_Rock(string chess[][8], int start_row, int start_col, int last_row, int last_col) {
	bool flag = false;
	string rock = chess[start_row][start_col];
	
		if ((start_row < last_row) && (start_col == last_col)) {
			flag = true;
			for (int i = start_row + 1; i < last_row; i++) {			
			     if (chess[i][start_col] == "..") {
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag) {
				flag=check_last_index(chess, start_row, start_col, last_row, last_col);
			}
		}
		else if ((start_row > last_row) && (start_col == last_col)) {
			flag = true;
		for (int i = last_row+1; i < start_row; i++) {
			 if (chess[i][start_col] == "..") {
				flag = true;
				}
			else {
				flag = false;
				break;
				}
		}
		if (flag) {
			flag= check_last_index(chess, start_row, start_col, last_row, last_col);
		}
	}
		else if ((start_col < last_col) && (start_row == last_row)) {
			flag = true;
		for (int i = start_col + 1; i < last_col; i++) {
			if (chess[start_row][i] == "..") {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			flag= check_last_index(chess, start_row, start_col, last_row, last_col);
		}
	}
		else if ((start_col > last_col) && (start_row == last_row)) {
			flag = true;
		for (int i = last_col+1; i < start_col; i++) {
			if (chess[start_row][i] == "..") {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			flag = check_last_index(chess, start_row, start_col, last_row, last_col);
		}
	}
		return flag;
}
// This is Used To Check The Rotation Of Rock 
bool isVAlid_Rotation_of_Rock(string chess[][8], int r_find, int c_find, int mr_find, int mc_find) {
	bool flag = false;
	if ((c_find == mc_find) || (r_find == mr_find)) {
		flag = check_Obstructing_Path_of_Rock(chess, r_find, c_find, mr_find, mc_find);
	}
	return flag;

}
// This is Used to check the validity Of knight 
bool isVAlid_Rotation_of_knight(string chess[][8], int r_find, int c_find, int mr_find, int mc_find) {
	bool flag = false;
	string knight = chess[r_find][c_find];
	if ((r_find + 2 == mr_find && c_find + 1 == mc_find) && (chess[r_find + 1][c_find] == ".." && chess[r_find + 2][c_find] == "..")) {
		flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((r_find + 2 == mr_find && c_find - 1 == mc_find)&& (chess[r_find + 1][c_find] == ".." && chess[r_find + 2][c_find] == "..")) {
		
		flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((r_find - 2 == mr_find && c_find + 1 == mc_find) && (chess[r_find - 1][c_find] == ".." && chess[r_find - 2][c_find] == "..")) {
	
		flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((r_find - 2 == mr_find && c_find - 1 == mc_find)&& (chess[r_find - 1][c_find] == ".." && chess[r_find - 2][c_find] == "..")) {
	
		flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((r_find + 1 == mr_find && c_find + 2 == mc_find) && (chess[r_find + 1][c_find] == ".." && chess[r_find + 1][c_find + 1] == "..")) {
	
		flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((r_find + 1 == mr_find && c_find - 2 == mc_find)&& (chess[r_find + 1][c_find] == ".." && chess[r_find - 1][c_find + 1] == "..")) {
		
		flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((r_find - 1 == mr_find && c_find + 2 == mc_find) && (chess[r_find - 1][c_find] == ".." && chess[r_find - 1][c_find + 1] == "..")) {
		
		flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((r_find - 1 == mr_find && c_find - 2 == mc_find)&& (chess[r_find - 1][c_find] == ".." && chess[r_find - 1][c_find - 1] == "..")) {

		flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((c_find + 2 == mc_find && r_find + 1 == mr_find) && (chess[r_find][c_find + 1] == ".." && chess[r_find][c_find + 2] == "..")){
	
	flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((c_find + 2 == mc_find && r_find - 1 == mr_find) && (chess[r_find][c_find + 1] == ".." && chess[r_find][c_find + 2] == "..")) {

	flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((c_find - 2 == mc_find && r_find + 1 == mr_find) && (chess[r_find][c_find - 1] == ".." && chess[r_find][c_find - 2] == "..")) {
	
	flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((c_find - 2 == mc_find && r_find - 1 == mr_find) && (chess[r_find][c_find - 1] == ".." && chess[r_find][c_find - 2] == "..")) {
	
	flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((c_find + 1 == mc_find && r_find + 2 == mr_find) && (chess[r_find][c_find + 1] == ".." && chess[r_find + 1][c_find +1] == "..")) {

	flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((c_find + 1 == mc_find && r_find - 2 == mr_find) && (chess[r_find][c_find + 1] == ".." && chess[r_find - 1][c_find + 1] == "..")) {
	
	flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((c_find - 1 == mc_find && r_find + 2 == mr_find) && (chess[r_find][c_find - 1] == ".." && chess[r_find + 1][c_find - 1] == "..")) {
	
	flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	else if ((c_find - 1 == mc_find && r_find - 2 == mr_find) && (chess[r_find][c_find - 1] == ".." && chess[r_find - 1][c_find - 1] == "..")) {

	flag = check_last_index(chess, r_find, c_find, mr_find, mc_find);
	}
	return flag;
}
// this is check The validity of Bishop 
bool isVAlid_Rotation_of_Bishop(string chess[][8], int r_find, int c_find, int mr_find, int mc_find) {
	bool flag = false;
	if ((mr_find - r_find == mc_find - c_find) && (mr_find-r_find)>0) {
		flag = true;
		for (int i =r_find+1, j=c_find+1; i<mr_find; i++, j++){
			if (chess[i][j] == "..") {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			flag=check_last_index(chess, r_find, c_find, mr_find, mc_find);
		}
	}
	if ((mr_find - r_find == mc_find - c_find) && (mr_find - r_find) < 0) {
		flag = true;
		for (int i = r_find-1, j = c_find-1; i > mr_find && j>mc_find; i--, j--) {
			if (chess[i][j] == "..") {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			flag=check_last_index(chess, r_find, c_find, mr_find, mc_find);
		}
	}
	else if ((-(mr_find - r_find) == (mc_find - c_find))  &&(mr_find-r_find<0) ) {
		flag = true;
		for (int i = r_find-1, j = c_find+1; i > mr_find ; i--, j++) {
			if (chess[i][j] == "..") {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			flag=check_last_index(chess, r_find, c_find, mr_find, mc_find);
		}
	}
	else if (((mr_find - r_find) == -(mc_find - c_find)) &&(mc_find-c_find<0)) {
		flag = true;
		for (int i = r_find+1, j = c_find-1; i < mr_find; i++, j--) {
			if (chess[i][j] == "..") {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			flag=check_last_index(chess, r_find, c_find, mr_find, mc_find);
		}
	}
	

	return flag;
}
// This si used To check The Validity Of queen
bool isVAlid_Rotation_of_queen(string chess[][8],int r_find,int c_find,int mr_find,int mc_find) {
	bool flag = false;
	if (isVAlid_Rotation_of_Bishop(chess, r_find, c_find, mr_find, mc_find) || isVAlid_Rotation_of_Rock(chess, r_find, c_find, mr_find, mc_find)) {
		flag = true;
	}
	return flag;
}
// Thsi is Used To check the validuty of king 
bool isVAlid_Rotation_of_king(string chess[][8],int r_find,int c_find,int mr_find,int mc_find) {
	bool flag = false;
	string king = chess[r_find][c_find];
	if (r_find + 1 == mr_find && c_find == mc_find) {
		if ((king.compare("k1") == 0)) {
			if (chess[mr_find][mc_find] != "..")
				flag = (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"));
			else
				flag = true;
		}
		else if (king.compare("k2") == 0) {
			if (chess[mr_find][mc_find] != "..")
				flag = (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"));
			else
				flag = true;
		}

	}
	else if (r_find - 1 == mr_find && c_find == mc_find) {
		if ((king.compare("k1") == 0)) {
			if (chess[mr_find][mc_find] != "..")
				flag = (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"));
			else
				flag = true;
		}
		else if (king.compare("k2") == 0) {
			if (chess[mr_find][mc_find] != "..")
				flag = (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"));
			else
				flag = true;
		}

	}
	else if (r_find == mr_find && c_find + 1 == mc_find) {
		if ((king.compare("k1") == 0)) {
			if (chess[mr_find][mc_find] != "..")
				flag = (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"));
			else
				flag = true;
		}
		else if (king.compare("k2") == 0) {
			if (chess[mr_find][mc_find] != "..")
				flag = (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"));
			else
				flag = true;
		}

	}
	else if (r_find == mr_find && c_find - 1 == mc_find) {
		if ((king.compare("k1") == 0)) {
			if (chess[mr_find][mc_find] != "..")
				flag = (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"));
			else
				flag = true;
		}
		else if (king.compare("k2") == 0) {
			if (chess[mr_find][mc_find] != "..")
				flag = (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"));
			else
				flag = true;
		}
	}
	return flag;
}

// This is Check and display The Result Of the Game 
bool Result(string chess[][8], int r_find, int c_find, string key) {
	bool flag = false;
	string index;
	for (int i = 0; i < r_find; i++) {
		for (int j = 0; j < c_find; j++) {
			index = chess[i][j];
			if (index.compare(key) == 0) {
				flag= true;
				break;
			}
			else {
				flag = false;
			}
		}
	}
	return flag;
}


// This is used To Check The  Move where turn will Land 
bool Move(string chess[][8], int r_find, int c_find) {
	bool flag = false;
	string move;
	string token = chess[r_find][c_find];
	int mr_find, mc_find;
	cout << " Where You want To Move: ";
	cin >> move;
	CheckTurn(move, mr_find, mc_find);
	//cout << " Value of Token IS: " << token << endl;
	if ((token.compare("p1")==0) || (token.compare("p2")==0)) {
		cout << " Condition 1" << endl;
		if (isValid_Rotation_of_pawn(chess, r_find, c_find, mr_find, mc_find)) {
			ValueReplace(chess, r_find, c_find, mr_find, mc_find);
			Start_Display(chess, 8, 8);
			flag = true;
		}
		else
			cout << " Your Move IS Inavlid" << endl;
	}
	else if ((token.compare("r1") == 0) || (token.compare("r2") == 0)) {
		cout << " Condition 2" << endl;
		if (isVAlid_Rotation_of_Rock(chess, r_find, c_find, mr_find, mc_find)) {
			ValueReplace(chess, r_find, c_find, mr_find, mc_find);
			Start_Display(chess, 8, 8);
			flag = true;
		}
		else {
			cout << " Your Move IS Invalid" << endl;
			flag = false;
		}
	}
	else if ((token.compare("n1") == 0) || (token.compare("n2") == 0)) {
		cout << " Condition 3" << endl;
		if (isVAlid_Rotation_of_knight(chess, r_find, c_find, mr_find, mc_find)) {
			ValueReplace(chess, r_find, c_find, mr_find, mc_find);
			Start_Display(chess, 8, 8);
			flag = true;
		}
		else {
			cout << " Your Move IS INvalid" << endl;
			flag = false;
		}
	}
	else if ((token.compare("b1") == 0) || (token.compare("b2") == 0)) {
		cout << " Condition 4" << endl;
		if (isVAlid_Rotation_of_Bishop(chess, r_find, c_find, mr_find, mc_find)) {
			ValueReplace(chess, r_find, c_find, mr_find, mc_find);
			Start_Display(chess, 8, 8);
			flag = true;
		}
		else {
			cout << " Your Move is Invalid" << endl;
			flag = false;
		}
	}
	else if ((token.compare("q1") == 0) || (token.compare("q2") == 0)) {
		if (isVAlid_Rotation_of_queen(chess, r_find, c_find, mr_find, mc_find)) {
			ValueReplace(chess, r_find, c_find, mr_find, mc_find);
			Start_Display(chess, 8, 8);
			flag = true;
		}
		else {
			cout << " Your Move is Invalid" << endl;
			flag = false;
		}
	}
	else if ((token.compare("k1") == 0) || (token.compare("k2") == 0)) {
		cout << " Condition 5" << endl;
		if (isVAlid_Rotation_of_king(chess, r_find, c_find, mr_find, mc_find)) {
			ValueReplace(chess, r_find, c_find, mr_find, mc_find);
			Start_Display(chess, 8, 8);
			flag = true;
		}
		else {
			cout << " Your Move is Invalid" << endl;
			flag = false;
		}
	}
	return flag;
}
void findrowandcolum_for_check_mate(string chess[][8],int r_find, int c_find, int& row, int& col,string key) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (key == chess[i][j]) {
				row = i;
				col = j;
			}
		}
	}
}
bool checkmate(string chess[][8], int row, int col, string king) {
	int r_find = 0;
	int c_find= 0;
	int mr_find=0;
	int mc_find=0;
	findrowandcolum_for_check_mate(chess, 8, 8, r_find, c_find,king);
	bool pawn = isValid_Rotation_of_pawn(chess, r_find, c_find, mr_find, mc_find);
	bool rock = isVAlid_Rotation_of_Rock(chess, r_find, c_find, mr_find, mc_find);
	bool knight= isVAlid_Rotation_of_knight(chess, r_find, c_find, mr_find, mc_find);
	bool bishop= isVAlid_Rotation_of_Bishop(chess, r_find, c_find, mr_find, mc_find);
	bool queen= isVAlid_Rotation_of_queen(chess, r_find, c_find, mr_find, mc_find);
	bool king1= isVAlid_Rotation_of_king(chess, r_find, c_find, mr_find, mc_find);

	if (pawn || rock || knight || bishop || queen || king1) {
		return true;
	}

}



//bool check_last_index_of_Bishop(string chess[][8], int r_find, int c_find, int mr_find, int mc_find) {
//	bool flag = false;
//	string bishop = chess[r_find][c_find];
//	if ((bishop.compare("b1") == 0) && (chess[mr_find][mc_find] != "..")) {
//		if (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"))
//			flag = true;
//	}
//	else if ((bishop.compare("b1") == 0) && (chess[mr_find][mc_find] == "..")) {
//		flag = true;
//	}
//	else if ((bishop.compare("b2") == 0) && (chess[mr_find][mc_find] != "..")) {
//		if (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"))
//			flag = true;
//	}
//	else if ((bishop.compare("b2") == 0) && (chess[mr_find][mc_find] == "..")) {
//		flag = true;
//	}
//	if ((bishop.compare("q1") == 0) && (chess[mr_find][mc_find] != "..")) {
//		if (CheckPlayer(chess, mr_find, mc_find, "p2", "r2", "n2", "b2", "q2", "k2"))
//			flag = true;
//	}
//	else if ((bishop.compare("q1") == 0) && (chess[mr_find][mc_find] == "..")) {
//		flag = true;
//	}
//	else if ((bishop.compare("q2") == 0) && (chess[mr_find][mc_find] != "..")) {
//		if (CheckPlayer(chess, mr_find, mc_find, "p1", "r1", "n1", "b1", "q1", "k1"))
//			flag = true;
//	}
//	else if ((bishop.compare("q2") == 0) && (chess[mr_find][mc_find] == "..")) {
//		flag = true;
//	}
//	return flag;
//}
