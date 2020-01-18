#include <iostream>
#include <cstring>

using namespace std;

char str[105];

int main(){
    int t,k,mmax=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        scanf("%s",str);
        mmax=0;
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='A'){
                int j=i+1;
                for(;j<strlen(str);j++){
                    if(str[j]=='A'){
                        break;
                    }
                }
                mmax=max(mmax,j-i-1);
                i=j;
                i--;
            }
        }
        printf("%d\n",mmax);
    }
    return 0;
}
