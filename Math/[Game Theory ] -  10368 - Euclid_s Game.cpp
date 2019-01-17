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
int fun (long long a , long long b , int ix)
{
    int ax = max(a,b) , bx = min(a,b) ;
  //  cout << ax << " " << bx << "\n" ;
     if ((ax % bx == 0) || (ax / bx  > 1))
        return ix ;

    return fun(bx , ax % bx , 1 - ix) ;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long a , b ;

    while(cin >> a >> b && a && b)
    {
       int ax = max(a,b) , bx = min(a,b) ;

        if (!fun(ax,bx,0))
            cout << "Stan wins\n" ;
        else
            cout << "Ollie wins\n" ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
