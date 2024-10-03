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

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;        // to store all susbets
        vector<int> curr;               // to store current individual subset (that we will build)
        sort(nums.begin(), nums.end()); // sort the array so that duplicates are adjacent
        helper(nums, ans, curr, 0);     // we start from index 0
        return ans;
    }

    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, int idx)
    {
        ans.push_back(curr); // we include current susbet into final ans
        for (int i = idx; i < nums.size(); i++)
        { // check for all possibilites
            if (i > idx && nums[i] == nums[i - 1])
                continue;            // if duplicate then we continue
            curr.push_back(nums[i]); // we include nums[i] in current subset
            helper(nums, ans, curr, i + 1);
            curr.pop_back(); // to get subset without nums[i]
        }
    }
};

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
        cin >>
            arr[i];
    }

    Solution s;

    vvi ans = s.subsetsWithDup(arr);

    for (auto x : ans){

        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
      

    return 0;
}