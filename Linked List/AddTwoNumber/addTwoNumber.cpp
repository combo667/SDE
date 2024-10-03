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
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertNode(int);

    void deleteNode(int);

    void printList();

     Node *AddTwoNumber(LinkedList);
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

Node *LinkedList::AddTwoNumber(LinkedList list2)
{
    Node *dummy = new Node();

    Node *temp = dummy;

    Node *l1 = this->head;
    Node *l2 = list2.head;

    int carry = 0;

    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        Node *t = new Node(sum % 10);
        temp->next = t;
        temp = temp->next;
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

    int n1, n2;
    cin >> n1 >> n2;

    LinkedList l1, l2;

    rep(i, 0, n1)
    {
        int t;
        cin >> t;
        l1.insertNode(t);
    }

    rep(i, 0, n2)
    {
        int t;
        cin >> t;
        l2.insertNode(t);
    }

    l1.printList();
    cout << "\n";
    l2.printList();
    cout << "\n";

    Node *t = l1.AddTwoNumber(l2);

    Node *x = t;

    while (x)
    {
        cout << x->data << " -> ";
        x = x->next;
    }

    cout << " NULL";

    return 0;
}