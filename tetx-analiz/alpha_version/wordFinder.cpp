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
#include "interface.h"


using namespace std;

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