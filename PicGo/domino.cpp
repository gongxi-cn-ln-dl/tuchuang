#include<bits/stdc++.h>
using namespace std;

struct BG{
	int len;
	int d[100];
}A[55];

BG add(BG b,BG a){
	BG t;
	memset(t.d,0,100);
	t.len = b.len;
	for(int i = 0;i<t.len;i++){
		t.d[i] = a.d[i] + b.d[i];
	}
	for(int i = 0;i<t.len;i++){
		if(t.d[i]>=10){
			t.d[i] -= 10;
			t.d[i+1] += 1;
		}
	}
	if(t.d[t.len]>0) t.len++;
	return t;
}
void output(BG a){
	for(int i = a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
}
int main(){
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n<=2){
		printf("%d",n);
		return 0;
	}
	
	A[1].len = 1;
	A[1].d[0] = 1;
	A[2].len = 1;
	A[2].d[0] = 2;
	
	for(int i = 3;i<=n;i++){
		A[i] = add(A[i-1],A[i-2]);
//		output(A[i]);
//		printf("\n");
	}
	output(A[n]);
	return 0;
}
