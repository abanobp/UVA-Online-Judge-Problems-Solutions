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

int main()
{
      // freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);

    int N , D , R ;

    while (scanf("%d%d%d",&N,&D,&R) && N)
    {
        vector <int> v1 (N) , v2 (N) ;

        for (int i = 0 ; i < N ; i++)
            scanf("%d",&v1[i]) ;

        for (int i = 0 ; i < N ; i++)
            scanf("%d",&v2[i]) ;

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end()) ;
        reverse(v2.begin(),v2.end()) ;

        int sum = 0 ;
        for (int i = 0 ; i < N ; i++)
        {
            if (v1 [i] + v2[i] > D)
                sum +=  (v1 [i] + v2[i]) - D ;
        }

        printf("%d\n", sum * R) ;
    }

}
