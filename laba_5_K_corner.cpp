#include <iostream>
#include <string>
#include <Windows.h>
#include <math.h>
using namespace std;


int countway = 0;
int m[1048576][20];
int x = 0, y = 0, z = 0, k = 0;


int CircleWay(int start, int way)
{
	int a = start + way;
	int res = k-1;

	if (a > res) return 0;
	if (a < 0) return res;

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


	int goodway = 0;
	int stone_bomb = 0;

	go(x, n, n);

	cout << endl << endl;

	for (int i = 0; i < pow(2, n); i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));

		if (m[i][n - 1] == y)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 0));
			goodway++;
		}

		for (int ii = 0; ii < n * n; ii++) if (m[i][ii] == z && (m[i][n - 1] == y)) //|| m[i][n - 1] == z))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((6 << 4) | 0));
			stone_bomb++;
			break;
		}

		cout << x;
		for (int ii = 0; ii < n; ii++) cout << " -> " + to_string(m[i][ii]);
		cout << endl;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	cout << endl;
	cout << "Всего путей за = " << pow(2, n) << endl;
	cout << "Количество путей в Y = " << goodway << endl;
	cout << "Количество путей в которых есть камень = " << stone_bomb << endl;
	cout << "Количество путей в которых нет камня = " << goodway - stone_bomb << endl;
	cout << "Вероятность попадания на мину = " << (goodway - stone_bomb) / pow(2, n);

	cout << endl << endl;
}



int main()
{
	setlocale(0, "");
	while (true)
	{
		int N;
		
		
		N = 6 ;
		x = 0;
		y = 2;
		z = 4;
		k = 12;

		cout << "Начальные значения: " << endl << "N (шагов)= " << N << " x(начальная)= " << x << " y(конечная)= " << y <<" z(камень, мина)= " << z << " k(угольник)= " << k << endl;



		grasshopper(N);
		system("pause");
		
		/*do {
			cout << "Введите количество прыжков (N) (от 2 до 12): ";
			cin >> N;
			if ((N > 1 && N <= 12))
			{
				cout << "Введите начальную вершину (X): "; cin >> x;
				cout << "Введите конечную вершину (Y): "; cin >> y;
			    cout << "Введите вершину c камнем и миной (Z): "; cin >> z;
				cout << "Введите размер угольника (K): "; cin >> k;
				
				grasshopper(N);

			}
			else cout << "Неверное значение" << endl;

			cin.clear(); // очистка потока, чтобы не зациклилось
			cin.ignore(cin.rdbuf()->in_avail()); // очистка буфера длины in_avail
		} while (!(N > 1 && N <= 12)); // То же самое условие
		*/


	}
}
