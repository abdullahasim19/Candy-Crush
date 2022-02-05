#include <iostream>
#include<ctime>
#include"mygraphics.h"
#include"myconsole.h"
#include<conio.h>
#include <cstdlib>
#include<fstream>
using namespace std;
void checkscore(int arr[][50], int n, int& score)
{
	if (n == 1)
		score = score + 90;
	else if (n == 2)
		score = score + 90;
	else if (n == 3)
		score = score + 160;
	else if (n == 4)
		score = score + 150;
	else if (n == 5)
		score = score + 180;
}
void candysearch(int arr[][50], int n)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == n)
				arr[i][j] = { 0 };
		}
	}
}
void shifting(int arr[][50])
{
	srand(time(NULL));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 0)
			{
				for (int k = i; k > 0; k--)
					arr[k][j] = arr[k - 1][j];
				arr[0][j] = rand() % 5 + 1;
			}
		}
	}

}
void drawBoard(int board[][50])
{
	int rows, columns, randomNumber, flag;
	srand(time(NULL));
	for (rows = 0; rows < 9; rows++)
	{
		for (columns = 0; columns < 9; columns++)
		{
			flag = 0;
			do
			{
				randomNumber = rand() % 5 + 1;
				board[rows][columns] = randomNumber;
				if (board[rows][columns] == board[rows - 1][columns] || board[rows][columns] == board[rows][columns - 1])
				{
					flag = 0;
					continue;
				}
				else
				{
					flag = 1;

				}
			} while (flag == 0);
		}
	}
}
void check(int arr[][50], bool& flag, int& score)
{
	flag = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				arr[i][j] = { 0 };
				arr[i][j + 1] = { 0 };
				arr[i][j + 2] = { 0 };
				shifting(arr);
				flag = true;
			}
			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				arr[i][j] = { 0 };
				arr[i + 1][j] = { 0 };
				arr[i + 2][j] = { 0 };
				flag = true;
				shifting(arr);
			}
		}
	}
}

void print(int arr[][50])
{
	int x1 = 10, x2 = 50, y1 = 0, y2 = 30;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			switch (arr[i][j])
			{
			case 1:
				myEllipse(x1, y1, x2, y2, RGB(0, 0, 0), RGB(0, 0, 240));//Blue
				break;
			case 2:
				myEllipse(x1, y1, x2, y2, RGB(0, 0, 0), RGB(0, 255, 0));//Green
				break;
			case 3:
				myEllipse(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 140, 0));//Orange
				break;
			case 4:
				myEllipse(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 255, 0));//Yellow
				break;
			case 5:
				myEllipse(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 0, 0));//Red
				break;
			case 6:
				myEllipse(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 105, 180));//pink
				break;
			}
			x1 = x2;
			x2 = x2 + 40;
		}
		x1 = 10; x2 = 50;
		y1 = y2; y2 = y2 + 30;
	}
		cout << endl << endl;
	
}
void stripecandy(int arr[][50], bool& flag, int& score)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j])
			{
				flag = true;
				arr[i][j] = { 6 };
				arr[i + 1][j] = { 0 };
				arr[i + 2][j] = { 0 };
				arr[i + 3][j] = { 0 };
				shifting(arr);
			}
			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
			{
				flag = true;
				arr[i][j] = { 6 };
				arr[i][j + 1] = { 0 };
				arr[i][j + 2] = { 0 };
				arr[i][j + 3] = { 0 };
				shifting(arr);
			}
		}
	}
}
void wrapcandy(int arr[][50], bool& flag, int& score)
{
	flag = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j + 1] == arr[i + 1][j] && arr[i][j + 1] == arr[i + 2][j])
			{
				flag = true;
				arr[i][j] = { 7 };
				arr[i][j + 1] = { 0 };
				arr[i][j + 2] = { 0 };
				arr[i + 1][j] = { 0 };
				arr[i + 2][j] = { 0 };
				shifting(arr);
			}
		}
	}
}
void colourbomb(int arr[][50], bool& flag, int& score)
{
	flag = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4])
			{
				flag = true;
				arr[i][j] = { 10 };
				arr[i][j + 1] = { 0 };
				arr[i][j + 2] = { 0 };
				arr[i][j + 3] = { 0 };
				arr[i][j + 4] = { 0 };
				shifting(arr);
			}
		}
	}
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			if (arr[a][b] == arr[a + 1][b] && arr[a][b] == arr[a + 2][b] && arr[a][b] == arr[a + 3][b] && arr[a][b] == arr[a + 4][b])
			{
				flag = true;
				arr[a][b] = { 10 };
				arr[a + 1][b] = { 0 };
				arr[a + 2][b] = { 0 };
				arr[a + 3][b] = { 0 };
				arr[a + 4][b] = { 0 };
				shifting(arr);
			}
		}
	}
}
void stripeclear(int arr[][50])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 6 && arr[i][j + 1] == arr[i][j + 2])
			{
				for (int k = i, l = 0; l < 9; l++)
					arr[i][l] = { 0 };
				for (int a = j, b = 0; b < 9; b++)
					arr[b][a] = { 0 };
				shifting(arr);
			}

		}
	}
}
void twocolourbomb(int arr[][50])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 10 && arr[i][j + 1] == 10)
				drawBoard(arr);
		}
	}
}
void bombsamecandy(int arr[][50], int n)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 10)
			{
				arr[i][j] = { 0 };
				if (n == 1)
					candysearch(arr, arr[i][j + 1]);
				else if (n == 2)
					candysearch(arr, arr[i][j - 1]);
				else if (n == 3)
					candysearch(arr, arr[i - 1][j]);
				else if (n == 4)
					candysearch(arr, arr[i + 1][j]);
			}
			shifting(arr);
		}
	}
}
void stripecolourbomb(int arr[][50])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 6 && arr[i][j + 1] == 10)
			{
				for (int k = i, l = 0; l < 9; l++)
					arr[i][l] = { 0 };
				for (int a = j, b = 0; b < 9; b++)
					arr[b][a] = { 0 };
				shifting(arr);
			}

		}
	}
}
void wrapcolourbomb(int arr[][50])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 10 && arr[i][j + 1] == 7)
			{
				for (int a = i, b = 0; b < 3; b++)
					arr[a][b] = { 0 };

			}
		}
	}
}
void againcheck(int arr[][50], bool& flag, int& score)
{
	check(arr, flag, score);
	shifting(arr);
}
//1Red=30 2yellow=30 3green=40 4blue=50 5orange=60 6stripe 7wrap 10bomb
int main()
{
	ifstream fin;
	ofstream fout;
	int i = 0;
	char rep;
	int moves = 20;
	int score = 0;
	/*cout << "To load game press L or to start new game press S\n";*/
	/*cin >> rep;
	while (rep != 'S' && rep != 'L')
	{
		cout << "Invalid input\n";
		cin >> rep;
	}
	if (rep == 'S')
	{
		i = 0;
		score = 0;
		moves = 20;
	}
	else if (rep == 'L')
	{
		fin.open("Data.txt");
		if (fin)
		{
			fin >> i;
			fin >> score;
			fin >> moves;
		}
		else
			cout << "No save game found\n";
		fin.close();
	}*/
	int arr[50][50];
	int targetscore = 500;
	int n;
	bool flag;
	int a = 0, b = 0;
	/*cout << "Target score: " << targetscore << endl;
	cout << "Score: " << score << endl;
	cout << "Moves remaining: " << moves << endl;*/
	drawBoard(arr);
	/*PlaceCursor(15, 15);*/
	print(arr);
	for (; i < 20; i++)
	{
		/*cout << "Enter the row of candy you want to move\n";*/
		cin >> a;
		while (a < 1 || a > 9)
		{
			cout << "Invalid input\n";
			cin >> a;
		}
		a--;
		/*cout << "Enter the column of candy you want to move\n";*/
		cin >> b;
		while (b < 1 || b>9)
		{
			cout << "Invalid input\n";
			cin >> b;
		}
		b--;
		/*cout << "To move candy right press 1\nTo move candy left press 2\nTo move candy up press 3\nTo move candy down press 4\n";
		cout << "Press 5 to save the game\n";*/
		cin >> n;
		while (n < 1 || n>5)
		{
			cout << "Invalid input\n";
			cin >> n;
		}
		if (n == 1)
		{
			moves--;
			swap(arr[a][b], arr[a][b + 1]);
			colourbomb(arr, flag, score);
			bombsamecandy(arr, n);
			twocolourbomb(arr);
			wrapcandy(arr, flag, score);
			stripecandy(arr, flag, score);
			stripecolourbomb(arr);
			stripeclear(arr);
			check(arr, flag, score);
			if (flag == false)
				swap(arr[a][b + 1], arr[a][b]);
			else
				checkscore(arr, arr[a][b], score);
			againcheck(arr, flag, score);
			system("cls");
			againcheck(arr, flag, score);
			/*cout << "Target score: " << targetscore << endl;
			cout << "Score: " << score << endl;
			cout << "Moves remaining: " << moves << endl;*/
			print(arr);
		}
		else if (n == 2)
		{
			moves--;
			swap(arr[a][b], arr[a][b - 1]);
			colourbomb(arr, flag, score);
			bombsamecandy(arr, n);
			twocolourbomb(arr);
			wrapcandy(arr, flag, score);
			stripecandy(arr, flag, score);
			stripecolourbomb(arr);
			stripeclear(arr);
			check(arr, flag, score);
			if (flag == false)
				swap(arr[a][b - 1], arr[a][b]);
			else
				checkscore(arr, arr[a][b], score);
			system("cls");
			againcheck(arr, flag, score);
			/*cout << "Target score: " << targetscore << endl;
			cout << "Score: " << score << endl;
			cout << "Moves remaining: " << moves << endl;*/
			print(arr);
		}
		else if (n == 3)
		{
			moves--;
			swap(arr[a][b], arr[a - 1][b]);
			colourbomb(arr, flag, score);
			bombsamecandy(arr, n);
			twocolourbomb(arr);
			wrapcandy(arr, flag, score);
			stripecandy(arr, flag, score);
			stripecolourbomb(arr);
			stripeclear(arr);
			check(arr, flag, score);
			if (flag == false)
				swap(arr[a - 1][b], arr[a][b]);
			else
				checkscore(arr, arr[a][b], score);
			system("cls");
			againcheck(arr, flag, score);
			/*cout << "Target score: " << targetscore << endl;
			cout << "Score: " << score << endl;
			cout << "Moves remaining: " << moves << endl;*/
			print(arr);
		}
		else if (n == 4)
		{
			moves--;
			swap(arr[a][b], arr[a + 1][b]);
			colourbomb(arr, flag, score);
			bombsamecandy(arr, n);
			twocolourbomb(arr);
			wrapcandy(arr, flag, score);
			stripecandy(arr, flag, score);
			stripecolourbomb(arr);
			stripeclear(arr);
			check(arr, flag, score);
			if (flag == false)
				swap(arr[a + 1][b], arr[a][b]);
			else
				checkscore(arr, arr[a][b], score);
			system("cls");
			againcheck(arr, flag, score);
			/*cout << "Target score: " << targetscore << endl;
			cout << "Score: " << score << endl;
			cout << "Moves remaining: " << moves << endl;*/
			print(arr);
		}
		else if (n == 5)
		{
			fout.open("Data.txt");
			fout << i << endl;
			fout << score << endl;
			fout << moves << endl;
			fout.close();
			break;
		}
	}
	if (score >= 500)
		cout << "You win\n";
	else
		cout << "You loose\n";
}
