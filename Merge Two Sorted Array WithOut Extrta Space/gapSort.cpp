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

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int *arr1 = new int[n];
    int *arr2 = new int[m];

    rep(i,0,n)
    cin>>arr1[i];

    rep(i,0,m)
    cin>>arr2[i];

    int gap = ((n + m) / 2) + ((n + m) % 2);

    while (gap >= 1)
    {
        int left = 0;
        int right = left + gap;

        while (right > n + m)
        {
            if (left < n && right >= n)
            {
                if (arr1[left] > arr2[right - n])
                {
                    swap(arr1[left], arr2[right - n]);
                }
                else if (left >= n && right >= n)
                {
                    if (arr2[left - n] > arr2[right - n])
                    {
                        swap(arr2[left - n], arr2[right - n]);
                    }
                }

                else
                {
                    if (arr1[left] > arr1[right])
                    {
                        swap(arr1[left], arr1[right]);
                    }
                }
            }
        }

        gap/=2;
    }

    rep(i,0,n){
        cout<<arr1[i]<<" ";
    }
    rep(i,0,m){
        cout<<arr2[i]<<" ";
    }

    delete[] arr1;
    delete[] arr2;

    arr1 = arr2 = NULL;

    return 0;
}