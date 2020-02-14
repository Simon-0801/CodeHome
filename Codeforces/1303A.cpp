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

char str[maxn];

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str+1);
        int len=strlen(str+1);
        int st=-1,en=-1;
        for(int i=1;i<=len;i++){
            if(str[i]=='1'){
                st=i;
                break;
            }
        }
        if(st==-1){
            printf("0\n");
            continue;
        }
        for(int i=len;i>=1;i--){
            if(str[i]=='1'){
                en=i;
                break;
            }
        }
        int ans=0;
        for(int i=st;i<=en;i++){
            if(str[i]=='0')  ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}