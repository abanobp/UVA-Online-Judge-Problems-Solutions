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
#define INF  1000000007
using namespace std;


int main()
{
            freopen("in.txt","r",stdin);
           freopen("out.txt","w",stdout);

    int T , TT = 1 ;

    scanf("%d",&T) ;

    while (T--)
    {
        int N ;
        long long D ;

        scanf("%d%lld", &N , &D) ;

        vector<long long > S (N + 2) ;
        vector<bool> X (N + 2) ;
        S [0] = 0;
        X [0] = 1 ;
        for (int i = 1 ; i <= N ;i++)
        {
            string a ;
            cin >> a ;
            if (a[0] == 'B')
                X [i] = 1 ;
            else
                X [i] = 0 ;
            a.erase(0,2) ;
            stringstream ss (a) ;
            ss >> S[i] ;
        }
        S [N + 1] = D ;
        X [N + 1] = 1 ;
        long long las = 0 ;
        long long MX = 0 ;
        for (int i = 0 ; i < N + 2 ; i++)
        {
            if (X [i])
                MX = max(MX , S [i] - las) , las = S[i];
            else
            {
                if (las != S[i - 1]){
                      MX = max(MX , S [i] - las) , las = S[i];
                      MX = max(MX , S [i + 1] -  S [i - 1]) ;
                }
            }
        }

        printf("Case %d: %lld\n", TT++ , MX ) ;
    }
}
