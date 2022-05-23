#include <iostream>
#include "Gestiune.h"
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <fstream>

using namespace std;

ifstream fin("date.txt");

const int Nr_camere_Camin=30;

int main()
{
    vector<Gestiune> gestiune;

    int i;
    int nr=0,nr1=0;
    int iesire=0,out=0;
    string nume, prenume,nume2,prenume2,ncautat,pcautat;
    int an1,an2;
    char r;

    do
    {
        system("cls");


        cout <<  " C - Creare baza de date;" <<"\n"<<
             " V - Vizualizare baza de date;" << "\n" <<
             " M - Modificare si inserare in baza de date;" << "\n"<<
             " F - Cautare student;" << "\n" <<
             " D - Preluare date din fisier;" << "\n" <<
             " S - Salvare in fisier;" << "\n" <<
             " I - Informatii autor;" << "\n" <<
             " E - Iesire." << "\n" << endl  <<
             "Dati optiunea: ";


        switch(r=toupper(getch()))
        {



        default :
        {
            cout<<"\n\ntComanda inexistenta !";

            getch();
            break;
        }


        case 'C':    ///Crearea bazei de date a caminului

            nume="*******";
            prenume="*******";
            nume2 ="*******";
            prenume2="*******";
            an1=0;
            an2=0;
            cout<<"\n     Atentie!!!Numarul de camere ale caminului este limitat la "<<Nr_camere_Camin;
            cout<<"\n\n   Vreti sa faceti inregistrari?";
            do
            {
                cout<<"\n\n D-DA";
                cout<<"\n\n N-NU";
                cout<<"\n";
                switch(getch())
                {

                default:
                {
                    cout<<"\n\n\t Optiune inexistenta!!!";

                    getch();
                    break;
                }

                case 'd':
                {
                    nr=0;
                    iesire=0;
                    system("cls");
                    cout<<" Dati nr. camerei in care vreti sa faceti inserarea: ";
                    cin>>i;
                    for(int j=0; j<gestiune.size(); j++)
                        if(gestiune[j].validare(i)==true)
                            nr=1;
                    while(i>Nr_camere_Camin || nr==1 )
                    {
                        system("cls");
                        cout<<" Introduceti din nou numarul camerei in care vreti sa faceti inserarea: \n";
                        if(nr==1)
                            cout<<" Camera este indisponibila:";
                        else
                            cout<<"Numarul introdus depaseste numarul camerelor din camin:";
                        cin>>i;
                        for(int j=0; j<gestiune.size(); j++)
                            if(gestiune[j].validare(i)==true)
                                nr=1;
                            else
                                nr=0;

                    }
                    do
                    {
                        system("cls");
                        cout<<"\n\n\t      == Dati optiunea: ==";
                        cout<<"\n\n\n 1 - Introducere informatii student nr. 1.";
                        cout<<"\n 2 - Introducere informatii student nr. 2.";
                        cout<<"\n B - Back";
                        cout<<"\n\n\t Introduceti optiunea: ";
                        switch(getch())
                        {
                        case '1':
                            cout<<"\nIntroduceti numele studentului : "<<endl;
                            cin >> nume;
                            cout<<"\nIntroduceti prenumele studentului: "<<endl;
                            cin >> prenume;
                            cout<<"\nIntroduceti anul de studiu: "<<endl;
                            cin >> an1;
                            cout<<"\n\n Inserare efectuata!";
                            getch();
                            break;

                        case '2':
                            cout<<"\nDati numele studentului: "<<endl;
                            cin>>nume2;
                            cout<<"\nDati prenumele studentului: "<<endl;
                            cin>>prenume2;
                            cout<<"\nDati anul de studiu: ";
                            cin>>an2;
                            cout<<"\n\n Inserare efectuata!";
                            getch();
                            break;
                        case 'b':
                            iesire=1;
                            break;
                        }
                    }
                    while(iesire!=1);
                    Gestiune stud(i,nume,prenume,an1,nume2,prenume2,an2);
                    gestiune.push_back(stud);
                    system("cls");
                    cout<<"\n\n Mai vreti sa faceti inregistrari?";
                }
                break;
                case 'n':
                    out=1;
                    break;

                }
            }
            while(out!=1);

            break;



        case 'V':    ///afisare pe ecran a bazai de date

            system("cls");
            cout<<"\n\n";
            if(gestiune.size()==0)
                cout<<"    Baza de date a firmei este goala,nu o puteti accesa";
            else
            {
                cout<<"\n\t == BAZA DE DATE STUDENTI-CAMIN ==";
                cout<<"\n\n\n";
                for(Gestiune studd: gestiune)
                    cout<<studd;
            }

            getch();
            break;



        case 'M':   ///modificare(si stergerea) studentilor din baza de date

        {
            int id;
            int ok=0,ok2=0;
            system("cls");
            cout<<"\n Introduceti id-ul camerei in care vreti sa faceti modificarea: ";
            cin>>id;

            while(ok==0)
            {
                for(int j=0; j<gestiune.size(); j++)
                    if(gestiune[j].validare(id)==true)
                    {
                        ok=1;
                        ok2=j;
                        gestiune[ok2].modificare();
                        break;
                    }
                if(ok==1)
                    break;
                else

                {
                    system("cls");
                    cout<<"Alege alta camera deoarece camera selectata nu este disponibila:";
                    cin>>id;
                }
            }

        }


        break;


        case 'F':  ///Cautarea unui student in baza de date

            nr1=0;
            system("cls");
            cout<<" Introduceti numele studentului pe care vreti sa-l cautati: ";
            cin>>ncautat;
            cout<<"\n Dati prenumele studentului pe care vreti sa-l cautati: ";
            cin>>pcautat;
            for(int j=0; j<gestiune.size(); j++)
                if(gestiune[j].searchStudent(ncautat,pcautat)==true)
                {
                    gestiune[j].print(ncautat,pcautat);
                    nr1=1;
                }
            if(nr1==0)
                cout<<"Studentul nu a fost gasit";
            cout<<"\n \n Cautare terminata!! \n\n == Apasati o tasta pentru a reveni la meniul anterior== ";

            getch();
            break;



        case 'D':   ///citire date din fisier
        {

            int numar=0;
            int nr_de_camere;
            int nr_camerei;
            fin>>nr_de_camere;
            for(int k=1; k<=nr_de_camere; k++)
            {
                fin>>nr_camerei>>nume>>prenume>>an1>>nume2>>prenume2>>an2;
                for(int j=0; j<gestiune.size(); j++)
                    if(gestiune[j].validare(nr_camerei)==true)
                        numar=1;
                if(numar==0 && nr_camerei<Nr_camere_Camin)
                {
                    Gestiune camera(nr_camerei,nume,prenume,an1,nume2,prenume2,an2);
                    gestiune.push_back(camera);
                }
                else
                {
                    nume="*******";
                    prenume="*******";
                    nume2 ="*******";
                    prenume2="*******";
                    an1=0;
                    an2=0;
                }
            }
            cout<<"\n\n\t Citirea s-a efectuat cu succes!!!";

        }

        getch();
        break;


        case 'S':  ///salvare date in fisier
        {

            if(gestiune.size()==0)
                cout<<"\n\n      Baza de date a firmei este goala,nu o puteti accesa";
            else

            {
                for(int j=0; j<gestiune.size(); j++)
                {
                    gestiune[j].printFisier();
                }
                cout<<"\n\n\t Salvarea s-a efectuat cu succes!!";
            }

        }

        getch();
        break;


        case 'E':             ///terminare program

            cout<<"Iesire program!";
            break;


        case 'I':   ///afisare date despe autor

            system("cls");
            cout<<"----- Proiect Gestionare Studenti Cazare -----"<< endl << endl;
            cout<<"- Proiect realizat de    Ostrovschi Artur"<< endl;
            cout<<"- Universitatea          Stefan cel Mare - Suceava"<< endl;
            cout<<"- Facultatea             FIESC"<< endl;
            cout<<"- Specializarea          Calculatoare"<< endl;
            cout<<"- Grupa                  3132"<< endl;
            cout<<"- Semigrupa              A"<< endl;

            getch();
            break;

        }
    }
    while (r!='E');

    return 0;
}
