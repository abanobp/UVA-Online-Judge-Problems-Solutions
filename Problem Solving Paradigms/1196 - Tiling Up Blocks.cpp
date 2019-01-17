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
#define ii pair<int,int>
#define fr first
#define sc second
using namespace std;

int main()
{
         freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

    int N ;

    while (scanf("%d" , &N) && N)
    {
        vector<ii> box (N) ;

        for (int i = 0 ; i < N ; i++)
            scanf("%d%d" , &box [i].fr , &box [i].sc) ;
        sort(box.begin() , box.end()) ;

        vector<int>  T2 (N);
        int sz = 0 ;

        T2 [0] = box [0].sc ;

        for (int i = 1 ; i < N ; i++)
        {
            if (T2 [sz] <= box [i].sc)
              sz++ , T2 [sz] = box [i].sc ;
            else
            {
                int in2 = upper_bound(T2.begin(),T2.begin() + sz , box [i].sc) - T2.begin() ;

                T2[in2] = box [i].sc  ;
            }
        }

        printf("%d\n" , sz + 1) ;
    }

    printf("*\n") ;
}
