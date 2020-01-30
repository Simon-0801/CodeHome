#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 50000 + 5;

struct node{
    int l,r;
    int lsum,rsum;//lsum,该区间下从左端点开始向右的最长连续子区间的长度；rsum,该区间下从右端点开始向左的最长连续子区间的长度
}t[maxn*4];

char str[10];
vector<int> sta;

void pushup(int p){
    int lson=p*2,rson=p*2+1;
    if(t[lson].lsum==t[lson].r-t[lson].l+1){
        t[p].lsum=t[lson].lsum+t[rson].lsum;
    }
    else{
        t[p].lsum=t[lson].lsum;
    }
    if(t[rson].rsum==t[rson].r-t[rson].l+1){
        t[p].rsum=t[rson].rsum+t[lson].rsum;
    }
    else{
        t[p].rsum=t[rson].rsum;
    }
}

void build(int p,int l,int r){
    int lson=p*2,rson=p*2+1;
    t[p].l=l;
    t[p].r=r;
    if(l==r){
        t[p].lsum=t[p].rsum=1;
        return;
    }
    int mid=(l+r)/2;
    build(lson,l,mid);
    build(rson,mid+1,r);
    pushup(p);
}

void update(int p,int x,int num){
    if(t[p].l==t[p].r){
        t[p].lsum=t[p].rsum=num;
        return;
    }
    int lson=p*2,rson=p*2+1;
    int mid=(t[p].l+t[p].r)/2;
    if(mid>=x) update(lson,x,num);
    else  update(rson,x,num);
    pushup(p); 
}

int query(int p,int x){
    if(p==1){
        if(t[p].lsum&&t[p].l+t[p].lsum-1>=x){
            return t[p].lsum;
        }
        if(t[p].rsum&&t[p].r-t[p].rsum+1<=x){
            return t[p].rsum;
        }
    }
    if(t[p].lsum&&t[p].l+t[p].lsum-1>=x){
        return t[p].lsum+t[p-1].rsum;
    }
    if(t[p].rsum&&t[p].r-t[p].rsum+1<=x){
        return t[p].rsum+t[p+1].lsum;
    }
    if(t[p].l==t[p].r)  return 0;
    int lson=p*2,rson=p*2+1;
    int mid=(t[p].l+t[p].r)/2;
    if(mid>=x){
        return query(lson,x);
    }
    else{
        return query(rson,x);
    }
}

int main() {
    int n,m,num;
    while(~scanf("%d%d",&n,&m)){
        sta.clear();
        build(1,1,n);
        for(int i=1;i<=m;i++){
            scanf("%s",str);
            if(str[0]=='D'){
                scanf("%d",&num);
                update(1,num,0);
                sta.push_back(num);
            }
            else if(str[0]=='R'){
                num=sta.back();
                sta.pop_back();
                update(1,num,1);
            }
            else if(str[0]='Q'){
                scanf("%d",&num);
                printf("%d\n",query(1,num));
            }
        }
    }
    return 0;
}