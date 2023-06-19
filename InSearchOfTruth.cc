#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int m[N], i = 1;
void ask(int x)
{
    cout << "+ " << x << endl;
    int k;
    cin >> k;
    i += x;
    if (m[k])
    {
        cout << "! " << i - m[k] << endl;
        exit(0);
    }
    m[k] = i;
}
int main()
{
    int x;
    cin >> x;
    m[x] = 1;
    for (int i = 1; i <= 1000; i++)
        ask(1);
    for (int i = 1; i <= 1023; i++)
        ask(1000);
}