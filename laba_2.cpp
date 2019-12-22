#include <iostream>
#include <string>
#include <ctime>


using namespace std;

int array[1000], arraySize=0, decrease;


string showArray(int size)
{
	string result;
	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		::array[i] = rand() % 100;
		result += to_string(::array[i]) + " ";
	}



	return result;

}

void sortc(int n)
{
	int tmp, k;
	int step = n; // готовим начальный шаг
	
	while (n > 1) {
		step /= 1.247f; // шаг на этом проходе.  На первом проходе получается примерно 80% от размера массива,
										// и легкие элементы в хвосте переносятся в первые 20% 
		if (step < 1) step = 1; // 0 быть не может, присвоим 1
		k = 0; // нет перестановок
		for (int i = 0; i + step < n; ++i)
		{ 
			if (::array[i] / 10 > ::array[i + step] / 10)
			 {
				tmp = ::array[i];
				::array[i] = ::array[i + step];
				::array[i + step] = tmp;
				k = i;
			 }
		
		}
		if (step == 1) // шаг 1, как в обычном пузырьке. Включаем контроль	
			n = k + 1;
	}


}


string showSort(int size)
{
	string result;

	sortc(size);

	for (int i = 0; i < size - 1; i++) 
	   for (int j = 0; j < size - i - 1; j++)
		   if (::array[j] > ::array[j + 1])
		   {
			   int temp = ::array[j];
			   ::array[j] = ::array[j + 1];
			   ::array[j + 1] = temp;


		   }

	for (int i = 0; i < size; i++) result += to_string(::array[i]) + " ";


	return result;
}

int averageCount()
 {
	int count=0;
	int average = (::array[0] + ::array[::arraySize]) / 2 ; 
	for (int i = 0; i < ::arraySize; i++) if (::array[i] == average) count++;

	
	return count;
 }

int lessCount(int x)
 { 
	int count = 0;
	for (int i = 0; i < ::arraySize; i++) 
		if (::array[i] < x) count = i+1;
		  else break;

		return count;
 }

int moreCount(int x)
 {
	int count = 0; 
	 for (int i = ::arraySize-1; i>=0; i--) 
       if (::array[i] > x) count = ::arraySize-i;
		 else break;

	return count;
 }

string showDecreaseArray(int d)
{
	string result="";
	for (int i = 0; i < ::arraySize; i++)
	{
		if (i % 2 != 0) ::array[i] = ::array[i] - d;
		result += to_string(::array[i]) + " ";

	}
		

	return result;
}

int main()
{
	setlocale(0, "");
	int a, b;
	


	  while (true)
	  {
		  cout << "Введите размер массива (число, цифрами от 1 до 999): ";

		  cin >> arraySize;
		  if (cin.fail())
		  {
			  cout << "\n Ошибка. Программа будет закрыта.\n";
			  cin.clear();
			  break;
			  
		  }
		  else
		  {

		  clock_t start = clock();
		  cout << "Массив случайных чисел из " << arraySize << " элементов:\n\n";
		  cout << showArray(arraySize) + "\n";
		  cout << showSort(arraySize) + "\n";
		  cout << "Максимальный элемент массива: " << ::array[arraySize - 1] << "\n";
		  cout << "Минимальный элемент массива: " << ::array[0] << "\n";
		  cout << "Кол-во элементов равных среднему значению: " << averageCount() << "\n\n";

		  double speed = ((clock() - start) * 1000000) / CLOCKS_PER_SEC;

		  cout << "Скорость выполнения (микро сек): " << speed << "\n";


		  cout << "Введите число 'a': ";
		  cin >> a;
		  cout << "Введите число 'b': ";
		  cin >> b;
		  cout << "Кол-во элементов меньше 'a': " << lessCount(a) << "\n";
		  cout << "Кол-во элементов больше 'b': " << moreCount(b) << "\n";

		  cout << "Задание. Уменьшить нечетный эл. на пользовательское значение и рандомно. \n";
		  cout << "Введите число, на которое надо уменьшить: ";
		  cin >> decrease;
		  cout << "Массив с уменьшенными нечетными элементами: " << showDecreaseArray(decrease) << "\n";
		  cout << "Массив со случайным уменьшение нечетными элементов: " << showDecreaseArray(rand() % 10) << "\n";

		  cout << "--------------------------------------------------------------------------------------\n\n";
	  }

  }
	  system("pause");
}
