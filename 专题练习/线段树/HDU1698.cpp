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
	int sum;//lsum从左端开始连续的区间长度，rsum从右端开始连续的区间长度
	int tag; 
};
 
segtree t[maxn*4];

ll a[maxn];

void pushup(int p){//区间合并 
	t[p].sum=t[2*p].sum+t[2*p+1].sum;
}

void pushdown(int p){//将父节点的状态向下传递（延迟标记的传递） 
	if(t[p].tag){//说明父节点的状态已被改变 
		int lson=p*2,rson=p*2+1;
		int mid=(t[p].l+t[p].r)/2;
		t[lson].tag=t[p].tag;
		t[rson].tag=t[p].tag;
		t[lson].sum=(t[lson].r-t[lson].l+1)*t[p].tag;
		t[rson].sum=(t[rson].r-t[rson].l+1)*t[p].tag;
		t[p].tag=0;//父节点传递完成后标志复原 
	}
}
 
void build(int p,int l,int r){//建树 
	int mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
	t[p].tag=0;
	if(l==r){
		t[p].sum=1;
		return;
	}
	build(p*2,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
 




//void change(int p,int pos,int num){
//	if(t[p].l==t[p].r){
//		t[p].sum+=num;
//		return;
//	}
//	int mid=(t[p].l+t[p].r)/2;
//	if(pos<=mid)  change(2*p,pos,num);
//	else  change(2*p+1,pos,num);
//	pushup(p);
//}
 
int query(int p,int L,int R){
//	if(t[p].l==t[p].r){
//		return t[p].sum;
//	}
	if(L<=t[p].l&&R>=t[p].r){
		return t[p].sum;
	}
	int lson=p*2;
	int rson=p*2+1;
	int tsum=0;
	int mid=(t[p].l+t[p].r)/2;
	pushdown(p);
	if(L<=mid){//如果左侧的空闲长度足够，先检测左侧（保证最小的编号） 
		tsum+=query(lson,L,R);
	}
	if(R>mid){//考虑跨越左右两侧的区间 
		tsum+=query(rson,L,R);
	} 
	return tsum;
} 
 

 
void update(int p,int L,int R,int num){//flag=1表示占用，flag=0表示空闲 
	int lson=p*2,rson=p*2+1;
	if(L<=t[p].l&&R>=t[p].r){//区间被完全覆盖 
		t[p].tag=num;
		t[p].sum=(t[p].r-t[p].l+1)*num;
		return;//由于此处直接返回，所以需要延迟标记，此处未更新该节点的子树 
	}
	pushdown(p);//进入子节点前先传递延迟标记，便于接下来的递归更新 
	int mid=(t[p].l+t[p].r)/2;
	if(L<=mid){
		update(lson,L,R,num);
	} 
	if(R>mid){
		update(rson,L,R,num);
	}
	pushup(p);//子节点更新返回后要更新父节点 
}

 
 
int main(){
	int n,q,t,x,y,z,cas=0;
	scanf("%d",&t);
	while(t--){
		cas++;
		scanf("%d%d",&n,&q);
		build(1,1,n);
		for(int i=1;i<=q;i++){
			scanf("%d%d%d",&x,&y,&z);
			update(1,x,y,z);
		} 
		printf("Case %d: The total value of the hook is %d.\n",cas,query(1,1,n));
	}
	
//	for(int i=1;i<=n;i++){
//		scanf("%lld",&a[i]);
//	}
//	build(1,1,n);
//	char ch[5];
//	for(int i=1;i<=q;i++){
//		
//		scanf("%s",ch);
//		if(ch[0]=='C'){
//			int a,b;
//			ll c;
//			scanf("%d%d%lld",&a,&b,&c);
//			update(1,a,b,c);
//		}
//		else{
//			int a,b;
//			scanf("%d%d",&a,&b);
//			printf("%lld\n",query(1,a,b));
//		}
//	} 
	return 0;
}
