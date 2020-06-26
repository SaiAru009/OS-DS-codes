//BEST-FIT, FIRST-FIT, WORST-FIT Implementation.
#include<iostream>
using namespace std;
void ffit(int holes[10],int prc[10],int m,int n){
	int map[n]={-1};     // '-1' indicates that prc hasn't been allocated yet.
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(holes[j]>prc[i]){
			holes[j]-=prc[i];
			map[i]=j;
			break;}
		}
	}
	for(int i=0;i<n;i++)
	 cout<<map[i]<<" ";
}

void wfit(int holes[10],int prc[10],int m,int n){
	int map[n]={-1},max,pos;     // '-1' indicates that prc hasn't been allocated yet.
	for(int i=0;i<n;i++){
		max=0; pos=-1;
		for(int j=0;j<m;j++){
			if(holes[j]>prc[i] && holes[j]>max){
				max=holes[j];
				pos=j;
			}
		}
		if(pos!=-1)
		holes[pos]-=prc[i];
		map[i]=pos;
	}
	for(int i=0;i<n;i++)
	 cout<<map[i]<<" ";
}
void bfit(int holes[10],int prc[10],int m,int n){
	int map[n]={-1},min,pos;     // '-1' indicates that prc hasn't been allocated yet.
	for(int i=0;i<n;i++){
		min=INT_MAX; pos=-1;
		for(int j=0;j<m;j++){
			if(holes[j]>=prc[i] && holes[j]<min){
				min=holes[j];
				pos=j;
			}
		}
		if(pos!=-1)
		holes[pos]-=prc[i];
		map[i]=pos;
	}
	for(int i=0;i<n;i++)
	 cout<<map[i]<<" ";
}
int main(){
	int holes[10], prc[10],rm[10],m,n,cnt=0;
	cout<<"Enter no of holes";
	cin>>m;
	cout<<"\nEnter no of processes";
	cin>>n;
	cout<<"\nEnter the holes size:";
	for(int i=0;i<m;i++){
	 cin>>holes[i];
	 rm[i]=holes[i];}
	cout<<"\nEnter the processes size:";
	for(int i=0;i<n;i++)
	 cin>>prc[i];
	ffit(rm,prc,m,n);
	for(int i=0;i<m;i++){
	 cnt+=rm[i];
	 rm[i]=holes[i];}
	cout<<"\nExternal fragmentation (in KB) for First-fit: "<<cnt<<endl;
	cnt=0;
	bfit(rm,prc,m,n);
	for(int i=0;i<m;i++){
	 cnt+=rm[i];
	 rm[i]=holes[i];}
	cout<<"\nExternal fragmentation (in KB) for best-fit: "<<cnt<<endl;
	cnt=0;
	wfit(rm,prc,m,n);
	for(int i=0;i<m;i++)
	 cnt+=rm[i];
	cout<<"\nExternal fragmentation (in KB) for worst-fit: "<<cnt;
}
