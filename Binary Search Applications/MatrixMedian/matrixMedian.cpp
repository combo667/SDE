#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, n) for (int i = 1; i <= n; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define remax(a, b) a = max(a, b)
#define remin(a, b) a = min(a, b)
#define all(v) v.begin(), v.end()
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define F first
#define S second
const int MAXN = 1000005;
const int MOD = 1000000007;

int cntElems(vi &a, int mid)
{
    int low = 0;
    int high = a.size() - 1;

    while (low <= high)
    {
        int m = (low + high) >> 1;

        if (a[m] <= mid)
        {
            low = m + 1;
        }
        else
            high = m - 1;
    }

    return low;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;

    vvi matrix(r, vi(c));

    rep(i, 0, r)
    {
        rep(j, 0, c)
        {
            cin >> matrix[i][j];
        }
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;
    rep(i, 0, r)
    {
        mini = min(mini, matrix[i][0]);
    }

    rep(i, 0, r)
    {
        maxi = max(maxi, matrix[i][c - 1]);
    }

    cout<<mini<<" "<<maxi<<"\n";

    int low = mini, high = maxi;

    int desired = (r * c) >> 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;

        rep(i,0,r)
        cnt += cntElems(matrix[i], mid);

        if (cnt <= desired)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << low;

    return 0;
}