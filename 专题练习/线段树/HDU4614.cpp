#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 50000 + 5;

struct node
{
    int l,r;
    int sum;
    int tag;
}t[maxn*4];

int n;

void pushup(int p){
    t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

void pushdown(int p){
    if(t[p].tag!=-1){
        int lson=p*2,rson=p*2+1;
        t[lson].tag=t[p].tag;
        t[lson].sum=(t[p].tag?0:(t[lson].r-t[lson].l+1));
        t[rson].tag=t[p].tag;
        t[rson].sum=(t[p].tag?0:(t[rson].r-t[rson].l+1));
        t[p].tag=-1;
    }
}

void build(int p,int l,int r){
    t[p].l=l;
    t[p].r=r;
    t[p].tag=-1;
    if(l==r){
        t[p].sum=1;
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}

void update(int p,int x,int y,int flag){
    if(x<=t[p].l&&t[p].r<=y){
        t[p].sum=(flag?0:(t[p].r-t[p].l+1));
        t[p].tag=flag;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    pushdown(p);
    if(x<=mid)  update(p*2,x,y,flag);
    if(y>mid)  update(p*2+1,x,y,flag);
    pushup(p);
}

int query(int p,int x,int y){
    if(x<=t[p].l&&t[p].r<=y){
        return t[p].sum;
    }
    int mid=(t[p].l+t[p].r)/2;
    pushdown(p);
    int ans=0;
    if(x<=mid)  ans+=query(p*2,x,y);
    if(y>mid)  ans+=query(p*2+1,x,y);
    return ans;
}

int bin_search(int x, int num) {
    int l = x, r = n-1;
    int mid = 0, ans = 0;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(query(1, x, mid) >= num) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

int main() {
    int T,m,k,a,b;
    scanf("%d",&T);
    // printf("[pre]");
    while (T--)
    {
        scanf("%d%d",&n,&m);
        build(1,0,n-1);
        while(m--){
            scanf("%d%d%d",&k,&a,&b);
            if(k==1){
                int emp=query(1,a,n-1),tmp;
                if(emp==0){
                    printf("Can not put any one.\n");
                    continue;
                }
                // else if(emp<=b){
                //     tmp=n-1;
                //     // update(1,a,n,1);
                // }
                // else{
                //     int l=a+b-1,r=n-1;
                //     while(l<=r){
                //         int mid=(l+r)/2;
                //         emp=query(1,a,mid);
                //         if(emp>b){
                //             r=mid-1;
                //         }
                //         else if(emp==b){
                //             tmp=mid;
                //             break;
                //         }
                //         else{
                //             l=mid+1;
                //         }
                //     }
                //     // update(1,a,tmp,1);
                // }
                int first=bin_search(a,1);
                int second=bin_search(a,min(emp,b));
                // int l=a,r=tmp,first=a-1,second=tmp+1;
                // while(l<=r){
                //     int mid=(l+r)/2;
                //     emp=query(1,a,mid);
                //     if(emp>0){
                //         r=mid-1;
                //     }
                //     else{
                //         l=mid+1;
                //         first=mid;
                //     }
                // }
                // l=a,r=tmp;
                // while(l<=r){
                //     int mid=(l+r)/2;
                //     emp=query(1,mid,n-1);
                //     if(emp>0){
                //         l=mid+1;
                //     }
                //     else{
                //         r=mid-1;
                //         second=mid;
                //     }
                // }
                printf("%d %d\n",first,second);
                update(1,first,second,1);
            }
            else{
                int emp=query(1,a,b);
                printf("%d\n",b-a+1-emp);
                update(1,a,b,0);
            }
        }
        printf("\n");
    }
    // printf("[/pre]\n");
    return 0;
}