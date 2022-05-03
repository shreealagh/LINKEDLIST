#include <iostream>
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
void insertatfront(node*&head,node* &tail,int data)
{
    node*n=new node(data);
    //if ll is empty
    if(head==NULL)
    {
       head=tail=n;
    }
    //if ll is not empty
    else{
    n->next=head;
    head=n;
    }
}
void insertattail(node*&head,node*&tail,int data)
{
    node*n=new node(data);
    //if ll is empty
    if(head==NULL)
    {
        head=tail=n;
    }
    //if ll isnot empty
    else{
        tail->next=n;
        tail=n;
    }
}
int length(node*head)
{
    int count=0;
    while(head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}
void insertatanypostion(node*&head,node*&tail,int data,int pos)
{
    
    if(pos==0)
    {
        insertatfront(head,tail,data);
    }
    if(pos>=length(head)){
		insertattail(head,tail,data);

 	}
     else{
         node*n=new node(data);
         node*temp=head;
         for(int jump=1;jump<pos;jump++)
         {
             temp=temp->next;
         }
         n->next=temp->next;
         temp->next=n;
     }
}
void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;

    }
}
int main() {
   node*head=NULL;
   node*tail=NULL;
   insertatfront(head,tail,9);   
	insertatfront(head,tail,12);
	insertatfront(head,tail,16);
	insertatfront(head,tail,18);
	insertatfront(head,tail,20); 
    print(head);
    insertattail(head,tail,19);//20 18 16 12 9 19
	insertattail(head,tail,190);//20 18 16 12 9 19 190
	print(head);
	insertatanypostion(head,tail,50,3);//20 18 16 50 12 9 19 190
	print(head);


}
