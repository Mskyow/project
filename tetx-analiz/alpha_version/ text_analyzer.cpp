#include <conio.h>
#include <time.h> 
#include <iomanip>
#include <iostream>
#include <algorithm>  // ����. ��� transform()
#include <fstream>  // ����. ��� ������ � �������
#include <windows.h>  // ����. ��� �����/������ � ������� 
#include <string>  // ����. ��� ������ �� ��������
#include <ctime>  // ����. ��� �������
#include <map>  // ����. ��� ��������
#include <set>  // ����. ��� ���
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


	// ������ ������ � ������ ������
	string str, str_arr = " ";
	while (!text.eof()) {
		text >> str;
		str_arr += " " + str;
	}


	// ������� � ������ �������
	switch (font_menu_answer) {
	case 1:
		transform(str_arr.begin(), str_arr.end(), str_arr.begin(), tolower);
		break;
	}


	// ������������ �������� ��������
	switch (symb_menu_answer) {
	case 1: {
		string unwanted_symbols = ".!?,-:;()*'\"\\/|���=+@#�$%^&`~";
		str_arr = del_unwanted_symbols(str_arr, unwanted_symbols);
		break;
	}
	case 2:
		string unwanted_symbols;
		cout << "		<=============================================>" << endl << endl;
		cout << "			������� ������ ���������� �������" << endl;
		cin >> unwanted_symbols;
		system("cls");
		str_arr = del_unwanted_symbols(str_arr, unwanted_symbols);
		break;
	}


	// ��������� ���� 
	int count = words_counter(str_arr);
	string* splited_arr = text_spliter(str_arr, count);


	// �������� ������� ���� "�����" - ���-�� ���������� (���������� ��� ���������� �� �������� �� � �� �)
	map <string, int> words_map = map_creater(splited_arr, count);


	// �������� ������������� ����
	switch (word_menu_answer) {
	case 1: {  // ����� � ��������
		const int unwanted_words_count = 49;
		string unwanted_words_union[unwanted_words_count] = { "�", "��", "����", "�����", "�", "��", "��", "������", "����", "��", "���", "����", "��", "����", "�������", "�������", "���", "���", "����", "�����", "������", "����", "�����", "�����", "����", "�", "�", "��", "�����", "�����", "��", "��", "��", "���", "���", "��", "��", "���", "���", "�����", "����", "�����", "����", "�����", "��", "�", "�", "��", "���" };
		words_map = del_unwanted_words(words_map, unwanted_words_union, unwanted_words_count);
	}
		  break;
	case 2: {  // �����������
		const int unwanted_words_count = 29;
		string unwanted_words_pronouns[unwanted_words_count] = { "���", "�", "��", "��", "��", "��", "���", "���", "���", "����", "���", "����", "���", "���", "����", "���", "���", "�����", "�����", "������", "������", "�������", "�����", "���������", "�����", "�����", "���", "�����", "������" };
		words_map = del_unwanted_words(words_map, unwanted_words_pronouns, unwanted_words_count);
	}
		  break;
	case 3: {
		const int unwanted_words_count = 78;
		string unwanted_words_all[unwanted_words_count] = { "���", "�", "��", "����", "�����", "�", "��", "��", "������", "����", "��", "���", "����", "��", "����", "�������", "�������", "���", "���", "����", "�����", "������", "����", "�����", "�����", "����", "�", "�", "��", "�����", "�����", "��", "��", "��", "���", "���", "��", "��", "���", "���", "�����", "����", "�����", "����", "�����", "�", "��", "��", "��", "��", "���", "���", "���", "����", "���", "����", "���", "���", "����", "���", "���", "�����", "�����", "������", "������", "�������", "�����", "���������", "�����", "�����", "���", "�����", "������", "��", "�", "�", "��", "���" };
		words_map = del_unwanted_words(words_map, unwanted_words_all, unwanted_words_count);
	}
	}


	// ���������� �� �������� / ����������� / �������� � �����
	cout << "		<=============================================>" << endl << endl;
	cout << "			��������������� �����" << endl << endl;
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