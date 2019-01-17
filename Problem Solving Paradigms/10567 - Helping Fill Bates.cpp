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
#define INF  1000000007
using namespace std;
vector<pair<char, int> > a ;

int lower (int s , int l , char val , int ser)
{
    if (l - s < 4)
    {
        for (int i = s ; i <= l ; i++)
            if (a [i].first == val  && a [i].second >= ser)
                return i ;
        return -1 ;
    }
    int mid = (s + l ) / 2 ;

    if ((a [mid].first < val) || (a [mid].first == val && a [mid].second < ser ) )
        return lower(mid,l,val , ser) ;
    else
        return lower(s,mid,val , ser) ;
}
int main()
{
        freopen("in.txt","r",stdin);
         freopen("out.txt","w",stdout);
     string d ;
     cin >> d ;
     a.resize(d.size()) ;
     for (int i = 0 ; i < d.size() ; i++)
        a [i].first = d [i] , a[i].second = i ;

     sort(a.begin(),a.end());

     int q ;
     cin >> q ;

     while (q--)
     {
        string s ;
        cin >> s ;
        bool done = 1;
        int b1 = -1 , b2 = -1 , p = -1 ;
        for (int i = 0 ; i < s.size() ;i++)
        {
             p = lower(0, a.size()-1 , s[i] , b2 + 1 ) ;

            if (p != -1)
            {
                if (b1 == -1)
                    b1 = a[p].second ;
                b2 = a[p].second ;
            }
            else
            {
                done = 0 ;
                break;
            }
        }
        if (done)
            printf("Matched %d %d\n",b1,b2) ;
        else
            printf("Not matched\n") ;
     }
}
