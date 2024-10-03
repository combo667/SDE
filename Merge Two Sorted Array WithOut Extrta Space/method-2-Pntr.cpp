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

    ll n, m;
    cin >> n >> m;

    vi arr1, arr2;

    rep(i, 0, n)
    {
        ll temp;
        cin >> temp;
        arr1.pb(temp);
    }
    rep(i, 0, m)
    {
        ll temp;
        cin >> temp;
        arr2.pb(temp);
    }

    ll l, r;
    l = n - 1;
    r = 0;

    while (arr1[l] >= arr2[r])
    {
        swap(arr1[l], arr2[r]);
        l--;
        r++;
    }

    sort(all(arr1));
    sort(all(arr2));

    rep(i,0,n){
        cout<<arr1[i]<<" ";
    }

    rep(i,0,m){
        cout<<arr2[i]<<" ";
    }

    return 0;
}