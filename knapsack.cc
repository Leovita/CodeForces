#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVect2(vector<float> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// returns index of the most worthy item
int getMaxWorth(vector<float> worth)
{
    int mxIndex = 0;
    for (int i = 1; i < worth.size(); i++)
    {
        if (worth[i] > worth[mxIndex])
        {
            mxIndex = i;
        }
    }
    return mxIndex;
}

vector<float> knapSackSolve()
{
    int size, mxRN;
    float comp, bagCap = 15;
    cin >> size;

    vector<float> ans(size); //{1 if taken: 0}
    vector<float> weight(size);
    vector<float> profit(size);
    vector<float> worth(size);

    fill(weight.begin(), weight.end(), 0);
    fill(profit.begin(), profit.end(), 0);
    fill(worth.begin(), worth.end(), 0);
    fill(ans.begin(), ans.end(), 0);

    for (int i = 0; i < size; i++)
    {
        cin >> weight[i] >> profit[i];
    }
    // compute worth vector values where worth[i] = profit[i]/weight[i]
    for (int i = 0; i < size; i++)
    {
        worth[i] = (profit[i] / weight[i]);
    }
    mxRN = getMaxWorth(worth);

    while ((bagCap - weight[mxRN]) >= 0)
    {
        bagCap -= weight[mxRN];
        ans[mxRN] = 1;
        worth[mxRN] = -1;
        mxRN = getMaxWorth(worth);
    }

    return ans;
}

int main()
{
    cin.tie(0);
    vector<float> ans = knapSackSolve();
    printVect2(ans);
}