#include <bits/stdc++.h>
using namespace std;

void readInput(string filename, map<int, vector<int>> &rules, vector<vector<int>> &updatesList)
{
    ifstream file{"../input/day05.in"};
    string line;
    int i, j;
    char c;
    bool readTable1{true};
    while (getline(file, line))
    {
        if (line.empty())
        {
            readTable1 = false;
            continue;
        }
        stringstream ss{line};
        if (readTable1)
        {
            ss >> i >> c >> j;
            rules[i].push_back(j);
        }
        else
        {
            vector<int> tmpUpdate{};
            string pageNum;
            while (getline(ss, pageNum, ','))
                tmpUpdate.push_back(stoi(pageNum));
            updatesList.push_back(tmpUpdate);
        }
    }
}

int main()
{
    map<int, vector<int>> rules;       // map of rules for each number
    vector<vector<int>> updatesList{}; // list of updates
    readInput("../input/day05.in", rules, updatesList);
    int result{0};
    for (const auto &updates : updatesList)
    {
        bool isValidList{true};
        // Iterate from back to front
        for (auto i = updates.rbegin(); i != updates.rend() - 1; i++)
        {
            int num{*i};
            int nextNum;
            auto violatesRule = [&](int nextNum) -> bool
            { return find(rules[num].begin(), rules[num].end(), nextNum) != rules[num].end(); };
            for (auto j = i + 1; j != updates.rend(); j++)
            {
                nextNum = *j;
                if (violatesRule(nextNum))
                    isValidList = false;
            }
        }
        auto middleEntry = [](const vector<int> &v) -> int
        { return v[v.size() / 2]; };
        if (isValidList)
            result += middleEntry(updates);
    }
    cout << "Result: " << result << endl;
}