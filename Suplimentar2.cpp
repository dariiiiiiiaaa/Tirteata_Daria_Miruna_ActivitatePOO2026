#include<iostream>
#include<cstring>
using namespace std;
class Carte {
private:
    char* titlu;
    int nrPagini;
    float pret;
    bool imprumutata;
public:
    Carte() {
        this->titlu=nullptr;
        this->nrPagini=0;
        this->pret=0;
        this->imprumutata=false;
    }
    Carte(const char* titluNou, int nrPagini, float pret, bool imprumutata) {
        this->titlu = new char[strlen(titluNou) + 1];
        strcpy(this->titlu, titluNou);
        this->nrPagini=nrPagini;
        this->pret=pret;
        this->imprumutata=imprumutata;
    }
    ~Carte() {
        delete [] this->titlu;
    }
    //Constructorul de copiere
    Carte(const Carte& c) {
        this->nrPagini=c.nrPagini;
        this->pret=c.pret;
        this->imprumutata=c.imprumutata;
        if (c.titlu!=nullptr) {
            this->titlu=new char[strlen(c.titlu)+1];
            strcpy(this->titlu, c.titlu);
        }
        else {
            this->titlu=nullptr;
        }
    }
    //Operatorul =
    Carte& operator=(const Carte& c) {
        if (this!=&c) {
            delete[] this->titlu;
            this->nrPagini=c.nrPagini;
            this->pret=c.pret;
            this->imprumutata=c.imprumutata;
            if (c.titlu!=nullptr) {
                this->titlu=new char[strlen(c.titlu)+1];
                strcpy(this->titlu, c.titlu);
            }
            else {
                this->titlu=nullptr;
            }
        }
        return *this;
    }
    //Operatorul +
    Masina operator+(float valoare) {
        Masina aux=*this;
        aux.pret=aux.pret+valoare;
        return aux;
    }
    //Operatorul +=
    Masina& operator+=(float valoare) {
        this->pret=this->pret+valoare;
        return *this;
    }
    //Operatorul -
    Masina operator-(float valoare) {
        Masina aux=*this;
        aux.pret=aux.pret-valoare;
        return aux;
    }
    //Operatorul -=
    Masina& operator-=(float valoare) {
        this->pret=this->pret-valoare;
        return *this;
    }
    //Operatorul ==
    bool operator==(const Masina& alta) {
        return this->anFabricatie == alta.anFabricatie && this->pret == alta.pret;
    }
    //Operatorul !=
    bool operator!=(const Masina& alta) {
        return !(*this==alta);
    }
    //Operatorul !
    bool operator!() {
        return !this->esteElectrica;
    }

    char* getTitlu() {
        return this->titlu;
    }
    int getNrPagini() {
        return this->nrPagini;
    }
    float getPret() {
        return this->pret;
    }
    bool getImprumutata() {
        return this->imprumutata;
    }
    void setTitlu(const char* titluNou) {
        delete[] this->titlu;
        this->titlu=new char[strlen(titluNou)+1];
        strcpy(this->titlu, titluNou);
    }
    void setPret(float pretNou) {
        this->pret=pretNou;
    }
    void afisare() {
        if (this->titlu != nullptr) {
            cout << "Titlu: " << this->titlu << endl;
        }
        cout<<"Pagini: "<<this->nrPagini<<endl;
        cout<<"Pret: "<<this->pret<<endl;
        cout<<"Imprumutata: "<<(this->imprumutata ? "DA" : "NU")<<endl;
    }
    void afisareCarte(Carte c) {
        c.afisare();
    }
}
float sumaPreturi(Masina* v, int n) {
    Masina total;
    for (int i=0;i<n;i++) {
        total=total+v[i];
    }
    return total.getPret();
}
void marestePreturi(Masina* v, int n, float valoare) {
    for (int i=0;i<n;i++) {
        v[i]=v[i]+valoare;
    }
}
Masina celMaiIeftina(Masina* v, int n) {
    Masina minima=v[0];
    for (int i=0;i<n;i++) {
        if (v[i].getPret()<minima.getPret()) {
            minima=v[i];
        }
    }
    return minima;
}
Masina ceaMaiScumpa(Masina* v, int n) {
    Masina maxima=v[0];
    for (int i=0;i<n;i++) {
        if (v[i].getPret()>maxima.getPret()) {
            maxima=v[i];
        }
    }
    return maxima;
}
int numaraEgale(Masina* v, int n, const Masina& m) {
    int nr=0;
    for (int i=0;i<n;i++) {
        if (v[i]==m)
            nr++;
    }
    return nr;
}
int numaraNeelectrice(Masini* v, int n) {
    int nr=0;
    for (int i=0;i<n;i++) {
        if (!v[i])
            nr++;
    }
    return nr;
}

}
int main() {
    Carte c1;
    Carte c2("Ion", 360, 29.9, false);
    c2.setPret(35.5);
    Carte c3 = c2
    Carte c4;
    c4 = c2;
    afisareCarte(c2);
    c2.afisare();
    c1.afisare();
    return 0;
};
//
// Created by Tirteata Daria-Miruna on 02.11.2026.
//
*