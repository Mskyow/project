#include <conio.h>
#include <time.h> 
#include <iomanip>
#include <iostream>
#include <algorithm>  // Библ. для transform()
#include <fstream>  // Библ. для работы с файлами
#include <windows.h>  // Библ. для ввода/вывода в консоль 
#include <string>  // Библ. для работы со строками
#include <ctime>  // Библ. для таймера
#include <map>  // Библ. для словарей
#include <set>  // Библ. для сет
#include <vector>


using namespace std;

// Interface func
void prog_name() {
	cout << "		<=============================================>" << endl << endl;
	cout << "		                 TEXT ANALYZER" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void nav_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			МЕНЮ НАВИГАЦИИ" << endl;
	cout << "		   1. Выбор файла" << endl;
	cout << "		   2. Настройки регистра" << endl;
	cout << "		   3. Настройки нежелательных символов" << endl;
	cout << "		   4. Настройки нежелательных слов" << endl;
	cout << "		   5. Режим сортировки" << endl << endl;
	cout << "		   ? - чтобы узнать инструкцию" << endl << endl;
	cout << "		   ! - чтобы узнать выбранные настройки" << endl << endl;
	cout << "		<=============================================>" << endl;
}

int file_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВЫБЕРИТЕ ФАЙЛ" << endl;
		cout << "		   1. Песни группы Курара" << endl;
		cout << "		   2. Песни группы Сплин" << endl;
		cout << "		   3. Песни группы ДДТ" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
		}
	}
}

int font_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ПЕРЕВОД РЕГИСТРА" << endl;
		cout << "		   1. Перевести в нижний" << endl;
		cout << "		   2. Не менять регистр" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 50 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
		}
	}
}

int symb_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВЫБЕРИТЕ НАСТРОЙКУ УДАЛЕНИЯ СИМВОЛОВ" << endl;
		cout << "		   1. Заготовленный набор символов" << endl;
		cout << "		   2. Создать свой набор" << endl;
		cout << "		   3. Не удалять символы" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
		}
	}
}

int word_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВЫБЕРИТЕ НАСТРОЙКУ УДАЛЕНИЯ СЛОВ" << endl;
		cout << "		   1. Союзы и предлоги" << endl;
		cout << "		   2. Местоимения" << endl;
		cout << "		   3. Все перечисленные" << endl;
		cout << "		   4. Не удалять слова" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 52 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
			word_menu();
		}
	}
}

int sort_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВЫБЕРИТЕ СОРТИРОВКУ" << endl;
		cout << "		   1. Алфавитный порядок" << endl;
		cout << "		   2. В порядке по убыванию" << endl;
		cout << "		   3. В порядке по возрастанию" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
			sort_menu();
		}
	}
}

void help() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			ИНСТРУКЦИЯ" << endl;
	cout << "		   В п.1 Вы должны выбрать открываемый файл." << endl;
	cout << "		   В п.2 Вы выбираете нужно ли переводить" << endl;
	cout << "		  текст в нижний регистр." << endl;
	cout << "		   В п.3 рекомендуется удалить некоторые" << endl;
	cout << "		  символы, во избежении слов со знаками" << endl;
	cout << "		  препинания(например, \"конец.\", \",утро-\")." << endl;
	cout << "		   В п.4 Вы можете выбрать какие слова" << endl;
	cout << "		  будут удалены(например, можно убрать" << endl;
	cout << "		  местоимения и союзы)." << endl;
	cout << "		   В п.5 у Вас есть возможность выбрать" << endl;
	cout << "		  желаемую сортировку." << endl << endl;
	cout << "		<=============================================>" << endl;
	_getch();
	system("cls");
}

void status(int file_menu_answer, int font_menu_answer, int symb_menu_answer, int word_menu_answer, int sort_menu_answer) {
	string status_answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБРАННЫЕ НАСТРОЙКИ" << endl;
	switch (file_menu_answer) {
	case 1:
		status_answer = "песни группы Курара";
		break;
	case 2:
		status_answer = "песни группы Сплин";
		break;
	case 3:
		status_answer = "песни группы ДДТ";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Открываемый файл: " << status_answer << endl;
	switch (font_menu_answer) {
	case 1:
		status_answer = "нижний";
		break;
	case 2:
		status_answer = "не изменять";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Регистр: " << status_answer << endl;
	switch (symb_menu_answer) {
	case 1:
		status_answer = "заготовленный набор";
		break;
	case 2:
		status_answer = "свой набор";
		break;
	case 3:
		status_answer = "не удалять символы";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Удаляемые символы: "  << status_answer << endl;
	switch (word_menu_answer) {
	case 1:
		status_answer = "союзы и предлоги";
		break;
	case 2:
		status_answer = "местоимения";
		break;
	case 3:
		status_answer = "все перечисленные";
		break;
	case 4:
		status_answer = "не удалять слова";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Удаляемые слова: " << status_answer << endl;
	switch (sort_menu_answer) {
	case 1:
		status_answer = "алфавитный порядок";
		break;
	case 2:
		status_answer = "в порядке убывания";
		break;
	case 3:
		status_answer = "в порядке возрастания";
		break;
	case 0:
		status_answer = "не выбрано";
		break;
	}
	cout << "		   Вид сортировки: " << status_answer << endl << endl;
	cout << "		<=============================================>" << endl;
	_getch();
	system("cls");
}

int ready_for_analysis() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВСЕ НАСТРОЙКИ ПРОИЗВЕДЕНЫ" << endl;
		cout << "		   1. Начать анализ" << endl;
		cout << "		   2. Поменять настройки" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) == 49 && answer.length() == 1) {
			system("cls");
			return 1;
		}
		else if(int(answer[0]) == 50 && answer.length() == 1) {
			system("cls");
			return 0;
		}
		else {
			cout << "Вы ввели некорректное значение. Попробуйте снова.";
			Sleep(2500);
			system("cls");
		}
	}
}

void statistics(double seconds, int count, map <string, int> words_map) {
	cout << "		<=============================================>" << endl << endl;
	cout << "			КРАТКАЯ СТАТИСТИКА" << endl;
	cout << "		   Время анализа: " << seconds << " сек." << endl;
	cout << "		   Общее количество слов: " << count << endl;
	cout << "		   Количество уникальных слов: " << words_map.size() << endl << endl;
	cout << "		<=============================================>" << endl << endl << endl;
}


// Programm func
string del_unwanted_symbols(string str_arr, string unwanted_symbols);

int words_counter(string str_arr);

string* text_spliter(string str_arr, int count);

map <string, int> map_creater(string* splited_str, int count);

map <string, int> del_unwanted_words(map <string, int> words_map, string* unwanted_words, const int unwanted_words_count);

struct comp1  // Эта штука для сортировки 
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		if (l.second != r.second) {
			return l.second > r.second;  // < - сортировка по возрастанию; > - по убыванию
		}

		return l.first < r.first;
	}
};
struct comp2
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

void map_sorter_des(map <string, int> words_map);

void map_sorter_as(map <string, int> words_map);

void word_finder(map <string, int> words_map);

void text_analyzer(int file_menu_answer, int font_menu_answer, int symb_menu_answer, int word_menu_answer, int sort_menu_answer);



// main func
void main() {

	string answer;

	int file_menu_answer = 0;
	int font_menu_answer = 0;
	int symb_menu_answer = 0;
	int word_menu_answer = 0;
	int sort_menu_answer = 0;

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	prog_name();
	cout << endl << endl;
	_getch();
	system("cls");

	
	while (true) {
		nav_menu();
		cin >> answer;
		if (answer.length() == 1) {
			switch (int(answer[0])) {
			case(49):
				system("cls");
				file_menu_answer = file_menu();
				break;
			case(50):
				system("cls");
				font_menu_answer = font_menu();
				break;
			case(51):
				system("cls");
				symb_menu_answer = symb_menu();
				break;
			case(52):
				system("cls");
				word_menu_answer = word_menu();
				break;
			case(53):
				system("cls");
				sort_menu_answer = sort_menu();
				break;
			case(63):
				system("cls");
				help();
				break;
			case(33):
				system("cls");
				status(file_menu_answer, font_menu_answer, symb_menu_answer, word_menu_answer, sort_menu_answer);
				break;
			default:
				cout << "Нет такой функции." << endl;
				Sleep(750);
				system("cls");
				break;
			}
			if (file_menu_answer && font_menu_answer && symb_menu_answer && word_menu_answer && sort_menu_answer && ready_for_analysis()) {
				text_analyzer(file_menu_answer, font_menu_answer, symb_menu_answer, word_menu_answer, sort_menu_answer);
				break;
			}
		}
		else {
			cout << "Нет такой функции." << endl;
			Sleep(750);
			system("cls");
		}
	}
}

void text_analyzer(int file_menu_answer, int font_menu_answer, int symb_menu_answer, int word_menu_answer, int sort_menu_answer) {

	time_t start, end;
	time(&start);

	ifstream text;
	if (file_menu_answer == 1) {
		text.open("d:\\software_labs\\tetx_analizator\\kurara_songs.txt", ios::in);
	}
	else if (file_menu_answer == 2) {
		text.open("d:\\software_labs\\tetx_analizator\\splin_songs.txt", ios::in);
	}
	else if (file_menu_answer == 3) {
		text.open("d:\\software_labs\\tetx_analizator\\ddt_songs.txt", ios::in);
	}


	// Запись текста в массив стринг
	string str, str_arr = " ";
	while (!text.eof()) {
		text >> str;
		str_arr += " " + str;
	}


	// Перевод в нижний регистр
	switch (font_menu_answer) {
	case 1:	
		transform(str_arr.begin(), str_arr.end(), str_arr.begin(), tolower);
		break;
	}


	// Выбрасывание ненужных символов
	switch (symb_menu_answer) {
	case 1: {
		string unwanted_symbols = ".!?,-:;()*'\"\\/|–«»=+@#№$%^&`~";
		str_arr = del_unwanted_symbols(str_arr, unwanted_symbols);
		break;
	}
	case 2:
		string unwanted_symbols;
		cout << "		<=============================================>" << endl << endl;
		cout << "			ВВЕДИТЕ ПОДРЯД НЕЖЕЛАЕМЫЕ СИМВОЛЫ" << endl;
		cin >> unwanted_symbols;
		system("cls");
		str_arr = del_unwanted_symbols(str_arr, unwanted_symbols);
		break;
	}


	// Разбиение слов 
	int count = words_counter(str_arr);
	string* splited_arr = text_spliter(str_arr, count);


	// Создание словаря типа "слово" - кол-во повторений (изначально идёт сортировка по алфавиту от А до Я)
	map <string, int> words_map = map_creater(splited_arr, count);


	// Удаление нежелательных слов
	switch (word_menu_answer) {
	case 1: {  // Союзы и предлоги
		const int unwanted_words_count = 49;
		string unwanted_words_union[unwanted_words_count] = { "и", "ни", "тоже", "также", "а", "но", "да", "однако", "зато", "же", "или", "либо", "то", "если", "столько", "сколько", "как", "так", "хотя", "будто", "словно", "пока", "когда", "зачем", "куда", "в", "к", "до", "через", "после", "до", "из", "за", "над", "под", "от", "по", "для", "про", "ввиду", "ради", "возле", "мимо", "около", "не", "у", "с", "на", "без"};
		words_map = del_unwanted_words(words_map, unwanted_words_union, unwanted_words_count);
	}
		  break;
	case 2: {  // Местоимения
		const int unwanted_words_count = 29;
		string unwanted_words_pronouns[unwanted_words_count] = {"мне", "я", "ты", "мы", "вы", "он", "она", "оно", "они", "себя", "мой", "твой", "наш", "ваш", "свой", "кто", "что", "никто", "ничто", "некого", "нечего", "никакой", "ничей", "нисколько", "некто", "нечто", "сам", "самый", "каждый"};
		words_map = del_unwanted_words(words_map, unwanted_words_pronouns, unwanted_words_count);
	}
		  break;
	case 3: {
		const int unwanted_words_count = 78;
		string unwanted_words_all[unwanted_words_count] = {"мне", "и", "ни", "тоже", "также", "а", "но", "да", "однако", "зато", "же", "или", "либо", "то", "если", "столько", "сколько", "как", "так", "хотя", "будто", "словно", "пока", "когда", "зачем", "куда", "в", "к", "до", "через", "после", "до", "из", "за", "над", "под", "от", "по", "для", "про", "ввиду", "ради", "возле", "мимо", "около", "я", "ты", "мы", "вы", "он", "она", "оно", "они", "себя", "мой", "твой", "наш", "ваш", "свой", "кто", "что", "никто", "ничто", "некого", "нечего", "никакой", "ничей", "нисколько", "некто", "нечто", "сам", "самый", "каждый", "не", "у", "с", "на", "без" };
		words_map = del_unwanted_words(words_map, unwanted_words_all, unwanted_words_count);
	}
	}


	// Сортировка по убыванию / возрастанию / алфавиту и вывод
	cout << "		<=============================================>" << endl << endl;
	cout << "			ОТСОРТИРОВАННЫЙ ТЕКСТ" << endl << endl;
	cout << "		<=============================================>" << endl << endl;
	switch (sort_menu_answer) {
	case 1: {
		map <string, int> ::iterator itt = words_map.begin();
		int n = 0;
		for (int i = 0; i < words_map.size(); i++) {
			itt = next(words_map.begin(), i);
			if (i == 4 + 4 * n) {
				n++;
				cout << endl;
			}
			cout << setw(18) << itt->first << "   - " << setw(4) << itt->second;
		}
		cout << endl << endl << endl;
	}
		break;
	case 2:
		map_sorter_des(words_map);
		break;
	case 3:
		map_sorter_as(words_map);
		break;
	}

	time(&end);
	double seconds = difftime(end, start);

	statistics(seconds, words_counter(str_arr), words_map);

	word_finder(words_map);
}


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

string* text_spliter(string str_arr, int count) {
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

map <string, int> map_creater(string* splited_str, int count) {
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

map <string, int> del_unwanted_words(map <string, int> words_map, string* unwanted_words, const int unwanted_words_count) {
	for (int i = 0; i < unwanted_words_count; i++) {
		auto it = words_map.find(unwanted_words[i]);
		if (it != words_map.end()) {
			words_map.erase(it);
		}
	}
	return words_map;
}

void map_sorter_des(map <string, int> words_map) {
	set<pair<string, int>, comp1> set(words_map.begin(), words_map.end());
	int n = 0;
	int i = 0;
	for (auto const& pair : set) {
		if (i == 4 + 4 * n) {
			n++;
			cout << endl;
		}
		cout << setw(18) << pair.first << "   - " << setw(4) << pair.second;
		i++;
	}
	cout << endl << endl << endl;
}
void map_sorter_as(map <string, int> words_map) {
	set<pair<string, int>, comp2> set(words_map.begin(), words_map.end());
	int n = 0;
	int i = 0;
	for (auto const& pair : set) {
		if (i == 4 + 4 * n) {
			n++;
			cout << endl;
		}
		cout << setw(18) << pair.first << "   - " << setw(4) << pair.second;
		i++;
	}
	cout << endl << endl << endl;
}

void word_finder(map <string, int> words_map) {
	cout << "		<=============================================>" << endl << endl;
	cout << "			ПОИСК ПО СЛОВУ" << endl;
	cout << "		   Введите слово, чтобы узнать, сколько раз" << endl;
	cout << "		   оно встречается в тексте." << endl << endl;
	cout << "		   !exit - чтобы выйти из программы" << endl << endl;
	cout << "		<=============================================>" << endl << endl;
	string exit = "!exit";
	while (true) {
		bool word_flag = true;
		string word_for_finding;
		cin >> word_for_finding;
		if (word_for_finding == exit) {
			break;
		}
		map <string, int> ::iterator it;
		for (it = words_map.begin(); it != words_map.end(); it++) {
			if (it->first == word_for_finding) {
				cout << it->first << "  |  " << it->second << endl;
				word_flag = false;
			}
		}
		if (word_flag) {
			cout << "Нет совпадений." << endl;
		}
	}
}