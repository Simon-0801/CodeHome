#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const int INF = 0x3f3f3f3f;

struct node//记录课程作业信息
{
    string s;//课程名称
    int ddl;//作业deadline
    int cost;//作业耗时
}w[20];

struct d//用于DP
{
    int time;//该状态下做完指定作业的时间
    int score;//该状态下扣除的分数
    int pre,now;//用于记录做作业的顺序
}dp[1<<15];

void Print(int state){//打印做作业的顺序
    if(!state)  return;
    Print(dp[state].pre);
    cout<<w[dp[state].now].s<<endl;
}

int main() {
    int t,n,d,c;
    char str[105];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s %d %d",str,&d,&c);
            w[i].s=str;
            w[i].ddl=d;
            w[i].cost=c;
        }
        for(int i=1;i<(1<<n);i++){//枚举每个状态
            dp[i].score=INF;//初始化扣除的分数为最大值
            for(int j=n-1;j>=0;j--){//从后往前枚举到达这一状态时所做的课程作业（做了哪一门课的作业到达这一状态的），为了满足最后输出的顺序为字典最小序
                if((i&(1<<j))){//i状态下第j+1门作业已完成
                    int pstate=i-(1<<j);//第j+1门作业未完成的前一状态
                    int tmp=dp[pstate].time+w[j+1].cost-w[j+1].ddl;//扣除的分数
                    if(tmp<0)  tmp=0;//扣除的分数不能为负
                    if(tmp+dp[pstate].score<dp[i].score){//更新i状态下的信息
                        dp[i].time=dp[pstate].time+w[j+1].cost;
                        dp[i].score=tmp+dp[pstate].score;
                        dp[i].now=j+1;//当前刚做完j+1
                        dp[i].pre=pstate;//记录前一状态
                    }
                }
            }

        }
        cout<<dp[(1<<n)-1].score<<endl;
        Print((1<<n)-1);
    }
    return 0;
}