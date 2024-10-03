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

int cntStudents(vi arr, int mid)
{
    int n = arr.size();
    int stu = 1;
    int pages = 0;

    rep(i, 0, n)
    {
        if ((pages + arr[i]) <= mid)
        {
            pages += arr[i];
        }
        else
        {
            stu++;
            pages = arr[i];
        }
    }

    

    return stu;
}

int minAllocation(vi arr, int students)
{
    
    int sum = 0;
    int maxi = INT_MIN;

    for (auto x : arr)
    {
        maxi = max(maxi, x);
        sum += x;
    }

    int low = maxi;
    int high = sum;
    

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        int cnt = cntStudents(arr, mid);

        if (cnt > students)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return low;
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
    int students;

    cin >> n >> students;

    vi arr(n);

    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    cout << minAllocation(arr, students);

    return 0;
}