#ifndef DEBUG_H
#define DEBUG_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>

using namespace std;

using Winners_and_actual = pair<int, int>;
using Cards = vector<Winners_and_actual>;

void print(string s) { cout << s << endl; };
void print(int i) { cout << i << endl; };

Cards cards;

#endif