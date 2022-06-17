#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*random;
    Node(int d)
    {
        data=d;
        next=NULL;
        random=NULL;
    }
};
Node*buildll(int size)
{
    if(size==0)
    {
        return NULL;
    }
    int x;
    cin>>x;
    Node*head=new Node(x);
    Node*temp=head;
    size--;
    while(size)
    {
        cin>>x;
        Node*n=new Node(x);
        temp->next=n;
        temp=n;
        size--;
    }
return head;
}
void printll(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node*midpointofll(Node*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;

    }
    return slow;
}
Node*mergesortedlists(Node*head1,Node*head2)
{
    //base case
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    if(head1->data<head2->data)
    {
        head1->next=mergesortedlists(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next=mergesortedlists(head1,head2->next);
        return head2;
    }

}

int main() {
    int q;
    cin>>q;
    while(q--)
    {
     int n;
     cin>>n;
    

     Node*head1 = buildll(n);
     int m;
     cin>>m;
     Node*head2 = buildll(m);
    Node* head=mergesortedlists(head1,head2);
     printll(head);
    }
    
}
