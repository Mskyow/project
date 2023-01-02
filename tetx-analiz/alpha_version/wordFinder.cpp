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
#include "interface.h"


using namespace std;

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