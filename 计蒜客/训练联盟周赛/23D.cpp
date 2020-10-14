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
const int maxn = 100000 + 5;

char a[20];

int getnum(int l,int r){
    int res=0;
    rep(i,l,r){
        res*=10;
        res+=a[i]-'0';
    }
    return res;
}

int main() {
    int n;
    scanf("%d",&n);
    rep(cas,1,n){
        scanf("%s",a+1);
        int len=strlen(a+1);
        printf("Ticket #%d:\n",cas);
        int f=0;
        rep(i,1,len-1){
            int num1=getnum(1,i);
            int num2=getnum(i+1,len);
            if(__gcd(num1,num2)==1){
                printf("%d %d\n\n",num1,num2);
                f=1;
                break;
            }
        }
        if(!f){
            printf("Not relative\n\n");
        }
    }
    return 0;
}