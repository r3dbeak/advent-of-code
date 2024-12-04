#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> numbers)
{
    vector<int> dx(numbers.size() - 1, 0);
    bool incValid = true;
    bool decValid = true;

    for (int i = 0; i < numbers.size() - 1; i++)
        dx[i] = numbers[i + 1] - numbers[i];

    for (const auto &dxi : dx)
    {
        if (dxi < 1 || dxi > 3)
            incValid = false;
        if (dxi > -1 || dxi < -3)
            decValid = false;
    }
    return incValid || decValid;
}

int main()
{
    ifstream file{"../input/day02.in"};
    string line;
    int valids{0};
    while (getline(file, line))
    {
        vector<int> numbers;
        stringstream ss(line);
        int number{0};
        while (ss >> number)
        {
            numbers.push_back(number);
        }
        if (isSafe(numbers))
            valids++;
        else
        {
            for (int i = 0; i < numbers.size(); i++)
            {
                vector<int> numbersAlt = numbers;
                numbersAlt.erase(numbersAlt.begin() + i);
                if (isSafe(numbersAlt))
                {
                    valids++;
                    break;
                }
            }
        }
    }
    cout << valids << endl;
}