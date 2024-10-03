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

bool checkPalindrome(string s, int first, int last)
{
    while (first <= last)
    {
        if (s[first++] != s[last--])
        {
            return false;
        }
    }
    return true;
}

void palindromePartitions(string s, int ind, vector<vector<string>> &ans, vector<string> &ds)
{
    if (ind == s.size())
    {
        ans.pb(ds);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if (checkPalindrome(s, ind, i))
        {
            ds.pb(s.substr(ind, i - ind + 1));
            palindromePartitions(s,i + 1, ans, ds);
            ds.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<vector<string>> ans;
    vector<string> ds;

    palindromePartitions(s, 0, ans,ds);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }

    return 0;
}