#include<iostream>
using namespace std;
template <class T> 
class String {
	struct Srep;			// representation
	Srep *rep;

	class Cref;			// reference to char
public:

	class Range { };		// for exceptions
	
	String();			// x = "" string of length 0 and empty
	String(const T*);		// x = "abc" 
	String(const String&);	// x = other_string
	String& operator=(const T*);
	String& operator=(const String&);
	~String();                             //distructor
	String(int n);                   // string of lenght n and empty
 	String &operator+(const String b);
  	String &operator+=(const T*s);
	void check(int i) const;
	T read(int i) const;
	void write(int i, T c); 

	Cref operator[](int i);
	T operator[](int i) const;
	
	int size() const;

	String& operator+=(const String&);
	//String& operator+=(const char*);
	int stringlength(const T* str) const;
	template <class U>
	friend ostream& operator<<(ostream&, const String<U>&);
	template <class U>
	friend istream& operator>>(istream&, String<U>&);
	template <class U>
	friend U* stringcpy(U* dest_ptr, const U* src_ptr);
	template <class U>
	friend bool operator==(const String<U>& x, const U* s);
	template <class U>
	friend bool operator==(const String<U>& x, const String<U>& y);
	template <class U>
	friend bool operator!=(const String<U>& x, const U* s);
	template <class U>
	friend bool operator!=(const String<U>& x, const String<U>& y);
};

template <class T>
int stringcmp(const T*,const T*);
template<class T> 
String<T>& String<T>::operator+(const String<T> b){              //addition operator overloading 
	String<T> s1((*this).size()+b.size());                  //initializing string of size of addition of both string
   
	for(int i=0;i<b.size()+(*this).size();i++){
		if(i<(*this).size()){
			s1.write(i,(*this).read(i));
		}else
			s1.write(i,b.read(i-(*this).size()));
	}
	(*this)=s1;
	return (*this);
}
//String operator+(const String&, const char*);
template<class T>
T* stringcpy(T* dest_ptr, const T* src_ptr);
template<class T>
struct String<T>::Srep {
	T* s;	// pointer to elements
	int sz;		// number of characters
	int n;		// reference count

	Srep(int nsz, const T* p)
	{
		n = 1;
		sz = nsz;
		s = new T[sz+1];	// add space for terminator
		stringcpy(s,p);
	}

	~Srep() { delete[] s; }
	
	Srep* get_own_copy()	// clone if necessary
	{
		if (n==1) return this;
		n--;	
		return new Srep(sz,s);
	}

	void assign(int nsz, const T* p)
	{
		if (sz != nsz) {
			delete[] s;
			sz = nsz;
			s = new T[sz+1];
		}
		stringcpy(s,p);
	}

private:				// prevent copying:
	Srep(const Srep&);
	Srep& operator=(const Srep&);
};
template<class T>
class String<T>::Cref {		// reference to s[i]
friend class String<T>;
	String<T>& s;
	int i;
	Cref(String<T>& ss, int ii) : s(ss), i(ii) { }
	Cref(const Cref& r) : s(r.s), i(r.i) { }
	Cref();	// not defined, never used
public:
	operator T() const { s.check(i); return s.read(i); }	// yield value
	void operator=(T c) { s.write(i,c); }			// change value
};
template<class T>
String<T>::String()		// the empty string is the default value 
{
	rep = new Srep(0,"");
}
template<class T>
String<T>::String(int n){
	rep=  new Srep(n,"");
}
template<class T>
String<T>::String(const String<T>& x)	// copy constructor
{
	x.rep->n++;
	rep = x.rep;	// share representation
}
template<class T>
String<T>::~String()
{
	if (--rep->n == 0) delete rep;
}
template <class T>
String<T>& String<T>::operator=(const String<T>& x)	// copy assignment
{
	x.rep->n++;				// protects against ``st = st''
	if (--rep->n == 0) delete rep;
	rep = x.rep;				// share representation
	return *this;
}
template <class T>
String<T>::String(const T* s)
{
	rep = new Srep(stringlength(s),s);
}
template <class T>
String<T>& String<T>::operator=(const T* s)
{
	if (rep->n == 1)			// recycle Srep
		rep->assign(stringlength(s),s);
	else {					// use new Srep
		rep->n--;
		rep = new Srep(stringlength(s),s);
	}
	return *this;
}
template <class T>
T* stringcpy(char * dest_ptr, const T * src_ptr)
  	 {
  	   T* strresult = dest_ptr;
  	   if((dest_ptr!=NULL) && (src_ptr!=NULL))
  	   {
 	     /* Start copy src to dest */
 	     while (*src_ptr!='\0')
  	     {
  	       *dest_ptr++ = *src_ptr++;
  	     }
 	     /* put NULL termination */
 	     *dest_ptr = '\0';
  	   }
 	   return strresult;
 	 
 	 }/* End: stringcpy() */
template <class T>
void String<T>::check(int i) const
{
	if (i<0 || rep->sz<=i) throw Range();
}
template <class T>
T String<T>::read(int i) const    //read the char at ith posITON
{
	return rep->s[i];
}
template <class T>
void String<T>::write(int i, T c)  //wrtite char at ith positoin
{
	rep=rep->get_own_copy();
	rep->s[i]=c;
} 
template <class T>
typename String<T>::Cref String<T>::operator[](int i)
{
	check(i);
	return Cref(*this,i);
}
template <class T>
T String<T>::operator[](int i) const
{
	check(i);
	return rep->s[i];
}
template <class T>
int String<T>::size() const
{
	return rep->sz;
} 
template <class T>
ostream& operator<<(ostream& os, const String<T>& s)
{
	return os << s.rep->s;
}
template <class T>
istream& operator>>(istream& is, String<T>& s)          //is refrence to input stream
{
	string ss;
	is >> ss;
	s = ss.c_str();                                 // c_str() convert string to char array
	return is; 
}
template <class T>
bool operator==(const String<T>& x, const T* s)
{
	return stringcmp(x.rep->s, s) == 0;
}
template <class T>
bool operator==(const String<T>& x, const String<T>& y)
{
	return stringcmp(x.rep->s, y.rep->s) == 0;
}
template <class T>
bool operator!=(const String<T>& x, const T* s)
{
	return stringcmp(x.rep->s, s) != 0;
}
template <class T>
bool operator!=(const String<T>& x, const String<T>& y)
{
	return stringcmp(x.rep->s, y.rep->s) != 0;
}
template <class T>
int String<T>::stringlength(const T* str) const
{int len = 0;
    int i;
    
    for (i=0; str[i] != '\0'; i++) 
    {
        len++;
    }
    return(len);
	}

template <class T>
int stringcmp(const T* s1, const T* s2)
{
    int i;
    for (i = 0; s1[i] && s2[i]; ++i)
    {
        /* If characters are same or inverting the 
           6th bit makes them same */
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
           continue;
        else
           break;
    }
 
    /* Compare the last (or first mismatching in 
       case of not same) characters */
    if (s1[i] == s2[i])
        return 0;
 
    // Set the 6th bit in both, then compare
    if ((s1[i] | 32) < (s2[i] | 32)) 
        return -1;
    return 1;
}
template <class T>
int hash(const String<T>& s)
{
	int h = s.read(0);
	const int max = s.size();
	for (int i = 1; i<max; i++) h ^= s.read(i)>>1;	// unchecked access to s
	return h;
}

