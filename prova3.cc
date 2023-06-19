#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool chance = true;
int lowest = 0;
int firstElem = 0;

bool isBeatiful(vector<int> data)
{
    bool sorted = is_sorted(begin(data), end(data));
    size_t arrSize = data.size();
    if (sorted)
    {
        return true;
    }
    else if (!sorted && chance == true)
    {
        lowest = data[arrSize - 1];
        chance = false;
        return true;
    }
    else if (!sorted && chance == false)
    {
        if ((data[arrSize - 1] >= lowest && data[arrSize - 1] <= firstElem))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void solve(vector<int> data)
{
    vector<int> app(data.size());
    for (int i = 0; i < data.size(); i++)
    {
        if (i == 0)
            firstElem = data[i];
        app.push_back(data[i]);
        if (isBeatiful(app))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int lenght;
        cin >> lenght;
        vector<int> a(lenght);
        for (auto &s : a)
        {
            cin >> s;
        }
        solve(a);
    }
}