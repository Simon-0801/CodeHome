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

char str[100];
string s[105];
int vis[105];
map<string,int> mp;
vector<string> v;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        s[i]=str;
    }
    mst(vis,0);
    string ans="";
    for(int i=1;i<=n;i++){
        if(vis[i])  continue;
        vis[i]=1;
        string tmp=s[i];
        reverse(tmp.begin(),tmp.end());
        int flag=0;
        for(int j=i+1;j<=n;j++){
            if(vis[j])  continue;
            if(tmp==s[j]){
                flag=1;
                vis[j]=1;
                break;
            }
        }
        if(flag){
            ans=ans+s[i];
            // vis[i]=1;
            continue;
        }
        if(tmp==s[i]){
            v.push_back(s[i]);
        }
    }
    string tans=ans;
    reverse(tans.begin(),tans.end());
    if(v.size()){
        ans=ans+v[0];
    }
    ans=ans+tans;
    printf("%d\n",ans.length());
    cout<<ans<<endl;
    return 0;
}