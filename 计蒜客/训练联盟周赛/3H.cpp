#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 10000 + 5;

struct node
{
    int a,b;
    int id;

    bool operator< (const node& x) const{
        if(a==x.a)  return b<x.b;
        return a<x.a;
    }
}nod[maxn];

struct vase
{
    int c;
    int id;

    bool operator< (const vase& x) const{
        return c<x.c;
    }
}vas[maxn];

int ans[maxn];
int vis[maxn];

int main() {
    int p,v,x,y;
    scanf("%d%d",&p,&v);
    rep(i,1,p){
        scanf("%d%d",&x,&y);
        nod[i].a=min(x,y);
        nod[i].b=max(x,y);
        nod[i].id=i;
    }
    sort(nod+1,nod+p+1);
    rep(i,1,v){
        scanf("%d",&vas[i].c);
        vas[i].id=i;
    }
    if(p<v){
        printf("impossible\n");
        return 0;
    }
    sort(vas+1,vas+v+1);
    int j=1,flag=1;
    rep(i,1,v){
        int tmp=vas[i].c;
        while(j<=p&&nod[j].a+1<tmp)   j++;
        if(j>p){
            flag=0;
            break;
        }
        if(nod[j].a+1==tmp){
            int tmpj=j;
            while(tmpj<=p&nod[tmpj].a==tmp-1)  tmpj++;
            tmpj--;
            int ff=0;
            rep(l,j,tmpj){
                if(nod[l].b==tmp&&!vis[l]){
                    ff=1;
                    ans[vas[i].id]=nod[l].id;
                    vis[l]=1;
                    j=l+1;
                    break;
                }
            }
            if(ff){
                continue;
            }
        }
        if(nod[j].a==tmp){
            int tmpj=j;
            while(tmpj<=p&&nod[tmpj].a==tmp)  tmpj++;
            tmpj--;
            int ff=0;
            rep(l,j,tmpj){
                if(nod[l].a==tmp&&!vis[l]){
                    ff=1;
                    ans[vas[i].id]=nod[l].id;
                    vis[l]=1;
                    j=l+1;
                    break;
                }
            }
            if(ff){
                continue;
            }
        }
        flag=0;
        break;
    }
    if(flag){
        rep(i,1,v){
            printf("%d\n",ans[i]);
        }
    }
    else{
        printf("impossible\n");
    }
    return 0;
}