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
const ll mod=1e9+7;
 
struct segtree{
	int l,r;
	ll sum;		//sum维护该区间内整数和
    ll cnt; 
	ll tag; 	//延迟标记	
};
 
segtree t[maxn*4];
 
ll sum[maxn];
char str[maxn];
 
void pushup(int p){//区间合并，向上拓展 
	t[p].sum=(t[2*p].sum+t[2*p+1].sum)%mod;
    t[p].cnt=t[2*p].cnt+t[2*p+1].cnt;
}
 
void pushdown(int p){//将父节点的状态向下传递（延迟标记的传递） 
	if(t[p].tag){//说明父节点的状态已被改变 
		int lson=p*2,rson=p*2+1;
		int mid=(t[p].l+t[p].r)/2;
		t[lson].tag+=t[p].tag;		//注意这里一定是要累加，因为该区间有可能被父节点多次更新 
		t[rson].tag+=t[p].tag;
		t[lson].sum+=(t[lson].r-t[lson].l+1)*t[p].tag;
		t[rson].sum+=(t[rson].r-t[rson].l+1)*t[p].tag;
		t[p].tag=0;//父节点传递完成后标志复原 
	}
}
 
void build(int p,int l,int r){//建树 
	int mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
	t[p].tag=0;			//初始化延迟标记 
	if(l==r){
		t[p].sum=sum[l];
        if(t[p].sum)  t[p].cnt=1;
        else t[p].cnt=0;
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
	pushdown(p);		//在向下访问之前，先向下更新 
	if(L<=mid){		//如果左侧还有区间 
		tsum=(tsum+query(lson,L,R))%mod;
	}
	if(R>mid){ 		//如果右侧还有区间
		tsum=(tsum+query(rson,L,R))%mod;
	} 
	return tsum;
} 
 
ll querycnt(int p,int L,int R){
    if(L<=t[p].l&&R>=t[p].r){
		return t[p].cnt;
	}
	int lson=p*2;
	int rson=p*2+1;
	ll tcnt=0;
	int mid=(t[p].l+t[p].r)/2;
	pushdown(p);		//在向下访问之前，先向下更新 
	if(L<=mid){		//如果左侧还有区间 
		tcnt+=querycnt(lson,L,R);
	}
	if(R>mid){ 		//如果右侧还有区间
		tcnt+=querycnt(rson,L,R);
	} 
	return tcnt;
}
 
void update(int p,int L,int R,ll num){
	int lson=p*2,rson=p*2+1;
	if(L<=t[p].l&&R>=t[p].r){//区间被完全覆盖 
		t[p].tag+=num;		//这里累加，原因同上 
		t[p].sum+=(t[p].r-t[p].l+1)*num;
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
 
void updatepoint(int p,int pos,int num){
    if(t[p].l==t[p].r){
        t[p].sum=num;
        if(t[p].sum)  t[p].cnt=1;
        else  t[p].cnt=0;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(pos<=mid)  updatepoint(p*2,pos,num);
    else  updatepoint(p*2+1,pos,num);
    pushup(p);
}
 
int main(){
	int n,q,m,pos;
	scanf("%d",&n);
    scanf("%s",str+1);
    memset(sum,0,sizeof sum);
    for(int i=1;i<=n;i++){
        if(str[i]=='1'){
            sum[i]=i;
        }
    }
	build(1,1,n);
    ll ans=0;
    int flag=0;
    for(ll i=1;i<=n;i++){
        if(sum[i]){
            if(!flag){
                flag=1;
                continue;
            }
            ans=(ans+(sum[i])*(querycnt(1,1,i)-1)%mod-query(1,1,i)%mod+sum[i]+mod*10)%mod;
        }
        
    }
    printf("%lld\n",ans%mod);
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&q,&pos);
        if(q==1){
            ll tmp=query(1,1,pos),tmpcnt=querycnt(1,1,pos);
            ans=(ans+pos*tmpcnt%mod-tmp%mod+mod*10)%mod;
            tmp=query(1,pos,n),tmpcnt=querycnt(1,pos,n);
            ans=(ans-pos*tmpcnt%mod+tmp%mod+mod*10)%mod;
            printf("%lld\n",ans%mod);
            updatepoint(1,pos,pos);
        }
        else{
            ll tmp=query(1,1,pos),tmpcnt=querycnt(1,1,pos);
            ans=(ans-pos*(tmpcnt-1)%mod+tmp%mod-pos+mod*10)%mod;
            tmp=query(1,pos,n);
            tmpcnt=querycnt(1,pos,n);
            ans=(ans+pos*(tmpcnt-1)%mod-tmp%mod+pos+mod*10)%mod;
            printf("%lld\n",ans%mod);
            updatepoint(1,pos,0);
        }
    }
	return 0;
}