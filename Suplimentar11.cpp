#include<iostream>
#include<string>
using namespace std;
class Telefon {
private:
    static int numarTelefoane;
    const int idTelefon;
    string model;
    int numarPreturi;
    double* preturi;
public:
    Telefon():idTelefon(++numarTelefoane) {
        this->model="Anonim";
        this->numarPreturi=0;
        this->preturi=nullptr;
    }
    Telefon(string model, int numarPreturi, double* preturi):idTelefon(++numarTelefoane) {
       if (model.size()>0) {
           this->model=model;
       } else {
           this->model="Anonim";
       }
    }
       if (numarPreturi>0 && preturi!=nullptr) {
        this->numarPreturi=numarPreturi;
        this->preturi=new double[numarPreturi];
        for (int i=0;i<numarPreturi;i++)
            if (preturi[i]>0) {
                this->preturi[i]=preturi[i];
            } else {
                this->preturi[i]=1;
            }
    } else {
        this->numarPreturi=0;
        this->preturi=nullptr;
    }
    ~Telefon() {
        delete[] this->preturi;
    }
    Telefon(const Telefon& t):idTelefon(++numarTelefoane) {
        this->model=t.model;
        this->numarPreturi=t.numarPreturi;
        if (t.preturi!=nullptr) {
            this->preturi=new double[t.numarPreturi];
            for (int i=0;i<t.numarPreturi;i++)
                this->preturi[i]=t.preturi[i];
        } else {
            this->preturi=nullptr;
        }
    }
    Telefon& operator=(const Telefon& t) {
        if (this!=&t) {
            delete[] this->preturi;
            this->model=t.model;
            this->numarPreturi=t.numarPreturi;
            if (t.preturi!=nullptr) {
                this->preturi=new double[t.numarPreturi];
                for (int i=0;i<t.numarPreturi;i++)
                    this->preturi[i]=t.preturi[i];
            } else {
                this->preturi=nullptr;
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Telefon& t) {
        out<<"Telefon: "<<t.idTelefon<<", preturi: "<<t.numarPreturi<<endl;
        for (int i=0;i<t.numarPreturi;i++)
            out<<" "<<t.preturi[i];
        out<<endl;
        return out;
    }
    ///operator!: returnează true dacă telefonul nu are prețuri în istoric.
    bool operator!() {
        return this->numarPreturi==0;
    }
    ///operator++ (prefix): crește cu 1 toate prețurile din vector.
    Telefon& operator++() {
        for (int i=0;i<this->numarPreturi;i++) {
            this->preturi[i]++;
            return *this;
        }
    }
    ///operator+ între un telefon și un număr (telefon + 50): returnează un telefon nou, cu toate prețurile mărite cu valoarea dată. Telefonul inițial rămâne neschimbat.
    Telefon& operator+(double preturi) {
        Telefon aux=*this;
        aux.preturi=new double[aux.numarPreturi];
        for (int i=0;i<aux.numarPreturi;i++) {
            aux.preturi[i]=this->preturi[i]+valoare;
        }
        return aux;
    }

};
int Telefon::numarTelefoane==0;
int main() {
    Telefon t1;
    double t[]={2000,-50,3500};
    Telefon t2("Apple",2,t);
    Telefon t3=t2;
    cout<<!(t1)<<endl;
    cout<<!(t2)<<endl;
    t1=t2;
    t1=t1;
    cout<<t2;
    cout<<!(t1)<<endl;
    ++t2;
    cout<<t2;
    cout<<t3;
    Telefon t4=t2+50;
    cout<<t4;
    cout<<t2;
    return 0;

}
