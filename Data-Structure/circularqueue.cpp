#include <iostream>
using namespace std;
#include<string.h>
struct queue{
	int a[100], front, top;
};
void insert(struct queue *s,int n){
	if((*s).top!=99&&(*s).front==0){
		(*s).a[(*s).top]=n;
		(*s).top++;
		}else
	if((*s).front!=0){
		(*s).a[(*s).front]=n;
	}
}
int delet(struct queue *s){
	(*s).front++;
	if((*s).front==100-1){
		(*s).front=0;
	}
	return (*s).a[(*s).front-1];
}
int main(){
	struct queue s;
	s.front=0; s.top=0;cout<<"1=insert"<<" "<<"2=delete"<<" "<<"3=exit"<<endl;
	int n,m; n=0;
	while(n!=3){
		cin>>n;
		if(n==1){
			cin>>m;
			insert(&s,m);
		}
		if(n==2){
			int u=delet(&s);cout<<u;
		}
	}
}
