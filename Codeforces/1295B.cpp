#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

char str[maxn];
int cnt0[maxn],cnt1[maxn];

int main() {
    int t,n,x;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        // getchar();
        scanf("%s",str+1);
        cnt0[0]=cnt1[0]=0;
        for(int i=1;i<=n;i++){
            if(str[i]=='0'){
                cnt0[i]=cnt0[i-1]+1;
                cnt1[i]=cnt1[i-1];
            }
            else{
                cnt0[i]=cnt0[i-1];
                cnt1[i]=cnt1[i-1]+1;
            }
        }
        int tmp,cnt=0,flag=0;
        tmp=cnt0[n]-cnt1[n];
        if(tmp==0){
            for(int i=1;i<=n;i++){
                int tt=x-(cnt0[i]-cnt1[i]);
                if(tt==0){
                    cnt=-1;
                    break;
                }
            }
            printf("%d\n",cnt);
            continue;
        }
        if(x==0)  cnt++;
        for(int i=1;i<=n;i++){
            int tt=x-(cnt0[i]-cnt1[i]);
            int mm=tt/tmp;
            if(mm<0)  continue;
            if(mm*tmp==tt)  cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}