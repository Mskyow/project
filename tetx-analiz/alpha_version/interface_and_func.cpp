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

// Interface func
void prog_name() {
	cout << "		<=============================================>" << endl << endl;
	cout << "		                 TEXT ANALYZER" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void nav_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			���� ���������" << endl;
	cout << "		   1. ����� �����" << endl;
	cout << "		   2. ��������� ��������" << endl;
	cout << "		   3. ��������� ������������� ��������" << endl;
	cout << "		   4. ��������� ������������� ����" << endl;
	cout << "		   5. ����� ����������" << endl << endl;
	cout << "		   ? - ����� ������ ����������" << endl << endl;
	cout << "		   ! - ����� ������ ��������� ���������" << endl << endl;
	cout << "		<=============================================>" << endl;
}

int file_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			�������� ����" << endl;
		cout << "		   1. ����� ������ ������" << endl;
		cout << "		   2. ����� ������ �����" << endl;
		cout << "		   3. ����� ������ ���" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "�� ����� ������������ ��������. ���������� �����.";
			Sleep(2500);
			system("cls");
		}
	}
}

int font_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			������� ��������" << endl;
		cout << "		   1. ��������� � ������" << endl;
		cout << "		   2. �� ������ �������" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 50 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "�� ����� ������������ ��������. ���������� �����.";
			Sleep(2500);
			system("cls");
		}
	}
}

int symb_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			�������� ��������� �������� ��������" << endl;
		cout << "		   1. ������������� ����� ��������" << endl;
		cout << "		   2. ������� ���� �����" << endl;
		cout << "		   3. �� ������� �������" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "�� ����� ������������ ��������. ���������� �����.";
			Sleep(2500);
			system("cls");
		}
	}
}

int word_menu() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			�������� ��������� �������� ����" << endl;
		cout << "		   1. ����� � ��������" << endl;
		cout << "		   2. �����������" << endl;
		cout << "		   3. ��� �������������" << endl;
		cout << "		   4. �� ������� �����" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 52 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "�� ����� ������������ ��������. ���������� �����.";
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
		cout << "			�������� ����������" << endl;
		cout << "		   1. ���������� �������" << endl;
		cout << "		   2. � ������� �� ��������" << endl;
		cout << "		   3. � ������� �� �����������" << endl << endl;
		cout << "		<=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) >= 49 && int(answer[0]) <= 51 && answer.length() == 1) {
			system("cls");
			return int(answer[0]) - 48;
		}
		else {
			cout << "�� ����� ������������ ��������. ���������� �����.";
			Sleep(2500);
			system("cls");
			sort_menu();
		}
	}
}

void help() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			����������" << endl;
	cout << "		   � �.1 �� ������ ������� ����������� ����." << endl;
	cout << "		   � �.2 �� ��������� ����� �� ����������" << endl;
	cout << "		  ����� � ������ �������." << endl;
	cout << "		   � �.3 ������������� ������� ���������" << endl;
	cout << "		  �������, �� ��������� ���� �� �������" << endl;
	cout << "		  ����������(��������, \"�����.\", \",����-\")." << endl;
	cout << "		   � �.4 �� ������ ������� ����� �����" << endl;
	cout << "		  ����� �������(��������, ����� ������" << endl;
	cout << "		  ����������� � �����)." << endl;
	cout << "		   � �.5 � ��� ���� ����������� �������" << endl;
	cout << "		  �������� ����������." << endl << endl;
	cout << "		<=============================================>" << endl;
	_getch();
	system("cls");
}

void status(int file_menu_answer, int font_menu_answer, int symb_menu_answer, int word_menu_answer, int sort_menu_answer) {
	string status_answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			��������� ���������" << endl;
	switch (file_menu_answer) {
	case 1:
		status_answer = "����� ������ ������";
		break;
	case 2:
		status_answer = "����� ������ �����";
		break;
	case 3:
		status_answer = "����� ������ ���";
		break;
	case 0:
		status_answer = "�� �������";
		break;
	}
	cout << "		   ����������� ����: " << status_answer << endl;
	switch (font_menu_answer) {
	case 1:
		status_answer = "������";
		break;
	case 2:
		status_answer = "�� ��������";
		break;
	case 0:
		status_answer = "�� �������";
		break;
	}
	cout << "		   �������: " << status_answer << endl;
	switch (symb_menu_answer) {
	case 1:
		status_answer = "������������� �����";
		break;
	case 2:
		status_answer = "���� �����";
		break;
	case 3:
		status_answer = "�� ������� �������";
		break;
	case 0:
		status_answer = "�� �������";
		break;
	}
	cout << "		   ��������� �������: "  << status_answer << endl;
	switch (word_menu_answer) {
	case 1:
		status_answer = "����� � ��������";
		break;
	case 2:
		status_answer = "�����������";
		break;
	case 3:
		status_answer = "��� �������������";
		break;
	case 4:
		status_answer = "�� ������� �����";
		break;
	case 0:
		status_answer = "�� �������";
		break;
	}
	cout << "		   ��������� �����: " << status_answer << endl;
	switch (sort_menu_answer) {
	case 1:
		status_answer = "���������� �������";
		break;
	case 2:
		status_answer = "� ������� ��������";
		break;
	case 3:
		status_answer = "� ������� �����������";
		break;
	case 0:
		status_answer = "�� �������";
		break;
	}
	cout << "		   ��� ����������: " << status_answer << endl << endl;
	cout << "		<=============================================>" << endl;
	_getch();
	system("cls");
}

int ready_for_analysis() {
	string answer;
	while (true) {
		cout << "		<=============================================>" << endl << endl;
		cout << "			��� ��������� �����������" << endl;
		cout << "		   1. ������ ������" << endl;
		cout << "		   2. �������� ���������" << endl << endl;
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
			cout << "�� ����� ������������ ��������. ���������� �����.";
			Sleep(2500);
			system("cls");
		}
	}
}

void statistics(double seconds, int count, map <string, int> words_map) {
	cout << "		<=============================================>" << endl << endl;
	cout << "			������� ����������" << endl;
	cout << "		   ����� �������: " << seconds << " ���." << endl;
	cout << "		   ����� ���������� ����: " << count << endl;
	cout << "		   ���������� ���������� ����: " << words_map.size() << endl << endl;
	cout << "		<=============================================>" << endl << endl << endl;
}


// Programm func
string del_unwanted_symbols(string str_arr, string unwanted_symbols);

int words_counter(string str_arr);

string* text_spliter(string str_arr, int count);

map <string, int> map_creater(string* splited_str, int count);

map <string, int> del_unwanted_words(map <string, int> words_map, string* unwanted_words, const int unwanted_words_count);

struct comp1  // ��� ����� ��� ���������� 
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		if (l.second != r.second) {
			return l.second > r.second;  // < - ���������� �� �����������; > - �� ��������
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
			return l.second < r.second;  // < - ���������� �� �����������; > - �� ��������
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
				cout << "��� ����� �������." << endl;
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
			cout << "��� ����� �������." << endl;
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
		string unwanted_words_union[unwanted_words_count] = { "�", "��", "����", "�����", "�", "��", "��", "������", "����", "��", "���", "����", "��", "����", "�������", "�������", "���", "���", "����", "�����", "������", "����", "�����", "�����", "����", "�", "�", "��", "�����", "�����", "��", "��", "��", "���", "���", "��", "��", "���", "���", "�����", "����", "�����", "����", "�����", "��", "�", "�", "��", "���"};
		words_map = del_unwanted_words(words_map, unwanted_words_union, unwanted_words_count);
	}
		  break;
	case 2: {  // �����������
		const int unwanted_words_count = 29;
		string unwanted_words_pronouns[unwanted_words_count] = {"���", "�", "��", "��", "��", "��", "���", "���", "���", "����", "���", "����", "���", "���", "����", "���", "���", "�����", "�����", "������", "������", "�������", "�����", "���������", "�����", "�����", "���", "�����", "������"};
		words_map = del_unwanted_words(words_map, unwanted_words_pronouns, unwanted_words_count);
	}
		  break;
	case 3: {
		const int unwanted_words_count = 78;
		string unwanted_words_all[unwanted_words_count] = {"���", "�", "��", "����", "�����", "�", "��", "��", "������", "����", "��", "���", "����", "��", "����", "�������", "�������", "���", "���", "����", "�����", "������", "����", "�����", "�����", "����", "�", "�", "��", "�����", "�����", "��", "��", "��", "���", "���", "��", "��", "���", "���", "�����", "����", "�����", "����", "�����", "�", "��", "��", "��", "��", "���", "���", "���", "����", "���", "����", "���", "���", "����", "���", "���", "�����", "�����", "������", "������", "�������", "�����", "���������", "�����", "�����", "���", "�����", "������", "��", "�", "�", "��", "���" };
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
	cout << "			����� �� �����" << endl;
	cout << "		   ������� �����, ����� ������, ������� ���" << endl;
	cout << "		   ��� ����������� � ������." << endl << endl;
	cout << "		   !exit - ����� ����� �� ���������" << endl << endl;
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
			cout << "��� ����������." << endl;
		}
	}
}