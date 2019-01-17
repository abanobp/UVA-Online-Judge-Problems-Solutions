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

//--------------------- This code is Written by " Abanob Ashraf " --------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it -----------------------------
//----------------------------------- START ------------------------------------------------------

vector<int> low , num , st;
vector<bool> vis ;
vector<vector<int> > adj , res ;
int coun ;

void ans (int ix)
{
    num [ix] = low [ix] = coun++ ;
    vis [ix] = 1 ;
    st.push_back(ix) ;

    for (int i = 0 ; i < adj[ix].size() ; i++)
    {
        if (num [adj[ix][i]] == INF)
            ans(adj[ix][i]) ;

        if (vis [adj[ix][i]])
            low [ix] = min(low [adj[ix][i]],low [ix]) ;
    }

    if (low [ix] == num [ix])
    {
        vector<int> v ;
        while(1)
        {
            int b = st.back() ;
            st.pop_back() ;
            vis [b] = 0 ;

            v.push_back(b) ;
            if (b == ix)
                break ;
        }

        sort(v.begin(), v.end()) ;
        res.push_back(v) ;
    }
}

int main()
{
        // freopen("in.txt","r",stdin);/
       // freopen("out.txt","w",stdout);

       int N , f = 0 ;

      while (scanf("%d" , &N) && N )
      {
          if (f)
          cout << "\n" ;
          f = 1 ;
          low.assign(105 , INF) ;
          num.assign(105 , INF) ;
          vis.assign(105 , 0 ) ;
          adj.clear() ;
          adj.resize(105) ;
          res.clear() ;
          coun = 1 ;
          vector<bool> yes (105 , 0) ;
          while (N--){
              char arr [8] ;
              for (int i = 0 ; i < 6 ; i++)
                  cin >> arr[i] , vis [arr[i]] = 1 ;
              for (int i = 0 ; i < 5 ; i++)
              {
                  if (arr [i] != arr [5])
                    adj [arr[5]].push_back(arr[i]) ;
              }
          }

          for (int i = 'A' ; i <= 'Z'; i++)
              if (vis [i])
                ans(i) ;

          sort(res.begin() , res.end()) ;

          for (int i = 0 ; i < res.size() ; i++)
          {
              for (int j = 0 ; j < res [i].size() ; j++)
                if (j)
                    cout << " " <<  char (res [i][j]) ;
                else
                    cout << char (res [i][j]) ;
                cout << "\n" ;
          }
      }
}

//------------------------------------- DONE --------------------------------------------------------
