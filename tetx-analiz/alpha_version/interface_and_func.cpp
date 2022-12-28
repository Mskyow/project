#include <conio.h>
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

// ������� ����
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
	cout << "		<=============================================>" << endl;
}

int file_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� ����" << endl;
	cout << "		   1. ����� �����" << endl;
	cout << "		   2. ���� ���-��" << endl;
	cout << "		   3. �����-�� �����" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
		system("cls");
		return int(answer[0]) - 48;
	}
	else {
		cout << "�� ����� ������������ ��������. ���������� �����.";
		Sleep(2500);
		system("cls");
		file_menu();
	}
}

int font_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� �������" << endl;
	cout << "		   1. ������" << endl;
	cout << "		   2. �������" << endl;
	cout << "		   3. �� ������ �������" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
		system("cls");
		return int(answer[0]) - 48;
	}
	else {
		cout << "�� ����� ������������ ��������. ���������� �����.";
		Sleep(2500);
		system("cls");
		font_menu();
	}
}

int symb_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� ��������� �������� ��������" << endl;
	cout << "		   1. ������������� ����� ��������" << endl;
	cout << "		   2. ������� ���� �����" << endl;
	cout << "		   3. �� ������� �������" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
		system("cls");
		return int(answer[0]) - 48;
	}
	else {
		cout << "�� ����� ������������ ��������. ���������� �����.";
		Sleep(2500);
		system("cls");
		symb_menu();
	}

}

int word_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� ��������� �������� ����" << endl;
	cout << "		   1. ������������� ����� ����" << endl;
	cout << "		   2. ������� ���� �����" << endl;
	cout << "		   3. �� ������� �����" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
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

int sort_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� ����������" << endl;
	cout << "		   1. ���������� �������" << endl;
	cout << "		   2. � ������� �� ��������" << endl;
	cout << "		   3. � ������� �� �����������" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
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

void help() { // ��������
	cout << "		<=============================================>" << endl << endl;
	cout << "			������ ������" << endl << endl;
	cout << "		   !navmenu - ���� ��������� �� ����������" << endl;
	cout << "		   !exit - ����� �� ���������" << endl;
	cout << "		   !start - ������ �����������" << endl;
	cout << "		   !findword - ����� �� �����" << endl;
	cout << "		   !settings - ������ ��������� ���������" << endl << endl;
	cout << "		<=============================================>" << endl;
	_getch();
	system("cls");
}

// ������� ���������



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
		default:
			cout << "��� ����� �������" << endl;
			Sleep(750);
			system("cls");
			break;
		}
		cout << "�� ��� �������:\n" << file_menu_answer << endl << font_menu_answer << endl << symb_menu_answer << endl << word_menu_answer << endl << sort_menu_answer << endl;
		if (answer == "!exit") {
			break;
		}
		if (file_menu_answer && font_menu_answer && symb_menu_answer && word_menu_answer && sort_menu_answer) {
			cout << "�� ������� �������!!!";
			break;
		}
	}
}