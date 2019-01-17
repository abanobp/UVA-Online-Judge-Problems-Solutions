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
int val [105][105] , K , N , M;

int one (long long com [] ,long long &tot)
{
    long long sum = 0 ;
    int s = 0 , e = 0 , mx = 0 ;

    while(e < N)
    {
        sum += com [e] ;
       // cout << s << " " << e << " " << sum << "\n" ;
        if (sum > K)
        {
          sum -= com [s] ;
          if (s == e)
            s++,e++ ;
          else
            s++ , sum -= com [e];
        }
        else
        {
            //cout << sum << " a\n" ;
            if (mx < e - s + 1)
                mx = e - s + 1 , tot = sum ;
            else if (mx == e - s + 1 && tot > sum)
                tot = sum ;
            e++;
        }

    }

/*
    for ( s = 0 ; s < N ; s++){
        long long sum = 0 ;
        for (e = s ; e < N ;e++)
        {
            sum += com [e] ;
            if (sum <= K)
            {
                if (mx < e - s + 1)
                    mx = e - s + 1 , tot = sum;
                else if (mx == e - s + 1 && tot > sum)
                    tot = sum ;
            }
            else
                break ;
        }
    }
*/
    return mx ;
}

void two (long long &toto , int &dis)
{
    for (int i = 0 ; i < M ;i++)
    {
        long long com [105] ;
        for (int j = i ; j < M ;j++)
        {
            for (int k = 0 ; k < N ;k++)
                if (i == j)
                    com [k] = val[k][j] ;
                else
                    com [k] += val [k][j] ;
            long long tot ;
            int res = one(com,tot) ;
            if (dis < (res * (j - i + 1)))
                dis = res * (j - i + 1) , toto = tot ;
            else if (dis && dis == (res * (j - i + 1)) && toto > tot)
                toto = tot ;
           // cout << i << " " << j << " " << dis << " " << tot << " --\n" ;
        }
    }
}

int main()
{
            freopen("in.txt","r",stdin);
           freopen("out.txt","w",stdout);

    int T ;
    cin >> T ;

    for (int i = 1 ; i <= T ;i++)
    {
        cin >> N >> M >> K ;
        for (int j = 0 ; j < N ;j++)
            for (int k = 0 ; k < M ;k++)
                cin >> val [j][k] ;

        int dis  = 0 ;
        long long toto ;

        two(toto,dis) ;

        if (dis)
            printf("Case #%d: %d %lld\n",i,dis,toto) ;
        else
            printf("Case #%d: 0 0\n",i) ;
    }
}
