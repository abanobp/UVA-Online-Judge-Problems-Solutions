#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
#include<stack>
#include<sstream>
#include<queue>
using namespace std;
int N,M;
char grid [30][30] , w ,vis [30][30];
int x [] = {0,0,1,-1};
int y [] = {1,-1,0,0};

int continent (int a,int b)
{
    if (a < 0 || a >= N )
        return 0;
    if (b == M)
        return continent(a , 0);
    if (b < 0)
        return continent(a , M-1);
    //cout<<a<<" "<<b<<"\n";
    if (grid [a][b]!=w || vis [a][b])
        return 0;
    vis [a][b] =1;

    int ans = 1;

    for (int i = 0 ; i < 4 ;i++)
      ans += continent(a + x [i] , y [i] + b);
    return ans;
}

int main()
{
     freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    while (scanf("%d%d",&N,&M)!=EOF)
    {
        memset(vis,0,sizeof vis);
        for (int i = 0 ;i < N ;i++)
            cin>>grid[i];
        int a , b;
        scanf("%d%d",&a,&b);
        w = grid [a][b];
       continent(a,b);
     int MX = 0 ;
     for (int i = 0 ; i < N ;i++)
            for (int j = 0 ;j<M ;j++)
                MX =max(MX,continent(i,j));
     printf("%d\n",MX);
     string s ;
     getline(cin,s);
    }

}
