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

int lcs(vi arr, int n)
{

    set<int> st(all(arr));

    int longest_seq = 0;

    for (auto i : st)
    {
        if (st.find(i - 1) == st.end())
        {
            int val = i + 1;
            int cnt = 1;
            while (st.find(val) != st.end())
            {
                cnt++;
                val++;
            }

            longest_seq = max(longest_seq, cnt);
        }
    }

    return longest_seq;
}

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

    vi arr(n);

    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    cout << lcs(arr, n);

    return 0;
}