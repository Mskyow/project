#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }

        return l.first < r.first;
    }
};

void main() {
    string out_str[9]{"apple", "gold", "apple", "red", "apple", "green", "gold", "gold", "red"}; 
    map <string, int> words_map;
    int str_len = 9;
    int temp_word_count = 1;
    for (int j = 0; str_len != 0; ) {
        for (int i = 1; i < str_len; i++) {
            if (out_str[j] == out_str[i]) {
                cout << out_str[j] << endl;
                temp_word_count++;
                for (; i < str_len - 1; i++) {
                    out_str[i] = out_str[i + 1];
                }
                str_len--;
                i = 1;
            }
        }
        words_map.insert(make_pair(out_str[j], temp_word_count));
        for (int g = 0; g < str_len; g++) {
            out_str[g] = out_str[g + 1];
        }
        str_len--;
        temp_word_count = 1;
    }
    map <string, int> ::iterator it = words_map.begin();
    for (int i = 0; it != words_map.end(); it++, i++) {
        cout << i << ") " << it->first << ", " << it->second << endl;
    }


    set<pair<string, int>, comp> set(words_map.begin(), words_map.end());
    for (auto const& pair : set) {
        cout << '{' << pair.first << "," << pair.second << '}' << endl;
    }
}