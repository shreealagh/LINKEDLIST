#include<iostream>
using namespace std;
class node
{
    public:
    node*next;
    int data;
    node(int d)
    {
        data=d;
        next=NULL;
    }

};
node* buildll(int size)
{
    if(size==0)
    {
        return NULL;
    }
    int x;
    cin>>x;
    node*head=new node(x);
    node*temp=head;
    int count=1;
    while(count!=size)
    {
        cin>>x;
        node*n=new node(x);
        temp->next=n;
        temp=n;
        count++;
    }
    return head;
}
node* oddevenll(node*head)
{ 
    node*oddhead=NULL;
    node*oddtail=NULL;
    node*evenhead=NULL;
    node*eventail=NULL;
    node*temp=head;
    while(temp!=NULL)
    {
        if(temp->data%2==0)
        {
            if(evenhead==NULL)
            {
                evenhead=eventail=temp;
            }
            else
            {
                eventail->next=temp;
                eventail=temp;
            }
        }
        else
        {
            if(oddhead==NULL)
            {
                oddhead=oddtail=temp;
            }
            else
            {
                oddtail->next=temp;
                oddtail=temp;
            }
        }
        temp=temp->next;
    }
    if(evenhead==NULL && oddhead==NULL)
    {
        return NULL;
    }
    else if(evenhead==NULL)
    {
        oddtail->next=NULL;
        return oddhead;
    }
    else if(oddhead==NULL)
    {
        eventail->next=NULL;
        return evenhead;
    }
    else
    {
        oddtail->next=evenhead;
        eventail->next=NULL;
        return oddhead;
    }

}
void printll(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
int main()
{
    int n;
    cin>>n;
    node*head=buildll(n);
    node*ans=oddevenll(head);
    printll(ans);

}
