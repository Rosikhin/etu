#include <iostream>
#include <string>
#include <Windows.h>
#include <math.h>
using namespace std;

string point[8] = { "A","B","C","D","E","F","G","H" };
int countway = 0;
int m[1048576][20];

int CircleWay(int start, int way)
{
	int x = start + way;
	if (x > 7) return 0;
	if (x < 0) return 7;

}

void go(int start, int now, int all)
{



	if (now == 1)
	{
		m[countway][all - now] = CircleWay(start, +1);

		for (int i = 0; i < all - now; i++) m[countway + 1][i] = m[countway][i];
		countway++;

		m[countway][all - now] = CircleWay(start, -1);

		for (int i = 0; i < all - now; i++) m[countway + 1][i] = m[countway][i];
		countway++;
	}
	else
	{
		m[countway][all - now] = CircleWay(start, +1);
		go(CircleWay(start, +1), now - 1, all);
		m[countway][all - now] = CircleWay(start, -1);
		go(CircleWay(start, -1), now - 1, all);
	}
}

void grasshopper(int n) // n max 18
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	
	cout << "Из точки А в точку С за N ходов" << endl << endl;
	
	int goodway = 0;
	int stone_bomb = 0;
	
	go(0, n, n);

	cout << endl << endl;

	for (int i = 0; i < pow(2, n); i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));

		if (m[i][n - 1] == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 0));
			goodway++;
		}

		for (int ii = 0; ii < n * n; ii++) if (m[i][ii] == 4 && (m[i][n-1] == 2)) //|| m[i][n - 1] == 4))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((6 << 4) | 0));
			stone_bomb++;
			break;
		}

		cout << "A";
		for (int ii = 0; ii < n; ii++) cout << " -> " + point[m[i][ii]];
		cout << endl;

		if ((i + 1) % n == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
			cout << endl;
		}

	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	cout << endl;
	cout << "Всего путей за " << n << " хода (ходов) = " << pow(2, n) << endl;
	cout << "Количество путей из А в С за " << n << " хода (ходов) = " << goodway << endl;
	cout << "Количество путей из А в С в которых есть камень в Е = " << stone_bomb << endl;
	cout << "Количество путей из А в С в которых нет камня в Е = " << goodway - stone_bomb << endl;
	cout << "Вероятность попадания на мину в Е = " << (goodway - stone_bomb) / pow(2, n);

	cout << endl << endl;
}

int main()
{
	setlocale(0, "");
	while (true)
	{
		int N;
		do {
			cout << "Введите количество вершин (от 2 до 12): ";
			cin >> N;
			if ((N > 1 && N <= 12)) grasshopper(N);
				else cout << "Неверное значение" << endl;
			
			cin.clear(); // очистка потока, чтобы не зациклилось
			cin.ignore(cin.rdbuf()->in_avail()); // очистка буфера длины in_avail
		} while (!(N > 1 && N <= 12)); // То же самое условие
	}
}
