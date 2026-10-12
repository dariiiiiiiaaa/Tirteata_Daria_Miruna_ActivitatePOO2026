#include <iostream>
#include<cstring>
using namespace std;
struct Telefon {
    float diagonala;
    int memorieGB;
    bool dualSim;
    char* model;
};
Telefon citireTelefon() { // citirea caracteristicilor unui telefon
    char numeModel[50];
    Telefon t;
    cout << "diagonala (inch): "; cin >> t.diagonala;
    cout << "memorie (GB): "; cin >> t.memorieGB;
    cout << "Dual SIM?: (0/1) "; cin >> t.dualSim;
    cout << "model: "; cin >> numeModel;
    t.model = new char[strlen(numeModel) + 1];
    strcpy(t.model, numeModel);
    return t;
}
void afisareTelefon(Telefon t) {
    cout << "diagonala: " << t.diagonala << " inch" << endl;
    cout << "memorie: " << t.memorieGB << " GB" << endl;
    cout << "dual SIM: " << t.dualSim << endl;
    cout << "model: " << t.model << endl;
}

void modificareMemorie(Telefon* t, int memorieNoua) {
    t->memorieGB = memorieNoua;
}
int calculeazaMemorieTotala(Telefon* telefoane, int nrTelefoane) {
    int suma = 0;
    for (int i = 0; i < nrTelefoane; i++) {
        suma += telefoane[i].memorieGB;
    }
    return suma;
}
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    int nrTelefoane = 3;
    Telefon* telefoane = new Telefon[nrTelefoane];

    for (int i = 0; i < nrTelefoane; i++) {
        telefoane[i] = citireTelefon();
    }
    for (int i = 0; i < nrTelefoane; i++) {
        afisareTelefon(telefoane[i]);
    }

    cout << "Memoria totala este: "
         << calculeazaMemorieTotala(telefoane, nrTelefoane) << " GB" << endl;

    // eliberare memorie
    for (int i = 0; i < nrTelefoane; i++) {
        delete[] telefoane[i].model;
    }
    delete[] telefoane;
    return 0;
}