#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    unordered_map<string, int> map;
    string ans = "";
    for (int i = A.size() - 1; i >= 0; i--)
    {
        string str = A[i];
        if (map.find(str) != map.end())
            continue;
        else
        {
            ans += str[str.size() - 2];
            ans += str[str.size() - 1];
            map[str]++;
        }
    }
    cout << ans << endl;
}