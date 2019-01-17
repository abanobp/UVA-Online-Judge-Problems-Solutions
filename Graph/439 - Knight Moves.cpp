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
int movX [] = {-1,-1,1,1,2,-2,2,-2} , movY [] = {2,-2,2,-2,1,1,-1,-1};

int shortest (string a , string b)
{
    int y1 = a[1] - '0' , x1 = a[0] - 'a' + 1 , x2 = b[0] - 'a' + 1 , y2 =  b[1] - '0' ;
    queue<pair<int,int> > q;
    map<pair<int,int> , int > vis;
    vis[MP(x1,y1)] = 1;
    q.push(MP(x1,y1)) ;

    while(!q.empty())
    {
        int ch1 = q.front().first , ch2 = q.front().second ;
        q.pop();
      //  cout << ch1 << " " << ch2 << "\n" ;
        if (ch1 == x2 && ch2 == y2)
            return vis[MP(x2,y2)] ;

        for (int i = 0 ; i < 8 ; i++)
        {
            int nx = movX[i] + ch1 , ny = movY[i] + ch2 ;
            if (nx > 0 && nx < 9 && ny > 0 && ny < 9 )
            {
                if (!vis[MP(nx,ny)])
                    q.push(MP(nx,ny)) , vis[MP(nx,ny)] = vis[MP(ch1,ch2)] + 1;
            }
        }
    }

    return 0;
}

int main()
{
     //freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char  a [5], b[5] ;

    while(cin >> a >> b)
    {
        printf("To get from %s to %s takes %d knight moves.\n" , a , b , shortest(a,b) - 1) ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
