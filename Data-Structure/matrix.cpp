#include <iostream>
using namespace std;

struct error{string s;
	error(string ss){
		s=ss;
	}
	~error(){}
};//error
#include<vector>

class matrix{int row,col;
	double **array;
	public:
	matrix(int r,int c);
	matrix(const matrix&);
	~matrix();
	//void setElement();
    double getElement (int r, int c);		
	matrix operator+(const matrix&);
	matrix operator-(const matrix&);
	matrix operator*(const matrix&);
	matrix & operator=(const matrix&);


	void display(){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<array[i][j]<<"\t";
			}
      cout<<endl;
		}
	}
  
	friend istream &operator>>( istream  &input,matrix &m) ;//>> overloaded
	
    friend ostream &operator<<( ostream &output, int n ) //<< overloaded
     { 
         output << n;
         return output;            
     }

matrix getCofactor(int p, int q) //cofactor
{

	matrix m3(row-1,col-1);
    
    int i = 0, j = 0;
    for (int k = 0; k < row; k++)
    {
        for (int l = 0; l< row; l++)
        {           
            if (k != p && l != q)
            {
                m3.array[i][j++] = array[k][l];
 
                if (j == col - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
     }
   return m3;
}

matrix transpose(){  
                                   //transpose
	matrix y(col,row);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			y.array[j][i]=array[i][j];
		}
	}
 return y;
}

double determinant(){double d=0;  //determinant
	if(row==1){
		return array[0][0];
	}
	int sign=1;
	for(int i=0;i<row;i++){
		//matrix m1(row-1,col-1);
	//	m1=(*this).getCofactor(0,i);
		
      d=d+sign*array[0][i]*(((*this).getCofactor(0,i)).determinant());
      sign=-sign; 
	}
  return d;
}

matrix adjoint(){                    //adjoint
	matrix m(row,col);
	int flag;
	int k=(*this).determinant(); 
	if(k==0){
		throw error("inverse not exist det=0");
	}else
	if(row!=col){
		throw error("not square matrix");
    }else{
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          if((i+j)%2==0){flag=1;}else flag=-1;
          m.array[i][j]=flag*(((*this).getCofactor(i,j)).determinant());
        }
      }
      return m.transpose();
     }
}
};

matrix::matrix(int r, int c){    //constructor initializing array with 0
	row = r;
	col = c;
	array = new double*[row];
	for (int i=0; i<row; i++){
		array[i] = new double[col];
		}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			array[i][j] = 0;
		}
	}
};                                 //class ended

matrix::matrix(const matrix &m){   //copy constructor
	row = m.row;
	col = m.col;
	array = new double*[row];
	for (int i=0; i<row; i++){
		array[i] = new double[col];
		}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			array[i][j] = m.array[i][j];
		}
	}
}
matrix::~matrix(){                 //distructor
	for (int i=0; i<row; i++){
		delete[] array[i];
		}
	delete[] array;
	};
/*void matrix::setElement(){   //setting elements
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
        cin>>array[i][j];
		}
	}
	
};*/
	istream &operator>>( istream  &input,matrix &m)
	{ for(int i=0;i<m.row;i++){
		for(int j=0;j<m.col;j++){
        input>>m.array[i][j];
		}
	}
        
         return input;            
    }

double matrix::getElement(int r, int c){   //getting elements in matrix 
	return array[r][c];
}
matrix matrix::operator+(const matrix& m){      //+ operator overloading
	if(row!=m.row || col!=m.col){
		throw error("not have same dimension");
	}else{
	
	matrix new_mat(row,col);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			new_mat.array[i][j] = array[i][j] + m.array[i][j];
		}
	}
	return new_mat;
}}
matrix matrix::operator-(const matrix& m)         //- operator overloading
{
	if(row!=m.row || col!=m.col){
		throw error("not have same dimension");
	}else{
	if (row != m.row || col != m.col){
		return (*this);
	}
	matrix new_mat(row,col);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			new_mat.array[i][j] = array[i][j] - m.array[i][j];
		}
	}
	return new_mat;
}}
matrix matrix::operator*(const matrix& m){            //* operator overloading
	matrix m3(row,m.col);
	if(col!=m.row){
		throw error("multiplication not exist");
	}else{
    for (int i = 0; i < row; i++){
          for (int j = 0; j < m.col; j++){
              m3.array[i][j] = 0;
              for (int k = 0; k < m.row; k++)
                  m3.array[i][j] += array[i][k]*m.array[k][j];
          }
    }
    return m3;
    }
}
matrix& matrix::operator=(const matrix& t){          //assign operator overloading
	if(this!=&t){
		delete[] array;
        array=new double*[row];
        for(int i=0;i<row;i++){
        	array[i]=new double [col];
        }
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		array[i][j]=t.array[i][j];
        	}
        }
	} 
  return *this;
}

int main(){int n,m2; 
while(1){
try{                                               
	cout<<"0==add"<<endl;;
	cout<<"1==subtract"<<endl;;
	cout<<"2==multiplication"<<endl;;
	cout<<"3==transpose"<<endl;;
	cout<<"4==Cofactor"<<endl;;
	cout<<"5==determinant"<<endl;;
	cout<<"6==inverse"<<endl;;
int k; cin>>k;
if(k==0){                                             //addition of matrix
	cout<<"enter no. of matrix"<<endl;
	int l; cin>>l;
	matrix *m[l];cout<<"enter matrix"<<endl;
	for(int i=0;i<l;i++){
		cout<<"enter dimension"<<endl;
		cin>>n>>m2;
       m[i]= new matrix(n,m2);
		
		//(*m[i]).setElement();
	cin>>(*m[i]);
	}

	matrix m1(n,m2);
	for(int i=0;i<n;i++){
		//(*m[i]).display();
		m1=m1+(*m[i]);
	}
m1.display();
}
if(k==1){                                           //subtraction of matrix
	cout<<"enter no. of matrix"<<endl;
	int l; cin>>l;
	matrix *m[l];cout<<"enter matrix"<<endl;
	for(int i=0;i<l;i++){
cout<<"enter dimension"<<endl;
		cin>>n>>m2;
       m[i]= new matrix(n,m2);
		
		//(*m[i]).setElement();
	cin>>(*m[i]);
	}

	matrix m1(n,m2);
	for(int i=0;i<n;i++){
		//(*m[i]).display();
		m1=m1-(*m[i]);
	}
m1.display();
}
if(k==2){                                          //multiplication of matrix
	cout<<"enter no. of matrix"<<endl;
	int l; cin>>l;
	matrix *m[l];cout<<"enter matrix"<<endl;
	for(int i=0;i<l;i++){
		cout<<"enter dimension"<<endl;cin>>n>>m2;
       m[i]= new matrix(n,m2);
		
		//(*m[i]).setElement();
	cin>>(*m[i]);
	}

	matrix m1(n,m2);
	m1=(*m[0]);
	for(int i=1;i<n;i++){
		//(*m[i]).display();
		m1=m1*(*m[i]);
	}
m1.display();
}
if(k==3){int n,m1;                                   //transpose of a matrix
	cout<<"enter dimension"<<endl;cin>>n>>m1;
	cout<<"enter matrix"<<endl;
	matrix m(n,m1);
	
	cin>>m;
	(m.transpose()).display();
}
if(k==4){int n,m1;
	cout<<"enter dimension"<<endl;cin>>n>>m1;
	cout<<"enter matrix"<<endl;
	matrix m(n,m1);

	//m.setElement();
cin>>m;

	cout<<"enter cordinate";int i,j;cin>>i>>j;
	(m.getCofactor(i,j)).display();
}
if(k==5){int n,m1;                                   //det of a matrix
	cout<<"enter dimension"<<endl;cin>>n>>m1;
	cout<<"enter matrix"<<endl;
	matrix m(n,m1);

	//m.setElement();
	cin>>m;
	cout<<(m.determinant());
}
if(k==6){int n,m1;                                 //inverse of a matrix
	cout<<"enter dimension"<<endl;cin>>n>>m1;
	cout<<"enter matrix"<<endl;
	matrix m(n,m1);

	//m.setElement();
	cin>>m;
	(m.adjoint()).display();
}

}

catch(error x){                           //catching errors
	cout<<x.s<<endl;
}
}
return 0;
}
