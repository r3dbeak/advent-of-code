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

    string diag1 = "";
    string diag2 = "";
    vector<string> allowedDiags{"MAS", "SAM"};
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            diag1 = string(1, grid[i - 1][j - 1]) + grid[i][j] + grid[i + 1][j + 1];
            diag2 = string(1, grid[i - 1][j + 1]) + grid[i][j] + grid[i + 1][j - 1];
            if (find(allowedDiags.begin(), allowedDiags.end(), diag1) != allowedDiags.end() &&
                find(allowedDiags.begin(), allowedDiags.end(), diag2) != allowedDiags.end())
                count++;
        }
    }
    cout << count << endl;
}