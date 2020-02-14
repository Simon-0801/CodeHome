#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int num[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    int ans=-1;
    for(int i=31;i>=0;i--){
        int first=-1,cnt=0;
        for(int j=1;j<=n;j++){
            if((1<<i)&num[j]){
                if(first==-1){
                    first=num[j];
                }
                cnt++;
            }
        }
        if(cnt==1){
            ans=first;
            break;
        }
    }
    if(ans==-1){
        for(int i=1;i<=n;i++){
            printf("%d%c",num[i],i==n?'\n':' ');
        }
        return 0;
    }
    printf("%d",ans);
    for(int i=1;i<=n;i++){
        if(num[i]==ans)  continue;
        printf(" %d",num[i]);
    }
    printf("\n");
    return 0;
}