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

void combnSum(vi arr, int n, int ind, int target, vvi &ans, vi &ds)
{
    if (ind == n)
    {
        if (target == 0)
        {
            ans.pb(ds);
        }
        return;
    }

    if (arr[ind] <= target)
    {
        ds.pb(arr[ind]);
        combnSum(arr, n, ind, target - arr[ind], ans, ds);
        ds.pop_back();
    }
        combnSum(arr, n, ind+1, target, ans, ds);
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;

    vi arr(n);
    for (auto &x : arr)
        cin >> x;

    vvi ans;
    vi ds;

    combnSum(arr, n, 0, target, ans, ds);

    for (auto x1 : ans)
    {
        for (auto x2 : x1)
        {
            cout << x2 << ' ';
        }
        cout << '\n';
    }

    return 0;
}