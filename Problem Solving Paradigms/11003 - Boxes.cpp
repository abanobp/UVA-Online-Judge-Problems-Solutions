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
ii arr [1005] ;
int dp [1005][3005] , N;
int maxi (int ix , int lod)
{
    if (ix == N)
        return 0 ;
    int &res = dp [ix][lod] ;

    if (res != -1)
        return res ;

    res = maxi(ix + 1 , lod) ;

    if (lod == 3003)
         res = max(res , 1 + maxi(ix + 1 , arr[ix].sc)) ;
    else if (arr[ix].fr <= lod)
    res = max(res , 1 + maxi(ix + 1 ,min(lod - arr[ix].fr , arr[ix].sc ))) ;
    return res ;
}

int main()
{
        // freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);

    while (scanf("%d" , &N) && N)
    {
        for (int i = 0 ; i < N ; i++)
            scanf("%d%d" , &arr[i].fr , &arr[i].sc) ;
        memset(dp , -1 ,sizeof dp) ;

        printf("%d\n" , maxi(0 ,3003)) ;
    }
}
