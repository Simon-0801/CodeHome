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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 20000 + 5;

int deg[maxn];
string citys[maxn];
map<string,int> mp;
string s1,s2;
char st[30],en[30];
int tot;
int ans[maxn];
int anstot;

vector<PII> edge[maxn];

struct node
{
    int nxt,id;

    bool operator< (const node &a) const{
        return id>a.id;
    }
};

priority_queue<node> q;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,id;
        scanf("%d",&n);
        mp.clear();
        tot=0;
        mst(deg,0);
        while(!q.empty())  q.pop();
        rep(i,1,n){
            scanf("%s%s%d",st,en,&id);
            s1=st;
            if(!mp.count(s1)){
                mp[s1]=++tot;
                citys[tot]=s1;
                edge[tot].clear();
            }
            s2=en;
            if(!mp.count(s2)){
                mp[s2]=++tot;
                citys[tot]=s2;
                edge[tot].clear();
            }
            edge[mp[s1]].push_back(PII(mp[s2],id));
            deg[mp[s2]]++;
        }
        node tmp;
        rep(i,1,tot){
            if(deg[i]==0){
                for(auto &x:edge[i]){
                    tmp.nxt=x.first;
                    tmp.id=x.second;
                    q.push(tmp);
                }
            }
        }
        anstot=0;
        while(!q.empty()){
            node tp=q.top();
            q.pop();
            deg[tp.nxt]--;
            ans[++anstot]=tp.id;
            if(deg[tp.nxt]==0){
                for(auto &x:edge[tp.nxt]){
                    tmp.nxt=x.first;
                    tmp.id=x.second;
                    q.push(tmp);
                }
            }
        }
        rep(i,1,n){
            printf("%d%c",ans[i],i==n?'\n':' ');
        }
    }
    return 0;
}