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
#define MOD  1000000007
#define inf  1000000007
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
vector<string> arr;
int N ;
int num(int x,int y)
{
    if (x < 0 || y < 0 ||x >= N || y >= arr[x].size() || arr[x][y] =='0')
        return 0;
    arr[x][y] = '0' ;

    int sum = 1 ;
    sum += num(x - 1, y) ;
    sum += num(x, y - 1) ;
    sum += num(x + 1, y) ;
    sum += num(x, y + 1) ;
    sum += num(x + 1, y + 1) ;
    sum += num(x + 1, y - 1) ;
    sum += num(x - 1, y + 1) ;
    sum += num(x - 1, y - 1) ;

    return sum;
}

int main()
{
    //  freopen("res.txt" , "w" , stdout) ;
       // freopen("in.txt" , "r" , stdin) ;

    int T ;
    scanf("%d", &T) ;
    cin.ignore();
    cin.ignore();
    while(T--)
    {
        string a ;
        arr.clear();
        while(getline(cin,a) && !a.empty() )
        {
            arr.push_back(a);
        }

        N = arr.size();
        int mx = 0 ;
        for (int i = 0 ; i <N ; i++)
        {
            for (int j = 0 ; j < arr[i].size() ;j++)
                if (arr[i][j] == '1')
                    mx = max(mx , num(i,j)) ;
        }
        cout << mx << "\n" ;
        if (T)
             cout << "\n";
    }
}
//------------------------------------ DONE -----------------------------------------------------
