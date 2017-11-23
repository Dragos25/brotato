#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

int litere;
int nr_cuvinte;
int greseli=0;
char cuvant_ales[20];
int v[20];
ifstream f("cuvinte.txt");

void cuvant()
{
    srand(time(NULL));
    int i=rand()%nr_cuvinte;
    int j=0;

    char aux[20];
    while(j<i){
        f>>aux;
        j++;
    }
    f>>cuvant_ales;

}

void afisare_cuvant()
{
    for(int i=0;i<litere;i++)
        if(v[i]==1) cout<< cuvant_ales[i]<<" ";
        else cout <<" _ ";
    cout<<endl<<endl;
}

int verificare_sfarsit()
{
    for(int i=0;i<litere;i++)
        if(v[i]==0) return 1;  //daca mai este cel putin o litera neghicita returneaza 1
    return 0;
}

int introducere_litera()
{
    char t;
    afisare_cuvant();
    cout<<"Alege o litera ";
    cin>>t; t=tolower(t);
    int ok=0;
    for(int i=0;i<litere;i++)
    if(v[i]==0 && cuvant_ales[i]==t) {ok=1; v[i]=1;}
    if(ok==0) {
            greseli++;
            cout<<"Imi pare rau, acea litera nu se afla in cuvant sau ai ales-o deja."<<endl;
            cout<<"Ai "<<greseli<<" greseli."<<endl;
    }

    afisare_cuvant();

}

void init() //prima si ultima litera sunt afisate
{           // de asemnea literele identice cu prima si ultima sunt afisate
        v[0]=1;v[litere-1]=1;
        for(int i=1;i<litere;i++)
            if(cuvant_ales[i]==cuvant_ales[0] || cuvant_ales[i]==cuvant_ales[litere-1])
            v[i]=1;
}

void start_joc()
{

    init();
    while(greseli<3 && verificare_sfarsit())
        if(verificare_sfarsit()) introducere_litera();
    if (greseli==3) cout<<"Imi pare rau, ai pierdut! Cuvantul era "<<cuvant_ales;
    else cout<<"Felicitari, ai castigat!"<<endl<<"Cuvantul era "<<cuvant_ales<<endl<<"Ai avut "<<greseli<<" greseli";




}

int main()
{
    f>>nr_cuvinte;
    cuvant();
    litere=strlen(cuvant_ales);
    start_joc();







}
