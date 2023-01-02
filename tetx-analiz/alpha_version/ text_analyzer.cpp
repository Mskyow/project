#include <conio.h>
#include <time.h> 
#include <iomanip>
#include <iostream>
#include <algorithm>  // Ѕибл. дл€ transform()
#include <fstream>  // Ѕибл. дл€ работы с файлами
#include <windows.h>  // Ѕибл. дл€ ввода/вывода в консоль 
#include <string>  // Ѕибл. дл€ работы со строками
#include <ctime>  // Ѕибл. дл€ таймера
#include <map>  // Ѕибл. дл€ словарей
#include <set>  // Ѕибл. дл€ сет
#include <vector>


using namespace std;

void text_analyzer(int file_menu_answer, int font_menu_answer, int symb_menu_answer, int word_menu_answer, int sort_menu_answer) {

	time_t start, end;
	time(&start);

	ifstream text;
	if (file_menu_answer == 1) {
		text.open("C:\\Users\\User\\Desktop\\engineering\\project\\kurara_songs.txt", ios::in);
	}
	else if (file_menu_answer == 2) {
		text.open("d:\\software_labs\\tetx_analizator\\splin_songs.txt", ios::in);
	}
	else if (file_menu_answer == 3) {
		text.open("d:\\software_labs\\tetx_analizator\\ddt_songs.txt", ios::in);
	}


	// «апись текста в массив стринг
	string str, str_arr = " ";
	while (!text.eof()) {
		text >> str;
		str_arr += " " + str;
	}


	// ѕеревод в нижний регистр
	switch (font_menu_answer) {
	case 1:
		transform(str_arr.begin(), str_arr.end(), str_arr.begin(), tolower);
		break;
	}


	// ¬ыбрасывание ненужных символов
	switch (symb_menu_answer) {
	case 1: {
		string unwanted_symbols = ".!?,-:;()*'\"\\/|ЦЂї=+@#є$%^&`~";
		str_arr = del_unwanted_symbols(str_arr, unwanted_symbols);
		break;
	}
	case 2:
		string unwanted_symbols;
		cout << "		<=============================================>" << endl << endl;
		cout << "			¬¬≈ƒ»“≈ ѕќƒ–яƒ Ќ≈∆≈Ћј≈ћџ≈ —»ћ¬ќЋџ" << endl;
		cin >> unwanted_symbols;
		system("cls");
		str_arr = del_unwanted_symbols(str_arr, unwanted_symbols);
		break;
	}


	// –азбиение слов 
	int count = words_counter(str_arr);
	string* splited_arr = text_spliter(str_arr, count);


	// —оздание словар€ типа "слово" - кол-во повторений (изначально идЄт сортировка по алфавиту от ј до я)
	map <string, int> words_map = map_creater(splited_arr, count);


	// ”даление нежелательных слов
	switch (word_menu_answer) {
	case 1: {  // —оюзы и предлоги
		const int unwanted_words_count = 49;
		string unwanted_words_union[unwanted_words_count] = { "и", "ни", "тоже", "также", "а", "но", "да", "однако", "зато", "же", "или", "либо", "то", "если", "столько", "сколько", "как", "так", "хот€", "будто", "словно", "пока", "когда", "зачем", "куда", "в", "к", "до", "через", "после", "до", "из", "за", "над", "под", "от", "по", "дл€", "про", "ввиду", "ради", "возле", "мимо", "около", "не", "у", "с", "на", "без" };
		words_map = del_unwanted_words(words_map, unwanted_words_union, unwanted_words_count);
	}
		  break;
	case 2: {  // ћестоимени€
		const int unwanted_words_count = 29;
		string unwanted_words_pronouns[unwanted_words_count] = { "мне", "€", "ты", "мы", "вы", "он", "она", "оно", "они", "себ€", "мой", "твой", "наш", "ваш", "свой", "кто", "что", "никто", "ничто", "некого", "нечего", "никакой", "ничей", "нисколько", "некто", "нечто", "сам", "самый", "каждый" };
		words_map = del_unwanted_words(words_map, unwanted_words_pronouns, unwanted_words_count);
	}
		  break;
	case 3: {
		const int unwanted_words_count = 78;
		string unwanted_words_all[unwanted_words_count] = { "мне", "и", "ни", "тоже", "также", "а", "но", "да", "однако", "зато", "же", "или", "либо", "то", "если", "столько", "сколько", "как", "так", "хот€", "будто", "словно", "пока", "когда", "зачем", "куда", "в", "к", "до", "через", "после", "до", "из", "за", "над", "под", "от", "по", "дл€", "про", "ввиду", "ради", "возле", "мимо", "около", "€", "ты", "мы", "вы", "он", "она", "оно", "они", "себ€", "мой", "твой", "наш", "ваш", "свой", "кто", "что", "никто", "ничто", "некого", "нечего", "никакой", "ничей", "нисколько", "некто", "нечто", "сам", "самый", "каждый", "не", "у", "с", "на", "без" };
		words_map = del_unwanted_words(words_map, unwanted_words_all, unwanted_words_count);
	}
	}


	// —ортировка по убыванию / возрастанию / алфавиту и вывод
	cout << "		<=============================================>" << endl << endl;
	cout << "			ќ“—ќ–“»–ќ¬јЌЌџ… “≈ —“" << endl << endl;
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