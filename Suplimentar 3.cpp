#include<iostream>
#include<cstring>
using namespace std;
class Masina {
    private:
    char* marca;
    int anFabricatie;
    float pret;
    bool electrica;
    public:
    Masina() {
        this->marca=nullptr;
        this->anFabfricatie=0;
        this->pret=0;
        this->electrica=false;
    }
    Masina(const char* marcaNoua, int anFabricatie, float pret, bool electrica) {
        this->marca=new char[strlen(marcaNoua)+1];
        strcpy(this->marca, marcaNoua);
        this->anFabricatie=anFabricatie;
        this->pret=pret;
        this->electrica=electrica;
    }
    ~Masina() {
        delete [] this->marca;
    }
    Masina(const Masina& m) {
        this->anFabricatie=m.anFabricatie;
        this->pret=m.pret;
        this->electrica=m.electrica;
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
             delete []this->marca;
             this->anFabricatie=m.anFabricatie;
             this->pret=m.pret;
             this->electrica=m.electrica;
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
char* getMarca() {
        return this->marca;
    }
    int getAnFabricatie() {
        return this->anFabricatie;
    }
    float getPret() {
        return this->pret;
    }
    bool getelectrica() {
        return this->electrica;
    }
    void setMarca(const char* marcaNoua) {
        delete[] this->marca;
        this->marca=new char[strlen(marcaNoua)+1];
        strcpy(this->marca, marcaNoua);
    }
    void setPret(float pretNou) {
        this->pret=pretNou;
    }
    void afisare() {
        if (this->marca!=nullptr) {
            cout<<"Marca: "<<this->marca<<endl;
        }
        cout<<"An: "<<this->anFabricatie<<endl;
        cout<<"Pret: "<<this->pret<<endl;
        cout<<"Electrica: "<<(this->electrica ? "DA" : "NU")<<endl;
    }
    }
void afisareMasina(Masina m) {
    m.afisare();

}

// Created by Tirteata Daria-Miruna on 02.11.2026.
//Operatorul --
    Masina operator-(float valoare) {
    Masina aux=*this;
    aux.pret=aux.pret-valoare;
    return aux;
}

