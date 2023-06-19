#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string ans = "";
vector<int> set;
unordered_set<int> unoset;

string oppositePlayer(string curr)
{
    if (curr == "Alice")
        return "Bob";
    return "Alice";
}

void eraseElementAndSum(int index1)
{
    int sum = 0;
    auto i = std::find(begin(set), end(set), set[index1]);
    set.erase(i, i + 2);
    set.insert(set.begin() + index1, sum);
    set.shrink_to_fit();
}

bool areDinstict()
{
    for (int i = 0; i < set.size(); i++)
    {
        unoset.insert(set[i]);
    }

    return (unoset.size() == set.size());
}

string solve(string currentPlayer)
{
    if (areDinstict(set))
        return currentPlayer;
    sort(set.begin(), set.end());
    for (int i = 0; i < set.size() - 1; i++)
    {
        if (set[i] == set[i + 1])
        {
            eraseElementAndSum(i);
            solve(oppositePlayer(currentPlayer));
        }
    }
}

int main()
{
    int n, s;
    cin >> n;
    string currentPlayer = "Alice";
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        set.resize(s);
        fill(set.begin(), set.end(), 1);
        solve(set, currentPlayer);
    }
}