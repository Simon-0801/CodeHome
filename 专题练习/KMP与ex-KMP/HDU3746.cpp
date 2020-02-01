#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

char a[maxn];
int nxt[maxn];
int n;

void cal_nxt(){
    nxt[1]=0;
    for(int i=2,j=0;i<=n;i++){
        while(j>0&&a[i]!=a[j+1])  j=nxt[j];
        if(a[i]==a[j+1])  j++;
        nxt[i]=j;
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",a+1);
        n=strlen(a+1);
        cal_nxt();
        if(n%(n-nxt[n])==0&&n/(n-nxt[n])>1){
            printf("0\n");
        }
        else{
            int len=n-nxt[n];
            printf("%d\n",len-n%len);
        }
    }
    return 0;
}