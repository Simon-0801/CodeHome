#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

char str[maxn];
vector<int> st[30];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++){
        st[str[i]-'a'+1].push_back(i);
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=26;i++){
        if(st[i].size()>=k){
            int len=st[i].size();
            for(int j=0;j<len+1-k;j++){
                ans=min(ans,st[i][j+k-1]-st[i][j]+1);
            }
            // ans=min(ans,end-start+1);
            // printf("%d  %d\n",start,end);
        }
    }
    if(ans==0x3f3f3f3f){
        printf("-1\n");
    }
    else{
        printf("%d\n",ans);
    }
    return 0;
}