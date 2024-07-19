#include <iostream>
#include <fstream>
#include <conio.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int h1 = 0, h2 = 0, v1 = 0, v2 = 0, d1 = 0, d2 = 0;
int rows[15]{}, columns[15]{};
void inputTeleword(char a[][15], char b[])
{
	ifstream tinput;
	tinput.open("teleword_1.txt");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			tinput >> a[i][j];//Input to 2D array
		}
	}
	for (int i = 0; i < 500; i++)//Input to 1D array
	{
		if (b[i + 1] == '.')
			break;
		tinput >> b[i];
	}
	//Console Output When Program Starts
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n";
	int Whiff = 1;
	for (int i = 0; i < 500; i++)
	{
		cout << b[i];
		if (b[i] == ',')
		{
			cout << " ";

		}
		if (Whiff > 80 && b[i] == ',')
		{
			cout << endl;
			Whiff = 1;
		}
		if (b[i] == '.')
			break;
		Whiff++;

	}
	cout << "\n\n";
	for (int i = 0; i < 500; i++)//Convert to Uppercase
	{
		if (b[i] >= 'a' && b[i] <= 'z')
			b[i] = b[i] - 32;
	}
}
bool HorizontalLR(char teleword[][15], char word[], int coloring[][15], int x, int z, int k)
{
	//Find Horizontally from Left To Right
	bool flag = false;
	int y = 0;
	while (word[k + y] != ',' && word[k + y] != '.')
	{
		if (teleword[x][z + y] == word[k + y])
		{
			flag = true;
			y++;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	if (flag == 1)
	{
		rows[x]++;
		y = 0;
		while (word[k + y] != ',' && word[k + y] != '.')
		{
			columns[z + y]++;
			if (teleword[x][z + y] == word[k + y])
			{
				coloring[x][z + y]++;
				y++;
			}
		}
	}
	return flag;
}
bool HorizontalRL(char teleword[][15], char word[], int coloring[][15], int x, int z, int k)
{
	//Search Horizontally from Right to left.
	bool flag = false;
	int y = 0;
	while (word[k + y] != ',' && word[k + y] != '.')
	{
		if (teleword[x][z - y] == word[k + y])
		{
			flag = true;
			y++;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	if (flag == 1)
	{
		rows[x]++;
		y = 0;
		while (word[k + y] != ',' && word[k + y] != '.')
		{
			columns[z - y]++;
			if (teleword[x][z - y] == word[k + y])
			{
				coloring[x][z - y]++;
				y++;
			}
		}
	}
	return flag;
}
bool VerticalUD(char teleword[][15], char word[], int coloring[][15], int x, int z, int k)
{
	//Search Vertically from Up To Down
	bool flag = false;
	int y = 0;
	while (word[k + y] != ',' && word[k + y] != '.')
	{
		if (teleword[x + y][z] == word[k + y])
		{
			flag = true;
			y++;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	if (flag == 1)
	{
		columns[z]++;
		y = 0;
		while (word[k + y] != ',' && word[k + y] != '.')
		{
			if (teleword[x + y][z] == word[k + y])
			{
				rows[x + y]++;
				coloring[x + y][z]++;
				y++;
			}
		}
	}
	return flag;
}
bool VerticalDU(char teleword[][15], char word[], int coloring[][15], int x, int z, int k)
{
	//Search Vertically from Down to Up
	bool flag = false;
	int y = 0;
	while (word[k + y] != ',' && word[k + y] != '.')
	{
		if (teleword[x - y][z] == word[k + y])
		{
			flag = true;
			y++;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	if (flag == 1)
	{
		columns[z]++;
		y = 0;
		while (word[k + y] != ',' && word[k + y] != '.')
		{

			if (teleword[x - y][z] == word[k + y])
			{
				rows[x - y]++;
				coloring[x - y][z]++;
				y++;
			}
		}
	}
	return flag;
}
bool DiagonalUDLR(char teleword[][15], char word[], int coloring[][15], int x, int z, int k)
{
	//Search Diagonally From Up To Down(Left to Right)
	bool flag = false;
	int y = 0;
	while (word[k + y] != ',' && word[k + y] != '.')
	{
		if (teleword[x + y][z + y] == word[k + y])
		{
			flag = true;
			y++;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	if (flag == 1)
	{
		y = 0;
		while (word[k + y] != ',' && word[k + y] != '.')
		{
			rows[x + y]++;
			columns[z + y]++;
			if (teleword[x + y][z + y] == word[k + y])
			{
				coloring[x + y][z + y]++;
				y++;
			}
		}
	}
	return flag;
}
bool DiagonalUDRL(char teleword[][15], char word[], int coloring[][15], int x, int z, int k)
{
	//Search Diagonally from Up To Down(Right to Left)
	bool flag = false;
	int y = 0;
	while (word[k + y] != ',' && word[k + y] != '.')
	{
		if (teleword[x + y][z - y] == word[k + y])
		{
			flag = true;
			y++;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	if (flag == 1)
	{
		y = 0;
		while (word[k + y] != ',' && word[k + y] != '.')
		{
			rows[x + y]++;
			columns[z - y]++;
			if (teleword[x + y][z - y] == word[k + y])
			{
				coloring[x + y][z - y]++;
				y++;
			}
		}
	}
	return flag;
}
bool DiagonalDULR(char teleword[][15], char word[], int coloring[][15], int x, int z, int k)
{
	//Search Diagonally from Down To Up(Left to Right)
	bool flag = false;
	int y = 0;
	while (word[k + y] != ',' && word[k + y] != '.')
	{
		if (teleword[x - y][z + y] == word[k + y])
		{
			flag = true;
			y++;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	if (flag == 1)
	{
		y = 0;
		while (word[k + y] != ',' && word[k + y] != '.')
		{
			rows[x - y]++;
			columns[z + y]++;
			if (teleword[x - y][z + y] == word[k + y])
			{
				coloring[x - y][z + y]++;
				y++;
			}
		}
	}
	return flag;
}

bool DiagonalDURL(char teleword[][15], char word[], int coloring[][15], int x, int z, int k)
{
	//Search Diagonally from Down To Up(Right to Left)
	bool flag = false;
	int y = 0;
	while (word[k + y] != ',' && word[k + y] != '.')
	{
		if (teleword[x - y][z - y] == word[k + y])
		{
			flag = true;
			y++;
		}
		else
		{
			flag = false;
			return flag;
		}
	}
	if (flag == 1)
	{
		y = 0;
		while (word[k + y] != ',' && word[k + y] != '.')
		{
			rows[x - y]++;
			columns[z - y]++;
			if (teleword[x - y][z - y] == word[k + y])
			{
				coloring[x - y][z - y]++;
				y++;
			}
		}
	}
	return flag;
}
void Display(int coloring[][15], char teleword[][15])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (coloring[i][j] == 0)
				cout << "\033[37m" << teleword[i][j] << " ";
			if (coloring[i][j] == 1)
				cout << "\033[33m" << teleword[i][j] << " ";
			if (coloring[i][j] == 2)
				cout << "\033[34m" << teleword[i][j] << " ";
			if (coloring[i][j] > 2)
				cout << "\033[31m" << teleword[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\033[37m";
}
void WordDistribution(int h1, int h2, int v1, int v2, int d1, int d2)
{
	cout << endl << "Word Distribution: " << "   " << "Horizontal: " << h1 + h2 << "(" << h1 << ", " << h2 << ")";
	cout << "   " << "Vertical: " << v1 + v2 << "(" << v1 << "," << v2 << ")";
	cout << "   " << "Diagonal: " << d1 + d2 << "(" << d1 << "," << d2 << ")";
}
void searchLetter(char teleword[][15], char word[], int coloring[][15], int comma[], int& numWords, char option)
{
	//initializing color grid to zero
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			coloring[i][j] = 0;
		}
	}
	int k = 0, x = 0, z = 0, c = 1; numWords = 1;
	comma[0] = 0;
	for (int i = 0; i < 400; i++)
	{
		if (word[i] == ',' || word[i] == '.')
		{
			comma[numWords] = i + 1;
			numWords++;
		}
	}
	int test = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (test>0 && option == 'T')
			{
				test = 0;
				int vape = comma[c - 2];
				Display(coloring, teleword);
				cout << "\nword checked: ";
				for (vape + 1; vape < comma[c - 1] - 1; vape++)
				{
					cout << word[vape];
				}
				cout << endl;
				_getch();
				system("cls");
			}
			if (teleword[i][j] == word[k])
			{
				if (teleword[i][j + 1] == word[k + 1])
				{
					bool cond = HorizontalLR(teleword, word, coloring, i, j, k);
					if (cond)
					{
						k = comma[c];
						c++;
						i = 0; j = -1;
						test++;
						h1++;
					}
				}
				if (teleword[i][j - 1] == word[k + 1])
				{
					bool cond = HorizontalRL(teleword, word, coloring, i, j, k);
					if (cond)
					{
						k = comma[c];
						c++;
						i = 0; j = -1;
						test++;
						h2++;
					}
				}
				if (teleword[i + 1][j] == word[k + 1])
				{
					bool cond = VerticalUD(teleword, word, coloring, i, j, k);
					if (cond)
					{
						k = comma[c];
						c++;
						i = 0; j = -1;
						test++;
						v1++;
					}
				}
				if (teleword[i - 1][j] == word[k + 1])
				{
					bool cond = VerticalDU(teleword, word, coloring, i, j, k);
					if (cond)
					{
						k = comma[c];
						c++;
						test++;
						i = 0; j = -1;
						v2++;
					}
				}
				if (teleword[i + 1][j + 1] == word[k + 1])
				{
					bool cond = DiagonalUDLR(teleword, word, coloring, i, j, k);
					if (cond)
					{
						k = comma[c];
						c++;
						test++;
						i = 0; j = -1;
						d1++;
					}
				}
				if (teleword[i + 1][j - 1] == word[k + 1])
				{
					bool cond = DiagonalUDRL(teleword, word, coloring, i, j, k);
					if (cond)
					{
						k = comma[c];
						c++;
						test++;
						i = 0; j = -1;
						d2++;
					}
				}
				if (teleword[i - 1][j + 1] == word[k + 1])
				{
					bool cond = DiagonalDULR(teleword, word, coloring, i, j, k);
					if (cond)
					{
						k = comma[c];
						c++;
						test++;
						i = 0; j = -1;
						d1++;
					}
				}
				if (teleword[i - 1][j - 1] == word[k + 1])
				{
					bool cond = DiagonalDURL(teleword, word, coloring, i, j, k);
					if (cond)
					{
						k = comma[c];
						c++;
						test++;
						i = 0; j = -1;
						d2++;
					}
				}
			}
		}
	}
}
void telewordFinder(char teleword[][15], int coloring[][15], char tele[])
{
	int k = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (coloring[i][j] == 0)
			{
				tele[k] = teleword[i][j];
				k++;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (i != 0)
			tele[i] += 32;
	}
	cout << endl << "The teleword is: ";
	for (int i = 0; i < k; i++)
		cout << tele[i];
}
void Statistics(char teleword[][15], int coloring[][15], char word[], int comma[], int numWords, char tele[])
{
	int temp1 = 0, temp2 = 0, r, c;
	int row_scatter = 0, temp = -1, longe = -333, shorte = 999;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (coloring[i][j] == 0)
			{
				if (i > temp)
				{
					row_scatter++;
					temp = i;
				}
			}
		}
		if (rows[i] > temp1)
		{
			temp1 = rows[i];
			r = i;
		}
		if (columns[i] > temp2)
		{
			temp2 = columns[i];
			c = i;
		}
	}
	numWords -= 1;
	for (int i = 0; i < numWords; i++)
	{
		if (shorte > comma[i + 1] - comma[i])
		{
			shorte = comma[i + 1] - comma[i];
		}
		if (longe < comma[i + 1] - comma[i])
		{
			longe = comma[i + 1] - comma[i];
		}
	}
	int sum = 0;
	for (int i = 0; i < numWords; i++)
	{
		cout << comma[i] << " ";
		if (i != numWords - 1)
			sum += comma[i + 1] - comma[i];
	}
	cout << endl << "Teleword Scatter: " << row_scatter;
	WordDistribution(h1, h2, v1, v2, d1, d2);
	cout << "\nLongest Word Length: " << longe - 1 << endl;
	cout << "Shortest Word Length: " << shorte - 1 << endl;
	cout << "Average Word Length: " << (sum-numWords)/ (numWords-1);
	cout << "\nHeaviest row is: " << r;
	cout << "\nHeaviest column is : " << c;
}
int main()
{
	char teleword[15][15], word[500], tele[100], option;
	int coloring[15][15], comma[400], numWords;
	inputTeleword(teleword, word);
	cout << "1.Press S to solve the puzzle at once.\n2.Press T to solve the puzzle step by step\n3.Press X to print puzzle statistics.\n";
	cin >> option;
	while (option != 'S' && option != 'T' && option != 'X')
	{
		cout << "Please enter valid option!\n";
		cin >> option;
	}
	system("cls");
	auto start = high_resolution_clock::now();
	searchLetter(teleword, word, coloring, comma, numWords, option);
	auto stop = high_resolution_clock::now();
	if (option == 'S' || option == 'T')
	{
		Display(coloring, teleword);
		telewordFinder(teleword, coloring, tele);
	}
	if (option == 'X')
	{
		auto duration = duration_cast<microseconds>(stop - start);
		Display(coloring, teleword);
		telewordFinder(teleword, coloring, tele);
		cout << "\n\nTime taken: " << duration.count() << " microseconds";
		Statistics(teleword, coloring, word, comma, numWords, tele);
	}
	cout << endl;
}