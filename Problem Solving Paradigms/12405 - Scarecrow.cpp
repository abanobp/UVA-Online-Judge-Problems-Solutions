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
    int T ;
    cin >> T ;

    for (int tes = 1 ; tes <= T ; tes++)
    {
        int N ;
        scanf("%d",&N) ;

        char s [105] = "\0";
        scanf("%s",&s) ;
        int c = 0 ;
        for (int i = 0 ; i < N ;i++)
        {
            if (i && s[i - 1] == '.')
                s[i-1] = s[i] = s [i+1] = '#' , c++ ;
        }

        if (s[N - 1] == '.')
            c++;
        printf("Case %d: %d\n",tes ,  c) ;
    }
}
