#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> nums_as_strings = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10}};

string signs = "0123456789";

int find_number(std::string &s)
{
    string num;
    int first_digit{0};
    int second_digit{0};

    for (char c : s)
    {
        if (first_digit != 0)
            break;
        if (signs.find(c) == string::npos)
        {
            num += c;

            for (pair<string, int> p : nums_as_strings)
            {
                if (num.find(p.first) != string::npos)
                {
                    first_digit = p.second;
                    break;
                }
            }
        }
        else
        {
            first_digit = c - '0';
            break;
        }
    }
    num = "";
    for (int x = s.length(); x >= 0; x--)
    {
        if (second_digit != 0)
            break;
        char c = s[x];
        if (signs.find(c) == string::npos)
        {
            num += c;
            string reversed_num = num;
            reverse(reversed_num.begin(), reversed_num.end());
            for (pair<string, int> p : nums_as_strings)
            {
                if (reversed_num.find(p.first) != string::npos)
                {
                    second_digit = p.second;
                    break;
                }
            }
        }
        else
        {
            second_digit = c - '0';
            break;
        }
    }
    return first_digit * 10 + second_digit;
}

int main()
{
    ifstream in("input_real");
    string line;
    int tot{0};

    while (in >> line)
    {
        cout << "check\n";
        tot += find_number(line);
    }
    cout << tot << endl;
}
