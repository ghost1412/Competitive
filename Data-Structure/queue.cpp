#include <iostream>
using namespace std;
#include <cstdlib>

template<class x>
class queue
{	
	x *ar;
	//int sizear;
	int front;				//index for front element
	int capacity;			//max capacity of queue
	int rear;				//index for last elememt
	int curr_size;			//current size of the queue

public:
	queue(int n);			//constructor
	void dequeue();			//fuction to remove element from front	
	void enqueue(int insert);//function to add element to end
	bool isempty();			//return 1 if empty
	bool isfull();			//return 1 if full
	int size();				//return current size
	x top();				//return element in front
};

template<class x>
queue<x>::queue(int size)
{
	ar=new x[size];			//making a array of given size
	capacity=size;
	front=0;
	rear=-1;
	curr_size=0;
}

template<class x>
void queue<x>::dequeue()
{
	if(isempty()){			//if already empty we can't remove any more so error
		cout<<"already empty"<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<ar[front]<<endl; //remove from front
	front=(front+1)%curr_size;
	curr_size--;

}
template<class x>
void queue<x>::enqueue(int insert)
{
	if(isfull()){			//if already of max size can't add any more so error
	 cout<<"already full"<<endl;
	 exit[EXIT_FAILURE];
	}
	rear=(rear+1)%capacity; //add to last
	ar[rear]=insert;
	curr_size++;

}
template<class x>
x queue<x>::top()
{
	if(isempty()){		//if empty can't return element at front so error
	 cout<<"empty"<<endl;
	 exit(EXIT_FAILURE);
	}	
	return ar[front];
}
template<class x>
int queue<x>::size()
{
	return curr_size;
}
template<class x>
bool queue<x>::isempty()
{
	return (size()==0);
}
template<class x>
bool queue<x>:: isfull()
{
	return (size()==capacity);
}

int main()
{	int n; cout<<"insert size"<<endl; cin>>n;
	queue<int> q(n);
	
	
	while(1){
	cout<<"1:enqueue"<<endl<<"2:dequeue"<<endl<<"3:isfull()"<<endl<<"4:isempty"<<endl<<"5:top element"<<endl;
		int t; cin>>t;
		if(t==1){
		
		while(n--){

			cout<<"insert value"<<endl;
			int insert; cin>>insert;
				q.enqueue(insert);}}
		if(t==2){
			q.dequeue();
		}
		if(t==3){
			cout<<q.isfull()<<endl;
		}
		if(t==4){
			cout<<q.isempty()<<endl;
		}
		if(t==5){
			cout<<q.top()<<endl;
		}
	}
	cout<<q.top()<<endl;
}
