#include<iostream>
#include<string>
using namespace std;
class Comanda {
private:
    static int numarComenzi;
    const int idComanda;
    string client;
    int numarProduse;
    int* cantitati;
public:
    Comanda():idComanda(++numarComenzi) {
        this->client="Anonim";
        this->numarProduse=0;
        this->cantitati=nullptr;
    }
    Comanda(string client, int numarProduse, int* cantitati): idComanda(++numarComenzi) {
        if (client.size>0) {
            this->client=client;
        } else {
            this->client="Anonim";
        }
        if (numarProduse>0 && cantitati!=nullptr) {
            this->numarProduse=numarProduse;
            this->cantitati=new int[numarProduse];
            for (int i=0;i<numarProduse;i++) {
                if (cantitati[i]>0) {
                    this->cantitati[i]=cantitati[i];
                } else {
                    this->cantitati[i]=1;
                }
            }
        } else {
            this->numarProduse=0;
            this->cantitati=nullptr;
        }
    }
    ~Comanda() {
        delete [] this->cantitati;
    }
    Comanda(const Comanda& c):idComanda(++numarComenzi){
        this->numarProduse=c.numarProduse;
        this->client=c.client;
        if (c.cantitati!=nullptr) {
            this->cantitati=new int[c.numarProduse];
            for (int i=0;i<c.numarProduse;i++)
                this->cantitati[i]=c.cantitati[i];
        } else {
            this->cantitati=nullptr;
        }
    }
    Comanda& operator=(const Comanda& c) {
        if (this!=&c) {
            delete [] this->cantitati;
            this->client=c.client;
            this->numarProduse=c.numarProduse;
            if (c.cantitati!=nullptr) {
                this->cantitati=new int[c.numarProduse];
                for (int i=0;i<c.numarProduse;i++)
                    this->cantitati[i]=c.cantitati[i];
            } else {
                this->cantitati=nullptr;
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Comanda& c) {
        out<<"Comanda"<<c.idComanda<<", clientul"<<c.client<<endl;
        for (int i=0;i<c.numarProduse;i++)
            out<<" "<<c.cantitati[i];
        out<<endl;
        return out;
    }
    int operator[](int index) {
        if (index<0 || index>=this->numarProduse)
            return -1;
        return this->cantitati[index];
    }
    operator int() {
        int suma=0;
        for (int i=0;i<this->numarProduse;i++)
            suma+=this->cantitati[i];
        return suma;
    }
    int getIdComanda() {
        return this->idComanda;
    }
    static int getnumarComenzi() {
        return numarComenzi;
    }
};
int Comanda::numarComenzi=0;
int main() {
    Comanda c1;
    int v[]={2,-3,5};
    Comanda c2("Zoe", 3, v);
    Comanda c3=c2;
    c1=c2;
    c1=c1;
    cout<<c2;
    cout<<c2[0]<<" "<<c2[10]<<endl;
    cout<<(int)c2<<endl;
    cout<<c3;
    return 0;
}

