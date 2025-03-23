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
    for (auto &updates : updatesList)
    {
        bool isValidList;
        auto didGetSorted{false};
        do
        {
            // Iterate from back to front
            for (auto i = updates.rbegin(); i != updates.rend() - 1; i++)
            {
                isValidList = true;
                auto j = i + 1;
                int num{*i};
                int nextNum;
                auto violatesRule = [&](int nextNum) -> bool
                { return find(rules[num].begin(), rules[num].end(), nextNum) != rules[num].end(); };
                // Sort the list until no violations anymore
                while (j != updates.rend())
                {
                    nextNum = *j;
                    if (violatesRule(nextNum))
                    {
                        isValidList = false;
                        iter_swap(i, j);
                        i = updates.rbegin() - 1;
                        didGetSorted = true;
                        break;
                    }
                    j++;
                }
            }
            auto middleEntry = [](const vector<int> &v) -> int
            { return v[v.size() / 2]; };
            if (didGetSorted)
                result += middleEntry(updates);
        } while (!isValidList);
    }
    cout << "Result: " << result << endl;
}