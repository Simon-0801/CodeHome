#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;

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
    while(scanf("%s",a+1)){
        if(a[1]=='.')  break;
        n=strlen(a+1);
        cal_nxt();
        if(n%(n-nxt[n])){
            printf("1\n");
            continue;
        }
        printf("%d\n",n/(n-nxt[n]));
    }
    return 0;
}