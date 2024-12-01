#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> lefties;
    vector<int> righties;

    // Read input
    ifstream file{"../input/day01.txt"};
    string line;
    while (getline(file, line))
    {
        int a, b;
        stringstream ss(line);
        ss >> a >> b;
        lefties.push_back(a);
        righties.push_back(b);
    }

    // Process input
    sort(lefties.begin(), lefties.end());
    sort(righties.begin(), righties.end());
    int result = inner_product(lefties.begin(), lefties.end(), righties.begin(), 0, plus<>(), [](int l, int r)
                               { return abs(l - r); });
    cout << result;
    return 0;
}