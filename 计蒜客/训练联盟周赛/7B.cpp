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
const int maxn = 100000 + 5;

struct node
{
    int id,pos;
};


vector<node> v[maxn];
int cnt[maxn];
map<string,int> mp;
char str[25];
vector<node> ans;

int main() {
    int m;
    scanf("%d",&m);
    int tot=0,tmp;
    string s;
    rep(i,1,m){
        scanf("%d",&tmp);
        rep(j,1,tmp){
            scanf("%s",str);
            s=str;
            node nod;
            nod.id=i;
            nod.pos=j;
            if(!mp[s]){
                mp[s]=++tot;
                v[tot].push_back(nod);
            }
            else{
                v[mp[s]].push_back(nod);
            }
        }
    }
    scanf("%d",&tmp);
    int f=1;
    rep(i,1,tmp){
        scanf("%s",str);
        s=str;
        if(!mp[s])  f=0;
        else{
            int index=mp[s],sz=v[index].size();
            int times=cnt[index]%sz;
            node res=v[index][times];
            ans.push_back(res);
            cnt[index]++;
        }
    }
    if(!f){
        printf("NOT POSSIBLE\n");
    }
    else{
        for(auto &x:ans){
            printf("%d %d\n",x.id,x.pos);
        }
    }
    return 0;
}