// Лабораторная работа №1 часть 3
// Росихин Александр, гр. 9893

#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

string showBinary(int* m, int* f) // вывод двоичного представления числа
{
	string s = "";
	for (int i = 0; i < 64; i++) // целая часть
	{
		s += to_string(m[63 - i]);
		if (((i + 1) % 8 == 0) || i == 0) s += " ";
	}


	s += " . \n";

	for (int i = 0; i < 64; i++) // дробная часть
	{
		s += to_string(f[i]);
		if ((i + 1) % 8 == 0) s += " ";

	}



	return s;
}

void Inversion(int* m)
{
	cout << "Инвертированное число  в 2й системе: " <<endl;
	int inversionBinary[64];
	for (int i = 0; i < 64; i++)
	{
		if (m[i] == 0) inversionBinary[i] = 1;  else  inversionBinary[i] = 0;
		cout << inversionBinary[i];

	}
	cout << endl;

	int number = 0;
	double doubleNumber = 0.0;
	int order = -1023;

	for (int i = 1; i < 12; i++) order += pow(2, 12 - 1 - i) * inversionBinary[i];
	for (int i = 12; i < 64; i++) number += pow(2, 64 - 1 - i) * inversionBinary[i];

	cout << "Порядок уже смещенный обратно: " << order << endl;
	cout << "Само число: " << number << endl;

	doubleNumber = number * pow(10, order);
	cout << "Итого. Инвертированное число в 10й системе: " << doubleNumber;


}

void GetBinary(double chislo, int* intArray, int* fractionArray)
{
	int integer = abs(chislo);
	double fraction = abs(chislo) - integer;

	for (int i = 0; i < 64; i++) // перевод целой части 
	{
		intArray[i] = integer & 1;
		integer >>= 1;
	}

	for (int i = 0; i < 64; i++) // перевод дробной части
	{
		fractionArray[i] = fraction * 2;
		fraction *= 2;
		if (fraction >= 1) fraction -= 1;
	}

}

int GetOrder(int* orderArray, int* intArray, int* fractionArray)
{
	int order = 0;
	for (int i = 63; i > 0; i--) if (intArray[i] != 0) //размер порядка, если число >=1
	{
		order = i;
		break;
	}

	if (order == 0) for (int i = 0; i < 64; i++) if (fractionArray[i] != 0) // размер порядка, при числе <1
	{
		order = -i;
		break;
	}

	cout << endl<< "Порядок: " << order << endl;

	int offsetOrder = 1023 + order;
	cout << "Смещенный порядок: " << offsetOrder << endl;


	for (int i = 0; i < 11; i++) // перевод целой части 
	{
		orderArray[10 - i] = offsetOrder & 1;
		offsetOrder >>= 1;
	}

	cout << "Двоичная форма смещ. порядка: ";
	for (int i = 0; i < 11; i++) cout << orderArray[i];
	cout << endl;


	return order;
}


void perevodDouble(double chislo)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));

	string str = "";
	int integerBinary[64] = {},
		fractionBinary[64] = {},
		normalizeMantissa[64] = {},
		resultBinary[64] = {};
	int offsetOrderBinary[64] = {};




	GetBinary(chislo, integerBinary, fractionBinary);

	cout << "Двоичная форма числа:\n " + showBinary(integerBinary, fractionBinary) << endl;

	int order = GetOrder(offsetOrderBinary, integerBinary, fractionBinary);

	if (order >= 0) for (int i = 1; i <= order; i++) normalizeMantissa[i - 1] = integerBinary[order - i];
	if (order >= 0) for (int i = order; i < 52; i++) normalizeMantissa[i] = fractionBinary[i - order];
	if (order < 0)  for (int i = 0; i < 52; i++) if ((i - order + 1) < 64) normalizeMantissa[i] = fractionBinary[i - order + 1];

	cout << "Нормализованная мантисса: ";
	for (int i = 0; i < 52; i++) cout << normalizeMantissa[i];
	cout << endl;

	if (chislo < 0) resultBinary[0] = 1; else resultBinary[0] = 0; //знак числа
	for (int i = 1; i < 12; i++) resultBinary[i] = offsetOrderBinary[i - 1];
	for (int i = 12; i < 64; i++) resultBinary[i] = normalizeMantissa[i - 12];



	cout << endl << "Представление в памяти ЭВМ: " << endl;;
	cout << resultBinary[0] << " ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 0));
	for (int i = 1; i < 12; i++) cout << resultBinary[i];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));

	cout << " ";
	for (int i = 12; i < 16; i++) cout << resultBinary[i];
	
	cout << " ";
	for (int i = 16; i < 24; i++) cout << resultBinary[i];
	
	cout << " ";
	for (int i = 24; i < 32; i++) cout << resultBinary[i];
	cout << " ";
	for (int i = 32; i < 40; i++) cout << resultBinary[i];
	cout << " ";
	for (int i = 40; i < 48; i++) cout << resultBinary[i];
	cout << " ";
	for (int i = 48; i < 56; i++) cout << resultBinary[i];
	cout << " ";
	for (int i = 56; i < 64; i++) cout << resultBinary[i];



	cout << endl << endl;

	cout << "Задание. Инверсия всех битов:  " << endl;
	Inversion(resultBinary);
	cout << endl << "------------------------------------------------------ " << endl;


}



int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));

	setlocale(0, "");
	double x;

	while (true)
	{
		cout << ("Введите число: ");
		
			cin >> x;
			if (cin.fail())
			{
				cout << "\n Ошибка. Программа будет закрыта.\n";
				cin.clear();
			    break;
			}
			else
			{
				cout << "Double:\n\n ";
				perevodDouble(x);

				cout << "\n\n";

			}

	
	}
	system("pause");
	return 0;

}


