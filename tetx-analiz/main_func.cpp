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

	// Выбрасывание ненужных символов
	string unwanted_symbols = ".!?,-:;()*'\"—«»";
	int unpos;  // Позиция ненужного символа
	for (int i = 0; i < unwanted_symbols.length(); i++) {
		for (int j = 0; j < str_arr.length(); j++) {
			if (unwanted_symbols[i] == str_arr[j]) {
				str_arr[j] = ' ';
			}
		}
	}
	
	// Перевод в нижний регистр
	transform(str_arr.begin(), str_arr.end(), str_arr.begin(), tolower);

	// Разбиение слов 
	string temp;
	int count = 0;
	for (int i = 0; i < str_arr.length(); i++) {  // Узнать сколько слов 
		if (str_arr[i] != ' ' && str_arr[i + 1] == ' ')
			count++;
	}
	for (int j = 0; j < str_arr.length(); j++) {  // Убрать многопробельные элементы
		if (str_arr[j] == ' ' && str_arr[j + 1] == ' ') {
			str_arr = str_arr.erase(j + 1, 1);
			j--;
		}
	}
	if (str_arr[0] == ' ') {  // Убрать вначале пробел
		str_arr = str_arr.erase(0, 1);
	}
	cout << "Slova: " << count << endl;
	string* out_str = new string[count];
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
			out_str[i] = temp;
			i++;
		}
	}

	// Создание словаря типа "слово" - кол-во повторений (изначально идёт сортировка по алфавиту от А до Я)
	map <string, int> words_map;
	int str_len = count;
	int temp_word_count = 1;
	for (int j = 0; str_len != 0; ) {
		for (int i = 1; i < str_len; i++) {
			if (out_str[j] == out_str[i]) {
				temp_word_count++;
				for (; i < str_len - 1; i++) {
					out_str[i] = out_str[i + 1];
				}
				str_len--;  // Здесь скорее всего ошибка
				i = 1;
			}
		}
		words_map.insert(make_pair(out_str[j], temp_word_count));
		for (int g = 0; g < str_len; g++) {
			out_str[g] = out_str[g + 1];
		}
		str_len--;
		temp_word_count = 1;
	}
	map <string, int> ::iterator it = words_map.begin();  // Вывод словаря
	for (int i = 0; it != words_map.end(); it++, i++) {
		cout << i << ") " << it->first << ", " << it->second << endl;
	}

	// Удаление нежелательных слов
	string unwanted_words[6] = { "и", "не", "я", "на", "в", "а" };
	for (int i = 0; i < 6; i++) {
		auto it = words_map.find(unwanted_words[i]);
		if (it != words_map.end()) {
			words_map.erase(it);
		}
	}


	// Сортировка по возрастанию/убыванию
	set<pair<string, int>, comp> set(words_map.begin(), words_map.end());
	for (auto const& pair : set) {
		cout << pair.first << "\t\t" << pair.second << endl;
	}

	// Поиск слова
	while (true) {
		bool word_flag = true;
		string word_for_finding;
		cin >> word_for_finding;
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
	
	// Время работы программы
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time;
}