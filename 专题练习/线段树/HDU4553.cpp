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
 
struct segtree{
	int l,r;
	int lsum,rsum,sum;//lsum从左端开始连续的区间长度，rsum从右端开始连续的区间长度 
    int llsum,rrsum,ssum;
	int tag;//延迟标记 
};
 
segtree t[100005*4];
 
void build(int p,int l,int r){//建树 
	int mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
	t[p].lsum=t[p].rsum=t[p].sum=r-l+1;
    t[p].llsum=t[p].rrsum=t[p].ssum=r-l+1;
	t[p].tag=-1;
	if(l==r)  return;
	build(p*2,l,mid);
	build(2*p+1,mid+1,r);
}
 
void pushdown(int p){//将父节点的状态向下传递（延迟标记的传递） 
	if(t[p].tag!=-1){//说明父节点的状态已被改变 
		int lson=p*2,rson=p*2+1;
		t[lson].tag=t[rson].tag=t[p].tag;
        if(t[p].tag==2){
            t[lson].llsum=t[lson].rrsum=t[lson].ssum=0;
            t[lson].lsum=t[lson].rsum=t[lson].sum=0;
            t[rson].llsum=t[rson].rrsum=t[rson].ssum=0;
			t[rson].lsum=t[rson].rsum=t[rson].sum=0;
        }
		else if(t[p].tag==1){//父节点的区间被占用 
			t[lson].lsum=t[lson].rsum=t[lson].sum=0;
			t[rson].lsum=t[rson].rsum=t[rson].sum=0;
            t[lson].llsum=t[lson].rrsum=t[lson].ssum=(t[lson].r-t[lson].l+1);
			t[rson].llsum=t[rson].rrsum=t[rson].ssum=(t[rson].r-t[rson].l+1);
		}
		else{//父节点的区间空闲 
			t[lson].lsum=t[lson].rsum=t[lson].sum=(t[lson].r-t[lson].l+1);
			t[rson].lsum=t[rson].rsum=t[rson].sum=(t[rson].r-t[rson].l+1);
            t[lson].llsum=t[lson].rrsum=t[lson].ssum=(t[lson].r-t[lson].l+1);
			t[rson].llsum=t[rson].rrsum=t[rson].ssum=(t[rson].r-t[rson].l+1);
		}
		t[p].tag=-1;//父节点传递完成后标志复原 
	}
}
 
int query(int len,int p){
	if(t[p].l==t[p].r){
		return t[p].l;
	}
	pushdown(p);//首先将本节点的状态传递下去，便于接下来的递归查询 
	int lson=p*2;
	int rson=p*2+1;
	if(t[lson].sum>=len){//如果左侧的空闲长度足够，先检测左侧（保证最小的编号） 
		return query(len,lson);
	}
	else if(t[lson].rsum+t[rson].lsum>=len){//考虑跨越左右两侧的区间 
		return (t[p].l+t[p].r)/2-t[lson].rsum+1;
	} 
	else{//检测右侧 
		return query(len,rson);
	} 
} 

int qquery(int len,int p){
	if(t[p].l==t[p].r){
		return t[p].l;
	}
	pushdown(p);//首先将本节点的状态传递下去，便于接下来的递归查询 
	int lson=p*2;
	int rson=p*2+1;
	if(t[lson].ssum>=len){//如果左侧的空闲长度足够，先检测左侧（保证最小的编号） 
		return qquery(len,lson);
	}
	else if(t[lson].rrsum+t[rson].llsum>=len){//考虑跨越左右两侧的区间 
		return (t[p].l+t[p].r)/2-t[lson].rrsum+1;
	} 
	else{//检测右侧 
		return qquery(len,rson);
	} 
} 
 
void pushup(int p){//区间合并 
	int lson=p*2,rson=p*2+1;
	t[p].lsum=t[lson].lsum;
	t[p].rsum=t[rson].rsum;
	//进一步更新lsum和rsum 
	if(t[lson].lsum==(t[lson].r-t[lson].l+1))  t[p].lsum+=t[rson].lsum;
	if(t[rson].rsum==(t[rson].r-t[rson].l+1))  t[p].rsum+=t[lson].rsum;
	//sum取三种情况下的最大值 
	t[p].sum=max(t[lson].rsum+t[rson].lsum,max(t[lson].sum,t[rson].sum));

    t[p].llsum=t[lson].llsum;
	t[p].rrsum=t[rson].rrsum;
	//进一步更新lsum和rsum 
	if(t[lson].llsum==(t[lson].r-t[lson].l+1))  t[p].llsum+=t[rson].llsum;
	if(t[rson].rrsum==(t[rson].r-t[rson].l+1))  t[p].rrsum+=t[lson].rrsum;
	//sum取三种情况下的最大值 
	t[p].ssum=max(t[lson].rrsum+t[rson].llsum,max(t[lson].ssum,t[rson].ssum));
}
 
void update(int p,int L,int R,int flag){//flag=1表示占用，flag=0表示空闲 
	int lson=p*2,rson=p*2+1;
	if(L<=t[p].l&&R>=t[p].r){//区间被完全覆盖 
		t[p].tag=flag;
		t[p].lsum=t[p].rsum=t[p].sum=(flag?0:(t[p].r-t[p].l+1));
        t[p].llsum=t[p].rrsum=t[p].ssum=(flag>1?0:(t[p].r-t[p].l+1));
		return;//由于此处直接返回，所以需要延迟标记，此处未更新该节点的子树 
	}
	pushdown(p);//进入子节点前先传递延迟标记，便于接下来的递归更新 
	int mid=(t[p].l+t[p].r)/2;
	if(L<=mid){
		update(lson,L,R,flag);
	} 
	if(R>mid){
		update(rson,L,R,flag);
	}
	pushup(p);//子节点更新返回后要更新父节点 
}
 
 
 
int main(){
    int cas,kcas=0;
    scanf("%d",&cas);
    while(cas--){
        printf("Case %d:\n",++kcas);
        int n,m;
	    scanf("%d%d",&n,&m);
        build(1,1,n);
        rep(i,1,m){
            char com[30];
            scanf("%s",com);
            if(com[0]=='D'){
                int d;
                scanf("%d",&d);
                if(d>t[1].sum)  printf("fly with yourself\n");//如果需要入住的量大于整个区间内的连续空闲区间，则无法安排 
                else{
                    int ans=query(d,1);
                    printf("%d,let's fly\n",ans);
                    update(1,ans,ans+d-1,1);//记得要更新 
                }
            }
            else if(com[0]=='N'){
                int d;
                scanf("%d",&d); 
                if(t[1].sum>=d){
                    int ans=query(d,1);
                    printf("%d,don't put my gezi\n",ans);
                    update(1,ans,ans+d-1,2);//记得要更新 
                }
                else if(t[1].ssum>=d){
                    int ans=qquery(d,1);
                    printf("%d,don't put my gezi\n",ans);
                    update(1,ans,ans+d-1,2);//记得要更新 
                }
                else{
                    printf("wait for me\n");
                }
            }
            else{
                int x,y;
                scanf("%d%d",&x,&y);
                update(1,x,y,0);
                printf("I am the hope of chinese chengxuyuan!!\n");
            }
        } 
    }
	return 0;
}