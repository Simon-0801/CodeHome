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
const int maxn = 1000000 + 5;

char str[maxn];
int num[30];

int main() {
    scanf("%s",str);
    int len=strlen(str);
    int n=len/2;
    rep(i,0,len-1){
        num[str[i]-'a'+1]++;
    }
    int te=-1,tot=0;
    rep(i,1,26){
        if(num[i]>n){
            te=i;
        }  
        if(num[i])  tot++;
    }
    if(te==-1){
        printf("YES\n");
        rep(i,1,26){
            rep(j,1,num[i]){
                printf("%c",(char)(i+'a'-1));
            }
        }
        printf("\n");
        return 0;
    }
    if(tot==1){
        printf("NO\n");
        return 0;
    }
    if(tot==2){
        if(num[te]>=2*n-2){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    rep(j,1,n){
        printf("%c",(char)(te+'a'-1));
    }
    rep(i,1,26){
        if(i==te)  continue;
        if(num[i]){
            printf("%c",(char)(i+'a'-1));
            num[i]--;
            break;
        }
    }
    rep(j,1,num[te]-n){
        printf("%c",(char)(te+'a'-1));
    }
    num[te]=0;
    rep(i,1,26){
        rep(j,1,num[i]){
            printf("%c",(char)(i+'a'-1));
        }
    }
    printf("\n");
    return 0;
}