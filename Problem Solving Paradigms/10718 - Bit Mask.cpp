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

      unsigned  long long n , l , u ;

        while (cin >> n >> l >> u)
        {
             bitset<32> yesl ;
             bitset<32> yesn (n) ;

             for (int i = 31 ; i >= 0 ; i--)
             {
                 if (yesn[i])
                    {
                        yesl [i] = 1 ;
                     if (yesl.to_ullong() > l)
                        yesl [i] = 0 ;
                    }
                    else
                    {
                        yesl [i] = 1 ;

                        if (yesl.to_ullong() > u)
                            yesl [i] = 0 ;
                    }
             }

             cout << yesl.to_ullong() <<"\n";
        }
}
