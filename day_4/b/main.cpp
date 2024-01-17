#include "../debug.h"

int main()
{
    fstream f("test_input");
    string line;

    while (f >> line)
    {
        print(line);
    }

    return 0;
}