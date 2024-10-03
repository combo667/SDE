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

vvi fourSum(vi arr, int n,int target)
{
    set<vi> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hash;
            for (int k = j + 1; k < n; k++)
            {
                ll four = arr[i] + arr[j];
                four+=arr[k];
                four=target-four;

                if (hash.find(four) != hash.end())
                {
                    vi tmp = {arr[i], arr[j], arr[k], (int)four};
                    sort(all(tmp));
                    ans.insert(tmp);
                }
                hash.insert(arr[k]);
            }
        }
    }

    vvi ans2(all(ans));

    return ans2;
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

    int target;
    cin>>target;

    vi arr(n);

    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    vvi ans = fourSum(arr, n,target);

    for (auto s1 : ans)
    {
        for (auto s2 : s1)
        {
            cout << s2 << " ";
        }
        cout << "\n";
    }

    return 0;
}