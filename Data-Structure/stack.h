#include<iostream>
using namespace std;
//using template we can use same class for different types like char, int, double, float, struct, built-in class, user-defined class or structure
template<class T> class stack{				//class stack<T>
private:
	T* p;									//pointer to object of class T
	int top1;								//index for end element 
	const int max_size;						//maximum size that stack can have
public:
	struct overflow;						//error struct already full
	struct underflow;						//error stack already empty
	stack(int _max_size =50);				//constructor
	void push(T);							//insert element to end of stack
	T pop();								//remove element from end 
	T top();								//return element at end 
	int size(){ return top1;}				//return current size of stack
	bool empty(){ return top1?0:1;}			//1 if stack is empty
	void clear(){ top1 = 0;}					//reset stack to 0
	bool full(){ return top1==max_size?1:0;}	//1 if stack is full
	~stack(){delete p;}						//disturctor 

};

template<class T> struct stack<T>::overflow{	//constructor of overflow
	overflow(int ii):i(ii){std::cout<<"The maximum size of stack reaches : "<<i<<std::endl;}
private:
	int i;
};

template<class T> struct stack<T>::underflow{//constructor of underflow
	underflow(int ii):i(ii){std::cout<<"The minimum size of stack reaches : "<<i<<std::endl;}
private:
	int i;
};

//defination for stack member funcitons
template<class T> stack<T>::stack(int _max_size):p(0),top1(0),max_size(_max_size){
	p = new T[max_size];								//create an array of type T  of size max_size
}

template<class T> void stack<T>::push(T x){
	if(top1>=max_size) throw overflow(top1);				//throw error if stack already full and trying to enter more
	p[top1] = x;
	top1++;
}

template<class T> T stack<T>::pop(){					//throw error if stack already emoty and trying to remove more
	if(top1<1) throw underflow(top1);
	top1--;
	return p[top1];
}

template<class T> T stack<T>::top(){
	return p[top1-1];
}
/*int main(){
	int size; cout<<"enter size"<<endl;cin>>size;
	stack <char> s(size);

	while(1){
	cout<<"1:push"<<endl<<"2:pop"<<endl<<"3:full()"<<endl<<"4:empty"<<endl<<"5:top"<<endl;
		int t; cin>>t;
		if(t==1){
		
		while(size--){
		
			cout<<"insert value"<<endl;
			char insert; cin>>insert;
				s.push(insert);}}
		if(t==2){
			s.pop();
		}
		if(t==3){
			cout<<s.full()<<endl;
		}
		if(t==4){
			cout<<s.empty()<<endl;
		}
		if(t==5){
			cout<<s.top()<<endl;
		}
	}
	cout<<s.top()<<endl;

*/

//}
