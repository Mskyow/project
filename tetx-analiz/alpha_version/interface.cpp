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
	cout << "		   ��������� �������: " << status_answer << endl;
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
		cout << "		    <=============================================>" << endl << endl;
		cout << "			   ��� ��������� �����������" << endl;
		cout << "		       1. ������ ������" << endl;
		cout << "		       2. �������� ���������" << endl << endl;
		cout << "		    <=============================================>" << endl;
		cin >> answer;
		if (int(answer[0]) == 49 && answer.length() == 1) {
			system("cls");
			return 1;
		}
		else if (int(answer[0]) == 50 && answer.length() == 1) {
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

