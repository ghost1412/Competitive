#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node *head=NULL;

void Reverse()
{
	Node *t,*tail;tail=NULL;
	while(head!=NULL){
		t=head->next;
		head->next=tail;
		tail=head;
		head=t;
	}
    	head=tail;
}
void Insertcir(int data,int position){
	Node *t=new Node;
	t->data=data;
	if(head==NULL){
	   head=t;
	   t->next=head;
	}else{
		Node *n=head;
		while(n->next!=head){
			n=n->next;
		}
		n->next=t;
		t->next=head;
	}
}
void InsertNth(int data, int position)
{
	Node *temp1=new Node;
	Node *root=head;
	temp1->next=NULL;
	Node *temp2=head;
	temp1->data=data;
	
	if (head == NULL) {
		    head=temp1;
		}else
	if(position==0){
		temp1->next=head;
		head=temp1;
	}else
	if(position==1){
		temp1->next=head->next;
		head->next=temp1;
	}else{
		for(int i=0;i<=position-2;i++){
			temp2=temp2->next;
		}
	 	temp1->next=temp2->next;
		temp2->next=temp1;
		head=root;
	}
}

Node* Delete(int position) {
struct Node *current=head;
	if(position==0){
		head=head->next;
	}
	while(position>1){
		current=current->next;
		position--;
	}

	struct Node *de=current->next;
	current->next=(current->next)->next;
	free(de);
}

void print(){
	Node *t=head;
	while(t!=NULL){
	   cout<<(t->data);
	   t=t->next;
	   cout<<"->";
	}
	cout<<endl;
}

int main(){
	cout<<"1=insert"<<" "<<"2=delete"<<" "<<"3=reverse"<<" "<<"4=print"<<" "<<"5=exit"<<" "<<"6=use as circular"<<endl;
	while(1){
		int x; cin>>x;
		if(x==1){
			int a,b; cin>>a>>b;
			InsertNth(a,b);
		}
		if(x==2){
			int pos; cin>>pos;
			Delete(pos);
		}
		if(x==3){
			Reverse();
		}
		if(x==5){
			break;}
		if(x==4){
			print();
		}
		if(x==6){
			if(x=="q"){
				int y,u; cin>>y;cin>>u;
				Insertcir(y,u);
			}
		}
	}
}
