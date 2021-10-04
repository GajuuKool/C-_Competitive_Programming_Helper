#include <bits/stdc++.h>
using namespace std;

//Comparison Function for sorting
bool comp(const pair<int, int> &a,
          const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    long long n;
    cin >> n;
    vector<pair<int, int>> point;
    for (int i = 0; i < n; ++i)
    {
        long long a, b;
        cin >> a >> b;
        point.push_back({a, b});
    }

    vector<long long > ans;
    //Sorting points accoring to its end value
    sort(point.begin(), point.end(), comp);
    long long last = point[0].second;
    ans.push_back(last);



    for (int i = 1; i < n; i++) {
        if (point[i].first > last || point[i].second < last) {
            last = point[i].second;
            ans.push_back(last);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;

}



