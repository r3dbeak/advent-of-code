#include <bits/stdc++.h>
using namespace std;

int main()
{
    int result{0};
    ifstream file{"../input/day03.in"};
    if (!file)
    {
        cerr << "Cannot open the file" << endl;
        exit(1);
    }
    string line;
    regex re(R"(mul\((\d+),(\d+)\))");
    while (getline(file, line))
    {
        for (sregex_iterator it(line.begin(), line.end(), re), end_it; it != end_it; ++it)
        {
            smatch match = *it;
            int a = stoi(match[1]);
            int b = stoi(match[2]);
            result += a * b;
        }
    }
    cout << result << endl;
}