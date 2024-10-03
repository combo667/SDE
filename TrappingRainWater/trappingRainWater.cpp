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

int TrapRainWater(vi arr)
{
    int left = 0;
    int n = arr.size();
    int right = n - 1;
    int leftmax = 0, rightmax = 0;

    int ans = 0;

    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (leftmax < arr[left])
                leftmax = max(leftmax, arr[left]);
            else
                ans += leftmax - arr[left];
            left++;
        }

        else
        {
            if (arr[right] > rightmax)
                rightmax = max(rightmax, arr[right]);
            else
                ans += rightmax - arr[right];

            right--;
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

    cout << TrapRainWater(arr);

    return 0;
}