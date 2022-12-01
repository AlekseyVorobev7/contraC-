#include <iostream> // это база
#include <string> // это строчки
#include <algorithm> //это ТОП
#include <vector> // это друг
#include <map> // это для души
#include <cctype>   // для функции isdigit которая не работает :(((
#include <cstdlib>  // для функции atoi

#define ln "\n"
#define ll long long
#define mkp(x,y) make_pair(x,y)
#define re return

using namespace std;

//map<string,string> m;

bool is_digits(string str) // Проверка является ли строка числом
{
    return str.find_first_not_of("0123456789") == string::npos;
}

vector<string> to_string_vector(char **a, int n) // перевод в вектор строк
{
    vector<string> v(n);
    for(int i = 0; i < n; i++)
    {
        v[i] = a[i];
    }
    re v;
}


vector<string> arguments = {"-o", "-help", "-version", "-n"}; // Все доступныые аргументы


vector<string> get_format_and_name(string str) // получени названия и расшерения файла
{
    string name = str.substr(0,str.find_last_of('.'));
    string format = str.substr(str.find_last_of('.'),str.size() - str.find_last_of('.'));
    vector<string> a(2);
    a[0] = name;
    a[1] = format;
    re a;
}

int main(int argc, char **argv)
{
    ll n = 2;// дефолтное значение
    ll ans = 0;
    string f = "a.txt";
    
    vector<string> args = to_string_vector(argv, argc); // перевод в вектор

    for(int i = 1; i < argc; i++)// цикл по всем аргументам
    {   
        if(args[i] == "-o") // обработка аргумента -о
        {
            if(i+1 >= argc || args[i+1][0] == '-') // проверка  задано ли значение аргумента или идут ли два аргумента подряд 
            {
                cout << "[Warnning] Net znachenia argumenta: " << "<" << args[i] << ">" << ln;
                continue;
            }
            else
            {
                f = args[i+1];
                if(f.find_last_of('.') == string::npos)// проверка на то что задано расшерение файла
                {
                    cout << "[Warnning] Ne zadan format txt dla fayla! Otet budet soxranen v fayle : " << f << ".txt" << ln;
                    f+=".txt"; //добавляем расшерение txt к файлу
                    freopen(f.c_str(), "w",stdout);
                    i++;
                }
                else
                {
                    vector<string> file = get_format_and_name(f);
                    if(file[1] != ".txt")// Проверка расшерения файла
                    {
                        cout << "[Warnning] Neverniy format fayla! Otet budet soxranen v fayle : " << file[0] << ".txt" << ln;
                        f = file[0] + ".txt";
                        freopen(f.c_str(), "w",stdout);
                        i++;
                    }
                }
            }
        }
        
        
        if(args[i] == "-help")// все доступные команды
        {
            cout << "Vse dostupnye comandy:\n -version : versiya programmy\n -n : peredaty colichestvo chisel dly clogenia\n -o <file name.txt> : fail gde bydet soxranen rezultat" << ln;
            re 0;
        }
        

        if(args[i] == "-version")// версия                                                                                                                                               
        {
            cout << "V 1.0.2" << ln;
            re 0;                                                                                                         
        }
        

        if(args[i] == "-n")// проверка на заданое количество чисел
        {
            if(i+1 >= argc || args[i+1][0] == '-') // есть ли значение аргумента
            {
                cout << "[Warnning] Net znachenia argumenta: " << "<" << args[i] << ">" << ln;
                continue;
            }
            else
            {
                string l = args[i+1];
                if(is_digits(l)) // проверка является ли числом
                {
                    n = stoi(l);
                    i++;
                }
                else
                {
                    cout << "[Warning] Ne Natyralnoe chislo" << ln;
                    i++;
                }
            }
        }

        if(args[i][0] == '-'  && find(arguments.begin(), arguments.end(),args[i]) == arguments.end()) // обработка не известных аргументов
        {
            cout << "Neponytniy argument : <" << args[i] << ">" << ln;
        }
    }   

    

    for(ll i = 0; i < n;i++)
    {
           ll x;
           cin >> x;
           ans+=x;
    }
    
    cout << "Suma zadanyx " << n << " chisel = " << ans;
    re 0;
}