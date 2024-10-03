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

    int n, m;
    cin >> n >> m;

    vvi arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rep(i, 0, n)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    rep(i, 0, n)
    {
        reverse(arr[i].begin(), arr[i].end());
    }

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

int a=10,b=7;
//swapping with 2 variables

a=a+b;
b=a-b;
a=a-b;

//swapping with 3 variables a,b, temp

int temp=a;
a=b;
b=temp;
