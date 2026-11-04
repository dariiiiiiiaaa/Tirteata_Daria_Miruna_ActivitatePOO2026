#include<iostream>
#include<string>
using namespace std;
class Reparatie {
private:
    static int numarReparatii;
    const int idReparatie;
    int numarPiese;
    char* client;
    float* costuri;
public:
    Reparatie():idReparatie(++numarReparatii) {
        this->numarPiese=0;
        this->client=nullptr;
        this->costuri=nullptr;
    }
    Reparatie(const char* client, int numarPiese, float* costuri):idReparatie(++numarReparatii) {
     if (client!=nullptr) {
         this->client=new char[strlen(client)+1];
         strcpy(this->client, client);
     } else {
         this->client=nullptr;
     }
        if (numarPiese>0 && costuri!=nullptr) {
            this->numarPiese=numarPiese;
            this->costuri=new float[numarPiese];
            for (int i=0;i<numarPiese;i++) {
                if (costuri[i]>0) {
                    this->costuri[i]=costuri[i];
                } else {
                    this->costuri[i]=1;
                }
            }
        } else {
            this->numarPiese=0;
            this->costuri=nullptr;
        }
    }
    ~Reparatie() {
        delete[] this->client;
        delete[] this->costuri;
    }
    Reparatie(const Reparatie &r):idReparatie(++numarReparatii) {
        this->numarPiese=r.numarPiese;
        if (r.client!=nullptr) {
            this->client=new char[strlen(r.client)+1];
            strcpy(this->client, r.client);
        } else {
            this->client=nullptr;
        }
        if (r.costuri!=nullptr) {
            this->costuri=new float[r.numarPiese];
            for (int i=0;i<r.numarPiese;i++) {
                this->costuri[i]=r.costuri[i];
            }
        } else {
            this->costuri=nullptr;
        }
    }
    Reparatie& operator=(const Reparatie &r) {
        if (this!=&r) {
            delete [] this->client;
            delete [] this->costuri;
            this->numarPiese=r.numarPiese;
            if (r.client!=nullptr) {
                this->client=new char[strlen(r.client)+1];
                strcpy(this->client, r.client);
            } else {
                this->client=nullptr;
            }
            if (r.costuri!=nullptr) {
                this->costuri=new float[r.numarPiese];
                for (int i=0;i<r.numarPiese;i++) {
                    this->costuri[i]=r.costuri[i];
                }
            } else {
                this->costuri=nullptr;
            }
        }
        return *this;
    }
    Reparatie& operator+=(float costNou) {
        if (costNou<=0)
            return *this;
        float* nou=new float[this->numarPiese+1];
        for (int i=0;i<this->numarPiese;i++) {
            nou[i]=this->costuri[i];
        }
        nou[this->numarPiese]=costNou;
        delete[] this->costuri;
        this->costuri=nou;
        this->numarPiese++;
        return *this;a
    }
    friend ostream& operator<<(ostream& out, const Reparatie& r) {
        out<<"Reparatie "<<r.idReparatie<<endl;
        if (r.client!=nullptr) {
            out<<"Client: "<<r.client<<endl;
        }
        out<<"Piese ("<<r.numarPiese<<"):";
        for (int i=0;i<r.numarPiese;i++) {
            out<<" "<<r.costuri[i];
        }
        out<<endl;
        return out;
    }
    float operator[](int index) {
        if (index<0 || index>=this->numarPiese) {
            return -1;
        }
        return this->costuri[index];
    }
    operator float() {
        float suma=0;
        for (int i=0;i<numarPiese;i++) {
            suma+=this->costuri[i];
        }
        return suma;
    }
    int getId() {
        return this->idReparatie;
    }
    static int getNumarPiese() {
        return numarPiese;
    }
};
int Reparatie::numarReparatii=0;
int main() {
    Reparatie r1;
    float c[]={100, -5, 50.5f};
    Reparatie r2("Popescu", 3, c);
    Reparatie r3=r2;
    r1=r2;
    r1=r1;
    cout<<r2;
    r2+=75.5f;
    cout<<r2;
    cout<<"Cost total: "<<(float)r2<<endl;
    cout<<r3;
    return 0;
}
