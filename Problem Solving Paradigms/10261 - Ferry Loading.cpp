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
int dp [305][10005], len ;
vector<int> car ;

int cul (int ix , int rem , int tot)
{
    if (ix == car.size())
        return 0 ;

    int &res = dp [ix][rem] ;

    if (res != -1)
        return res ;
    res = 0 ;

    if (car [ix] <= tot)
        res = 1 + cul(ix + 1 , rem , tot - car [ix]) ;

    if (car [ix] <= rem)
       res = max(res ,1 + cul(ix + 1 , rem - car [ix] , tot)) ;

    return res ;
}

void print (int ix ,int rem ,int tot,int sz)
{
    if (!sz)
        return ;

    if (car [ix] <= tot && cul (ix + 1 , rem ,tot - car [ix]) == sz - 1 )
    {
       printf("port\n") ;
       print(ix + 1 ,rem ,tot - car [ix] , sz - 1) ;
    }
    else
    {
        printf("starboard\n") ;
        print(ix + 1, rem - car [ix] ,tot , sz - 1) ;
    }
}

int main()
{
         freopen("in.txt","r",stdin);
         freopen("out.txt","w",stdout);

    int T ;

    scanf("%d" , &T) ;

    while (T--)
    {
        int  a ;
        cin >> len ;
        len *= 100 ;
        car.clear() ;

        while (scanf("%d" , &a) && a)
            car.push_back(a) ;

        memset(dp , -1 , sizeof dp ) ;

        int res = cul(0,len,len) ;

        cout << res << "\n" ;
        print(0 , len ,len ,res) ;

        if (T)
            cout << "\n" ;
    }
}


