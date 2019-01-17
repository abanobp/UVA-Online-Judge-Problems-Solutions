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
using namespace std;
vector<int> T , R , in ,arr ;


void print (int p)
{
    if (R [p] != -1)
        print(R [p]) ;

    printf("%d\n" , arr [p]) ;
}

int main()
{
             freopen("in.txt","r",stdin);
             //freopen("out.txt","w",stdout);
    int a ;
    while (scanf("%d" , &a) != EOF )
       arr.push_back(a) ;

    int N  = arr .size();

    T.resize(N) , R.assign(N , -1) , in.resize(N) ;

    int sz = 0 ;

    for (int i = 1 ; i < arr.size() ;i++)
    {
        if (arr [i] > T [sz])
            sz++ , T [sz] = arr[i] , in [sz] = i , R [i] = in [sz - 1] ;
        else
        {
            int x = lower_bound(T.begin(),T.begin() + sz , arr[i]) - T.begin() ;
            T [x] = arr [i] , in [x] = i ;
            if (x)
                R [i] = in [x - 1] ;
        }
    }

    printf("%d\n-\n" , sz + 1) ;
    print(in [sz]) ;
}
