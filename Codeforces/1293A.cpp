#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

map<int,int> mp;

int main() {
    int t,n,s,k,a;
    scanf("%d",&t);
    while(t--){
        mp.clear();
        scanf("%d%d%d",&n,&s,&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&a);
            mp[a]=1;
        }
        int tmp=0,flag=0,ans=0;
        while((s-tmp)>=1&&(s+tmp)<=n){
            if(!mp[s-tmp]){
                flag=1;
                ans=tmp;
                break;
            }
            else if(!mp[s+tmp]){
                flag=1;
                ans=tmp;
                break;
            }
            tmp++;
        }
        if(flag){
            printf("%d\n",ans);
            continue;
        }
        while((s-tmp)>=1){
            if(!mp[s-tmp]){
                flag=1;
                ans=tmp;
                break;
            }
            tmp++;
        }
        if(flag){
            printf("%d\n",ans);
            continue;
        }
        while((s+tmp)<=n){
            if(!mp[s+tmp]){
                flag=1;
                ans=tmp;
                break;
            }
            tmp++;
        }
        if(flag){
            printf("%d\n",ans);
        }
    }
    return 0;
}