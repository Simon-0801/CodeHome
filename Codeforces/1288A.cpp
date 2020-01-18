#include <iostream>
#include <cmath>
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    int t,n,d,mmin;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);
        mmin=INF;
        int tmp=sqrt(d);
        for(int i=-3;i<=3;i++){
            int tt;
            if(tmp+i<=0)  continue;
            if(d%(tmp+i)==0){
                tt=d/(tmp+i)+tmp+i-1;
            }
            else{
                tt=d/(tmp+i)+1+tmp+i-1;
            }
            mmin=min(mmin,tt);
        }
        if(mmin<=n){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}