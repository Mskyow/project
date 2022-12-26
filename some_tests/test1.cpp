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
    
}