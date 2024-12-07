#include <bits/stdc++.h>
using namespace std;

using Data = vector<vector<unsigned long long>>;
Data readData(const string &filename)
{
    Data data;
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        vector<unsigned long long> numbers;
        istringstream iss(line);
        unsigned long long result;
        char trash;
        iss >> result >> trash;
        numbers.push_back(result);
        unsigned long long num;
        while (iss >> num)
        {
            numbers.push_back(num);
        }
        data.push_back(numbers);
    }
    return data;
}

unsigned long long concatenate(unsigned long long a, unsigned long long b)
{
    stringstream ss;
    ss << a << b;
    return stoull(ss.str());
}

int main()
{
    Data data = readData("../input/day07.in"); // vector<vector<int>> = [result, num1, num2, num3, ... ]

    unsigned long long sum{};
    for (auto &numbers : data)
    {
        auto result = numbers[0];
        auto inputs = vector<unsigned long long>{numbers.begin() + 1, numbers.end()};
        unsigned long long tmp;
        unsigned long long numOperators = inputs.size() - 1;
        unsigned long long numCombinations = pow(3, numOperators); // 3 operators: +, *, ||

        for (unsigned long long i = 0; i < numCombinations; ++i)
        {
            auto tmp{inputs[0]};
            unsigned long long op = i;
            for (size_t j = 0; j < numOperators; ++j)
            {
                unsigned long long operatorType = op % 3;
                op /= 3;
                if (operatorType == 0)
                    tmp += inputs[j + 1];
                else if (operatorType == 1)
                    tmp *= inputs[j + 1];
                else if (operatorType == 2)
                    tmp = concatenate(tmp, inputs[j + 1]);
            }
            if (tmp == result)
            {
                cout << "FOUND: " << tmp << " == " << result << endl;
                cout << "Operators: ";
                op = i;
                for (size_t j = 0; j < numOperators; ++j)
                {
                    unsigned long long operatorType = op % 3;
                    op /= 3;
                    if (operatorType == 0)
                        cout << "+ ";
                    else if (operatorType == 1)
                        cout << "* ";
                    else if (operatorType == 2)
                        cout << "|| ";
                }
                cout << endl;
                sum += tmp;
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}