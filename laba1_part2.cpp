// Лабораторная работа №1 часть 2, 3
// Росихин Александр, гр. 9893

#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

string showBinary(int *m,int *f) // вывод двоичного представления числа
{
	string s = "";
	for (int i = 0; i < 32; i++) // целая часть
	    {
		 s += to_string(m[31 - i]);
		 if (((i + 1) % 8 == 0) || i == 0) s += " ";
	     }


	s += " . ";

	for (int i = 0; i < 32; i++) // дробная часть
	{
		s += to_string(f[i]);
		if ((i + 1) % 8 == 0) s += " ";

	}



	return s;
}

void Inversion(int *m)
{
	cout << "Инвертированное число  в 2й системе: ";
	int inversionBinary[32];
	for (int i = 0; i < 32; i++)
	{
		if (m[i] == 0) inversionBinary[i] = 1;  else  inversionBinary[i] = 0;
		cout << inversionBinary[i];

	}
	cout << endl;

	int number = 0;
	float floatNumber = 0.0;
	int order = -127; 
	
	for (int i = 1; i < 9; i++) order += pow(2, 9 - 1 - i) * inversionBinary[i];
	for (int i = 9; i < 32; i++) number += pow(2, 32-1-i) * inversionBinary[i];
	
	cout << "Порядок уже смещенный обратно: " << order << endl;
	cout << "Само число: " << number << endl;

	floatNumber = number * pow(10, order);
	cout << "Итого. Инвертированное число в 10й системе: " << floatNumber;
	

	}

void GetBinary(float chislo,int* intArray, int* fractionArray)
{
	int integer = abs(chislo);
	float fraction = abs(chislo) - integer;

	for (int i = 0; i < 32; i++) // перевод целой части 
	{
		intArray[i] = integer & 1;
		integer >>= 1;
	}

	for (int i = 0; i < 32; i++) // перевод дробной части
	{
		fractionArray[i] = fraction * 2;
		fraction *= 2;
		if (fraction >= 1) fraction -= 1;
	}

}

int GetOrder(int*orderArray , int* intArray, int* fractionArray)
{
	int order = 0;
	for (int i = 31; i > 0; i--) if (intArray[i] != 0) //размер порядка, если число >=1
	{
		order = i;
		break;
	}

	if (order == 0) for (int i = 0; i < 32; i++) if (fractionArray[i] != 0) // размер порядка, при числе <1
	{
		order = -i;
		break;
	}

	cout << "Порядок: " << order << endl;

	int offsetOrder = 127 + order;
	cout << "Смещенный порядок: " << offsetOrder << endl;
	
	
	for (int i = 0; i < 8; i++) // перевод целой части 
	{
		orderArray[7 - i] = offsetOrder & 1;
		offsetOrder >>= 1;
	}

	cout << "Двоичная форма смещ. порядка: ";
	   for (int i = 0; i < 8; i++) cout << orderArray[i];
	cout << endl;


	return order;
}


void perevodFloat(float chislo)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	
	string str="";
	int integerBinary[32]= {}, 
		fractionBinary[32] = {},
		normalizeMantissa[23] = {},
		resultBinary[32] = {};
	int offsetOrderBinary[8] = {};
	
	
	
	
    GetBinary(chislo, integerBinary, fractionBinary);

	cout <<"Двоичная форма числа:\n " + showBinary(integerBinary, fractionBinary) << endl;
	
	int order = GetOrder(offsetOrderBinary, integerBinary, fractionBinary);
	
	if (order>=0) for (int i = 1; i <= order; i++) normalizeMantissa[i-1] = integerBinary[order-i];
	if (order>=0) for (int i = order; i < 23 ; i++) normalizeMantissa[i] = fractionBinary[i-order];
	if (order < 0)  for (int i = 0; i < 23; i++) if((i - order + 1)<32) normalizeMantissa[i] = fractionBinary[i - order+1];
			
	cout << "Нормализованная мантисса: ";
	for (int i = 0; i < 23; i++) cout << normalizeMantissa[i];
			cout << endl;
	
   if (chislo < 0) resultBinary[0] = 1; else resultBinary[0] = 0; //знак числа
   for (int i = 1; i < 9; i++) resultBinary[i] = offsetOrderBinary[i-1];
   for (int i = 9; i < 32; i++) resultBinary[i] = normalizeMantissa[i - 9];
   
   
   
   cout << "\n\n Представление в памяти ЭВМ: ";
   cout << resultBinary[0] << " ";

   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 0));
	   for (int i = 1; i < 9; i++) cout << resultBinary[i];
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));

   cout << " ";
      for (int i = 9; i < 16; i++) cout << resultBinary[i];
   cout << " ";
     for (int i = 16; i < 24; i++) cout << resultBinary[i];
   cout << " ";
     for (int i = 24; i < 32; i++) cout << resultBinary[i];

	 cout << endl << endl;
 
	cout << "Задание. Инверсия всех битов:  " << endl;
	  Inversion(resultBinary);
	cout << endl << "------------------------------------------------------ " << endl;

	
	}
	


int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
	
	setlocale(0, "");
	float x;

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
			cout << "Float:\n\n ";
			      perevodFloat(x);

		    cout << "\n\n";

		   }
	}
	//system("pause");
	
	
}


