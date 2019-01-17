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
#include<iomanip>
#include<bitset>
#include<limits.h>
#define INF  1000000007
#define MOD  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define fr first
#define sc second
using namespace std;
vector<vector<int> > adj;
bool yes [105] ;

void fine (int ix)
{
    if (yes [ix])
        return ;

    yes [ix] = 1 ;

    for (int i = 0 ; i < adj [ix].size() ; i++)
        fine(adj[ix][i]) ;
}

int main()
{
       //freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);

       int N , T = 1;

       while (scanf("%d" , &N) && N)
       {
           if (T != 1)
                printf("\n") ;

           map <string , int> mp;
           adj.clear() ;
           adj.resize(N + 5) ;
           vector<string> s (N + 5);
           s [0] = "" ;
           for (int i = 1 ; i <= N ; i++)
           {
               cin >> s [i] ;
               mp [s[i]] = i ;
           }

           int R ;
           scanf("%d" , &R) ;

           while (R--)
           {
               string a , b ;
               cin >> a >> b ;

               adj[mp[a]].push_back(mp[b]) ;
               adj[mp[b]].push_back(mp[a]) ;
           }


           vector<string> v ;
           for (int i = 1 ; i <= N ; i++)
           {
               memset(yes , 0 , sizeof yes) ;
               bool f = 0 ;
               yes [i] = 1 ;
                //cout << s [i]  << "   ***\n";
               for (int j = 0 ; j < adj[i].size() ; j++)
               {
                    //cout << s [adj[i][j]] << "\n" ;
                   if (!j)
                   {
                       fine(adj[i][j]) ;
                   }
                   else
                   {
                       if (!yes [adj[i][j]])
                       {
                           f = 1 ;
                           break ;
                       }
                   }
               }

               if (f)
                    v.push_back(s [i]) ;
           }

            printf("City map #%d: %d camera(s) found\n" ,T++ , v.size()) ;

            sort(v.begin(),v.end()) ;

            for (int i = 0 ; i < v.size() ; i++)
                cout << v [i] << "\n" ;

    }
}
