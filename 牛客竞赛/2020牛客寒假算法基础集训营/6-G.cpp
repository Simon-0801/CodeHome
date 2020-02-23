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
const int maxn = 1000000 + 5;

char str[maxn];
vector<int> v;

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        int ans=0;
        scanf("%d",&n);
        scanf("%s",str+1);
        v.clear();
        int len=strlen(str+1);
        for(int i=1;i<=len;i++){
            if(str[i]=='('){
                v.push_back(str[i]);
            }
            else{
                if(v.size()==0){
                    ans++;
                }
                else{
                    char tmp=v.back();
                    v.pop_back();
                }
            }
        }
        if(v.size()>0)  ans+=v.size();
        printf("%d\n",ans);
    }
    return 0;
}