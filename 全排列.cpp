#include<bits/stdc++.h>
using namespace std;

int n;

bool isUsed(int A[],int x,int t){
	for(int i = 0;i<x;i++){
		if(A[i]==t) return true;
	}
	return false;
}
void print(int A[]){
	for(int i = 0;i<n;i++){
		printf("%5d",A[i]);
	}
	printf("\n");
}
int f(int A[],int x){
	if(x == n){
		print(A);
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(isUsed(A,x,i)) continue;
		A[x] = i;
		f(A,x+1);
	}
}

int main(){
	scanf("%d",&n);
	int A[15] = {0};
	f(A,0);
	return 0;
}
