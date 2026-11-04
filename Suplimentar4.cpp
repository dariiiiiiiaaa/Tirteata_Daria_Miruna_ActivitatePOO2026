#include<iostream>
#include<string>
using namespace std;
class ContBancar {
private:
    static int numarConturi;
    const int idCont;
    string titularCont;
    double* istoricTranzactii;
    int numarTranzactii;
public:
    ContBancar() : idCont(++numarConturi) {
        this->titularCont="Anonim";
        this->numarTranzactii=0;
        this->istoricTranzactii=nullptr;
    }
    ContBancar(string titularCont, int nrTranzactii, double* tranzactii) : idCont(++numarConturi) {
        if (titularCont.size()>0) {
            this->titularCont=titularCont;
        }else {
            this->titularCont="Anonim";
        }
        if (nrTranzactii>0 && tranzactii!=nullptr) {
            this->numarTranzactii=nrTranzactii;
            this->istoricTranzactii=new double[numarTranzactii];
            for (int i=0;i<nrTranzactii;i++) {
                this->istoricTranzactii[i]=tranzactii[i];
            }
        } else {
            this->numarTranzactii=0;
            this->istoricTranzactii=nullptr;
        }
    }
    ~ContBancar() {
        delete[] this->istoricTranzactii;
    }
    //Constructor de copiere
    ContBancar(const ContBancar& c) : idCont(++numarConturi) {
        this->titularCont=c.titularCont;
        this->numarTranzactii=c.numarTranzactii;
        if (c.istoricTranzactii!=nullptr) {
            this->istoricTranzactii=new double[c.numarTranzactii];
            for (int i=0;i<c.numarTranzactii;i++) {
                this->istoricTranzactii[i]=c.istoricTranzactii[i];
            }
        } else {
            this->istoricTranzactii=nullptr;
        }
    }
    //Operatorul =
    ContBancar& operator=(const ContBancar& c) {
        if (this!=&c) {
            delete[] this->istoricTranzactii;
            this->titularCont=c.titularCont;
            this->numarTranzactii=c.numarTranzactii;
            if (c.istoricTranzactii!=nullptr) {
                this->istoricTranzactii=new double[c.numarTranzactii];
                for (int i=0;i<c.numarTranzactii;i++) {
                    this->istoricTranzactii[i]=c.istoricTranzactii[i];
                }
            } else {
                this->istoricTranzactii=nullptr;
            }
        }
        return *this;
    }
    //Operatorul <<
    friend ostream& operator<<(ostream& out, const ContBancar& c) {
        cout<<"Cont: "<<c.idCont<<", titular: "<<c.titularCont<<endl;
        cout<<"Tranzactii ("<<c.numarTranzactii<<"):";
        for (int i=0;i<c.numarTranzactii;i++) {
            out<<" "<<c.istoricTranzactii[i];
        }
        out<<endl;
        return out;
    }
    //Operatorul []
    double operator[](int index) {
        if (index<0 || index>=this->numarTranzactii) {
            return -1;
        }
        return this->istoricTranzactii[index];
    }
    //Operatorul cast la double:soldul
    operator double() {
        double suma=0;
        for (int i=0;i<this->numarTranzactii;i++) {
            suma+=this->istoricTranzactii[i];
        }
        return suma;
    }
    int getId() {
        return this->idCont;
    }
    static int getNumarConturi() {
        return numarConturi;
    }
};
int ContBancar::numarConturi=0;
int main() {
    ContBancar c1;
    double t[]={100, -20, 50.5};
    ContBancar c2("Ionescu",3, t);
    ContBancar c3("Popescu", 0, nullptr);
    cout<<c1.getId()<<" "<<c2.getId()<<" "<<c3.getId()<<" "<<endl;
    cout<<ContBancar::getNumarConturi()<<endl;
    cout<<c2;
    cout<<c2[0]<<" "<<c2[10]<<endl;
    double sold=(double)c2;
    cout<<"Sold: "<<sold<<endl;
    return 0;
}