#include<bits/stdc++.h>
using namespace std;

struct BigNum {
	int len;
	int d[10000];
} a,b;

void input() {
	string n1,n2;
	cin>>n1>>n2;
	int l1 = n1.length();
	int l2 = n2.length();

	for(int i = 0; i<l1; i++) {
		a.d[l1-i-1] = n1[i] - '0';
	}
	a.len = l1;

	for(int i = 0; i<l2; i++) {
		b.d[l2-i-1] = n2[i] - '0';
	}
	b.len = l2;
}

void output() {
	for(int i = a.len-1; i>=0; i--) {
		cout<<a.d[i];
	}
	cout<<endl; 
}

bool cmp(BigNum a1,BigNum a2) {
	if(a1.len!=a2.len) return a1.len>a2.len;
	for(int i = a1.len-1; i>=0; i--) {
		if(a1.d[i]!=a2.d[i]) return a1.d[i]>a2.d[i];
	}
	return false;
}

int mod(int a1,int n) {
	while(a1>=n) {
		a1 -= n;
	}
	return a1;
}

void jia() {
	if(a.len<b.len) swap(a,b);
	for(int i = 0; i<a.len; i++) {
		a.d[i] = a.d[i] + b.d[i];
	}
	for(int i = 0; i<a.len; i++) {
		if(a.d[i]>=10) {
			a.d[i] -= 10;
			a.d[i+1] += 1;
		}
	}
	if(a.d[a.len]!=0) a.d[a.len]++;
}

void jian() {
	bool zhengshu = cmp(a,b);
	if(!zhengshu) swap(a,b);

	for(int i = 0; i<a.len; i++) {
		a.d[i] = a.d[i] - b.d[i];
	}
	for(int i = 0; i<a.len; i++) {
		if(a.d[i]<0) {
			a.d[i] += 10;
			a.d[i+1] -= 1;
		}
	}
	if(a.d[a.len-1]==0) a.len--;
	if(!zhengshu) a.d[a.len-1] = -a.d[a.len-1];
}

void cheng() {

	BigNum t;

	if(a.len<b.len) swap(a,b);
	for(int i = 0; i<b.len; i++) {
		for(int j = 0; j<a.len; j++) {
			t.d[i+j] = t.d[i+j] + b.d[i] * a.d[j];
		}
	}
	for(int i = 0; i<a.len+b.len; i++) {
		if(t.d[i] >= 10) {
			t.d[i+1] = t.d[i+1] + (t.d[i] - mod(t.d[i],10))/10;
			t.d[i] = mod(t.d[i],10);
		}
	}
	int jinwei = 0;
	for(int i = a.len; i<=a.len+b.len; i++) {
		if(t.d[i]!=0) jinwei++;
	}
	for(int i = 0; i<=a.len+jinwei; i++) {
		a.d[i] = t.d[i];
	}
	a.len += jinwei;
//	a.len = 50;
}

void youyiwei(BigNum &a,int n) {
	for(int i = a.len + n-1; i>=n; i--) {
		a.d[i] = a.d[i-n];
	}
	for(int i = 0; i<n; i++) {
		a.d[i] = 0;
	}
	a.len+=n;
}

void zuoyiwei(BigNum &a,int n) {
	for(int i = 0; i<a.len-n; i++) {
		a.d[i] = a.d[i+n];
	}
	for(int i = a.len-n; i<=a.len; i++) {
		a.d[i] = 0;
	}
	a.len-=n;
}

void chu() {
	BigNum r;
	if(!cmp(a,b)) {
		cout<<"0";
		return;
	}
	int xiangchaweishu = a.len-b.len;
	int s = xiangchaweishu;
	youyiwei(b,xiangchaweishu);
	
	while(xiangchaweishu>=0) {
		int cnt = 0;
		while(cmp(a,b)) {
			cnt++;
			jian();
		}
		r.d[xiangchaweishu] = cnt;
		zuoyiwei(b,1);
		xiangchaweishu -= 1;

	}
	for(int i = s;i>=0;i--){
		if(r.d[i]!=0){
			r.len = i+1;
			break;
		}
	}
	for(int i = r.len-1; i>=0; i--) {
		cout<<r.d[i];
	}
	cout<<endl;
}

int main() {
	input();
	
//	jia();
//	output();
	
//	jian();
//	output();
	
	cheng();
	output();
//	
//	chu();

	return 0;
}
