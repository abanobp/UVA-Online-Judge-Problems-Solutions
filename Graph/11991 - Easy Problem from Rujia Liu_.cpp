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
        vector<vector<int> >gr(1000009);
        for (int i = 0 ; i < n ; i++ )
            {
                    int a;
                    scanf("%d",&a);
                    gr[a].push_back(i+1);
            }

        for (int i = 0 ; i < m ; i++ )
            {
                int a,b;
                scanf("%d%d",&a,&b);
                if (a>gr[b].size())
                    printf("0\n");
                else
                    printf("%d\n",gr[b][a-1]);
            }
    }
}
