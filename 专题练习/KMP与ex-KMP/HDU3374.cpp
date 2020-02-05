#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;

char str[maxn*2];
int nxt[maxn],match[maxn*2];
int n;

int minString(){
    int i=1,j=2,k;
    while(i<=n&&j<=n){
        for(k=0;k<n&&str[i+k]==str[j+k];k++);
        if(k==n) break;
        if(str[i+k]>str[j+k]){
            i=i+k+1;
            if(i==j)  i++;
        }
        else{
            j=j+k+1;
            if(i==j)  j++;
        }
    }
    return min(i,j);
}

int maxString(){
    int i=1,j=2,k;
    while(i<=n&&j<=n){
        for(k=0;k<n&&str[i+k]==str[j+k];k++);
        if(k==n) break;
        if(str[i+k]<str[j+k]){
            i=i+k+1;
            if(i==j)  i++;
        }
        else{
            j=j+k+1;
            if(i==j)  j++;
        }
    }
    return min(i,j);
}

void cal_nxt(int l,int r){
    nxt[1]=0;
    for(int i=2,j=0;i<=r-l+1;i++){
        while(j>0&&str[i+l-1]!=str[l-1+j+1])  j=nxt[j];
        if(str[i+l-1]==str[l-1+j+1])  j++;
        nxt[i]=j;
    }
}

int cal_match(int l,int r){
    int ans=0;
    for(int i=1,j=0;i<=n*2-1;i++){
        while(j>0&&(j==n||str[i]!=str[l-1+j+1]))  j=nxt[j];
        if(str[i]==str[l-1+j+1])  j++;
        match[i]=j;
        if(match[i]==r-l+1){
            ans++;
        }
    }
    return ans;
}

int main() {
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        for(int i=1;i<=n;i++)  str[i+n]=str[i];
        int index=minString();
        cal_nxt(index,index+n-1);
        printf("%d %d ",index,cal_match(index,index+n-1));
        index=maxString();
        cal_nxt(index,index+n-1);
        printf("%d %d\n",index,cal_match(index,index+n-1));
    }
    return 0;
}