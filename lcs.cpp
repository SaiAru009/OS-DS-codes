#include<iostream>
#include<string.h>
using namespace std;

int maxno(int m,int n)
{
	if(n>m||m==n)
	 return n;
	else
	 return m;
}
int main()
{ char a[]="ACTGATTGCAT",b[]="AGGTCCGCCTA";
  int m,n,i,j,l[20][20],N,k,tmp;
  m=strlen(b); n=strlen(a);
  for(i=0;i<m+1;i++)
   l[i][0]=0;
  for(j=0;j<n+1;j++)
   l[0][j]=0;
  for(i=1;i<m+1;i++)
   for(j=1;j<n+1;j++){
    if(b[i-1]==a[j-1])
     l[i][j]=l[i-1][j-1]+1;
    else
     l[i][j]=maxno(l[i][j-1],l[i-1][j]);}
   
   for(i=0;i<m+1;i++){
    for(j=0;j<n+1;j++)
	 {cout<<l[i][j]<<" ";}  
	cout<<endl;}
   N=l[m][n];
   i=m; j=n;
   k=0;
   while(k<N)
   {
   	if(b[i-1]==a[j-1])
   	 {cout<<b[i-1];
   	  i-=1; j-=1;
   	  k+=1;}
   	else
   	 {tmp=maxno(l[i][j-1],l[i-1][j]);
   	  if(l[i][j-1]==l[i-1][j]) i-=1;
   	  else if(tmp==l[i][j-1]) j-=1;
   	  else i-=1;}
   }
	return 0;
}
