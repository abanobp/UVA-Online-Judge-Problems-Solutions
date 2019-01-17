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

    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        vector<vector<pair<int,int> > >v(m+4);
       for (int i = 0 ; i < n ; i++)
       {

           int r;
           scanf("%d",&r);
           if (r==0)
            {
                string a;
               getline(cin,a);
            }
           else
           {
               vector<pair<int,int> >in;
               for (int j = 0 ; j < r ; j++ )
               {
                 int a;
                 scanf("%d",&a);
                 v[a].push_back(make_pair(i+1,0));
                 in.push_back(make_pair(a,v[a].size()-1));
               }

                for (int j = 0 ; j < in.size() ; j++ )
                {
                 int a;
                 scanf("%d",&a);
                 v[ in[j].first ][in[j].second].second = a;
                }

           }
       }

       printf("%d %d\n",m,n);

       for (int i = 1 ;i <= m ; i++ )
       {
           printf("%d",v[i].size());

        for (int j = 0 ; j<v[i].size() ; j++)
            printf(" %d",v[i][j].first);

             printf("\n");

         for (int j = 0 ; j<v[i].size() ; j++)
            if (j==0)
            printf("%d",v[i][j].second);
            else
                 printf(" %d",v[i][j].second);

             printf("\n");
       }
    }
}
