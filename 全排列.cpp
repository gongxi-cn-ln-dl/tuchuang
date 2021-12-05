#include<bits/stdc++.h>
using namespace std;

int n;

bool Used(int a,int A[],int x){
	for(int i = 1;i<=a;i++){
		if(A[i]==x) return true;
	}
	return false;
}
void f(int a,int A[]){
	if(a>n){
		for(int i = 1;i<=n;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1;i<=n;i++){
		if(Used(a,A,i)) continue;
		A[a] = i;
		f(a+1,A);
	}
}
int main(){
	scanf("%d",&n);
	int A[50];
	f(1,A);
	return 0;
}

