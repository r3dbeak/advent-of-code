#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> lefties;
    vector<int> righties;

    // Read input
    ifstream file{"../input/day01.in"};
    string line;
    while (getline(file, line))
    {
        // Parse via stringstream
        // a-b identifier: word number
        int a, b;
        stringstream ss(line);
        ss >> a >> b;
        lefties.push_back(a);
        righties.push_back(b);
    }

    // Process input
    long long result = accumulate(lefties.begin(), lefties.end(), 0, [&](long long sum, int l)
                                  { return sum + count(righties.begin(), righties.end(), l) * l; });
    cout << result;
    return 0;
}