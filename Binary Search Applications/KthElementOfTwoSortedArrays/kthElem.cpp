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

int FindKthElement(vi arr1, vi arr2, int k)
{
    if (arr2.size() < arr1.size())
        return FindKthElement(arr2, arr1, k);

    int n1 = arr1.size();
    int n2 = arr2.size();

    int low = max(0,k-n2);
    int high = min(k,n1);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1)
            return max(left1, left2);
        else if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return -1;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vi arr1(n), arr2(m);
    rep(i, 0, n)
    {
        cin >> arr1[i];
    }

    rep(i, 0, m)
    {
        cin >> arr2[i];
    }

    cout << FindKthElement(arr1, arr2, k);

    return 0;
}