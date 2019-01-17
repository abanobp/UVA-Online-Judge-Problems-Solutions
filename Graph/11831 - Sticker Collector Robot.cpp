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
using namespace std;

int main()
{
  // freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

    int W [4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

   int n,m,s;

   while (scanf("%d%d%d",&n,&m,&s))
   {

            if (s==0&&m==0&&n==0)
            return 0;

       char A [ 105 ] [ 105 ];
       char c ;
       int N,M,p;

       for (int i = 0 ; i < n ; i++ )
        {
            for (int j = 0 ; j < m ; j++)
            {
                cin>>A [  i ] [ j];

                if (A [i][j] == 'N' || A[i][j] == 'S' || A[i][j] == 'L' || A[i][j] == 'O')
                    c = A[i][j] ,N = i , M = j;
            }
        }

        if (c=='N')
            p=0;
        else if (c=='S')
            p=2;
        else if (c=='L')
            p=1;
        else if (c=='O')
            p=3;
        string in;
        cin>>in;

        int tot = 0;
        for (int i = 0 ; i < s ; i++)
        {
            if (in [ i ]=='D')
            p++;
        else if (in [ i ]=='E')
            p--;
        else if (in [ i ]=='F')
           {

               int x = W[p][0]+ N , y = W[p][1]+ M;

               if ( x < 0 || y <0 || x==n || y == m )
                continue ;
               else if (A [ x ][ y ] != '#')
               {
                   N = x ,M = y;
                   if (A [ x ][ y ]=='*')
                    A [ x ][ y ]='.',tot++;
               }
           }
          if (p==4)
            p=0;
          if (p==-1)
            p=3;

        }

       printf("%d\n",tot) ;
   }

}
