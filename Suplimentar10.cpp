#include<iostream>
#include<string>
using namespace std;
class Angajat {
private:
    static int numarAngajati;
    const int idAngajat;
    string nume;
    int numarLuni;
    double* salarii;
public:
    Angajat():idAngajat(++numarAngajati) {
        this->nume="Anonim";
        this->numarLuni=0;
        this->salarii=nullptr;
    }
    Angajat(string nume, int numarLuni, double* salarii):idAngajat(++numarAngajati) {
        if (nume.size()>0) {
            this->nume=nume;
        } else {
            this->nume="Anonim";
        }
        if (numarLuni>0 && salarii!=nullptr) {
            this->numarLuni=numarLuni;
            this->salarii=new double[numarLuni];
            for (int i=0;i<numarLuni;i++)
                if (salarii[i]>0) {
                    this->salarii[i]=salarii[i];
                } else {
                    this->salarii[i]=1;
                }
        } else {
            this->numarLuni=0;
            this->salarii=nullptr;
        }
    }
    ~Angajat() {
        delete[] this->salarii;
    }
    Angajat(const Angajat& a):idAngajat(++numarAngajati) {
        this->nume=a.nume;
        this->numarLuni=a.numarLuni;
        if (a.salarii!=nullptr) {
            this->salarii=new double[a.numarLuni];
            for (int i=0;i<a.numarLuni;i++)
                this->salarii[i]=a.salarii[i];
        } else {
            this->salarii=nullptr;
        }
    }
    Angajat& operator=(const Angajat& a) {
        if (this!=&a) {
            delete[] this->salarii;
            this->nume=a.nume;
            this->numarLuni=a.numarLuni;
            if (a.salarii!=nullptr) {
                this->salarii=new double[a.numarLuni];
                for (int i=0;i<a.numarLuni;i++)
                    this->salarii[i]=a.salarii[i];
            } else {
                this->salarii=nullptr;
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Angajat& a) {
        out<<"Angajat:"<<a.idAngajat<<", nume: "<<a.nume<<endl;
        for (int i=0;i<a.numarLuni;i++)
            out<<" "<<a.salarii[i];
        out<<endl;
        return out;
    }
    bool operator==(const Angajat& a) {
        if (this->nume!=a.nume) return false;
        if (this->numarLuni!=a.numarLuni) return false;
        for (int i=0;i<this->numarLuni;i++)
            if (this->salarii[i]!=a.salarii[i]) return false;
        return true;
    }
    ///Realocare
    Angajat& operator+=(double nou) {
        if (nou <= 0) return *this;
        double* aux=new double[this->numarLuni+1];
        for (int i=0;i<this->numarLuni;i++)
            aux[i]=this->salarii[i];
        aux[this->numarLuni]=nou;
        delete[] this->salarii;
        this->salarii=aux;
        this->numarLuni++;

        return *this;
    }
};

int Angajat::numarAngajati=0;
int main() {
    Angajat a1;
    double a[]={2, -3, 5};
    Angajat a2("Popescu", 3, a);
    Angajat a3=a2;
    Angajat a4;
    a4=a3;
    a4=a4;
    cout<<a2;
    cout<<(a2==a3)<<endl;
    cout<<(a2==a1)<<endl;
    a2+=2500;
    cout<<a2;
    a2+=-10;
    cout<<a2;
    cout<<(a3==a2)<<endl;
    cout<<a3;
    return 0;
}

