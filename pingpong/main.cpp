#include<iostream>
#include<windows.h>
#include<conio.h>
#include <mmsystem.h >
#define BLACK 0
#define BROWN 6
#define MAGENTA 5
#define WHITE 15
#define GREEN 2
#define RED 4
#define LBLUE 9
#define YELLOW 14
using namespace std;
#pragma comment (lib, "winmm.lib")
int x2 = 12, y2 = 50;
char way = 'C';
int s = -37;
char c = s;
int n = 12;
int m = 12;
int l = 0;
int y = 0;
string player1;
string player2;
int player1score = 0;
int player2score = 0;
int k1 = 0, k2 = 0;
int totalscore;

void SetClr(int tcl, int bcl)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tcl + (bcl * 16)));
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void timer() {
	gotoRowCol(10, 45);
	cout << "---";
	gotoRowCol(11, 47);
	cout << "|";
	gotoRowCol(12, 47);
	cout << "|";
	gotoRowCol(13, 47);
	cout << "|";
	gotoRowCol(14, 45);
	cout << "---";
	gotoRowCol(15, 47);
	cout << "|";
	gotoRowCol(16, 47);
	cout << "|";
	gotoRowCol(17, 47);
	cout << "|";
	gotoRowCol(18, 45);
	cout << "---";
	gotoRowCol(30, 0);
	Sleep(1000);
	for (int i = 10; i <= 18; i++) {
		gotoRowCol(i, 45);
		cout << "    ";
		gotoRowCol(i, 47);
		cout << "    ";
	}
	gotoRowCol(10, 45);
	cout << "---";
	gotoRowCol(11, 47);
	cout << "|";
	gotoRowCol(12, 47);
	cout << "|";
	gotoRowCol(13, 47);
	cout << "|";
	gotoRowCol(14, 45);
	cout << "---";
	gotoRowCol(15, 45);
	cout << "|";
	gotoRowCol(16, 45);
	cout << "|";
	gotoRowCol(17, 45);
	cout << "|";
	gotoRowCol(18, 45);
	cout << "---";
	gotoRowCol(30, 0);
	Sleep(1000);
	for (int i = 10; i <= 18; i++) {
		gotoRowCol(i, 45);
		cout << "    ";
		gotoRowCol(i, 47);
		cout << "    ";
	}
	gotoRowCol(10, 45);
	cout << "|";
	gotoRowCol(11, 45);
	cout << "|";
	gotoRowCol(12, 45);
	cout << "|";
	gotoRowCol(13, 45);
	cout << "|";
	gotoRowCol(14, 45);
	cout << "|";
	gotoRowCol(15, 45);
	cout << "|";
	gotoRowCol(30, 0);
	Sleep(1000);
	gotoRowCol(10, 45);
	cout << " ";
	gotoRowCol(11, 45);
	cout << " ";
	gotoRowCol(12, 45);
	cout << " ";
	gotoRowCol(13, 45);
	cout << " ";
	gotoRowCol(14, 45);
	cout << " ";
	gotoRowCol(15, 45);
	cout << " ";
}
void score() {
	gotoRowCol(30, 0);
	gotoRowCol(3, 108);
	SetClr(MAGENTA, BLACK);
	cout << "Score";
	gotoRowCol(5, 103);
	SetClr(MAGENTA, BLACK);
	cout << player1;
	gotoRowCol(5, 112);
	SetClr(MAGENTA, BLACK);
	cout << player2;
	gotoRowCol(7, 105);
	SetClr(MAGENTA, BLACK);
	cout << k1;
	gotoRowCol(7, 114);
	SetClr(MAGENTA, BLACK);
	cout << k2;
}
void score1() {
	gotoRowCol(30, 0);
	gotoRowCol(10, 50);
	SetClr(MAGENTA, BLACK);
	cout << "Score";
	gotoRowCol(12, 45);
	SetClr(MAGENTA, BLACK);
	cout << player1;
	gotoRowCol(12, 55);
	SetClr(MAGENTA, BLACK);
	cout << player2;
	gotoRowCol(14, 47);
	SetClr(MAGENTA, BLACK);
	cout << k1;
	gotoRowCol(14, 57);
	SetClr(MAGENTA, BLACK);
	cout << k2;
	if (k1 == totalscore) {
		gotoRowCol(16, 48);
		SetClr(MAGENTA, BLACK);
		cout << player1 << "Wins";
	}
	if (k2 == totalscore) {
		gotoRowCol(16, 48);
		SetClr(MAGENTA, BLACK);
		cout << player2 << "Wins";
	}
}
void boared(int row, int column) {
	SetClr(BLACK, BLACK);
	system("CLS");
	for (int i = 0; i <= 100; i++) {
		SetClr(RED, BLACK);
		cout << c;
	}

	cout << endl;
	for (int i = 0; i <= 100; i++) {
		SetClr(RED, BLACK);
		cout << c;
	}

	cout << endl;
	for (int i = 0; i <= 100; i++) {
		SetClr(RED, BLACK);
		cout << c;
	}
	cout << endl;
	row = 2;
	for (int i = 0; i < 23; i++) {
		SetClr(RED, BLACK);
		cout << c;
		gotoRowCol(row, 100);
		SetClr(RED, BLACK);
		cout << c << endl;
		row = row + 1;
	}
	for (int i = 0; i <= 100; i++) {
		cout << c;
	}
	cout << endl;
	for (int i = 0; i <= 100; i++) {
		SetClr(RED, BLACK);
		cout << c;
	}
}
void initialize_ball() {
	gotoRowCol(x2, y2);
	SetClr(LBLUE, BLACK);
	cout << "O";
	gotoRowCol(30, 0);
}
void scoring() {
	gotoRowCol(x2, y2);
	cout << " ";
	gotoRowCol(30, 0);
	PlaySound(TEXT("megalovania.wav"), NULL, SND_FILENAME | SND_SYNC);
	x2 = 12, y2 = 50;
	initialize_ball();
}
void erase() {
	gotoRowCol(x2 + 1, y2 - 1);
	cout << " ";
	gotoRowCol(30, 0);
	if (l == 1) {
		Sleep(75);
	}
	else if (l == 2) {
		Sleep(50);
	}
	else if (l == 3) {
		Sleep(20);
	}
}

void erase2() {
	gotoRowCol(x2 - 1, y2 - 1);
	cout << " ";
	gotoRowCol(30, 0);
	if (l == 1) {
		Sleep(75);
	}
	else if (l == 2) {
		Sleep(50);
	}
	else if (l == 3) {
		Sleep(20);
	}
}
void erase3() {
	gotoRowCol(x2 - 1, y2 + 1);
	cout << " ";
	gotoRowCol(30, 0);
	if (l == 1) {
		Sleep(75);
	}
	else if (l == 2) {
		Sleep(50);
	}
	else if (l == 3) {
		Sleep(20);
	}
}
void erase4() {
	gotoRowCol(x2 + 1, y2 + 1);
	cout << " ";
	gotoRowCol(30, 0);
	if (l == 1) {
		Sleep(75);
	}
	else if (l == 2) {
		Sleep(50);
	}
	else if (l == 3) {
		Sleep(20);
	}
}
void erase5() {
	gotoRowCol(x2, y2 - 1);
	cout << " ";
	gotoRowCol(30, 0);
	if (l == 1) {
		Sleep(75);
	}
	else if (l == 2) {
		Sleep(50);
	}
	else if (l == 3) {
		Sleep(20);
	}
}
void erase6() {
	gotoRowCol(x2, y2 + 1);
	cout << " ";
	gotoRowCol(30, 0);
	if (l == 1) {
		Sleep(75);
	}
	else if (l == 2) {
		Sleep(50);
	}
	else if (l == 3) {
		Sleep(20);
	}
}
void boundarycheck(int x2, int y2, char& way) {
	switch (way) {
	case 'A':
		if (y2 == 99) {
			k1++;
			scoring();
		}
		else if (x2 == 3) {//
			way = 'B';
		}
		else if (x2 >= m - 3 && x2 < m && y2 == 98) {

			way = 'D';
		}
		else if (y2 == 98 && x2 <= m + 3 && x2 > m) {

			way = 'C';
		}
		else if (y2 == 98 && x2 == m) {

			way = 'F';
		}
		break;
	case 'B':
		if (y2 == 99) {
			k1++;
			scoring();

		}
		else if (x2 == 23) {
			way = 'A';
		}
		else if (x2 >= m - 3 && x2 < m && y2 == 98) {

			way = 'D';
		}
		else if (y2 == 98 && x2 <= m + 3 && x2 > m) {


			way = 'C';
		}
		else if (y2 == 98 && x2 == m) {

			way = 'F';
		}
		break;
	case 'C':
		if (y2 == 1) {
			k2++;
			scoring();
		}
		else if (x2 == 23) {//
			way = 'D';
		}
		else if (x2 >= n - 3 && x2 < n && y2 == 2) {

			way = 'A';
		}
		else if (y2 == 2 && x2 <= n + 3 && x2 > n) {

			way = 'B';//
		}
		else if (y2 == 2 && x2 == n) {

			way = 'E';
		}
		break;
	case 'D':
		if (y2 == 1) {
			k2++;
			scoring();
		}
		else if (x2 == 3) {
			way = 'C';
		}
		else if (x2 >= n - 3 && x2 < n && y2 == 2) {

			way = 'A';
		}
		else if (y2 == 2 && x2 <= n + 3 && x2 > n) {

			way = 'B';
		}
		else if (y2 == 2 && x2 == n) {
			way = 'E';
		}
		break;
	case 'E':
		if (y2 == 99) {
			k1++;
			scoring();
		}
		else if (x2 >= m - 3 && x2 < m && y2 == 98) {
			way = 'D';
		}
		else if (y2 == 98 && x2 <= m + 3 && x2 > m) {
			way = 'C';
		}
		else if (y2 == 98 && x2 == m) {
			way = 'F';
		}
		break;
	case 'F':
		if (y2 == 1) {
			k2++;
			scoring();
		}
		else if (x2 >= n - 3 && x2 < n && y2 == 2) {
			way = 'A';
		}
		else if (y2 == 2 && x2 <= n + 3 && x2 > n) {
			way = 'B';
		}
		else if (y2 == 2 && x2 == n) {

			way = 'E';
		}
		break;

	}
}
void move() {
	switch (way) {
	case 'A':
		x2--;
		y2++;
		initialize_ball();

		erase();
		boundarycheck(x2, y2, way);
		break;
	case 'B':
		x2++;
		y2++;
		initialize_ball();

		erase2();

		boundarycheck(x2, y2, way);
		break;
	case 'C':
		x2++; y2--;
		initialize_ball();

		erase3();

		boundarycheck(x2, y2, way);
		break;
	case 'D':
		x2--; y2--;
		initialize_ball();

		erase4();

		boundarycheck(x2, y2, way);
		break;
	case 'E':
		y2++;
		initialize_ball();

		erase5();

		boundarycheck(x2, y2, way);
		break;
	case 'F':
		y2--;
		initialize_ball();

		erase6();

		boundarycheck(x2, y2, way);
		break;
	}
}
void paddle1(int n, char c) {
	gotoRowCol(n, 1);
	SetClr(YELLOW, BLACK);
	cout << c;
	for (int i = n - 1; i >= n - 3; i--) {
		gotoRowCol(i, 1);
		SetClr(YELLOW, BLACK);
		cout << c;
	}
	for (int j = n + 1; j <= n + 3; j++) {
		gotoRowCol(j, 1);
		SetClr(YELLOW, BLACK);
		cout << c;
	}
}
void paddle2(int m, char c) {
	gotoRowCol(m, 99);
	SetClr(YELLOW, BLACK);
	cout << c;
	for (int i = m - 1; i >= m - 3; i--) {
		gotoRowCol(i, 99);
		SetClr(YELLOW, BLACK);
		cout << c;
	}
	for (int j = m + 1; j <= m + 3; j++) {
		gotoRowCol(j, 99);
		SetClr(YELLOW, BLACK);
		cout << c;
	}
}
int keys() {
	if (_kbhit()) {
		switch (_getch()) {
		case 72:
			return 1;
		case 80:
			return 2;
			break;
		case 'w':
			return 3;
			break;
		case 'W':
			return 3;
			break;
		case 's':
			return 4;
			break;
		case 'S':
			return 4;
			break;
		default:
			break;
		}
	}
}
void paddle_move() {
	int a = keys();
	if (a == 1) {
		if (n - 4 <= 4) {

		}
		else {
			paddle1(n, ' ');
			n = n - 3;
			paddle1(n, c);
		}
	}
	if (a == 2) {
		if (n + 3 > 23) {

		}
		else {
			paddle1(n, ' ');
			n = n + 3;
			paddle1(n, c);
		}
	}
	if (a == 3) {
		if (m - 4 <= 4) {

		}
		else {
			paddle2(m, ' ');
			m = m - 3;
			paddle2(m, c);
		}
	}
	if (a == 4) {
		if (m + 3 > 23) {

		}
		else {
			paddle2(m, ' ');
			m = m + 3;
			paddle2(m, c);
		}
	}
}
void questions() {
	cout << "Enter the difficulty level (1) for easy (2) for medium and (3) for hard" << endl;
	cin >> l;
	system("CLS");
	cout << "Enter the score limit:" << endl;
	cin >> totalscore;
	system("CLS");
	cout << "Enter the name of the first player:" << endl;
	cin >> player1;
	cout << endl << "Enter the name of the second player" << endl;
	cin >> player2;
	system("CLS");
}
void mainprogram() {
	questions();
	timer();
	int row = 0; int column = 0;
	boared(row, column);
	initialize_ball();
	paddle1(n, c);
	paddle2(m, c);
	gotoRowCol(30, 0);
	while (true) {
		if (k1 == totalscore || k2 == totalscore) {
			system("CLS");
			score1();
			k1 = 0; k2 = 0;
			gotoRowCol(25, 50);
			Sleep(3000);
			break;
		}
		score();
		paddle_move();
		move();
	}
}
int main()
{
	int u;
	mainprogram();
	while (true) {
		system("CLS");
		SetClr(WHITE, BLACK);
		system("CLS");
		cout << "Enter 1 if you wanted to play again and enter 2 for quit" << endl;
		cin >> u;
		system("CLS");
		if (u == 1) {
			mainprogram();
		}
		else {
			system("CLS");
			break;
		}
	}
	return 0;
}
