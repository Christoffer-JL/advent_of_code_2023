#include "../debug.h"

string not_signs = "0123456789.";

int main()
{
    ifstream in("input_real");

    string upper_line, middle_line, lower_line, temp_line;

    int sum{0};

    while (getline(in, temp_line))
    {
        upper_line = middle_line;
        middle_line = lower_line;
        lower_line = temp_line;

        sum += get_sum_from_lines(upper_line, middle_line, lower_line);
    }
    upper_line = middle_line;
    middle_line = lower_line;
    lower_line = "";

    sum += get_sum_from_lines(upper_line, middle_line, lower_line);

    print(to_string(sum));

    return 0;
}

int get_sum_from_lines(string &upper, string &middle, string &lower)
{
    int sum{0};
    int found_num{0};
    string nums = "0123456789";
    for (int index = 0; index < middle.length(); index++)
    {
        char c = middle[index];
        if (nums.find(c) != string::npos)
        {
            found_num = found_num * 10 + (c - '0');
        }
        else if (found_num != 0)
        {
            if (is_machine_part(upper, middle, lower, index - to_string(found_num).length(), to_string(found_num).length()))
            {
                sum += found_num;
            }
            found_num = 0;
        }
    }
    if (found_num != 0)
    {
        if (is_machine_part(upper, middle, lower, middle.length() - to_string(found_num).length(), to_string(found_num).length()))
        {
            sum += found_num;
        }
    }
    return sum;
}

bool is_machine_part(string &upper, string &middle, string &lower, const int &index, const int &length)
{
    string sign_composite = get_sign_composite(upper, middle, lower);

    for (int i = index; i < index + length; i++)
    {
        char c = sign_composite[i];
        if (c != '.')
        {
            return true;
        }
    }
    if (index != 0)
    {
        if (sign_composite[index - 1] != '.')
        {
            return true;
        }
    }

    if (index + length < middle.length())
    {
        if (sign_composite[index + length] != '.')
        {
            return true;
        }
    }

    return false;
}

string get_sign_composite(string &upper, string &middle, string &lower)
{
    string ret;

    auto upper_sign = '.';
    auto middle_sign = '.';
    auto lower_sign = '.';

    for (size_t index = 0; index < middle.length(); index++)
    {
        if (upper.length() > 0)
            upper_sign = not_signs.find(upper[index]);

        if (middle.length() > 0)
            middle_sign = not_signs.find(middle[index]);

        if (lower.length() > 0)
            lower_sign = not_signs.find(lower[index]);

        if (upper_sign == string::npos)
        {
            ret += upper_sign;
        }
        else if (middle_sign == string::npos)
        {
            ret += middle_sign;
        }
        else if (lower_sign == string::npos)
        {
            ret += lower_sign;
        }
        else
        {
            ret += '.';
        }
    }
    return ret;
}