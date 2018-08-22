using namespace std; 
#include <iostream>

template <class T>
struct Node 
{
    T val; 
    Node<T> *next; 
};

template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList&);
        void push_back(T insert);
        bool pop_back();
        void print();
        bool isempty();
        int size();
        void clear();
        void push_front(T insert);
        bool pop_front();
  	T& front();
  	void decrefcount(){
  		refcount--;
  	}
  	void increfcount(){
  		refcount++;
  	}
  	//void splice(iterator postion,LinkedList& x);
  	//	void splice(iterator postion,LinkedList& x,iterator i);
  	//	void splice(iterator postion,LinkedList& x,iterator first,iterator last);

    private:
        Node<T> *first; 
        Node<T> *last; 
        int refcount;
};
template<class T>
LinkedList<T>::LinkedList(const LinkedList& L){
	L.decrefcount();
	Node<T>* newnode=first;
	Node<T>* temp=L.first;
	while(temp!=NULL){
		newnode->value=temp.value;
		temp=temp->next;
		newnode=newnode->next;
	}

}
template <class T>
LinkedList<T>::LinkedList()
{
	first = NULL;
	last = NULL;
	refcount=1;
}
template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = first;
	while(temp != NULL)
	{
		temp = temp->next;
		delete(first); 
		first = temp;
	}
}
template <class T>
void LinkedList<T>::push_back(T insert)											//insert value at the end of the linked list
{
	Node<T>* newNode=new Node<T>;															//new node created
	newNode->val = insert;													
	newNode->next = NULL;														//next node to new node point to null

	Node<T>* temp = first;
	if(first==NULL) first=newNode;
	if (temp != NULL) 															//traverse till end of the linked list
	{
		while (temp->next != NULL) 
		{
			temp = temp->next;
		}

		temp->next = newNode;													//we get pointer to last node
	}																			//so we make this last pointer to point to our new node
	else 
	{
		first = newNode;														//if linked list already empty then our created node is first node
	}
}
template <class T>																//remove from last of the linked lsit
bool LinkedList<T>::pop_back()
{	
	if (first == NULL && last == NULL) {return false;}							//if first and last both point ot null then no value stored in the linked list

	if (first == last)															//if have only and 1 value in the liinked list
	{
		cout<<"First=Last"<<endl;
		delete(first);
		first = last = NULL;
		return true;
	}

	else																		//if have more than 1 value
	{
		Node<T>* temp = first;
		int nodeCount = 0;														//no. of nodes

		while (temp != NULL)													//traverse till end of the lined list
		{
			nodeCount = nodeCount + 1;
			temp = temp->next;													//at the end we will get no. of element
		}

		Node<T>* temp2 = first;													//new pointer pointing to first
	
		for(int i = 1; i < (nodeCount - 1); i++)								//till no. of nodes-1
		{
			temp2 = temp2->next;
		}

		cout << temp2->val<<endl;
		delete(temp2->next);													//delete last one
		
		last = temp2;
		last->next = NULL;
		
		return true;
	}
}
template <class T>
void LinkedList<T>::print()														//print the linked list
{
	Node<T>* temp = first;														//pointing to 1st element

	if (temp == NULL) 															//if no element return empty sting
	{
		cout<<"";
	}

	if (temp->next == NULL) 													//if only 1 value cout first
	{
		cout<<temp->val;
	}
	else 
	{
		while (temp != NULL)													//if more than 1 value present traverse till end while printing presetn
		{
			cout<< temp->val;
			temp = temp->next;
			cout<< "->";
		}
	}
}

template <class T>
bool LinkedList<T>::isempty()													//return 1 if linked list is empty
{
	if (first == NULL && last == NULL) {return true;}
	else {return false;}
}

template <class T>
int LinkedList<T>::size()														//return current size of linked list
{	
	if (first == NULL && last == NULL) {return 0;}

	Node<T>* temp = first;
	int nodeCount = 0;

	while (temp != NULL)														//traverse till end while incrementing nodecount
	{
		nodeCount = nodeCount + 1;
		temp = temp->next;
	}
	return nodeCount;
}

template <class T>																//delete every element in the linked list
void LinkedList<T>::clear()
{
	Node<T>* temp = first;
	while(temp != NULL)															//traverse till end while deleteing presetn
	{
		temp = temp->next;
		first = temp;															//changing first pointer to because the new linked list must start after the last element of current
		delete(temp);
	}
}

template <class T>
void LinkedList<T>::push_front(T insert)											//insert at front of the linked list
{
	Node<T>* newNode=new Node<T>;

	newNode->val = insert;													

  	 if(first == NULL)															//if linkned llist already empty inseting value first node
   	{
   		first = newNode;
   		newNode->next=NULL;
   	}
   	else																		//else only chaing first pointer
   	{
   		newNode->next = first;
   		first = newNode;
   	}

}

template <class T>
bool LinkedList<T>::pop_front()                 							//remove from front
{
	if (first == NULL && last == NULL) {return false;}							//if already empty can't deleet anymore
	
	else
	{
		Node<T>* temp;

		temp = first;															//else changeing pointer to 1st node
		first = first->next;

		delete(temp);

		return true;
	}
}

template <class T>
T& LinkedList<T>::front()													//return element at front
{
	return first->val;
}
int main(){
	LinkedList <int>L;
	while(1){
	cout<<"1:push_back"<<endl<<"2:pop_back"<<endl<<"3:clear()"<<endl<<"4:isempty"<<endl<<"5:front"<<endl<<"6:push_front"<<endl<<"7:pop_front"<<endl<<"8:print"<<endl;
		int t; cin>>t;
		if(t==1){
		
			cout<<"insert value"<<endl;
			int insert; cin>>insert;
				L.push_back(insert);}
		if(t==2){
			L.pop_back();
		}
		if(t==3){
			L.clear();
		}
		if(t==4){
			cout<<L.isempty()<<endl;
		}
		if(t==5){
			cout<<L.front()<<endl;
		}
		if(t==6){
		
			cout<<"insert value"<<endl;
			int insert; cin>>insert;
				L.push_front(insert);
		}
		if(t==7){
			L.pop_back();
		}
		if(t==8){
			L.print();
		}

	}
	


}
