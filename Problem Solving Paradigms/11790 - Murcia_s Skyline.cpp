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
#define INF  100000007
using namespace std;
vector<int> bil  , wid ;
int  N ;
vector<vector<int> > dp ;

int fun  (int in , int pr)
{
    if (in == N + 1)
        return 0 ;
    int &res = dp [in][pr] ;

    if (res != -1)
        return res ;

    res = fun(in + 1 , pr) ;

    if (!pr || (bil [in] > bil [pr]))
    {
       // cout << in << "\n" ;
        res = max(res ,wid [in] + fun(in + 1 , in)) ;
    }
    // cout <<in << " " <<  res << "\n" ;
    return res ;
}

int main()
{
          //   freopen("in.txt","r",stdin);
             //freopen("out.txt","w",stdout);
    int T , ss = 1;
    scanf("%d" , &T) ;

    while (T--)
    {
            scanf("%d" , &N) ;

            bil.resize(N + 1) , wid.resize(N + 1) ;
            if (N)
                bil[0] = wid[0] = INT_MIN ;

            dp.clear();
            dp.resize(N + 3, vector<int> (N + 3, -1)) ;
            for (int i = 1 ; i <= N ; i++)
                scanf("%d" , &bil [i]) ;
            for (int i = 1 ; i <= N ;i++)
                scanf("%d" , &wid[i]) ;

            int in = fun(1,0) ;

            reverse(wid.begin() + 1,wid.end()) ;
            reverse(bil.begin() + 1,bil.end()) ;
            dp.clear();
            dp.resize(N + 3 , vector<int> (N + 3, -1)) ;
           // cout << "\n" ;

            int dc = fun(1,0) ;

            if (dc > in)
                printf("Case %d. Decreasing (%d). Increasing (%d).\n" ,ss++ ,dc,in) ;
            else
                printf("Case %d. Increasing (%d). Decreasing (%d).\n" ,ss++ ,in,dc) ;
    }
}
