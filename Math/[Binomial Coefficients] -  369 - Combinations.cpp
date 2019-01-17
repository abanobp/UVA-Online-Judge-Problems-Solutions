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
    int N, M ;
    while(cin >> N >> M && N && M)
    {
        int p = N - M , mx = max(p, M) , s = 1 , e = N ;
        long long res = 1;

        while(e > mx)
        {
            res *= e ;
            if (s <= min(p,M))
            res /= s ;
            e--,s++;
        }
        printf("%d things taken %d at a time is %lld exactly.\n",N,M,res) ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
