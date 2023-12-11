#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <fstream>
#define filec "tabel.txt"
using namespace std;
ifstream fin(filec);
int nrlinii=1;
int jale=1;

struct vreme
{
    char cod[30];
    int zi;
    int luna;
    int an;
    char ora[30];
    int temperatura;
    int presiune;
    int precipitatii;
} tabel[101];

void temp_medie()
{
    int tm=0, i;
    for(i=1; i<=nrlinii; i++)
    {
        tm+=tabel[i].temperatura;
    }
    tm/=nrlinii;
    cout<<endl<<"temperatura medie este de "<<tm<<"*C"<<"\n\n";
}

void temp_mxm()
{
    int i, m;
    m=tabel[1].temperatura;
    for(i=2; i<=nrlinii; i++)
    {
        if(m<tabel[i].temperatura)
            m=tabel[i].temperatura;
    }
    cout<<endl<<"datele cu temperatura maxima egala cu "<<m<<"*C"<<" sunt"<<"\n\n";
    for(i=1; i<=nrlinii; i++)
    {
        if(tabel[i].temperatura==m)
            cout<<tabel[i].zi<<'/'<<tabel[i].luna<<'/'<<tabel[i].an<<"\n\n";
    }
}

void temp_dep()
{
    int i, m;
    cout<<"ce temperatura"<<endl;
    cin>>m;
    for(i=1; i<=nrlinii; i++)
    {
        if(tabel[i].temperatura>m)
            cout<<tabel[i].zi<<'/'<<tabel[i].luna<<'/'<<tabel[i].an<<" cu temperatura de "<<tabel[i].temperatura<<"*C"<<"\n\n";
    }
}

void pres_min()
{
    int i, m;
    m=tabel[1].presiune;
    for(i=2; i<=nrlinii; i++)
    {
        if(m>tabel[i].presiune)
            m=tabel[i].presiune;
    }
    cout<<endl<<"datele cu presiune minima egala cu "<<m<<"ATM"<<" sunt"<<"\n\n";
    for(i=1; i<=nrlinii; i++)
    {
        if(tabel[i].presiune==m)
            cout<<tabel[i].zi<<'/'<<tabel[i].luna<<'/'<<tabel[i].an<<"\n\n";
    }
}




void inserare(char p[], int l, int nrcaz)
{
    switch(nrcaz)
    {
    case 1:
        strcpy(tabel[l].cod, p);
        break;
    case 2:
        tabel[l].zi=atoi(p);
        break;
    case 3:
        tabel[l].luna=atoi(p);
        break;
    case 4:
        tabel[l].an=atoi(p);
        break;
    case 5:
        strcpy(tabel[l].ora, p);
        break;
    case 6:
        tabel[l].temperatura=atoi(p);
        break;
    case 7:
        tabel[l].presiune=atoi(p);
        break;
    case 8:
        tabel[l].precipitatii=atoi(p);
        break;
    }
}

void trecere(char sens[], int nlinii)
{
    char a[5000];
    char *p=strtok(sens, ",");
    for(int i=1; i<=8; i++)
    {
        strcpy (a, p);
        inserare(a, nlinii, i);
        p=strtok(NULL, ",");
    }
}

void adaugare(char sir[])
{
    trecere(sir, nrlinii);
    nrlinii++;
}

void citire()
{
    char sir[200];
    while(!fin.eof())
    {
        fin.getline(sir, 200);
        if(strlen(sir))
            adaugare(sir);
    }
    nrlinii--;
    fin.close();
}

void afisare_date()
{
    cout<<endl;
    for(int i=1; i<=nrlinii; i++)
        cout<<tabel[i].cod<<' '<<tabel[i].zi<<'/'<<tabel[i].luna<<'/'<<tabel[i].an<<' '<<tabel[i].ora<<' '<<tabel[i].temperatura<<' '<<tabel[i].presiune<<' '<<tabel[i].precipitatii<<"\n";
    cout<<"\n";
}


void selector(int d){
    cout << "1 afisare informatii" << endl<<"2 introducere date noi"<<endl<<"3 stergere date"<<endl<<"4 temperatura medie"<<endl<<"5 datele cu temperatura maxima"<<endl<<"6 datele ordonate descrescator dupa temperatura"<<endl<<"7 media precipitatiilor an curent"<<endl<<"8 lista temperaturi si precipitatii"<<endl<<"9 temperatura depasita"<<endl<<"0 zile cu minim de presiune atmosferica"<<endl<<"10 iesire"<<endl<<endl;
    cin>>d;
    switch(d)
    {
    case 1:
        afisare_date();
        break;
    case 2:
        cout<<"WIP"<<endl;
        //introducere_date();
        //nu e functional, stergea intreg fisierul, verific in alta zi
        break;
    case 3:
        cout<<"WIP"<<endl;
        break;
    case 4:
        temp_medie();
        break;
    case 5:
        temp_mxm();
        break;
    case 6:
        cout<<"WIP"<<endl;
        break;
    case 7:
        cout<<"WIP"<<endl;
        break;
    case 8:
        cout<<"WIP"<<endl;
        break;
    case 9:
        temp_dep();
        break;
    case 10:
        jale=0;
        break;
    case 0:
        pres_min();
        break;
    }
}


int main()
{
    int d;
    citire();
    while(jale!=0){
        selector(d);
    }
    return 0;
}
