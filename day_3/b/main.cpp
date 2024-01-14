#include "../debug.h"
// 86841457
int main()
{
    ifstream in("input_real");

    string upper_line, middle_line, lower_line, temp_line;

    long sum{0};

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
    for (size_t index = 0; index < middle.length(); index++)
    {
        char c = middle[index];
        if (c == '*')
        {
            two_parts_surround(upper, middle, lower, index, sum);
        }
    }
    return sum;
}

void two_parts_surround(string &upper, string &middle, string &lower, size_t &index, int &sum)
{
    vector<int> found_nums;

    bool upper_found = false, lower_found = false;

    for (size_t i = (index == 0) ? 0 : index - 1; i <= (index == middle.size() ? middle.size() : index + 1); i++)
    {
        if (isdigit(upper[i]) && !upper_found)
        {
            int extracted_num = extract_num(upper, i);

            if (extracted_num != 0)
                found_nums.push_back(extracted_num);

            if (isdigit(upper[index]))
            {
                upper_found = true;
            }
        }

        if (isdigit(middle[i]))
        {
            found_nums.push_back(extract_num(middle, i));
        }

        if (isdigit(lower[i]) && !lower_found)
        {
            int extracted_num = extract_num(lower, i);

            if (extracted_num != 0)
                found_nums.push_back(extracted_num);

            if (isdigit(lower[index]))
            {
                lower_found = true;
            }
        }
    }

    if (found_nums.size() == 2)
    {
        print(to_string(found_nums[0]) + "  " + to_string(found_nums[1]));
        sum += found_nums[0] * found_nums[1];
    }
}

int extract_num(string &line, int index)
{
    if (index < 0 || index >= line.length() || !isdigit(line[index]))
    {
        return 0;
    }

    while (index > 0 && isdigit(line[index - 1]))
    {
        index--;
    }

    int ret = 0;

    while (index < line.length() && isdigit(line[index]))
    {
        ret = ret * 10 + (line[index] - '0');
        index++;
    }

    return ret;
}
