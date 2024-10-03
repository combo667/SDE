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

void addEdge(vi arr[], int s, int d)
{
    arr[s].pb(d);
    arr[d].pb(s);
}

void printGraph(vi graph[], int vertices)
{
    rep(i, 0, vertices)
    {
        cout << i;
        for (auto x : graph[i])
        {
            cout << " -> " << x;
        }
        cout << "\n";
    }
}

void DFS(vi graph[], int start, int visited[], vi &list)
{
    visited[start] = 1;
    list.pb(start);

    for (auto x : graph[start])
    {
        if (!visited[x])
        {
            DFS(graph, x, visited, list);
        }
    }
}

void DFT(vi graph[], int vertices)
{
    int start = 0;
    int visited[vertices] = {0};

    vi list;

    rep(i,0,vertices){
        if(!visited[i]){
            DFS(graph,i,visited,list);
        }
    }

    for(auto x:list){
        cout<<x<<" ";
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

    int vertices, edges;
    cin >> vertices >> edges;

    vi graph[vertices];

    rep(i, 0, edges)
    {
        int s, d;
        cin >> s >> d;
        addEdge(graph, s, d);
    }

    DFT(graph,vertices);

    return 0;
}