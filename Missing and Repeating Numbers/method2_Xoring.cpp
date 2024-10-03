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

    ll res = 0;

 for(int i=0;i<n;i++)
    {

        res = res ^ arr[i];
        res = res ^ i+1;
    }

    int ind = 0;

    while ((res & (1 << ind)) ==0)
    {

        ind++;
    }

    int zero_club = 0, one_club = 0;

    rep(i, 0, n)
    {
        if (arr[i] & (1 << ind))
        {
            one_club ^= arr[i];
        }
        else
        {
            zero_club ^= arr[i];
        }
    }

    rep(i, 1, n + 1)
    {
        if (i & (1 << ind))
            one_club ^= i;
        else
            zero_club ^= i;
    }

    

    int cnt = 0;
    rep(i, 0, n)
    {
        if (arr[i] == zero_club)
            cnt++;
    }

    if (cnt == 2)
    {
        cout << "Repeating Number is : " << zero_club << "\n";
        cout << "Missing Number is : " << one_club;
    }
    else
    {
        cout << "Repeating Number is :" << one_club << "\n";
        cout << "Missing Number is : " << zero_club;
    }

    return 0;
}