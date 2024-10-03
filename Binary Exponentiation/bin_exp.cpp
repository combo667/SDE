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

void Power(double x, int n)
{
    ll nn = n;

    double ans = 1.0;

    if (nn < 0)
        nn = nn * (-1);

    while (nn)
    {
        if (nn & 1)
        {

            nn = nn - 1;
            ans *= x;
        }
        else
        {
            nn = nn >> 1;
            x= (x * x);
        }
    }

    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    cout<<ans;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Power(2.1,3);

    return 0;
}