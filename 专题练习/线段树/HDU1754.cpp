#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <cstdio> 
#include <map> 
#include <iomanip>
 
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define INF 0x3f3f3f3f
 
using namespace std;

const int maxn=200005;
 
struct segtree{
	int l,r;
	int maxx;//lsum从左端开始连续的区间长度，rsum从右端开始连续的区间长度 
};
 
segtree t[maxn*4];

int a[maxn];
 
void build(int p,int l,int r){//建树 
	int mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
	if(l==r){
		t[p].maxx=a[l];
		return;
	}
	build(p*2,l,mid);
	build(2*p+1,mid+1,r);
	t[p].maxx=max(t[2*p].maxx,t[2*p+1].maxx);
}
 
//void pushdown(int p){//将父节点的状态向下传递（延迟标记的传递） 
//	if(t[p].tag!=-1){//说明父节点的状态已被改变 
//		int lson=p*2,rson=p*2+1;
//		t[lson].tag=t[rson].tag=t[p].tag;
//		if(t[p].tag==1){//父节点的区间被占用 
//			t[lson].lsum=t[lson].rsum=t[lson].sum=0;
//			t[rson].lsum=t[rson].rsum=t[rson].sum=0;
//		}
//		else{//父节点的区间空闲 
//			t[lson].lsum=t[lson].rsum=t[lson].sum=(t[lson].r-t[lson].l+1);
//			t[rson].lsum=t[rson].rsum=t[rson].sum=(t[rson].r-t[rson].l+1);
//		}
//		t[p].tag=-1;//父节点传递完成后标志复原 
//	}
//}

void pushup(int p){//区间合并 
	t[p].maxx=max(t[2*p].maxx,t[2*p+1].maxx);
}

void change(int p,int pos,int num){
	if(t[p].l==t[p].r){
		t[p].maxx=num;
		return;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(pos<=mid)  change(2*p,pos,num);
	else  change(2*p+1,pos,num);
	pushup(p);
}
 
int query(int p,int L,int R){
	if(t[p].l==t[p].r){
		return t[p].maxx;
	}
	if(L<=t[p].l&&R>=t[p].r){
		return t[p].maxx;
	}
	int lson=p*2;
	int rson=p*2+1;
	int tmax=-1;
	int mid=(t[p].l+t[p].r)/2;
	if(L<=mid){//如果左侧的空闲长度足够，先检测左侧（保证最小的编号） 
		tmax=max(tmax,query(lson,L,R));
	}
	if(R>mid){//考虑跨越左右两侧的区间 
		tmax=max(tmax,query(rson,L,R));
	} 
	return tmax;
} 
 

 
//void update(int p,int L,int R,int flag){//flag=1表示占用，flag=0表示空闲 
//	int lson=p*2,rson=p*2+1;
//	if(L<=t[p].l&&R>=t[p].r){//区间被完全覆盖 
//		t[p].tag=flag;
//		t[p].lsum=t[p].rsum=t[p].sum=(flag?0:(t[p].r-t[p].l+1));
//		return;//由于此处直接返回，所以需要延迟标记，此处未更新该节点的子树 
//	}
//	pushdown(p);//进入子节点前先传递延迟标记，便于接下来的递归更新 
//	int mid=(t[p].l+t[p].r)/2;
//	if(L<=mid){
//		update(lson,L,R,flag);
//	} 
//	if(R>mid){
//		update(rson,L,R,flag);
//	}
//	pushup(p);//子节点更新返回后要更新父节点 
//}
// 
 
 
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		build(1,1,n);
//		cout<<"---"<<t[1].maxx<<endl;
		char ch[5];
		int a,b;
		for(int i=1;i<=m;i++){
			scanf("%s %d %d",ch,&a,&b);
//			cout<<ch[0]<<endl;
			if(ch[0]=='Q'){
				cout<<query(1,a,b)<<endl;
			}
			else{
				change(1,a,b);
			}
		}
	}
	return 0;
}
