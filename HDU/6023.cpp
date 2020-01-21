
//传送门：http://acm.hdu.edu.cn/viewcode.php?rid=101&cid=772

#include <iostream>

#include <string.h>

#include <stdio.h>

#include <algorithm>

#include <math.h>

#include <vector>

using namespace std;

#define LL long long

#define N 100005

#define M 2005

#define INF 0x3f3f3f3f

const double eps = 1e-10;

/*

注意：没AC的题不算罚时

*/

bool has[25];

int cot[25];

int main()

{

    int t;

    scanf("%d",&t);

    while(t--){

        memset(has,0,sizeof(has));

        memset(cot,0,sizeof(cot));

        int tol = 0;

        int n,m;

        scanf("%d%d",&n,&m);

        int ans = 0;

        while(m--){

            int a,b,c;

            string s;

            scanf("%d %02d:%02d",&a,&b,&c);

            cin>>s;

            a-=1000;

            if(has[a]) continue;

            if(s=="AC"){

                tol++;

                has[a] = 1;

                ans += cot[a]*20 + b*60 + c;

            }else{

               cot[a]++;

            }

        }

        cout<<tol<<" "<<ans<<endl;

    }

}

