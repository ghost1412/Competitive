#include <iostream>
#include<cctype>
using namespace std;

struct error{
	string s;
	error(string ss){s=ss;}
};

class complex{
	double real, img;
public:
	complex(int r=0,int i=0){real = r;img = i;}
	~complex(){}
	void plus(complex);
	void minus(complex);
	void mult(complex);
	void divide(complex);
	complex& operator += (complex);
	complex& operator -= (complex);
	void getcom(){cout <<"real part : ";cin>>real;cout << "img. part : ";cin>>img;}
	void show(){cout <<real;if(img>0)cout <<" + j"<<img;
	else 
		if(img<0)cout << " - j"<<0-img; cout <<endl<<endl;}
};
int main(){
	char cha= '1';
	while((cha-'0')){
	  try{
		complex c;c.getcom();
		char ch;
		cout <<"\n0.To show the entered number\n1.To add\n2.To subtract\n3.To multiply\n4.To divideide\n\tPress : ";cin>>ch;cout <<endl;
		if(!isdigit(ch))throw error("====Invalid choice====");
		switch(ch){
			case '0':c.show();break;
			case '1':{complex c1;cout <<"Enter \n";
			c1.getcom();c.plus(c1);cout <<"Sum : ";c.show();
			break;
			}
			case '2':{complex c1;cout <<"Enter\n";
			c1.getcom();c.minus(c1);cout <<"Subraction : ";c.show();
			break;}
			case '3':{complex c1;cout <<"Enter\n";c1.getcom();
			c.mult(c1);cout << "Product : ";c.show();
			break;}
			case '4':{complex c1;cout <<"Enter the value of new number \n";
			c1.getcom();c.divide(c1);cout<<"divideision : ";c.show();break;}
			default :throw error("====Invalid choice====");
		}
	    }
	    catch(error x){cout <<"Error : "<< x.s<<endl<<"Try again\n";}
	  cout << "To Stop press 0\n\tPress here : ";cin>>cha;
	}
		
	return 0;
}

void complex::plus(complex c){/*this->real +=c.real;this->img +=c.img;*/ (*this) += c;}//end plus
void complex::minus(complex c){/*this->real -=c.real;this->img -=c.img;*/ (*this) -= c;}//end minus
void complex::mult(complex c){
	double r=real,i=img;
	this->real = r*c.real - i*c.img;
	this->img = i*c.real + r*c.img;
}/
void complex::divide(complex c){
	if((!c.real)&&(!c.img))throw error("====While divideiding both real and img cann't be zero simultaneously====");
	double r = real,i = img;
	real = (r*c.real + i*c.img)/(c.real*c.real + c.img*c.img);
	img = (i*c.real - r*c.img)/(c.real*c.real + c.img*c.img);
}

complex& complex::operator+=(complex c){
	real += c.real;
	img += c.img;
	return *this;
}

complex& complex::operator-=(complex c){
	real -= c.real;
	img -= c.img;
	return *this;
}
