#include<iostream>
#include<string>
using namespace std;
class Rezervare {
private:
    static int numarRezervari;
    const int idRezervare;
    string oaspete;
    int numarNopti;
    double* preturiNopti;
public:
    Rezervare() : idRezervare(++numarNopti){
        this->oaspete="Anonim";
        this->numarNopti=0;
        this->preturiNopti=nullptr;
    }
    Rezervare(string oaspete, int numarNopti, double* preturiNopti):idRezervare(++numarNopti){
    if (oaspete.size()>0)
    this->oaspete=oaspete;
        else this->oaspete="Anonim";
        if (numarNopti>0 && preturiNopti!=nullptr) {
            this->numarNopti=numarNopti;
            this->preturiNopti = new double[numarNopti];
            for (int i=0;i<numarNopti;i++)
                if (preturiNopti[i]>0) {
                    this->preturiNopti[i]=preturiNopti[i];
                } else {
                    this->preturiNopti[i]=1;
                }
        }
        else {
            this->numarNopti=0;
            this->preturiNopti=nullptr;
        }
    }
    ~Rezervare() {
        delete [] this->preturiNopti;
    }
    Rezervare(const Rezervare& r) : idRezervare(++numarNopti) {
        this->oaspete=r.oaspete;
        this->numarNopti=r.numarNopti;
        if (r.preturiNopti!=nullptr) {
            this->preturiNopti=new double[r.numarNopti];
            for (int i=0;i<numarNopti;i++)
                this->preturiNopti[i]=r.preturiNopti[i];
        } else
            this->preturiNopti=nullptr;
    }
    Rezervare& operator=(const Rezervare& r) {
        if (this!=&r) {
            delete [] this->preturiNopti;
            this->oaspete=r.oaspete;
            this->numarNopti=r.numarNopti;
            if (r.preturiNopti!=nullptr) {
                this->preturiNopti=new double[r.numarNopti];
                for (int i=0;i<numarNopti;i++)
                    this->preturiNopti[i]=r.preturiNopti[i];
            } else
                this->preturiNopti=nullptr;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Rezervare& r) {
        out<<"Rezervare: "<<r.idRezervare<<", oaspete"<<r.oaspete<<endl;
        for (int i=0;i<r.numarNopti;i++)
            out<<" "<<r.preturiNopti[i];
        out<<endl;
        return out;
    }
    double operator[](int index){
    if (index<0 || index>=this->numarNopti) {
        return -1;
    } else {
        return this->preturiNopti[index];
     }
    }
    operator double() {
        double suma=0;
        for (int i=0;i<numarNopti;i++)
            suma+=this->preturiNopti[i];
        return suma;
    }
    int getIdRezervare() {
        return this->idRezervare;
    }
    static int getgetNumarRezervari() {
        return numarRezervari;
    }
};
int Rezervare::numarRezervari=0;
int main() {
    Rezervare r1;
    double v[]={2, -3, 5};
    Rezervare r2("Ion", 3, v);
    Rezervare r3=r2;
    r2=r1;
    r1=r1;
    cout<<r2;
    cout<<r2[0]<<" "<<r2[10]<<endl;
    cout<<(double)r2<<endl;
    cout<<r3;
    return 0;
}
