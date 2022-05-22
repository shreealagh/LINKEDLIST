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
void reversell(Node*&head){
	// node*ans1=head; //100
	Node*prev=NULL;//pichli wali link jahan mujhe node ko point karana hai
	Node*c=head; //jis node ki link piche le jana hai
	Node*n; //baki ll ka pointer so that wo ll kho na jaye
	while(c!=NULL){
		n=c->next;
		c->next=prev;
		prev=c;
		c=n;

	}
	head=prev;
	// tail=ans1;

}
bool palindrome(Node* &head,Node* &head2)
{
	while(head!=NULL && head2!=NULL)
	{
		if(head->data!=head2->data)
		{
			return false;
			break;
			
		}
		head=head->next;
		head2=head2->next;
		
	}
	return true;
}




int main() {
	int n;
	cin>>n;
	

	  Node* head=buildLinkedList(n);
	
	Node* temp=head;
	reversell(head);
	Node* temp2=head;
	bool ans=palindrome(temp,temp2);
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
