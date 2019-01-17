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
long long FastPow(long long x , long long y , int mod)
{
    if (y == 0)
        return 1 ;
    long long res = FastPow(x , y / 2 , mod)  % mod;
    if (y % 2 == 0)
        return (res * res ) % mod ;
    else
        return (((x * res ) % mod ) * res) %mod ;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n , p , m ;

    while (cin >> n >> p >> m )
    {
        cout << FastPow(n,p,m) <<"\n";
    }
}
//------------------------------------ DONE -----------------------------------------------------
