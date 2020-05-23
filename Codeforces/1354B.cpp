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
const int maxn = 200000 + 5;

char str[maxn];

struct node
{
    int num,cnt;
};

vector<node> v;
int f[5];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        f[1]=f[2]=f[3]=0;
        scanf("%s",str+1);
        int len=strlen(str+1);
        rep(i,1,len){
            int j=i;
            while(j<=len&&str[i]==str[j])  j++;
            node tmp;
            tmp.num=str[i]-'0';
            f[tmp.num]=1;
            tmp.cnt=j-i;
            v.push_back(tmp);
            i=j-1;
        }
        if(f[1]&&f[2]&&f[3]){
            int sz=v.size();
            int ans=INF;
            int l,m,r;
            rep(i,1,sz-2){
                l=v[i-1].num;
                m=v[i].num;
                r=v[i+1].num;
                if(l!=r&&l!=m&&m!=r){
                    ans=min(ans,v[i].cnt+2);
                }
            }
            printf("%d\n",ans);
        }
        else{
            printf("0\n");
        }
        
    }
    return 0;
}