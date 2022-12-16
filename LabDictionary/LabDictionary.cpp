#include <iostream>
#include "Dictionary.h"
#include "DictionaryIterator.h"
#include "KeyValue.h"
#include <fstream>
using namespace std;

string remove(string str, int i, int j)
{
	int k = 1;
	for (i ;i <= j; i++)
	{
		if(j + k > str.length())
		{
			while (i <= j) {
				str.pop_back();
				i++;
			}
		}
		else {
			str[i] = str[j + k];
			k++;
		}
	}
}
void PrintEntry(const KeyValue<string, string>& word)
{
	KeyValue<string, string> w = word;
	int linepos = w.Key().length() + 3;
	int i;
	cout << w.Key() << " - ";
	while (!w.value.empty())
	{
		if (w.value.length() > 65 - linepos)
		{
			i = 64 - linepos;
			while (w.value[i] != ' ')
				i--;
		}
		else
			i = w.value.length() - 1;
		cout << w.value.substr(0, i + 1) << endl;
		w.value = remove(w.value, 0, i + 1);
		linepos = 0;
	}
}
string ReadString(string str, istream& istr, char delimiter = ' ') {
	char tmp[256];
	if (istr.getline(tmp, 256, delimiter)) {
		str = tmp;
		return str;
	}
}
int main()
{
	setlocale(0, "ru");
	ifstream fin;
	string word, definition;
	Dictionary<string, string> wordDictionary("");

	fin.open("defs.dat", ios::in | ios::_Nocreate);
	if (!fin) {
		cerr << "Файл defs.dat не найден" << endl;
		exit(1);
	}
	while (fin >> word)
		if (fin.eof())
			break;
	definition = ReadString(definition, fin);
	
	wordDictionary[word] += definition;
	DictionaryIterator<string, string> dictIter(wordDictionary);

	cout << "Тольковый словарь:" << endl << endl;
	for (dictIter.Reset(); !dictIter.EndOfList(); dictIter.Next())
	{
		PrintEntry(dictIter.Data());
		cout << endl;
	}

	wordDictionary.clearList(wordDictionary.getRoot());
}
