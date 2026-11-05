#include<iostream>
#include<string>
using namespace std;
class Colet {
private:
    static int numarColete;
    const int idColet;
    string destinatar;
    int numarObiecte;
    double* greutatiObiecte;
public:
    Colet():idColet(++numarColete) {
        this->destinatar="Anonim";
        this->numarObiecte=0;
        this->greutatiObiecte=nullptr;
    }
    Colet(string destinatar, int numarObiecte, double* greutatiObiecte):idColet(++numarColete) {
        if (destinatar.size()>0) {
            this->destinatar=destinatar;
        } else this->destinatar="Anonim";
        if (numarObiecte>0 && greutatiObiecte!=nullptr) {
            this->numarObiecte=numarObiecte;
            this->greutatiObiecte=new double[numarObiecte];
            for (int i=0;i<numarObiecte;i++) {
                if (greutatiObiecte[i]>0) {
                    this->greutatiObiecte[i]=greutatiObiecte[i];
                } else {
                    this->greutatiObiecte[i]=1;
                }
            }
        } else {
            this->numarObiecte=0;
            this->greutatiObiecte=nullptr;
        }

    }
    ~Colet() {
        delete[] this->greutatiObiecte;
    }
    Colet(const Colet& c):idColet(++numarColete) {
        this->destinatar=c.destinatar;
        this->numarObiecte=c.numarObiecte;
        if (c.greutatiObiecte!=nullptr) {
            this->greutatiObiecte=new double[c.numarObiecte];
            for (int i=0;i<c.numarObiecte;i++)
                this->greutatiObiecte[i]=c.greutatiObiecte[i];
        } else {
            this->greutatiObiecte=nullptr;
        }
    }
    Colet& operator=(const Colet& c) {
        if (this!=&c) {
            delete[] this->greutatiObiecte;
            this->destinatar=c.destinatar;
            this->numarObiecte=c.numarObiecte;
            if (c.greutatiObiecte!=nullptr) {
                this->greutatiObiecte=new double[c.numarObiecte];
                for (int i=0;i<c.numarObiecte;i++)
                    this->greutatiObiecte[i]=c.greutatiObiecte[i];
            } else {
                this->greutatiObiecte=nullptr;
            }
        }
        return *this;
    }
    bool operator==(Colet& c) {
        if (this->destinatar!=c.destinatar) return false;
        if (this->numarObiecte!=c.numarObiecte) return false;
        for (int i=0;i<this->numarObiecte;i++)
            if (this->greutatiObiecte[i]!=c.greutatiObiecte[i]) return false;
        return true;
    }
    friend ostream& operator<<(ostream& out, const Colet& c) {
        out<<"Colet: "<<c.idColet<<", destinatar: "<<c.destinatar<<endl;
        for (int i=0;i<c.numarObiecte;i++)
            out<<" "<<c.greutatiObiecte[i]<<endl;
        out<<endl;
        return out;
    }
    double operator[](int index) {
        if (index<0 || index>=this->numarObiecte) {
            return -1;
        } else {
            return this->greutatiObiecte[index];
        }
    }
    operator double() {
        double suma=0;
        for (int i=0;i<this->numarObiecte;i++)
            suma+=this->greutatiObiecte[i];
        return suma;
    }
    int getIdColet() {
        return this->idColet;
    }
    static int getNumarColete() {
        return numarColete;
    }
};
int Colet::numarColete=0;

int main() {
    Colet c1;
    double c[]={2, -3, 5};
    Colet c2("Ion", 3, c);
    Colet c3=c2;
    c1=c2;
    c1=c1;
    cout<<c2;
    cout<<c2[0]<<" "<<c2[10]<<endl;
    cout<<(double)c2<<endl;
    cout<<c3;
    Colet c4=c2;
    cout<<(c2==c4)<<endl;
    Colet c5;
    cout<<(c2==c5)<<endl;
    return 0;
}