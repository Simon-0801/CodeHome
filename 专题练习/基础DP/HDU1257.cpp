#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int dp[maxn],num[maxn];
multiset<int> st;

int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        st.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        st.insert(num[1]);
        for(int i=2;i<=n;i++){
            int flag=0,tmp;
            for(multiset<int>::iterator it=st.begin();it!=st.end();it++){
                if(*it>=num[i]){
                    flag=1;
                    tmp=*it;
                    break;
                }
            }
            if(flag){
                st.erase(tmp);
                st.insert(num[i]);
            }
            else{
                st.insert(num[i]);
            }
        }
        printf("%d\n",st.size());
    }
    return 0;
}