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

    vpii arr;
    rep(i, 0, n)
    {
        int a, b;
        cin >> a >> b;
        arr.pb({a, b});
    }

    
     vpii ans;

     rep(i, 0, n)
     {
         if (ans.empty() || ans.back().second < arr[i].first)//back() returns the last inserted element
         {
             ans.pb(arr[i]);
         }
         else
         {
             ans.back().second = max(arr[i].second, ans.back().second);
         }
     }

     for (auto x : ans)
     {
         cout << x.first << " " << x.second << "\n";
     }
 
    return 0;
}