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
//#define INF 0x3f3f3f3f
 
using namespace std;

const int maxn=1e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
 
struct segtree{
	int l,r;
	ll sum;		//sum维护该区间内整数和 
//	ll tag; 	//延迟标记	
};
 
segtree t[maxn*4];

ll a[maxn];

void pushup(int p){//区间合并，向上拓展 
	t[p].sum=t[2*p].sum+t[2*p+1].sum;
}

//void pushdown(int p){//将父节点的状态向下传递（延迟标记的传递） 
//	if(t[p].tag){//说明父节点的状态已被改变 
//		int lson=p*2,rson=p*2+1;
//		int mid=(t[p].l+t[p].r)/2;
//		t[lson].tag+=t[p].tag;		//注意这里一定是要累加，因为该区间有可能被父节点多次更新 
//		t[rson].tag+=t[p].tag;
//		t[lson].sum+=(t[lson].r-t[lson].l+1)*t[p].tag;
//		t[rson].sum+=(t[rson].r-t[rson].l+1)*t[p].tag;
//		t[p].tag=0;//父节点传递完成后标志复原 
//	}
//}
 
void build(int p,int l,int r){//建树 
	int mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
//	t[p].tag=0;			//初始化延迟标记 
	if(l==r){
		scanf("%lld",&t[p].sum);
		return;
	}
	build(p*2,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
 
ll query(int p,int L,int R){
	if(L<=t[p].l&&R>=t[p].r){
		return t[p].sum;
	}
	int lson=p*2;
	int rson=p*2+1;
	ll tsum=0;
	int mid=(t[p].l+t[p].r)/2;
//	pushdown(p);		//在向下访问之前，先向下更新 
	if(L<=mid){		//如果左侧还有区间 
		tsum+=query(lson,L,R);
	}
	if(R>mid){ 		//如果右侧还有区间
		tsum+=query(rson,L,R);
	} 
	return tsum;
} 
 

 
void update(int p,int L,int R){
	int lson=p*2,rson=p*2+1;
	if(t[p].sum==t[p].r-t[p].l+1)  return;
	if(t[p].l==t[p].r){//区间被完全覆盖 
//		t[p].tag+=num;		//这里累加，原因同上 
		t[p].sum=(ll)sqrt(t[p].sum);
		return;//由于此处直接返回，所以需要延迟标记，此处未更新该节点的子树 
	}
//	pushdown(p);//进入子节点前先传递延迟标记，便于接下来的递归更新 
	int mid=(t[p].l+t[p].r)/2;
	if(L<=mid){
		update(lson,L,R);
	} 
	if(R>mid){
		update(rson,L,R);
	}
	pushup(p);//子节点更新返回后要更新父节点 
}

 
 
int main(){
	int n,q,cas=0;
	while(scanf("%d",&n)!=EOF){
		++cas;
		printf("Case #%d:\n",cas);
		build(1,1,n);
		int t,x,y;
		scanf("%d",&q);
		
		for(int i=1;i<=q;i++){
			scanf("%d%d%d",&t,&x,&y);
			if(x>y)  swap(x,y);
			if(t==0){
				update(1,x,y);
			}
			else{
				printf("%lld\n",query(1,x,y));
			}
		} 
		printf("\n");
	}
	return 0;
}
