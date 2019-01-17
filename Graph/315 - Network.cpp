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
int low [150]  , num [150] , counter = 1 ,vis [150];
set<int>sz ;
bool root = 0 ;

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

            if (low [ch] >= num [N])
            {
                if (P == -1 &&!root)
                    root = 1;
                else
                    sz.insert(N);
            }
          low [N] = min(low [N] ,low [ch]);
        }
        else if (N != P)
        {
            low [N] = min(low [N] , num [ch]);
        }
    }


}

int main()
{
    freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);


    int N ;

    while (scanf("%d",&N) && N )
    {

     memset(vis , -1 ,sizeof vis);
     memset(low , 0 , sizeof low );
     memset(num , 0, sizeof num ) ;
     counter  = 1 ;
     sz.clear() ;
     node.clear();
     node.resize(N+5);

     string net ;
     getline(cin, net);

        while (getline(cin, net))
        {
                 //  cout<<net<<"  nn\n";
            if (net == "0")
                break ;

            stringstream ss (net);

            int big1 , big2 ;
            ss >> big1 ;

            while (ss >> big2){
                node [ big1 ].push_back(big2) ;
                node [ big2 ].push_back(big1) ;
            }


        }
          for (int i = 1 ; i <= N ; i++)
            {
                if (vis [i] == -1)
                {
                    vis [ i ] = 1 ;
                    root = 0 ;
                    critical(i , -1) ;
                }
            }
            printf("%d\n",sz.size());
    }
}
