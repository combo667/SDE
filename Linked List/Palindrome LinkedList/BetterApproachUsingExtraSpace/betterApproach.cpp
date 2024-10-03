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

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{

public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void insertNode(int);

    void deleteNode(int);

    void printList();

    bool checkPalindrome(void);
};

void LinkedList::insertNode(int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *t = head;

    while (t->next != NULL)
    {
        t = t->next;
    }

    t->next = newNode;
}

void LinkedList::deleteNode(int pos)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty,Deletion Not possible!\n";
        return;
    }

    Node *temp1 = head;

    int LLLength = 0;
    while (temp1)
    {
        temp1 = temp1->next;
        LLLength++;
    }

    if (pos > LLLength)
    {
        cout << "Index out of range!\n";
        return;
    }

    temp1 = head;

    if (pos == 1)
    {
        head = head->next;
        delete temp1;
        temp1 = NULL;
        return;
    }

    temp1 = head;

    for (int cnt = 0; cnt < pos - 2; cnt++)
    {
        temp1 = temp1->next;
    }

    Node *temp2 = temp1->next;

    temp1->next = temp2->next;
    temp2->next = NULL;
    delete temp2;
    temp2 = NULL;
}

void LinkedList::printList()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "List is Empty!\n";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";
}

bool LinkedList::checkPalindrome(void)
{

    vi arr;
    Node *p = this->head;

    while (p)
    {
        arr.pb(p->data);
        p = p->next;
    }

    for (int i = 0; i < (arr.size() >> 1); i++)
    {
        if (arr[i] != arr[arr.size() - 1 - i])
            return false;
    }
    return true;
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
    LinkedList list;

    while (n--)
    {
        int t;
        cin >> t;
        list.insertNode(t);
    }

    if (list.checkPalindrome())
        cout << "List is Palindrome!\n";
    else
        cout << "List is not Palindrome!\n";

    return 0;
}