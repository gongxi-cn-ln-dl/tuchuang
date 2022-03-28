//LuoGu P1038.cpp
#include<bits/stdc++.h>
using namespace std;

const int maxN = 150;
const int maxE = (1e6+50);

struct Node{
	int inn,oun;
	int val;
	int u;
}node[maxN];

int head[maxN];
int tot;

struct Edge{
	int u,nxt,to,w;
}edge[maxE];

void add_edge(int u,int v,int w){
	edge[++tot].u = u;
	edge[tot].to = v;
	edge[tot].w = w;
	edge[tot].nxt = head[u];
	head[u] = tot;
}

int n,p;

int Search(int k){
	int eid = k;
	if(node[eid].val != 0) return node[eid].val;
	if(node[eid].inn == 0) return node[eid].val;
	for(int i = head[eid];i;i = edge[i].nxt){
		int to_ = edge[i].to;
		int un = edge[i].u;
		int t = Search(to_);
		if(t <= 0) continue;
//		int vn = edge[i].to;
		node[un].val +=  t * edge[i].w;
	}
//	for(int i = 1;i<=n;i++) printf("%d ",node[i].val);
//	printf("\n");
	node[k].val -= node[k].u;
	return node[k].val;
}

int main(){
	scanf("%d%d",&n,&p);
	for(int i = 1;i<=n;i++){
		int sta,u;
		scanf("%d%d",&sta,&u);
		node[i].val = sta;
		node[i].u = u;
		node[i].oun = 0;
		node[i].inn = 0;
	}
	for(int i = 0;i<p;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		node[u].oun++;
		node[v].inn++;
		add_edge(v,u,w);
	}
	int flg = 1;
	for(int i = 1;i<=n;i++){
		if(node[i].oun != 0) continue;
		int t = Search(i);
		if(t <= 0) continue;
		printf("%d %d\n",i,node[i].val);
		flg = 0;
	}
	if(flg) printf("NULL");
	return 0;
}
