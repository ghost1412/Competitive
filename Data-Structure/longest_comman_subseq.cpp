#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int longest_common_sub(string a,string b,int n,int m){
		if(m==0 || n==0)
			return 0;
		else 
		if(a[n-1]==b[m-1])
			return 1+longest_common_sub(a,b,n-1,m-1);
		else
			return max(longest_common_sub(a,b,n,m-1),longest_common_sub(a,b,n-1,m));
}
void lsc(string a,string b,int n,int m){
	int ar[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0){
				ar[i][j]=0;
			}
			else
				if(a[i-1]==b[j-1]){
					ar[i][j]=ar[i-1][j-1]+1;
				}
				else
					ar[i][j]=max(ar[i-1][j],ar[i][j-1]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++)
			cout<<ar[i][j];
		cout<<endl;
	}
	int t=ar[n][m];
	char st[t];
	st[t]='\0';
		int i=n; int j=m;
			while(i>0 && j>0){
				if(a[i-1]==b[j-1]){
					st[t-1]=a[i-1]; t--; i--;j--;
				}
				else
					if(ar[i-1][j]>ar[i][j-1]){
						i--;
					}else
					j--;
			}
cout<<st;
}
int main(){
	string a,b;                    //string for comparision
		cin>>a>>b;
		int n=a.length();
		int m=a.length();
	lsc(a,b,n,m);
		
return 0;
}
