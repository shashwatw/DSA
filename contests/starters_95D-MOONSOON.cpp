#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    long long int turn;
    cin >> turn;
    while (turn--)
    {
        long long int N, M, h;
        cin >> N >> M >> h;
        long long int c[N], o[M];
        for (long long int i = 0; i < N; i++)
            cin >> c[i];
        for (long long int i = 0; i < M; i++)
            cin >> o[i];
        sort(c, c + N);
        sort(o, o + M);
        long long int cEnd = N - 1;
        long long int oEnd = M - 1;
        long long int ans1 = 0;
        while (cEnd >= 0 && oEnd >= 0)
        {
            long long int capacity = c[cEnd];
            long long int outlerCap = o[oEnd];
            ans1 += min(capacity, h * outlerCap);
            cEnd--;
            oEnd--;
        }
        cEnd = 0;
        oEnd = 0;
        long long int ans2 = 0;
        while (cEnd < N && oEnd < M)
        {
            long long int capacity = c[cEnd];
            long long int outlerCap = o[oEnd];
            ans2 += min(capacity, h * outlerCap);
            cEnd++;
            oEnd++;
        }
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}