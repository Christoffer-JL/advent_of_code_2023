#include "../debug.h"

int main()
{
    fstream f("test_input");
    string line;

    while (getline(f, line))
    {
        line = line.substr(line.find_first_of(':') + 2);

        stringstream ss(line);
        string num;

        while (ss >> num)
        {
            if (num == "|")
            {
                break;
            }

            print("first: " + num);
        }

        while (ss >> num)
        {
            print("second: " + num);
        }
    }

    return 0;
}