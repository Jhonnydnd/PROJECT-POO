#include <iostream>
#include "Gestiune.h"
#include<vector>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <fstream>

using namespace std;

ofstream fout("afisare.txt");

Gestiune::Gestiune()   ///Constructorul implicit
{

    nume="*******";
    nume1="*******";
    prenume="*******";
    prenume1="*******";
    anul1=0;
    anul2=0;
    id=0;

}



ostream& operator <<( ostream& c, Gestiune& b )  ///  afiseaza cei doi studenti dintr-o camera anume pe ecran
{

    c <<"\n\t Camera: "<<b.id<<"  "<<b.nume<<"  "<<b.prenume<<"  "<<b.anul1<<"\n\t            "<<b.nume1<<"  "<<b.prenume1<<"  "<<b.anul2<<"\n";
    return c;

}



Gestiune::Gestiune(int n, string nume2,string prenume2,int an,string nume3,string prenume3,int an2) ///constructor cu parametri
{

    id=n;
    nume=nume2;
    prenume=prenume2;
    anul1=an;
    anul2=an2;
    nume1=nume3;
    prenume1=prenume3;

}



void Gestiune::modificare() /// aceasta functie modifica baza de date (inlocuieste studentii sau ii poate sterge din memorie)
{
    int iesire=0;
    string nume2, prenume2, nume3,prenume3;
    int an1,an2;
    do
    {
        system("cls");
        cout<<"\n\n\t      == Dati optiunea: ==";
        cout<<"\n 1 - Inlocuire primul student.";
        cout<<"\n 2 - Inlocuire al doilea student.";
        cout<<"\n 3 - Sterge primul student din baza de date.";
        cout<<"\n 4 - Sterge al doilea student din baza de date.";
        cout<<"\n B - Back";
        cout<<"\n" ;
        switch(getch())
        {
        case '1':
            cout<<"\n Introduceti numele noului student:"<<endl;
            cin>>nume2;
            nume=nume2;
            cout<<"\n Introduceti prenumele noului student:"<<endl;
            cin>>prenume2;
            prenume=prenume2;
            cout<<"\n Introduceti anul de studiu: ";
            cin>>an1;
            anul1=an1;
            cout<<"\n\n\n Inlocuire efectuata!";
            getch();
            break;
        case '2':
            cout<<"\n Introduceti numele noului student:"<<endl;
            cin>>nume3;
            nume1=nume3;
            cout<<"\n Introduceti prenumele noului student:"<<endl;
            cin>>prenume3;
            prenume1=prenume3;
            cout<<"\n Inroduceti anul de studiu: ";
            cin>>an2;
            anul2=an2;
            cout<<"\n\n\n Inlocuire efectuata!";
            getch();
            break;
        case '3':
            nume="******";
            prenume="*******";
            anul1=0;
            cout<<"\n\n Stergere efectuata! ";
            getch();
            break;
        case '4':
            nume1="*******";
            prenume1="*******";
            anul2=0;
            cout<<"\n\n Stergere efectuata! ";
            getch();
            break;

        case 'b':
            iesire=1;
            break;
        }
    }
    while(iesire!=1);
}



bool Gestiune :: searchStudent(string ncautat,string prcautat) /// aceasta functie cauta studentii dupa numele si prenumele lor
{


    if((ncautat==nume && prcautat==prenume) || (ncautat==nume1 && prcautat==prenume1))///Compara numele cautat cu numele existent daca este cazul.
        return true;
    else
        return false;

}



void Gestiune::print( string ncautat,string pcautat)   ///metoda care afiseaza studentul cautat de utilizator
{

    cout<<"Studentul "<<ncautat<<" "<<pcautat<<" a fost gasit in camera cu numarul "<<id;

}



bool Gestiune::validare(int i) ///functia prin verifica daca un student este deja in baza de date
{

    if(id==i)
        return true;
    else
        return false;

}

void Gestiune::printFisier()  ///metoda care afiseaza datele in fiserul text
{

    fout<<id<<"  "<<nume<<"  "<<prenume<<"  "<<anul1<<"\n   "<<nume1<<"  "<<prenume1<<"  "<<anul2<<"\n";

}

