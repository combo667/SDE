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

vvi threeSumOptimal(vi arr, int n)
{

    int j;
    int k;
    sort(all(arr));
    vvi ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            int val = arr[i] + arr[j] + arr[k];
            if (val == 0)
            {
                vi temp = {arr[i], arr[j], arr[k]};
                ans.pb(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;

                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }

            else if (val < 0)
                j++;
            else
                k--;
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

    int n;
    cin >> n;
    vi arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    /*     for(auto x:arr)
        cout<<x; */

    vvi ans = threeSumOptimal(arr, n);

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