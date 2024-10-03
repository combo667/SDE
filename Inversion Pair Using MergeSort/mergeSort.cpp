#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define rep1(left, n) for (int left = 0; left < n; left++)
#define rep2(left, n) for (int left = 1; left <= n; left++)
#define rep(left, a, b) for (int left = a; left < b; left++)
#define REPD(left, n) for (int left = n - 1; left >= 0; left--)
#define FORD(left, a, b) for (int left = a; left >= b; left--)
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

int merge(vi &arr, int low, int mid, int high)
{

    int cnt = 0;
    int left = low;
    int right = mid + 1;
    vi temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.pb(arr[left++]);
        }
        else
        {

            cnt += (mid - left + 1);
            temp.pb(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.pb(arr[left++]);
    }
    while (right <= high)
    {
        temp.pb(arr[right++]);
    }

    rep(i, low, high + 1)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vi &arr, int low, int high)
{

    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) >> 1;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
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

    rep(left, 0, n)
    {

        cin >> arr[left];
    }

    int low = 0;
    int high = n - 1;

    cout << mergeSort(arr, 0, n - 1);

    return 0;
}