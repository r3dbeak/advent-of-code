#include <bits/stdc++.h>
using namespace std;

int main()
{
    int result{0};
    bool readInstruction{true};
    ifstream file{"../input/day03.in"};
    string line;
    regex re(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    while (getline(file, line))
    {
        for (sregex_iterator it(line.begin(), line.end(), re), end_it; it != end_it; ++it)
        {
            smatch match = *it;
            if (match[0] == "do()")
                readInstruction = true;
            else if (match[0] == "don't()")
                readInstruction = false;
            else
            {
                if (readInstruction)
                {
                    int a = stoi(match[1]);
                    int b = stoi(match[2]);
                    result += a * b;
                }
            }
        }
    }
    cout << result << endl;
}