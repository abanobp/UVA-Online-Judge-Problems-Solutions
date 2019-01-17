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
string rev (string n)
{

    reverse(n.begin() , n.end()) ;
    int i = 0 ;
    while(n[i] == '0')
        i++ ;
    n = n.substr(i,n.size() - i) ;
    if (n.size())
        return n ;
    return "0" ;
}
string add (string a , string b)
{
    int fr = a.size() - 1 , sc = b.size() - 1 , rem = 0 ;
    string res = "" ;
    while( (fr >= 0) || (sc >= 0) )
    {
        if ((fr >= 0) && (sc >= 0) )
        {
            int x =  ((a[fr] - '0') + (b[sc] - '0') ) + rem ;
            //cout << x << "\n" ;
            res += (char)((x % 10) + '0' ) ;
            rem = x / 10 ;
        }
        else
        {
            if (fr >= 0)
            {
                int x = (a[fr] - '0')  + rem ;
                res += (char)((x % 10) + '0' ) ;
                rem = x / 10 ;
            }
            else
            {
                int x = (b[sc] - '0')  + rem ;
                res += (char)((x % 10) + '0' ) ;
                rem = x / 10 ;
            }
        }
    //    cout << res << " " << rem << "\n" ;
        fr--,sc-- ;
    }
    while(rem)
    {
        res += ((char)(rem % 10) + '0');
        rem /= 10 ;
    }
    reverse(res.begin() , res.end()) ;
    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a , b ;
    int T ;
    cin >> T ;

    while(T--)
    {
        cin >> a >> b ;
        string Na = rev(a) , Nb = rev(b) ;
        string sum =  add(Na,Nb) ;
        cout << rev(sum) << "\n" ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
