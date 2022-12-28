#include <iostream>
#include <algorithm>  // Библ. для transform()
#include <fstream>  // Библ. для работы с файлами
#include <windows.h>  // Библ. для ввода/вывода в консоль 
#include <string>  // Библ. для работы со строками
#include <ctime>  // Библ. для таймера
#include <map>  // Библ. для словарей
#include <set>  // Библ. для сет
#include <vector>  // Библ. для векторов
using namespace std;

string del_unwanted_symbols(string str_arr, string unwanted_symbols) {
	int unpos;
	for (int i = 0; i < unwanted_symbols.length(); i++) {
		for (int j = 0; j < str_arr.length(); j++) {
			if (unwanted_symbols[i] == str_arr[j]) {
				str_arr[j] = ' ';
			}
		}
	}
	str_arr += ' ';
	return str_arr;
}

int words_counter(string str_arr) {
	int count = 0;
	for (int i = 0; i < str_arr.length(); i++) {  
		if (str_arr[i] != ' ' && str_arr[i + 1] == ' ')
			count++;
	}
	return count;
}

string *text_spliter(string str_arr, int count) {
	string temp;
	for (int j = 0; j < str_arr.length(); j++) {  
		if (str_arr[j] == ' ' && str_arr[j + 1] == ' ') {
			str_arr = str_arr.erase(j + 1, 1);
			j--;
		}
	}
	if (str_arr[0] == ' ') {
		str_arr = str_arr.erase(0, 1);
	}
	string* splited_str = new string[count];
	int i = 0;
	while (true) {
		temp = str_arr.substr(0, str_arr.find(' '));
		if (temp.size() == str_arr.size()) {
			break;
		}
		else {
			str_arr = str_arr.substr(temp.size() + 1);
		}
		if (temp != " ") {
			splited_str[i] = temp;
			i++;
		}
	}
	return splited_str;
}

map <string, int> map_creater(string *splited_str, int count) {
	map <string, int> words_map;
	int str_len = count;
	int temp_word_count = 1;
	for (int j = 0; str_len != 0; ) {
		for (int i = 1; i < str_len; i++) {
			if (splited_str[j] == splited_str[i]) {
				temp_word_count++;
				for (; i < str_len - 1; i++) {
					splited_str[i] = splited_str[i + 1];
				}
				str_len--; 
				i = 1;
			}
		}
		words_map.insert(make_pair(splited_str[j], temp_word_count));
		for (int g = 0; g < str_len; g++) {
			splited_str[g] = splited_str[g + 1];
		}
		str_len--;
		temp_word_count = 1;
	}
	return words_map;
}

map <string, int> del_unwanted_words(map <string, int> words_map, string *unwanted_words) {
	for (int i = 0; i < 6; i++) {
		auto it = words_map.find(unwanted_words[i]);
		if (it != words_map.end()) {
			words_map.erase(it);
		}
	}
	return words_map;
}

struct comp  // Эта штука для сортировки 
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		if (l.second != r.second) {
			return l.second < r.second;  // < - сортировка по возрастанию; > - по убыванию
		}

		return l.first < r.first;
	}
};

void map_sorter(map <string, int> words_map) {
	set<pair<string, int>, comp> set(words_map.begin(), words_map.end());
	for (auto const& pair : set) {
		cout << pair.first << "\t\t" << pair.second << endl;
	}
}

void word_finder(map <string, int> words_map) {
	string exit = "!exit";
	while (true) {
		bool word_flag = true;
		string word_for_finding;
		cin >> word_for_finding;
		if (word_for_finding == exit) {
			break;
		}
		map <string, int> ::iterator itt;
		for (itt = words_map.begin(); itt != words_map.end(); itt++) {
			if (itt->first == word_for_finding) {
				cout << itt->first << " | " << itt->second << endl;
				word_flag = false;
			}
		}
		if (word_flag) {
			cout << "Нет совпадений." << endl;
		}
	}
}



void main() {
	unsigned int start_time = clock();  // Это чтобы узнать время работы программы

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ifstream text("d:\\software_labs\\tetx_analizator\\grob_text.txt", ios::in);

	// Проверка на открыт ли файл
	if (!text) {
		cout << "Файл не открыт\n";
	}
	else {
		cout << "Все ОК! Файл открыт!\n";
	}


	// Запись текста в массив стринг
	string str, str_arr = " ";
	while (!text.eof()) {
		text >> str;
		str_arr += " " + str;
	}


	// Перевод в нижний регистр
	transform(str_arr.begin(), str_arr.end(), str_arr.begin(), tolower);


	// Выбрасывание ненужных символов
	string unwanted_symbols = ".!?,-:;()*'\"\\/|–«»=+@#№$%^&`~";
	str_arr = del_unwanted_symbols(str_arr, unwanted_symbols);
	

	// Разбиение слов 
	int count = words_counter(str_arr);
	string *splited_arr = text_spliter(str_arr, count);


	// Создание словаря типа "слово" - кол-во повторений (изначально идёт сортировка по алфавиту от А до Я)
	map <string, int> words_map = map_creater(splited_arr, count);
	map <string, int> ::iterator it = words_map.begin();

	
	// Удаление нежелательных слов
    string unwanted_words[6] = { "и", "не", "я", "на", "в", "а" };
	words_map = del_unwanted_words(words_map, unwanted_words);


	// Сортировка по убыванию / возрастанию и вывод
	map_sorter(words_map);


	// Поиск слова
	word_finder(words_map);

	
	// Время работы программы
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time;
}