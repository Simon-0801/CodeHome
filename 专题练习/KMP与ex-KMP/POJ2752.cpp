#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 400000 + 5;

vector<int> v;

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
    while(~scanf("%s",a+1)){
        n=strlen(a+1);
        cal_nxt();
        int tmp=nxt[n];
        v.clear();
        v.push_back(n);
        // printf("%d",n);
        while(tmp>0){
            // printf(" %d",tmp);
            v.push_back(tmp);
            tmp=nxt[tmp];
        }
        while(!v.empty()){
            printf("%d%c",v.back(),v.size()==1?'\n':' ');
            v.pop_back();
        }
        // printf("\n");
    }
    return 0;
}