#include <windows.h>  // Библ. для ввода/вывода в консоль 
#include <string>  // Библ. для работы со строками
#include <ctime>  // Библ. для таймера
#include <map>  // Библ. для словарей
#include <set>  // Библ. для сет
#include <vector>
#include "interface.h"
#include "interface_and_func.cpp"

using namespace std;

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