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

ll binExp(ll, ll);

void BinSearchNthRoot(ll n, ll m)
{
    ll low = 1;
    ll high = m;

    while (low <= high)
    {
        ll unsigned mid = (low + high) >> 1;
     

        ll unsigned res = binExp(mid, n);
        
        if (res == m)
        {
            cout << mid;
            return;
        }
        else if (res < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << -1;
    return;
}

ll binExp(ll a, ll b)
{
    ll unsigned ans = 1;

    while (b>0)
    {
        if (b & 1)
        {
            ans = ans * a;
            b = b - 1;
        }
        else
        {
            b >>= 1;
            a = a * a;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    BinSearchNthRoot(n, m>>1);

    return 0;
}