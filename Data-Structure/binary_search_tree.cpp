#include <iostream>
#include "stack.cpp"
using namespace std;
struct node{
	int value;
	node* right;
	node* left;
};
node* root=NULL;

void insert_bst(int i)
{
	if(root==NULL){
		node* newnode=new node;
		newnode->value=i;
		newnode->left=NULL;
		newnode->right=NULL;
		root=newnode;
	}
	else{
		node* newnode=new node;
		newnode->value=i;
		newnode->left=NULL;
		newnode->right=NULL;
		node* temp=root;
		node* t=NULL;
		while(temp!=NULL){
			//cout<<"s";
			t=temp;
			if(i<=(temp)->value){
				temp=(temp)->left;
				
			}
			else{
				temp=(temp)->right;
				
			}
		}
		if(t->value>=i)
			t->left=newnode;
		else
			t->right=newnode;
		//cout<<temp->value;
		
	}
}

void inorder_bst(){
	node* temp=root;
	stack<node*> s;
		while(!s.empty()||temp!=NULL){
			if(temp!=NULL){
				s.push(temp);
				temp=temp->left;
				
			}
			else{
				temp=s.top();
				s.pop();
				cout<<(temp)->value<<"->";
				temp=temp->right;
				
			}
		}cout<<endl;
}
void preorder_bst(){
	node* temp=root;
	stack<node*> s;
		while(!s.empty()||temp!=NULL){
			if(temp!=NULL){
				cout<<(temp)->value<<"->";
				s.push(temp);
				temp=temp->left;
				
			}
			else{
				temp=s.top();
				s.pop();
				temp=temp->right;
				
			}
		}cout<<endl;
}

void postorder_bst(){
	 node *current = root;
        stack<node*> s;
        while(current != NULL || !s.empty()){
            if(current != NULL){
                s.push(current);
                current = current->left;
            }else{
                node* temp = (s.top())->right;
                if (temp == NULL) {
                    temp = s.pop();
                    cout<<temp->value<<" ";
                    while (!s.empty() && temp == (s.top())->right) {
                        temp = s.pop();
                        cout<<temp->value<<" ";
                    }
                } else {
                    current = temp;
                }
            }
        }

}
int main()
{
	
	int n; cin>>n;
	while(n--){
		int i; cin>>i;
		insert_bst(i);
	}	
	//inorder_bst();
	//preorder_bst();
	postorder_bst();

}
