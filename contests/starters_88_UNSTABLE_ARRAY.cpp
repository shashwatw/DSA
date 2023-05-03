#include <bits/stdc++.h>
using namespace std;
// #define int long long

void solve()
{
    long long int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        m[x]++;
    }
    long long int v = 0, d = 0, g = 0;
    for (auto i : m)
    {
        d++;
        v = i.second;
        g += ((v * (v - 1)) / 2);
    }
    cout << (n * n - n) / 2 - (g) << endl;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}