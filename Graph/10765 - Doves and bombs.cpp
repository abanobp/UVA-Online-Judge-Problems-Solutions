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
vector<vector<int> > node ;
vector<int>low ,num ,vis;
int  counter = 1 , car [10009];

bool root = 0;

void critical (int N , int P )
{
    low [N] = num [N] = counter++;

    for (int i = 0 ; i < node [N].size() ; i++)
    {
        int ch = node [N][i] ;

        if (vis [ch]== -1 )
        {
            vis [ch] = 1;
            critical(ch , N ) ;
             //cout<<ch <<" "<< N <<"\n";
           // cout<<low [ch] <<" "<< num [N]<<"\n";
            if (low [ch] >= num [N])
            {
               if (P == -1 && !root)
                root = 1;
               else
                car [N]++;
            }

          low [N] = min(low [N] ,low [ch]);
        }
        else if (ch != P)
        {
            low [N] = min(low [N] , num [ch]);
        }
    }


}

int main()
{
   freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);


    int N , M ;

    while (scanf("%d %d",&N,&M) && N )
    {

    memset(car , 0 , sizeof car ) ;
    vis.clear();
    low.clear();
     node.clear();

    vis.assign(N+5 , -1 ) ;
    num.assign(N+5 , 0 ) ;
    low.assign(N+5 , 0 ) ;
     node.resize(N+5);
     counter  = 1 ;
     root = 0;

      int x , y ;

      while (scanf("%d %d",&x,&y) && x!=-1){

        node [x].push_back(y);
        node [y].push_back(x);
      }

          for (int i = 0 ; i < N ; i++)
            {
                if (vis [i] == -1)
                {
                    root = 0 ;
                    vis [ i ] = 1 ;
                    critical(i , -1) ;
                }
            }
            vector<pair<int,int> > par ;
           for (int i = 0 ; i < N ; i++)
           {
               if (car [i] >= 0)
               {
                   par.push_back(make_pair(car[i] + 1,-i));
               }
           }

        sort(par.begin(),par.end());
        reverse(par.begin(),par.end());

        int sz = par.size();
        for (int i = 0 ; i<min(sz,M); i++)
            printf("%d %d\n",-par[i].second , par[i].first);

             printf("\n") ;
    }
}
