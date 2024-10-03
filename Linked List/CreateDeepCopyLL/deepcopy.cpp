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

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->random = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

Node *CreateDeepCopyLinkedList(Node *head)
{
    Node *ptr = head;

    while (ptr)
    {
        Node *t = new Node(ptr->data);
        t->next = ptr->next;
        ptr->next = t;
        ptr = ptr->next->next;
    }

    ptr = head;

    while (ptr)
    {
        ptr->next->random = ptr->random != NULL ? ptr->random->next : NULL;
        ptr = ptr->next->next;
    }

    Node *dummy = new Node(0);
    Node *d = dummy;

    Node *iter = head;

    while (iter)
    {
        Node *front = iter->next->next;

        d->next = iter->next;
        iter->next = front;
        d = d->next;
        iter = iter->next;
    }

    return dummy->next;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->random = head->next->next->next;
    head->next->random = head;
    head->next->next->random = NULL;
    head->next->next->next->random = head->next;

    Node *copiedList = CreateDeepCopyLinkedList(head);

    Node *x = head;
    cout << "Original List:\n";
    while (x)
    {
        cout << x->data<<" "<<x << " -> ";
        x = x->next;
    }

    cout << "NULL";

    Node *y = copiedList;
    cout << "\nDeep Copy List:\n";

    while (y)
    {
        cout << y->data << " " << y << " -> ";
        y = y->next;
    }

    cout << "NULL";

    return 0;
}