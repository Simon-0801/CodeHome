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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

char s1[10],s2[10];
pair<string,char> p[50];
int n,q;
ll ans=0;

void dfs(int len,string s){
    if(len>=n){
        ans++;
        return;
    }
    char tmp=s[0];
    for(int i=1;i<=q;i++){
        if(p[i].second==tmp){
            // string tt=p[i].first;
            string tt=s.substr(1,s.length()-1);
            dfs(len+1,p[i].first+tt);
        }
    }
}

int main() {
    ans=0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
        scanf("%s %s",s1,s2);
        p[i]=make_pair(s1,s2[0]);
    }
    dfs(1,"a");
    printf("%I64d\n",ans);
    return 0;
}