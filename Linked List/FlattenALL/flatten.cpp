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
    Node *bottom;
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->bottom = NULL;
        this->next = NULL;
    }
};

Node* merge(Node *a,Node *b){
    Node *temp=new Node(0);
    Node *res=temp;

    while(a&&b){
        if(a->data<b->data){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }

        else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }


    }


    if(a)
    temp->bottom=a;
    else
    temp->bottom=b;


    return res->bottom;
}


Node *flatten(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }


    head->next=flatten(head->next);

    head=merge(head,head->next);

    return head;
}



int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);

    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);


    Node *res=flatten(head);

    Node *p=res;
    while(p){
        cout<<p->data<<" ";
        p=p->bottom;
    }

    cout<<"NULL";

    return 0;
}