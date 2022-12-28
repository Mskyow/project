#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


// ��������� ����
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
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void file_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� ����" << endl;
	cout << "		   1. ����� �����" << endl;
	cout << "		   2. �����-�� �����" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void font_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� �������" << endl;
	cout << "		   1. ������" << endl;
	cout << "		   2. �������" << endl;
	cout << "		   3. �� ������ �������" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void symb_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� ��������� �������� ��������" << endl;
	cout << "		   1. ������������� ����� ��������" << endl;
	cout << "		   2. ������� ���� �����" << endl;
	cout << "		   3. �� ������� �������" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void word_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� ��������� �������� ����" << endl;
	cout << "		   1. ������������� ����� ����" << endl;
	cout << "		   2. ������� ���� �����" << endl;
	cout << "		   3. �� ������� �����" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void sort_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			�������� ����������" << endl;
	cout << "		   1. ���������� �������" << endl;
	cout << "		   2. � ������� �� ��������" << endl;
	cout << "		   3. � ������� �� �����������" << endl << endl;
	cout << "		   !help ����� �������� ������ ���� ������" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void help() { // ��������
	cout << "		<=============================================>" << endl << endl;
	cout << "			������ ������" << endl << endl;
	cout << "			������� ��� ������ ����" << endl;
	cout << "		   !navmenu - ���� ��������� �� ����������" << endl;
	cout << "		   !filemenu - ���� �������� �������� �����" << endl;
	cout << "		   !fontmenu - ���� �������� ��������" << endl;
	cout << "		   !symbmenu - ���� �������� ��������� ��������" << endl;
	cout << "		   !wordmenu - ���� �������� ��������� ����" << endl;
	cout << "		   !sortmenu - ���� �������� ����������" << endl << endl;
	cout << "			������ �������" << endl;
	cout << "		   !exit - ����� �� ���������" << endl;
	cout << "		   !start - ������ �����������" << endl;
	cout << "		   !findword - ����� �� �����" << endl;
	cout << "		   !settings - ������ ��������� " << endl << endl;
	cout << "		<=============================================>" << endl;
}

void main() {

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int answer;
	cin >> answer;
	cout << answer;

	prog_name();
	cout << endl << endl;
	_getch();
	system("cls");

	nav_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	file_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	font_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	symb_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	word_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	sort_menu();
	cout << endl << endl;
	_getch();
	system("cls");

	help();
	cout << endl << endl;
	_getch();
	system("cls");
}