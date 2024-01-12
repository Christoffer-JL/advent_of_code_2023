#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

bool check_possibility(string &set)
{

    map<string, int> counts = {
        {"blue", 14},
        {"green", 13},
        {"red", 12},
    };

    while (!set.empty())
    {
        string cube_color_and_count;
        auto index = set.find_first_of(',');

        if (index != string::npos)
        {
            cube_color_and_count = set.substr(0, index);
            set.erase(0, index + 1);
        }
        else
        {
            cube_color_and_count = set;
            set = "";
        }

        for (auto p : counts)
        {
            if (cube_color_and_count.find(p.first) != string::npos)
            {

                int count = stoi(cube_color_and_count.substr(0, cube_color_and_count.find_last_of(' ')));
                if (p.second < count)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{

    ifstream in("input_real");
    string game;
    int game_tot{0};
    while (getline(in, game))
    {
        bool impossible = false;

        string game_num(&game[game.find_first_of(' ') + 1], &game[game.find_first_of(':')]);

        game = game.substr(game.find_first_of(':') + 2);

        string set;

        while (!game.empty())
        {
            auto index = game.find_first_of(';');
            if (index != string::npos)
            {
                set = game.substr(0, index);
                game.erase(0, index + 1);
            }
            else
            {
                set = game;
                game = "";
            }

            if (!check_possibility(set))
            {
                impossible = true;
            }
        }
        if (!impossible)
            game_tot += stoi(game_num);
    }

    cout << "Tot: " << game_tot << endl;
    return 0;
}