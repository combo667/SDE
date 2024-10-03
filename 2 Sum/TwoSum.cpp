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

void twoSum(vi arr, vvi &ans, int target)
{
    sort(all(arr));
    int n = arr.size();

    int i = 0, j = n - 1;

    while (i < j)
    {
        ll sum = arr[i] + arr[j];
        if (sum == target)
        {
            vi ds = {arr[i], arr[j]};
            ans.pb(ds);
            i++;
            j--;
            while (i < j && arr[i] == arr[i - 1])
                i++;
            while (i < j && arr[j] == arr[j + 1])
                j--;
        }
        else if (sum < target)
            i++;
        else
            j--;
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

    ll n, target;
    cin >> n >> target;

    vi arr(n);

    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    vvi ans;

    twoSum(arr, ans, target);

    for (auto x : ans){
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
        

    return 0;
}