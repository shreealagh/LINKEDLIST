//Given a linked list, write a function to reverse every k nodes (k>0).
#include <iostream>
using namespace std;
class node
{
    public:
    node*next;
    int data;
    node(int d)
    {
        next=NULL;
        data=d;
    }
};
node* buildll(int size)
{
    int x;
    cin>>x;
    node*head=new node(x);
    node*temp=head;
    size--;
    while(size)
    {
        cin>>x;
        node*n=new node(x);
        temp->next=n;
        temp=n;
        size--;
    }
    return head;

}
node* kreverse(node*head,int k)
{

    //base case
    if(head==NULL)
    {
        return NULL;
    }




    node*prev=NULL;
    node*curr=head;
    node*next;
    int cnt=0;
    while(curr!=NULL && cnt!=k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
  //i have reversed the 1st k nodes rest i will delegate the reponsibility to recursion
  //recursive case
  head->next=kreverse(curr,k);
  return prev;

}
void printll(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main() {
    int n,k;
    cin>>n>>k;
    node*head=buildll(n);
    head=kreverse(head,k);
    printll(head);
}
