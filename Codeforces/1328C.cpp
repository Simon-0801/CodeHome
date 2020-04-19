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
const int maxn = 100000 + 5;

char str[maxn];
char a[maxn],b[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        scanf("%s",str+1);
        int flag=0;
        rep(i,1,n){
            if(str[i]=='2'){
                if(flag){
                    a[i]='2';
                    b[i]='0';
                }
                else{
                    a[i]='1';
                    b[i]='1';
                }
            }
            else if(str[i]=='1'){
                if(flag){
                    a[i]='1';
                    b[i]='0';
                }
                else{
                    a[i]='0';
                    b[i]='1';
                    flag=1;
                }
            }
            else{
                a[i]='0';
                b[i]='0';
            }
        }
        rep(i,1,n){
            printf("%c",a[i]);
        }
        printf("\n");
        rep(i,1,n){
            printf("%c",b[i]);
        }
        printf("\n");
    }
    return 0;
}