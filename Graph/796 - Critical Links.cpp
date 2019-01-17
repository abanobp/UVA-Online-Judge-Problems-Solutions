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
int  counter = 1 ;
vector<pair<int,int> > link ;

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
            if (low [ch] > num [N])
            {
             link.push_back(make_pair(min(ch,N),max(ch,N)));
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


    int N ;

    while (scanf("%d",&N)!=EOF )
    {

    link.clear();
    vis.clear();
    low.clear();
     node.clear();

    vis.assign(N+5 , -1 ) ;
    num.assign(N+5 , 0 ) ;
    low.assign(N+5 , 0 ) ;
     node.resize(N+5);
     counter  = 1 ;

        string net ;
        getline(cin, net);

        for (int i = 0 ; i < N ; i++){

            getline(cin, net);
         //   cout<<net<<"\n";
            stringstream ss (net);

            int big1 , big2 ;
            string par;
            ss >> big1 ;
            ss >> par ;
            while (ss >> big2){
                node [ big1 ].push_back(big2) ;
            }
        }

          for (int i = 0 ; i < N ; i++)
            {
                if (vis [i] == -1)
                {
                 //   cout<<i<<"\n";
                    vis [ i ] = 1 ;
                    critical(i , -1) ;
                }
            }

            printf("%d critical links\n",link.size());

            sort(link.begin(),link.end());
            for (int i =  0 ; i < link.size() ; i++ )
                printf("%d - %d\n",link[i].first,link[i].second);

             printf("\n") ;
    }
}
