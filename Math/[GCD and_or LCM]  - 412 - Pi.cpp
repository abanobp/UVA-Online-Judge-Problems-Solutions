#include<bits/stdc++.h>
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
#define INF  -1
#define MOD  1000000007
#define BIG  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define MP(a,b) make_pair(a,b)
#define fr first
#define sc second

using namespace std;

//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

     int N ;

    while(cin >> N && N)
    {
        vector<int> v (N) ;
        for (int i = 0 ; i < N ; i++)
            cin >> v[i] ;
        int c = 0 ;

        for (int i = 0 ; i < N ; i++)
            for (int j = i + 1 ; j < N ; j++)
                if (__gcd(v[i],v[j]) == 1)
                    c++;
        //cout << c << "\n" ;
        int tot = (N * (N - 1))/2;
        if (c)
        {
            double res = sqrt((6 * tot) / ((double)c)) ;
            cout << fixed << setprecision(6) <<  res << "\n";
        }
        else
            cout << "No estimate for this data set.\n";
    }
}
//------------------------------------ DONE -----------------------------------------------------
