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
Node* cloneLinkedList(Node*  head) {

	// 1. insert a copy of ith node between the ith & (i+1)th node
	Node* curr = head;
	while(curr != NULL) {
		Node* node = new Node(curr->data);
		Node* save = curr->next;
		curr->next = node;
		node->next = save;
		curr = save;
	}

	// printLinkedList(head);
	// printDoublyLinkedList(head);

	// 2. set the random pointers for newly created nodes
	curr = head;
	while(curr != NULL) {
		if(curr->next != NULL)
			curr->next->random = curr->random ? curr->random->next : NULL;
		curr = curr->next ? curr->next->next : NULL;
	}

	// printDoublyLinkedList(head);

	// 3. adjust the next pointers
	Node* cloneHead = head->next;
	Node* cloneCurr = cloneHead;
	curr = head;

	while(curr != NULL && cloneCurr != NULL) {
		curr->next = curr->next ? curr->next->next : NULL;
		cloneCurr->next = cloneCurr->next ? cloneCurr->next->next : NULL;

		curr = curr->next;
		cloneCurr = cloneCurr->next;
	}

	return cloneHead;

}
int main() {
    int n;
    cin>>n;
    int random;
    cin>>random;

    Node*head = buildll(n);
    head->random=head->next;
    head->next->random=head->next->next->next;
    Node*clonehead=cloneLinkedList(head);
    printll(clonehead);
    
}
