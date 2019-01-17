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
#define INF  -1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define fr first
#define sc second
using namespace std;
long long  dp [12][30005] ;
int con [] = {10000,5000,2000,1000,500,200,100,50,20,10,5} ;

long long sol (int ix ,int tot)
{

    if (ix == 11)
        return (tot)?0:1 ;
//    cout << ix << " " <<  tot << "\n" ;
    long long  &res = dp [ix][tot];
    if (res != -1)
        return res ;

    res  = sol(ix + 1 , tot) ;

    if (con [ix] <= tot)
        res += sol(ix , tot - con [ix]) ;
   // cout << res << " @\n" ;

    return res ;
}

int main()
{
       freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);

    string cur ;

    while (cin >> cur )
    {
        memset(dp , -1 ,sizeof dp) ;

        double crr ;

        stringstream ss (cur) ;
        ss >> crr ;

        for (int i = 0 ; i < cur.size() ; i++)
        {
            if (cur [i] == '.')
            {
                cur.erase(i,1) ;
                break ;
            }
        }

        stringstream sss  (cur);
        int num ;
        sss >> num ;

        if (!num)
            break ;

        for (int i = 0 ; i < 6 - cur.size() - 1 ; i++)
            printf (" ") ;

        cout << fixed << setprecision(2) <<  crr ;

        long long  res = sol(0,num) , c = 0;

        while(res)
            res/=10 , c++ ;

        for (int i = 0 ; i < 17 - c ; i++)
            printf(" ") ;

        cout << sol(0,num) << "\n";
    }
}
