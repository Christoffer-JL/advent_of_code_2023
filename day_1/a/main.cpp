#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream in("input_real");
    string line;
    int tot{0};
    string signs = "0123456789";

    while (in >> line)
    {
        int num{0};
        num = line[line.find_first_of(signs)] - '0';
        num = num * 10;
        num += line[line.find_last_of(signs)] - '0';
        tot += num;
    }
    cout << tot << endl;
}