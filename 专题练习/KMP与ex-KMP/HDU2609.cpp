#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;

char str[maxn];
map<string,int> mp;
string s;
int n;

int minString(){
    int i=0,j=1,k;
    while(i<n&&j<n){
        for(k=0;k<n&&s[i+k]==s[j+k];k++);
        if(k==n) break;
        if(s[i+k]>s[j+k]){
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

int main() {
    int t;
    while(scanf("%d",&t)!=EOF){
        mp.clear();
        while(t--){
            scanf("%s",str);
            s=str;
            n=s.length();
            s+=s;
            int index=minString();
            string tmp=s.substr(index,n);
            if(!mp[tmp])  mp[tmp]=1;
        }
        printf("%d\n",mp.size());
    }
    return 0;
}