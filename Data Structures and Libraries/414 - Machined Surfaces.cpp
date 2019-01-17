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

    while (cin >> N )
    {
        if (!N)
            break ;
        string a ;
        cin >> a ;
        int mimi = INT_MAX ;
        vector<int> v ;

        for (int i = 0 ; i < N ; i++)
        {
            getline(cin , a) ;
            int sum = 0 ;
            for (int i = 0 ; i < a.size() ; i++)
            {
                if (a [i] == ' ')
                    sum++ ;
            }
            v.push_back(sum) ;
            mimi = min(mimi , sum) ;
        }

        int tot = 0 ;
        for (int i = 0 ; i < N ; i++)
            tot += v[i] - mimi ;

        printf("%d\n" , tot) ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
