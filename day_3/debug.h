#ifndef DEBUG_H
#define DEBUG_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

void print(string s) { cout << s << endl; };
int get_sum_from_lines(string &upper, string &middle, string &lower);
bool is_machine_part(string &upper, string &middle, string &lower, const int &index, const int &length);
string get_sign_composite(string &upper, string &middle, string &lower);

void two_parts_surround(string &upper, string &middle, string &lower, size_t &index, int &sum);
int extract_num(string &line, int index);

#endif