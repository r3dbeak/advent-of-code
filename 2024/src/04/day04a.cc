#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<char>> grid;
    ifstream file{"../input/day04.in"};
    string line;
    while (getline(file, line))
    {
        grid.push_back(vector<char>(line.begin(), line.end()));
    }

    int m = grid.size();
    int n = grid[0].size();
    int count{0};
    vector<pair<int, int>> dirs{{1, 0},
                                {0, 1},
                                {-1, 0},
                                {0, -1},
                                {1, 1},
                                {1, -1},
                                {-1, 1},
                                {-1, -1}};
    set<string> allowedWords{"XMAS", "SAMX"};
    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            for (auto [dx, dy] : dirs)
            {
                string word = "";
                for (auto x = i, y = j; x >= 0 && x < m && y >= 0 && y < n; x += dx, y += dy)
                {
                    word += grid[x][y];
                    if (allowedWords.find(word) != allowedWords.end())
                    {
                        cout << "Found " << word << " at (" << i << ", " << j << ") and (" << x << ", " << y << ")" << endl;
                        count++;
                    }
                }
            }
        }
    }
    cout << count / 2 << endl;
    return 0;
}