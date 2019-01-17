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
#define INF  -10000000000007
using namespace std;
int N , T;
vector<int> arr ;
set<vector<int> > yes ;
vector<int> v;
bool flag ;
void sum (int p , int tot)
{
    if (p == N)
    {
        if (yes.find(v) != yes.end() || tot != T)
            return ;
        flag = 1 ;
        for (int i = 0 ; i < v.size();i++)
            if (!i)
                printf("%d",v[i]);
            else
                printf("+%d",v[i]);
        yes.insert(v);
        printf("\n");
        return ;
    }
     v.push_back(arr [p]) ;
    sum(p + 1 , tot + arr[p] ) ;
    v.pop_back();

    sum (p + 1 , tot ) ;
}
int main()
{
             // freopen("in.txt","r",stdin);
         // freopen("out.txt","w",stdout);

        while (scanf("%d%d",&T,&N) && N )
        {
            yes.clear();
            arr.resize(N) ;
            flag = 0 ;
            printf("Sums of %d:\n",T);
            for (int i = 0 ; i < N ; i++)
                scanf("%d",&arr [i]) ;
           // reverse(arr.begin(),arr.end());
            sum(0 , 0) ;
            if (!flag)
                printf("NONE\n");
        }
}
