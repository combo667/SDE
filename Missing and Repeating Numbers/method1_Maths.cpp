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

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    int arr[n];

    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    ll s = 0, sn, s2 = 0, s2n;
    sn = (n * (n + 1)) >> 1;

    s2n = (n * ((2 * n) + 1) * (n + 1)) / 6;
    rep(i, 0, n)
    {
        s += arr[i];
        s2 += (ll)arr[i] * (ll)arr[i];
    }

    ll val1 = s - sn;
    ll val2 = s2 - s2n;
    val2=val2/val1;

    ll x = (val1 + val2) >> 1;
    ll y = x-val1;

    cout << "repeating no: " << x << "\n"
         << "missing No: " << y << "\n";
    return 0;
}