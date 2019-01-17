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
#include<list>
#define INF 1000000000
using namespace std;
int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int maze [1005][1005] ;

int shortest (int n, int m ,int X,int Y )
{
    priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> > > , greater<pair<int,pair<int,int> > > > pq;

    vector<vector<int> > dis (n+5,vector<int> (m+5));
     for (int i = 0 ; i < n ; i++ )
            for (int j = 0 ; j < m ; j++)
               dis [i][j] = INF;

    pq.push(make_pair(maze [0][0],make_pair(0,0)));
    dis [0] [0] = maze [0][0];

    while(!pq.empty())
    {
       // cout <<"a";
         int d = pq.top().first  , x = pq.top().second.first , y = pq.top().second.second ;
            pq.pop();
        if (d > dis [x][y]) continue ;
       // cout << v <<"\n" ;
        if (x == X  && Y == y )
            return dis [x][y];

        for (int i = 0 ; i < 4 ; i++)
        {
            int in1 = x + moves [i][0] , in2 = y + moves [i][1] ;
            if (in1 >=0 && in1 <n && in2 >= 0 && in2 < m){
            if (dis [x][y] + maze [in1][in2] < dis [in1][in2])
            {
                dis [in1][in2] = dis [x][y] + maze [in1][in2] ;
                pq.push(make_pair(dis[in1][in2],make_pair(in1,in2))) ;
            }
        }
        }
    }
    return -1;
}

int main()
{
       // freopen("in.txt","r",stdin);
      // freopen("out.txt","w",stdout);

   int N  ;
    cin >> N;
    while (N--)
    {
            int n , m ;
        scanf("%d%d",&n,&m);

        for (int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j < m ; j++)
                cin >> maze [i][j];
        }

       cout <<   shortest(n,m,n-1,m-1) << "\n";

    }
}
