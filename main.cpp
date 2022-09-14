#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class produs
{
private:

    int nr_stoc;
    bool restock = 0;
    char tip;
    char* nume_producator;
    char nume[100];
    float pret_v;
    int* codbare;
    double pret_c;
    static int nr_produse_diferite;
    const char magazin[10] = "MegaImage";
public:
    produs(const int a, char b, char *c, char d[100], float e, int* f, double g) // folosit pentru produse la care stim toate detalile
    {
        nr_stoc = a;
        if (nr_stoc < 10) restock = 1;
        tip = b;
        nume_producator =(char*) malloc(sizeof(char) * (strlen(c)+1));
        strcpy(nume_producator, c);
        strcpy(nume, d);
        pret_v = e;
        codbare =(int*) malloc(sizeof(int) * 13); //Consideram codul de bare ca find mereu de tip EAN-13

        for (int i = 0; i < 13; i++)
        {
            codbare[i] = f[i];
        }
        pret_c = g;
        nr_produse_diferite++;
    }

    produs(const int a, char b, char d[100], float e, int* f, double g) // folosit pentru produse la care stim toate detalile inafara de producator
    {
        nr_stoc = a;
        if (nr_stoc < 10) restock = 1;
        tip = b;
        nume_producator =(char*) malloc(sizeof(char) * 11);
        strcpy(nume_producator, "necunoscut");
        strcpy(nume, d);
        pret_v = e;
        codbare =(int*) malloc(sizeof(int) * 13); //Consideram codul de bare ca find mereu de tip EAN-13

        for (int i = 0; i < 13; i++)
        {
            codbare[i] = f[i];
        }
        pret_c = g;
        nr_produse_diferite++;
    }

    produs()
    {
        nr_stoc = 0;
        restock = 0;
        tip = 0;
        nume_producator = (char*)malloc(sizeof(char));
        strcpy(nume_producator, "-");
        strcpy(nume, "-");
        pret_v = 0;
        pret_c = 0;
        codbare = (int*)malloc(sizeof(int));
        codbare[0] = 0;
    }

    produs(produs& copiere)
    {
        this->nr_stoc = copiere.nr_stoc;
        this->restock = copiere.restock;
        this->tip = copiere.tip;
        this->nume_producator = (char*)malloc(sizeof(char) * (strlen(copiere.nume_producator) + 1));
        strcpy(this->nume_producator, copiere.nume_producator);
        strcpy(this->nume, copiere.nume);
        this->codbare = (int*)malloc(sizeof(int) * 13);
        for (int i = 0; i < 13; i++)
        {
            this->codbare[i] = copiere.codbare[i];
        }
        this->pret_c = copiere.pret_c;
        this->pret_v = copiere.pret_v;

        this->nr_produse_diferite++;
    }
    ~produs()
    {
        nr_produse_diferite--;
        delete[] this->codbare;
        delete[] this->nume_producator;
        cout << "te dirigjhu";
    }

};
int produs::nr_produse_diferite = 0;

class angajat
{
public:

    int nr_ture;
    bool gender;
    char rol;
    char* nume_manager;
    char nume[100];
    float salariu_h;
    int* data_n;
    double bonus_tn;
    //const, static
};

int main()
{
    produs a;

}
