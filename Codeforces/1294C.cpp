#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

ll num[maxn],p[maxn];
int m;

void divide(ll n){
    m=0;
    for(ll i=2;i<=(ll)sqrt(n);i++){
        if(n%i==0){
            p[++m]=i;
            num[m]=0;
            while(n%i==0){
                n/=i;
                num[m]++;
            }
        }
    }
    if(n>1){
        p[++m]=n;
        num[m]=1;
    }
    return;
}

int main() {
    int t;
    ll n;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&n);
        divide(n);
        if(m==1){
            if(num[1]<6)  printf("NO\n");
            else{
                printf("YES\n");
                // printf("%d %d %d\n",pow(p[1],1),pow(p[1],2),pow(p[1],num[1]-3));
                cout<<(ll)pow(p[1],1)<<" "<<(ll)pow(p[1],2)<<" "<<(ll)pow(p[1],num[1]-3)<<endl;
            }
        }
        else if(m==2){
            if(num[1]==1){
                if(num[2]<=2)  printf("NO\n");
                else{
                    printf("YES\n");
                    // printf("%d %d %d\n",pow(p[1],1),pow(p[1],1),pow(p[2],num[2]-1));
                    cout<<(ll)pow(p[1],1)<<" "<<(ll)pow(p[2],1)<<" "<<(ll)pow(p[2],num[2]-1)<<endl;
                }
            }
            else if(num[1]==2){
                if(num[2]<=1)  printf("NO\n");
                else{
                    printf("YES\n");
                    // printf("%d %d %d\n",pow(p[1],1),p[1]*p[2],pow(p[2],num[2]-1));
                    cout<<(ll)pow(p[1],1)<<" "<<(ll)p[1]*p[2]<<" "<<(ll)pow(p[2],num[2]-1)<<endl;
                }
            }
            else{
                printf("YES\n");
                // printf("%d %d %d\n",pow(p[1],1),pow(p[2],num[2]),pow(p[1],num[1]-1));
                cout<<(ll)pow(p[1],1)<<" "<<(ll)pow(p[2],num[2])<<" "<<(ll)pow(p[1],num[1]-1)<<endl;
            }
        }
        else{
            printf("YES\n");
            ll san=1;
            for(int i=3;i<=m;i++){
                san*=(ll)pow(p[i],num[i]);
            }
            // printf("%d %d %d\n",pow(p[1],num[1]),pow(p[2],num[2]),san);
            cout<<(ll)pow(p[1],num[1])<<" "<<(ll)pow(p[2],num[2])<<" "<<(ll)san<<endl;
        }
    }
    return 0;
}