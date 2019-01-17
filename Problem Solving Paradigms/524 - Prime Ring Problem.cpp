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
vector<bool> used ;
vector<int> v;

bool Prime (int n)
{
    for (int i = 2 ; i * i <= n ; i++ )
        if (n % i == 0)
            return 0 ;
    return 1 ;
}

void print_p (int m , int pr)
{
 if (m == N && Prime(pr + 1 ))
 {
     for (int i = 0 ; i < m ; i++)
        if (!i)
        printf("%d",v[i]) ;
        else
        printf(" %d",v[i]);
     printf("\n");
 }

    for (int i = 2 ; i <= N ; i++)
    {
        if (!used [i] && Prime(i + pr))
        {
            used [i] = 1 ;
            v.push_back(i);
            print_p(m + 1 , i) ;
            used [i] = 0 ;
            v.pop_back();
        }
    }
}

int main()
{
             // freopen("in.txt","r",stdin);
         // freopen("out.txt","w",stdout);
        v.push_back(1);
        T = 1 ;
        while (scanf("%d",&N) != EOF)
        {
            if (T > 1)
            printf("\n");
            used.assign(N+3 , 0) ;
            printf("Case %d:\n",T++);
            print_p(1,1) ;
        }
}
