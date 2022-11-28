#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>   // для функции isdigit
#include <cstdlib>  // для функции atoi

#define ln "\n"
#define ll long long
#define mkp(x,y) make_pair(x,y)
#define re return

using namespace std;

map<string,string> m;

bool is_digits(string str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}

int main(int argc, char **argv)
{
    ll n = 2;
    ll ans = 0;
    string f = "a.txt";
    for(int i = 1; i < argc; i++)
    {
        string s = argv[i];
        if(s == "-o")
        {
            if(i+1 >= argc)
            {
                cout << "Net znachenia argumenta" << s << ln;
            }
            else
            {
                f = argv[i+1];
                i++;
            }
        }
        if(s == "-help")
        {
            cout << "Vse dostupnye comandy:\n -version : versiya programmy\n -n : peredaty colichestvo chisel dly clogenia\n -o <file name> : fail gde bydet soxranen rezultat" << ln;
        }
        if(s == "-version")                                                                                                                                                     
        {
            cout << "V 1.0.0";
            re 1;                                                                                                         
        }
        if(s == "-n")
        {
            if(i+1 >= argc)
            {
                cout << "Net znachenia argumenta" << ln;
            }
            else
            {
                string l = argv[i+1];
                if(is_digits(l))
                {
                    n = stoi(l);
                    i++;
                }
                else
                {
                    cout << "Ne Natyralnoe chislo";
                }
            }
        }
        freopen(f.c_str(), "w",stdout);
        for(ll i = 0; i < n;i++)
        {
            ll x;
            cin >> x;
            ans+=x;
        }
        cout << ans;
        re 0;
    }   
}