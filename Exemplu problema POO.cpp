#include<iostream>
#include<cstring>
using namespace std;
enum Categorie {ALIMENTAR, ELECTRONIC, VESTIMENTAR};
class Produs {
    private:
    char* denumire;
    int stoc;
    int nrAprovizionari;
    int* cantitate;
    Categorie categorie;
    public:
    Produs() {
        this->denumire=nullptr;
        this->stoc=0;
        this->nrAprovizionari=0;
        this->cantitate=nullptr;
        this->categorie=ALIMENTAR;
    }
    //Constructorul cu validare
    Produs(const char* denumire, int nrAprovizionari, int* cantitate, Categorie categorie) {
        this->denumire=new char[strlen(denumire)+1];
        strcpy(this->denumire, denumire);
        this->nrAprovizionari=nrAprovizionari;
        this->categorie=categorie;
        this->cantitate=new int[nrAprovizionari];
        this->stoc=0;
        for (int i=0;i<nrAprovizionari;i++) {
            if (cantitate[i]>0 && cantitate[i]<=100) {
                this->cantitate[i]=cantitate[i];
            }else
                this->cantitate[i]=1;
            this->stoc=this->stoc+cantitate[i];
        }
    }
    ~Produs() {
        delete [] this->denumire;
        delete [] this->cantitate;
    }
    void afisare() {
        cout << "Denumire: " << (this->denumire != nullptr ? this->denumire : "-") << endl;
        cout << "Stoc: " << this->stoc << endl;
        cout << "Nr aprovizionari: " << this->nrAprovizionari << endl;
        cout << "Cantitati:";
        for (int i = 0; i < this->nrAprovizionari; i++) {
            cout << " " << this->cantitate[i];
        }
        cout << endl;
        switch (this->categorie) {
            case ALIMENTAR: cout << "Categorie: Alimentar" << endl; break;
            case ELECTRONIC: cout << "Categorie: Electronic" << endl; break;
            case VESTIMENTAR: cout << "Categorie: Vestimentar" << endl; break;
        }
    }
};
int main() {
    int cant[]={50, 200, 30};
    Produs p("Laptop", 3, cant, ELECTRONIC);
    p.afisare();
    return 0;
}
//
// Created by Tirteata Daria-Miruna on 03.11.2026.
//
