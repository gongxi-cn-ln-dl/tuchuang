#include<bits/stdc++.h>
using namespace std;

int p(int n){
	int sum = 1;
	for(int i = 0;i<n;i++){
		sum *= 2;
	}
	return sum-1;
}
int main(){
	freopen("hanoi.in","r",stdin);
	freopen("hanoi.out","w",stdout);
	int n;
	scanf("%d",&n);
	printf("%d",p(n));
	return 0;
}
