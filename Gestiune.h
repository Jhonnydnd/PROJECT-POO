#ifndef GESTIUNE_H
#define GESTIUNE_H
#include <iostream>
using namespace std;

class Gestiune
{
    int id;
    string nume,prenume,nume1,prenume1;
    int anul1,anul2;
   public:

    Gestiune();
    bool searchStudent(string ncautat,string prcautat);
    Gestiune(int n, string nume2,string prenume2,int an,string nume3,string prenume3,int an2);
    friend ostream& operator <<( ostream& c,Gestiune& b );
    void modificare();
    bool validare(int);
    void print(string,string);
    void printFisier();
};

#endif // GESTIUNE_H
