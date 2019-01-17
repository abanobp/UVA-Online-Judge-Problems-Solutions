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
int N , arr [105][105] , com [105];

int one_d ( )
{
    int sum = 0 , mx = INT_MIN , neg = INT_MIN  ;
    for (int i = 0 ; i < N ; i++)
    {
        sum += com [i] ;
        if (sum < 0)
            sum = 0 ;
        else
            mx = max(mx , sum) ;
        neg = max(neg , com[i]) ;
    }

    if (mx >= 0)
    return mx ;

    return neg ;
}

int two_d ()
{
    int sub = INT_MIN ;
    for (int i = 0 ; i < N ;i++)
    {
        for (int j = i ; j < N ;j++)
        {
             for (int k = 0 ; k < N ; k++)
                if (i == j)
                    com [k] = arr [k][j] ;
                else
                    com [k] += arr [k][j] ;

            sub = max(sub ,one_d()) ;
        }
    }
    return sub ;
}

int main()
{
           freopen("in.txt","r",stdin);
           freopen("out.txt","w",stdout);

   while (cin >> N )
    {
       for (int i = 0 ; i < N ; i++)
            for (int j = 0 ; j < N ; j++)
                cin >> arr [i][j] ;

        cout << two_d()  << "\n" ;
    }
}
