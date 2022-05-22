#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data=data;
		next=NULL;
	}

};
Node* buildLinkedList(int size) {
	if(size==0)
	{
		return NULL;
	}

	int x;
	cin >> x;

	Node* head = new Node(x);
	Node* temp = head;
	int count=1;

	while(count != size) {
		cin >> x;
		
		Node* node = new Node(x);
		temp->next = node;
		temp = node;
		count++;
	}

	return head;
}
void print(Node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
Node* reversell(Node*head)
{
    Node*prev=NULL;
    Node*c=head;
    Node*n;
    while(c!=NULL)
    {
        n=c->next;
        c->next=prev;
        prev=c;
        c=n;
    }
    return prev;
}
bool palindrome(Node*head)
{
    if(head==NULL || head->next==NULL)
    {
        return true;
    }
    //mid point
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reversell(slow->next);
    slow=slow->next;
    //compare slow with head
    while(slow!=NULL)
    {
        if(head->data!=slow->data)
        {
            return false;
            break;
        }
    }
    return true;

}
int main() {
	int n;
	cin>>n;
	

	  Node* head=buildLinkedList(n);
	bool ans=palindrome(head);
	if(ans)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
	
	
	return 0;
}
