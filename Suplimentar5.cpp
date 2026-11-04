#include<iostream>
#include<string>
using namespace std;
class Carte {
private:
    static int numarCarti;
    const int idCarte;
    string titlu;
    double pret;
    int* paginiCapitole;
    int numarCapitole;
public:
    ///Constructor fara parametri(carte anonima, idCarte din contor)
    Carte():idCarte(++numarCarti) {
        this->titlu="Anonim";
        this->pret=0;
        this->paginiCapitole=nullptr;
        this->numarCapitole=0;
    }
    ///Constructor cu parametri, cu validari(pret>0, fiecare capitol cu pagini>0, altfel valoare la alegere)
    Carte(string titlu, double pret, int* capitole, int numarCapitole):idCarte(++numarCarti) {
       if (titlu.size()>0) {
           this->titlu=titlu;
       }else {
           this->titlu="Anonim";
       }
        if (pret>0) {
            this->pret=pret;
        }else {
            this->pret=1;
        }
        if (numarCapitole>0 && capitole!=nullptr) {
            this->numarCapitole=numarCapitole;
            this->paginiCapitole=new int[numarCapitole];
            for (int i=0;i<numarCapitole;i++) {
                if (capitole[i]>0) {
                    this->paginiCapitole[i]=capitole[i];
                } else {
                    this->paginiCapitole[i]=1;
                }
            }

        }
        else {
            this->numarCapitole=0;
            this->paginiCapitole=nullptr;
        }
    }
    ~Carte() {
        delete[] paginiCapitole;
    }
    ///Constructorul de copiere
    Carte(const Carte& c):idCarte(++numarCarti) {
        this->titlu=c.titlu;
        this->pret=c.pret;
        this->numarCapitole=c.numarCapitole;
        if (c.paginiCapitole!=nullptr) {
            this->paginiCapitole=new int[c.numarCapitole];
            for (int i=0;i<c.numarCapitole;i++) {
                this->paginiCapitole[i]=c.paginiCapitole[i];
            }
        } else {
            this->paginiCapitole=nullptr;
        }
    }
    ///Operatorul =
    Carte& operator=(const Carte& c) {
        if (this!=&c) {
            delete[] this->paginiCapitole;
            this->titlu=c.titlu;
            this->pret=c.pret;
            this->numarCapitole=c.numarCapitole;
            if (c.paginiCapitole!=nullptr) {
                this->paginiCapitole=new int[c.numarCapitole];
                for (int i=0;i<c.numarCapitole;i++) {
                    this->paginiCapitole[i]=c.paginiCapitole[i];
                }
            } else {
                this->paginiCapitole=nullptr;
            }
        }
        return *this;
    }
    ///Operatorul <<
    friend ostream& operator<<(ostream& out, const Carte& c) {
        out<<"Carte: "<<c.idCarte<<", titlu"<<c.titlu<<endl;
        out<<"Numar capitole: ("<<c.numarCapitole<<" ): "<<endl;
        for (int i=0;i<c.numarCapitole;i++) {
            out<<c.paginiCapitole[i]<<" ";
        }
        out<<endl;
        return out;
    }
    ///Operatorul []
    int operator[](int index) {
        if (index<0 || index>=this->numarCapitole)
            return -1;
        return this->paginiCapitole[index];
    }
    ///Operatorul cast
    operator int() {
        int suma=0;
        for (int i=0;i<numarCapitole;i++) {
            suma+=this->paginiCapitole[i];
        }
        return suma;
    }
    int getId() {
        return this->idCarte;
    }
    static int getNumarCarti() {
        return numarCarti;
    }
    int Carte::numarCarti = 0;
};
int Carte::numarCarti = 0;
int main() {
    Carte c1;
    int t[]={100, 20, 30.5};
    Carte c2("Ion", 3, t, 29.9);
    Carte c3 = c2;
    c1 = c2;
    c1 = c1;
    cout << c2;
    cout << c2[0] << " " << c2[10] << endl;
    cout << (int)c2 << endl;
    return 0;

}