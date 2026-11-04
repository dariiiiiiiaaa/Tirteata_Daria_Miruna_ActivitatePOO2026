#include<iostream>
using namespace std;
class Carte {
private:
    int nrPagini;
    float pret;
    bool esteNoua;
public:
    //Constructor implicit
    Carte() {
        this->nrPagini=300;
        this->pret=50;
        this->esteNoua=true;
    }
    //Constructor cu parametri
    Carte(int nrPagini, float pret, bool esteNoua) {
        this->nrPagini=nrPagini;
        this->pret=pret;
        this->esteNoua=esteNoua;
    }
    int getNrPagini() {
        return this->nrPagini;
    }
    float getPret() {
        return this->pret;
    }
    bool getEsteNoua() {
        return this->esteNoua;
    }void setPret(float pretNou) {
        if (pretNou>0) {
            this->pret=pretNou;
        }
    }
    float pretPePagina() {
        if (this->nrPagini==0) {
            return 0;
        }
        return this->pret/this->nrPagini;
    }
    void afisare() {
        cout<<"NrPagini "<<this->nrPagini<<endl;
        cout<<"Pret "<<this->pret<<endl;
        cout<<"EsteNoua "<<(this->esteNoua ? "DA" : "NU")<<endl;
    }
};
int main() {
    Carte c1;
    Carte c2(400, 45, true);
    cout<<"Carte 1 "<<endl;
    c1.afisare();
    c2.setPret(60);    // valid
    c2.setPret(-5);    // invalid, ramane 60
    cout << "Pret c2 dupa setPret: " << c2.getPret() << endl;

    cout << "Pret pe pagina c1: " << c1.pretPePagina() << endl;
    cout << "Pret pe pagina c2: " << c2.pretPePagina() << endl;
    return 0;
}