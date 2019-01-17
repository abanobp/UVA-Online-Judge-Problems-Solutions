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
using namespace std;
int unlock ;
vector<int>but;
bool vis [10005] ;
int least (int x)
{
  return x % 10000;
}

int BFS (int v)
{
    queue<int>q;
    q.push(v) ;
    vis [v] = 1;
    int level = 0 , sz = 1 ;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        sz--;
        for (int i = 0 ; i < but.size() ; i++)
        {
            int res = least ( top + but [i] ) ;
             //cout <<top <<"\n";
            if (!vis[res])
            {
                q.push(res);
                vis [res] = 1 ;
                if (res == unlock)
                    return level + 1;
            }
        }

        if (!sz)
        {
            sz = q.size();
            level++;
        }
    }
    return -1;
}
int main()
{
       //  freopen("in.txt","r",stdin);
      //  freopen("out.txt","w",stdout);

     int lock , R , T = 1 ;

     while (scanf("%d%d%d",&lock,&unlock,&R) )
     {
         if (!lock && !unlock && !R)
            break;
         but.clear();
         but.resize(R);
         memset(vis , 0 , sizeof vis);

         for (int i = 0 ; i < R ;i++)
            cin >> but[i];

         int res = BFS(lock);
         if (res == -1)
            printf("Case %d: Permanently Locked\n",T++) ;
         else
            printf("Case %d: %d\n",T++,res) ;
     }
}
