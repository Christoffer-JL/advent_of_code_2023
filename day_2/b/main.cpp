#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void check_possibility(string &set, int &red, int &green, int &blue)
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
                cube_color_and_count.erase(0, cube_color_and_count.find_last_of(' ') + 1);

                if (cube_color_and_count == "green")
                {
                    if (count > green)
                        green = count;
                }

                else if (cube_color_and_count == "red")
                {
                    if (count > red)
                        red = count;
                }

                else if (cube_color_and_count == "blue")
                {
                    if (count > blue)
                        blue = count;
                }
            }
        }
    }
}

int main()
{
    ifstream in("input_real");
    string game;
    int game_tot{0};
    while (getline(in, game))
    {
        int red{0}, blue{0}, green{0};

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

            check_possibility(set, red, green, blue);
        }

        game_tot += red * green * blue;
    }
    cout << "Tot: " << game_tot << endl;
    return 0;
}