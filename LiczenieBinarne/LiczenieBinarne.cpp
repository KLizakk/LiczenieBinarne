// LiczenieBinarne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "stdlib.h"
#include <string>
string PrzeliczNa2(int x)
{
    if (x == 0) {
        cout << "nie wprowadzaj 0";
    }
    string L2 = "";
    while (x > 0) {
        int r = x % 2;
        L2 = to_string(r) + L2;
        x /= 2;
    }
    return L2;
}

string PrzeliczNa8(int x)
{
    if (x == 0) {
        cout << "Nie wprowadzaj 0";
    }
    string L8 = "";
    while (x > 0) {
        int r = x % 8;
        L8 = to_string(r) + L8;
        x /= 8;
    }
    return L8;
}
string PrzeliczNa16(int x)
{
    if (x == 0) {
        cout << "Nie wprowadzaj 0";
    }
    string L16 = "";
    while (x > 0) {
        int r = x % 16;
        L16 = to_string(r) + L16;
        x /= 16;
    }
    return L16;
}

int Na10(string x)
{
    int Liczba10 = 0;
    int PotegaDwa = 1;
    for (int i = x.length() - 1;i >= 0;--i)
    {
        if (x[i] == '1') {
            Liczba10 += PotegaDwa;
        }
        PotegaDwa *= 2;
    }
    return Liczba10;
}
//Niepoprawne dodawanie
string Dodawanie(string a, string b)
{
    int A = Na10(a);
    int B = Na10(b);
    
    int suma = A + B;

    return PrzeliczNa2(suma);

}
//Poprawne dodawania
string DodawanieP(string a, string b)
{
    string wynik;
    char jeden = '0';
    for (int i = a.length(); i >= 0; i--)
    {
        
        if (a[i] == '1' && b[i] == '1' &&jeden == '0') { wynik = '0' + wynik; jeden = '1'; }
        else if (a[i] == '1' && b[i] == '1' &&jeden == '1') { wynik = '1' + wynik; jeden = '1'; }
        else if (a[i] == '1' && b[i] == '0'&& jeden == '1') { wynik =  '0' + wynik; jeden = '1'; }
        else if (a[i] == '1' && b[i] == '0' && jeden == '0') { wynik = '1' + wynik; jeden = '0'; }

        else if (a[i] == '0' && b[i] == '0' && jeden == '1') { wynik = '1' + wynik;  jeden = '0'; }
        else if (a[i] == '0' && b[i] == '0' && jeden == '0') { wynik = '0' + wynik;  jeden = '0'; }
        else if (a[i] == '0' && b[i] == '1' && jeden == '1') { wynik = '0' + wynik; jeden = '1'; }
        else if (a[i] == '0' && b[i] == '1' && jeden == '0') { wynik = '1' + wynik; jeden = '0'; }
        
    }
    if (jeden == '1') { wynik = '1' + wynik; };
    return wynik;
}
//Odejmowanie : 
string OdejmowanieP(string a, string b)
{
    string wynik;
    char jedenA = '0';
    
    for (int i = wynik.length(); i >=0; i--)
    {
        
        if (a[i] == '1' && b[i] == '1') { wynik = '0' + wynik; }
        
     
        if (a[i] == '0' && b[i] == '0') { wynik = '0' + wynik;}
        if (a[i] == '0' && b[i] == '1'  && a[i - 1] == '1') { wynik = '1' + wynik; a[i - 1] = '0'; };

        
        

    }
    return wynik;
}
int main()
{
    int x;
    cout << "Podaj liczbe :";
    cin >> x;
    //2
    string Rezultat = PrzeliczNa2(x);
    cout << "Liczba : " << x<<endl << " W przeliczeniu na system 2 to : " << Rezultat;
    

    //8
    string Rezultat2 = PrzeliczNa8(x);
    cout <<endl<<"Liczba w systemie 8 : " << Rezultat2;
    //16
    string Rezultat3 = PrzeliczNa16(x);
    cout << endl << "Liczba  w systemie 16 : " << Rezultat3;

    ///Dodawanie: 
    string xD = DodawanieP("1111", "1010");
    string xD2 = Dodawanie("1111", "1010");
    cout << endl << "Wartoœc po dodaniu : " << xD <<endl<< "Poprawny wynik to : " << xD2;

    //Odejmowanie:
    xD = OdejmowanieP("110", "001");
    cout << endl << "Wartoœc po odjêciu : " << xD;
   


}


