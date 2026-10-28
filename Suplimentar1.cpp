#include<iostream>
using namespace std;
class Telefon {
private:
    int memorie;
    float pret;
    bool areDualSim;
public:
    ///un constructor implicit
    Telefon() {
        this->memorie=64;
        this->pret=1000;
        this->areDualSim=false;
    }
    ///un constructor cu parametri
    Telefon(int memorie, float pret, bool areDualSim) {
        this->memorie=memorie;
        this->pret=pret;
        this->areDualSim=areDualSim;
    }
    int getMemorie() {
        return this->memorie;
    }
    float getPret() {
        return this->pret;
    }
    bool getAreDualSim() {
        return this->areDualSim;
    }
    void setPret(float pret) {
        if (pret>0) {
            this->pret=pret;
        }
    }
    float pretPeGB() {
        if (this->memorie==0) {
            return 0;
        }
        return this->pret/this->memorie;
    }

void afisare() {
        cout<<"Memorie= "<<this->memorie<<endl;
        cout<<"Pret "<<this->pret<<endl;
        cout << "Dual SIM: " << (this->areDualSim ? "DA" : "NU") << endl;
    }
};
int main() {
    Telefon t1;
    Telefon t2(128,2500,true);
    cout << "Telefon 1:" << endl;
    t1.afisare();
    cout << "Telefon 2:" << endl;
    t2.afisare();
    t2.setPret(3000);
    t2.setPret(-50);
    cout << "Dupa setPret, t2 are pretul " << t2.getPret() << endl;
    cout << "Pret pe GB t1: " << t1.pretPeGB() << endl;
    cout << "Pret pe GB t2: " << t2.pretPeGB() << endl;
    return 0;
}