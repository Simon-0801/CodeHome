#include <iostream>
#include <sstream>
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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

map<string,int> mp;
map<PII,int> inedge;
char str[55];
string nam[55];
VI edge[55];
int vis[55];
VI route,ans;
int stid,enid;

void dfs(int x){
    if(x==enid){
        for(auto &nod:route){
           ans.push_back(nod); 
        }
        ans.push_back(enid);
        return;
    }
    vis[x]=1;
    route.push_back(x);
    for(auto &nod:edge[x]){
        if(vis[nod])  continue;
        dfs(nod);
    }
    vis[x]=0;
    route.pop_back();
}

int main() {
    int n,tot=0;
    string s,tmp,st,en;
    scanf("%d",&n);
    getchar();
    rep(i,1,n){
        getline(cin,s);
        istringstream ss(s);
        ss>>tmp;
        if(!mp[tmp]){
            mp[tmp]=++tot;
            nam[tot]=tmp;
        }
        int id=mp[tmp],to;
        while(ss>>tmp){
            if(!mp[tmp]){
                mp[tmp]=++tot;
                nam[tot]=tmp;
            }
            to=mp[tmp];
            if(!inedge[PII(id,to)]){
                edge[id].push_back(to);
                inedge[PII(id,to)]=1;
            }
            if(!inedge[PII(to,id)]){
                edge[to].push_back(id);
                inedge[PII(to,id)]=1;
            }  
        }
    }
    cin>>st>>en;
    if(!mp[st]){
        mp[st]=++tot;
        nam[tot]=st;
    }
    if(!mp[en]){
        mp[en]=++tot;
        nam[tot]=en;
    }
    stid=mp[st],enid=mp[en];
    dfs(stid);
    if(ans.size()==0){
        printf("no route found\n");
        return 0;
    }
    for(auto &nod:ans){
        cout<<nam[nod]<<" ";
    }
    return 0;
}