#include<iostream>
using namespace std;

class Prajitura {
private:
    char* denumire;
    float pret;
    int cantitate;
    bool dePost;
    int nrIngrediente;
    string* ingrediente;
    const int id;
    static int cnt;
public:
    Prajitura(const Prajitura& p):id(cnt++) {
        //implementare inline
        this->denumire = new char[strlen("Tiramisu") + 1];
        strcpy(denumire, "Tiramisu");
        this->pret = 15;
        this->cantitate = 250;
        this->dePost = true;
        this->nrIngrediente = 3;
        this->ingrediente = new string[this->nrIngrediente];
        this->ingrediente[0] = "Piscoturi";
        this->ingrediente[1] = "Vanilie";
        this->ingrediente[2] = "Cafea";

    }


    Prajitura(const char* denumire, float pret) {
        //implementare inline
        this->denumire = new char[strlen("Tiramisu") + 1];
        strcpy(this->denumire, denumire);
        this->pret = 15;
        this->cantitate = 250;
        this->dePost = true;
        this->nrIngrediente = 3;
        this->ingrediente = new string[this->nrIngrediente];
        this->ingrediente[0] = "Piscoturi";
        this->ingrediente[1] = "Vanilie";
        this->ingrediente[2] = "Cafea";
    }
    //seminar4
    Prajitura(const Prajitura& p) {
        this->denumire = new char[strlen(p.denumire) + 1];
        strcpy(this->denumire, p.denumire);

        this->pret = p.pret;
        this->cantitate = p.cantitate;
        this->dePost = p.dePost;
        this->nrIngrediente = p.nrIngrediente;

        this->ingrediente = new string[this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->ingrediente[i] = p.ingrediente[i];
        }
    }


    ~Prajitura();//declarare constructor
    int getCantitate() {
        return this->cantitate;
    }

    int getnrIngrediente() {
        return this->ingrediente;
    }

    float getPret() {
        return this->pret;
    }
    static int getCnt() {
        return this->cnt;
    }

    void afisare() {
        cout << "Denumire: " << this->denumire << endl;
        cout << "Pret: " << this->pret << endl;
        cout << "Cantitate: " << this->cantitate << endl;
        cout << "De post? (0/1): " << (this->dePost ? "Da" : "Nu") << endl;
        cout << "Numar ingrediente: " << this->nrIngrediente << endl;
        cout << "Ingredientele sunt: ";
        for (int i = 0; i < this->nrIngrediente; i++) {
            cout << this->ingrediente[i] << "; ";
        }
        cout << endl;
    }
    float costMediuGram() {
        if (cantitate == 0) {
            return 0;
        }
        else {
            return this->pret / this->cantitate;
        }
    }

    void modificaDenumire(const char* denumire) {
        delete this->denumire;

        this->denumire = new char[strlen(denumire) + 1];
        strcpy(this->denumire, denumire);
    }
};
int Prajitura::cnt = 100;
Prajitura:~Prajitura(); {
delete[] this->denumire;
delete[] this->ingrediente;
}

float calculeazaCantitateaTotala(Prajitura* prajituri, int nr_prajituri) {
    float greutate = 0;
    for (int p = 0; p < nr_prajituri; p++) {
        greutate += prajituri[p].getCantitate();
    }
    return greutate;
}

float calculeazaPretPerIngredient(Prajitura p) {
    if (p.getnrIngrediente() != 0) {
        return p.getPret() / p.getnrIngrediente();
    }
    return 0;
}