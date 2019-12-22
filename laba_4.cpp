#include <iostream>
#include <string>
#include <fstream>


using namespace std;

string LoadFile()
{

	string oneString="", allStrings="" ;
	ifstream file("text.txt");

	if (file)
	  do
		{
			getline(file, oneString);
			allStrings += oneString+" ";
					
		} while (!file.eof());

	else cout << "Ошибка открытия файла." << endl;

	return allStrings;
}

string DeleteDoubleChar(string deleteSymbols,string wholeText)
{
	int pos = 0;
	do
	{
		pos = wholeText.find(deleteSymbols);
		if (pos>0) wholeText.erase(pos, 1);
	} while (pos != -1);
	
	return wholeText;
}

string LowerCase(string s)
{
	 //transform(s.begin(), s.end(), s.begin(), tolower); // преобразует весь текст #include <algorithm>
	int i = 1;
	
	while (s[i])
	{ 
	   if (s[i-1]!=' ')
		s[i] = tolower(s[i]);
		i++;
	}
	return s;
}

string GetDoubleWords(string wholeText)
{
	string word = "";
	string resultString = "";
	int position=0;
	
	do
	{
		position = wholeText.find(" ");
	
		if (position == -1) position = wholeText.find(".");
		if (position == -1) position = wholeText.find("\n");
		if (position != -1)
		{
			word = wholeText.substr(0, position);
			wholeText.erase(0, position + 1);

			int repeat = 0;
			for (int i = 0; i < word.length(); i++)
				for (int ii = 0; ii < word.length(); ii++)
					if ((i != ii) && (word[i] == word[ii])) repeat++;

			if (repeat > 0) resultString += word +"\n";

		}
	} while (position != -1);

		
	
	return resultString;
}

void ShowResult(string text)
{
	
	cout << "Текст без лишних пробелов:" << endl << endl;
	text = DeleteDoubleChar("  ", text);
	cout << text << endl << endl;

	cout << "Текст без лишних знаков препинания:" << endl << endl;
	text = DeleteDoubleChar(",,", text);
	text = DeleteDoubleChar("!!", text);
	text = DeleteDoubleChar("??", text);
	text = DeleteDoubleChar(";;", text);
	text = DeleteDoubleChar("::", text);
	text = DeleteDoubleChar("''", text);
	text = DeleteDoubleChar("))", text);
	text = DeleteDoubleChar("((", text);
	cout << text << endl << endl;
	   
	cout << "Текст с исправленным регистром:" << endl << endl;
	text = LowerCase(text);
	cout << text << endl << endl;


	cout << "Слова, в которых есть повторяющиеся буквы:" << endl << endl;
	cout << GetDoubleWords(text) << endl << endl;

	cout << "-----------------------------------------" << endl << endl;
}


int main()
{
	string text;
	setlocale(0, "");
	
	text = LoadFile();
	cout << "Исходный текст из файла:" << endl << endl;
	cout << text << endl << endl;

	ShowResult(text);

	while (true)
	{
		cout << "Введите текст на английском языке:  ";
		string textFromKeyboard;
		getline(cin,textFromKeyboard);

		if (textFromKeyboard!="")
		{

			cout << endl << "Исходный введенный текст:" << endl << endl;
			cout << textFromKeyboard << endl << endl;

			ShowResult(textFromKeyboard);
		}
	}

	system("pause");
}
