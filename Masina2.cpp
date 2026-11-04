#include<iostream>
#include<cstring>
using namespace std;
class Masina {
private:
    char* marca;
    int anFabricatie;
    float pret;
    bool esteElectrica;
public:
    Masina() {
        this->marca=nullptr;
        this->anFabricatie=0;
        this->pret=0;
        this->esteElectrica=false;
    }
    Masina(const char* marcaNoua, int anFabricatie, float pret, bool esteElectrica) {
        this->marca=new char[strlen(marcaNoua)+1];
        strcpy(this->marca, marcaNoua);
        this->anFabricatie=anFabricatie;
        this->pret=pret;
        this->esteElectrica=esteElectrica;
    }
    ~Masina() {
        delete [] this->marca;
    }
    Masina(const Masina& m) {
        this->anFabricatie=m.anFabricatie;
        this->pret=m.pret;
        this->esteElectrica=m.esteElectrica;
        if (m.marca!=nullptr) {
            this->marca=new char[strlen(m.marca)+1];
            strcpy(this->marca, m.marca);
        }
        else {
            this->marca=nullptr;
        }
    }
    Masina& operator=(const Masina& m) {
        if (this!=&m) {
            delete [] this->marca;
            this->anFabricatie=m.anFabricatie;
            this->pret=m.pret;
            this->esteElectrica=m.esteElectrica;
            if (m.marca!=nullptr) {
                this->marca=new char[strlen(m.marca)+1];
                strcpy(this->marca, m.marca);
            }
            else {
                this->marca=nullptr;
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
    char* getMarca() {
        return this->marca;
    }
    int getAnFabricatie() {
        return this->anFabricatie;
    }
    float getPret() {
        return this->pret;
    }
    bool getEsteElectrica() {
        return this->esteElectrica;
    }
    void setMarca(const char* marcaNoua) {
        delete [] this->marca;
        this->marca=new char[strlen(marcaNoua)+1];
        strcpy(this->marca, marcaNoua);
    }
    void setPret(float pretNou) {
        this->pret=pretNou;
    }
    void afisare(){
        if (this->marca!=nullptr) {
            cout<<"Marca: "<<this->marca<<endl;
        }
        cout<<"An: "<<this->anFabricatie<<endl;
        cout<<"Pret: "<<this->pret<<endl;
        cout<<"Electrica: "<<(this->esteElectrica ? "DA" : "NU")<<endl;
    }
    void afisareMasina(Masina m) {
        m.afisare();
    }
};
    float sumaPreturi(Masina* v, int n) {
        float suma=0;
        for (int i=0;i<n;i++)
       suma=suma+v[i].getPret();
        return suma;
    }
    void marestePreturi(Masina* v, int n, float valoare) {
        for (int i=0;i<n;i++) {
            v[i]=v[i]+valoare;
        }
    }
    Masina celMaiIeftina(Masina* v, int n) {
        Masina minima=v[0];
        for (int i=1;i<n;i++) {
            if (v[i].getPret()<minima.getPret()) {
                minima=v[i];
            }
        }
        return minima;
    }
    Masina ceaMaiScumpa(Masina* v, int n) {
        Masina maxima=v[0];
        for (int i=1;i<n;i++) {
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
    int numaraNeelectrice(Masina* v, int n) {
        int nr=0;
        for (int i=0;i<n;i++) {
            if (!v[i])
                nr++;
        }
        return nr;
    }
//
// Created by Tirteata Daria-Miruna on 03.11.2026.
//
