#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <ctime>

using namespace std;
int menuPosition = 0;
string globaluser = "UserN";

string perevod(int chislo)
{
	int i = 0, x, b[32];
	string str = "";

	x = chislo;
	for (int ii = 0; ii < 32; ii++) b[ii] = 0;

	i = 0;
	while (x != 0)
	{
		b[i] = x % 2;
		x = x / 2;
		i++;
	}

	str += std::to_string(b[31]);
	for (int i = 30; i >= 0; i--) str += std::to_string(b[i]);

	
	return str;
}

void LoadMatrixFromFile(int* m, int* msize)
{

	string s, ss;
	ifstream file("matrix.txt");

	if (file)
	{
		string s;
		int i = 0;
		do
		{
			getline(file, s);
			m[i] = atoi(s.c_str());
			i++;
		
		} while (!file.eof());
		*msize = i;
	}
	else cout << "Ошибка открытия файла.";
	
}

void ShowFlag()
{
	int m[11][13] = {
	{0,0,0,0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,1,0,0,1,0,0},
	{0,0,0,1,1,1,0,1,0,1,1,1,0},
	{0,0,0,0,1,0,0,1,0,0,1,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,1,0,0,1,0,0},
	{0,0,0,1,1,1,0,1,0,1,1,1,0},
	{0,0,0,0,1,0,0,1,0,0,1,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0},
	};


	for (int y = 0; y < 11; y++)
	{
		
		for (int x = 0; x < 13; x++)
		{
			if (m[y][x]==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 4));
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
			cout << "#";
		}
			cout << endl;
	}

	cout << endl;
	cout << endl;
	for (int y = 0; y < 3; y++)
	{

		for (int x = 0; x < 13; x++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 15));
			cout << "#";
		}
		cout << endl;
	}

	for (int y = 0; y < 3; y++)
	{

		for (int x = 0; x < 13; x++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 1));
			cout << "#";
		}
		cout << endl;
	}

	for (int y = 0; y < 3; y++)
	{

		for (int x = 0; x < 13; x++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 4));
			cout << "#";
		}
		cout << endl;
	}



}

void Menu(int n)
{
	system("cls");
	menuPosition += n;
	if (menuPosition == 4) menuPosition = 0;
	if (menuPosition == -1) menuPosition = 3;

	if (menuPosition == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	 else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 15));
	cout << "2. Регистрация нового пользователя." << endl;
	if (menuPosition == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 15));
	cout << "3. Приветсвие." << endl;
	if (menuPosition == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 15));
	cout << "4. Массив" << endl;
	if (menuPosition == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 15));
	cout << "5. Флаг" << endl;


}

void IsLogin(boolean good)
{
	if (!good)
	{
		cout << "Вы не вошли в систему. Повторите попытку" << endl;
    }

	if (good)
	{
		cout << "Приветствую, тебя " << globaluser << endl;

	}


	cout << "Эту программу написал студент группы 9893, Росихин Александр." << endl;
	cout << "Кстати, в памяти моего компьютера номер мой группы выглядит как: " << endl;

	cout << perevod(9)<< perevod(8)<< perevod(9)<< perevod(3);
	   	 
	cout << endl;

	cout << "A фамилия: " << endl;

	cout << perevod((int)(unsigned char)'Р');
	cout << perevod((int)(unsigned char)'о');
	cout << perevod((int)(unsigned char)'с');
	cout << perevod((int)(unsigned char)'и');
	cout << perevod((int)(unsigned char)'х');
	cout << perevod((int)(unsigned char)'и');
	cout << perevod((int)(unsigned char)'н') << endl;
}

void User()
{
	boolean goodenter = false;
	cout << "Нажмите 1 для создания пользователя" << endl;
	cout << "Нажмите 2 для входа в систему" << endl;
	char ch;
	ch = _getch();
	if (ch == '1')
	{
		cout << "Новый пользователь." << endl;

		string login, password;

		cout << "Login: ";
		cin >> login;
		cout << "Password: ";
		//cin >> password;

		char c;
		do
		{
			c = _getch();
			cout << '*';
			password += c;
		} while (c != 13);


	
		cout << endl;

		ofstream f("data.txt");
		f << login << endl << password;
		f.close();

		goodenter = true;
		globaluser = login;

	}
	if (ch == '2')
	{
		
		string login,logintxt, password,passwordtxt ;
		
		cout << "Вход в систему." << endl;

		ifstream file("data.txt");
		if (file) getline(file, logintxt);
		if (file) getline(file, passwordtxt);


		cout << "Login: ";
		cin >> login;
		cout << "Password: ";

		//cin >> password;
		
		char c;
		do 
		{
			c = _getch();
			cout << '*';
			password += c;
		} while (c != 13);
		
		
		cout << endl;


		if (login!=logintxt) cout << "Пользователь не найден" << endl;
		else
		{
			if (password!=passwordtxt) cout << "Пароль неверен" << endl;
			else
			{
				cout << "Вы успешно вошли в систему" << endl;
				goodenter = true;
				globaluser = login;
			}
		}
	

	}


	IsLogin(goodenter);

}

void Bubble(int* m, int msize)
{
	for (int i = 0; i < msize - 1; i++)
		for (int j = 0; j < msize - i - 1; j++)
			if (m[j] > m[j + 1])
			{
				int temp = m[j];
				m[j] = m[j + 1];
				m[j + 1] = temp;


			}

}

void Shaker(int* m, int msize)
{
	int left = 0, right = msize - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// или пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (m[i] > m[i + 1]) // если следующий элемент меньше текущего,
			{             // меняем их местами
				double t = m[i];
				m[i] = m[i + 1];
				m[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (m[i - 1] > m[i]) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				double t = m[i];
				m[i] = m[i - 1];
				m[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}

void Comb(int* m, int msize)
{
	int n = msize;
	int tmp, k;
	int step = n; // готовим начальный шаг

	while (n > 1) {
		step /= 1.247f; // шаг на этом проходе.  На первом проходе получается примерно 80% от размера массива,
										// и легкие элементы в хвосте переносятся в первые 20% 
		if (step < 1) step = 1; // 0 быть не может, присвоим 1
		k = 0; // нет перестановок
		for (int i = 0; i + step < n; ++i)
		{
			if (m[i] / 10 > m[i + step] / 10)
			{
				tmp = m[i];
				m[i] = m[i + step];
				m[i + step] = tmp;
				k = i;
			}

		}
		if (step == 1) // шаг 1, как в обычном пузырьке. Включаем контроль	
			n = k + 1;
	}




}

void InsertSort(int* m, int msize)
{
	int temp,
		item;
	for (int counter = 1; counter < msize; counter++)
	{
		temp = m[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && m[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			m[item + 1] = m[item]; // перестановка элементов массива
			m[item] = temp;
			item--;
		}
	}

}

void quickSort(int* numbers, int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = numbers[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	numbers[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}

unsigned long long int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;

	return fib(n - 1) + fib(n - 2);
}

void Massiv(int* m, int *msize)
{
	cout << "Нажмите нужную кнопку" << endl;
	cout << "1 - ввести массив вручную" << endl;
	cout << "2 - заполнить случайными числами" << endl;
	cout << "3 - считать из файла" << endl;

	char ch;
	ch = _getch();
	if (ch == '1')
	{
		int x = 0;
		int i = 0;

		do
		{
			cout << "Введите массив через enter. Число 0 завершит ввод массива" << endl;
			cin >> x;
			m[i] = x;
			i++;

		} while (x != 0);
		*msize = i;

	}
	if (ch == '2')
	{
		srand(time(0));

		for (int i = 0; i < 1000; i++)
		{
			m[i] = rand() % 100;

			//cout << m[i];
		}
		*msize = 1000;

	}
	if (ch == '3') LoadMatrixFromFile(m,msize);
		

	cout << "Неотсортированный массив: " << endl;
	for (int i = 0; i < *msize; i++) cout << m[i] << " ";
	cout << endl;

	cout << "Выберите сортировку" << endl;
	cout << "1. Bubble sort" << endl;
	cout << "2. Shaker sort" << endl;
	cout << "3. Comb sort" << endl;
	cout << "4. Insert sort" << endl;
	cout << "5. Quick sort" << endl;
	
	ch = _getch();
	clock_t start = clock();
	if (ch == '1') Bubble(m, *msize);
	if (ch == '2') Shaker(m, *msize);
	if (ch == '3')
	{
		Comb(m, *msize);
		Shaker(m, *msize);
	}
	if (ch == '4') InsertSort(m, *msize);
	if (ch == '5') quickSort(m, 0, *msize - 1);

	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < *msize; i++) cout << m[i] << " ";
	cout << endl;

	clock_t stop = clock();
	double speed = ((clock() - start) * 1000000) / CLOCKS_PER_SEC;
     
	cout << "Скорость работы сортировки: " << speed << endl;

	int countfib = 0, countnotfib = 0;
	for (int i = 0; i < 15; i++)
	{
		boolean f = false;

		for (int ii = 0; ii < 2; ii++) if (m[i] == fib(ii))
		{
			f = true;
			
		}
		if (f) countfib++;
		if (!f) countnotfib++;
	}

	cout << "Чисел Фибоначчи: " << countfib << endl;
	cout << "Не чисел Фибоначчи: " << countnotfib << endl;

	int all = 0;
	for (int i = 0; i < *msize; i++) all += m[i];
	cout << "Среднее значение: " << (all / *msize) << endl;
	cout << "Медиана массива: " << m[*msize/2] << endl;

	int modacount = 0, moda=0, big=0;

	for (int i = 0; i < *msize-1; i++)
	{
		if (m[i] == m[i + 1])
		{
			modacount++;
			if (modacount>big)
			{
				big = modacount;
				moda = m[i];

			}
		}
		else modacount = 0;
	}

	cout << "Мода массива: " << moda << endl;
}


int main()
{
	setlocale(0, "");
	
	int m[1000];
	int msize = 0;


    Menu(0);
    char ch;
	do
	{
		ch = _getch();
		if (ch == 's' || ch == 80) Menu(+1);
		if (ch == 'w' || ch == 72) Menu(-1);
	} while (ch != 13);

	if (menuPosition == 0) User();
	if (menuPosition == 1) IsLogin(false);
	if (menuPosition == 2) Massiv(m, &msize);
	if (menuPosition == 3) ShowFlag();

	cout << endl << "конец работы программы" << endl;
	system("pause");
}

