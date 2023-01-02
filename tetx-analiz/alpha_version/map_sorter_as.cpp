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
#include "interface_and_func.cpp"


using namespace std;


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