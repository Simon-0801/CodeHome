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
const int maxn = 1000 + 5;

char num[maxn];
int a[maxn];

int main() {
    scanf("%s",num);
    int len=strlen(num);
    reverse(num,num+len);
    rep(i,1,len){
        a[i]=num[i-1]-'0';
    }
    int ans=0;
    a[len+1]=0;
    rep(i,1,len){
        if(a[i]>=0&&a[i]<5){
            ans+=a[i];
        }
        else if(a[i]==5){
            if(a[i+1]>=5){
                ans+=a[i];
                a[i+1]++;
            }
            else{
                ans+=a[i];
            }
        }
        else{
            int tmp=a[i];
            ans+=10-tmp;
            a[i+1]++;
        }
    }
    if(a[len+1])  ans+=a[len+1];
    printf("%d\n",ans);
    return 0;
}