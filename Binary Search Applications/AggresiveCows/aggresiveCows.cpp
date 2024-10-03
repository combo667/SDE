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

bool canBePlaced(vi arr, int dis, int cows)
{
    int cntCow = 1;
    int lastPlaced = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - lastPlaced >= dis)
        {
            cntCow++;
            lastPlaced = arr[i];
        }

        if(cntCow>=cows)
        return true;

       
    }

    return false;

   
}

int aggresiveCows(vi arr, int n, int cows)
{
    sort(all(arr));

    int low = 0;
    int high = arr[n - 1] - arr[0];

    while (low <= high)
    {
        int mid = (low + high) >> 1;

      if(canBePlaced(arr, mid, cows)){
      
        low=mid+1;
      }
      else
      high=mid-1;

        
    }

    return high;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cows;
    cin >> n >> cows;

    vi arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    cout << aggresiveCows(arr, n, cows);

    return 0;
}