#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

ll num[maxn*maxn];
int n,m;

bool checkAC(ll x,ll y){
    if(x>=0&&x<n&&y>=0&&y<m)  return true;
    return false;
}

bool checkUB(ll x,ll y){
    ll tmp=x*m+y;
    if(tmp>=0&&tmp<n*m)  return true;
    return false;
}

int main() {
    int t,p;
    ll x,y,val;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&p);
        memset(num,0,sizeof num);
        int AC=0,UB=0,RE=0;
        if(p==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%lld%c",num[i*m+j],j==m-1?'\n':' ');
                }
            }
            printf("Accepted\n");
            continue;
        }
        while(p--){
            scanf("%lld%lld%lld",&x,&y,&val);
            if(checkAC(x,y)){
                AC=1;
                num[x*m+y]=val;
            }
            else if(checkUB(x,y)){
                UB=1;
                num[x*m+y]=val;
            }
            else{
                RE=1;
            }
        }
        if(RE){
            printf("Runtime error\n");
        }
        else if(UB){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%lld%c",num[i*m+j],j==m-1?'\n':' ');
                }
            }
            printf("Undefined Behaviour\n");
        }
        else if(AC){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%lld%c",num[i*m+j],j==m-1?'\n':' ');
                }
            }
            printf("Accepted\n");
        }
    }
    return 0;
}