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

    int n;
    cin >> n;

    int arr[n];

    for (auto &s : arr)
        cin >> s;

    int cnt1 = 0;
    int cnt2 = 0;
    int el1, el2;

    rep(i, 0, n)
    {
        if (cnt1 == 0 && arr[i] != el2)
        {
            cnt1 = 1;
            el1 = arr[i];
        }

        else if (cnt2 == 0 && arr[i] != el1)
        {
            cnt2 = 1;
            el2 = arr[i];
        }

        else if (arr[i] == el1)
        {
            cnt1++;
        }
        else if (arr[i] == el2)
        {
            cnt2++;
        }

        else
        {
            cnt1--;
            cnt2--;
        }
    }

    int c1 = 0, c2 = 0;

    rep(i, 0, n)
    {
        if (arr[i] == el1)
        {
            c1++;
        }
        if (arr[i] == el2)
        {
            c2++;
        }
    }

    int mini = (int)(n / 3) + 1;

    vi ans;

    if (c1 >= mini)
        ans.pb(el1);
    if (c2 >= mini)
        ans.pb(el2);

    sort(all(ans));

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}