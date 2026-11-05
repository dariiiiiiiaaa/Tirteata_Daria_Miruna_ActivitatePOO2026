#include<iostream>
#include<string>
using namespace std;
class Film {
private:
    static int numarFilme;
    const int idFilm;
    string titlu;
    int numarRatinguri;
    int* ratinguri;
public:
    Film():idFilm(++numarFilme) {
        this->titlu="Anonim";
        this->numarRatinguri=0;
        this->ratinguri=nullptr;;
    }
    Film(string titlu, int numarRatinguri, int* ratinguri):idFilm(++numarFilme) {
        if (titlu.size()>0) {
            this->titlu=titlu;
        } else {
            this->titlu="Anonim";
        }
        if (numarRatinguri>0 && ratinguri!=nullptr) {
            this->numarRatinguri=numarRatinguri;
            this->ratinguri=new int[numarRatinguri];
            for (int i=0;i<numarRatinguri;i++)
                if (ratinguri[i]>= 1 && ratinguri[i]<=5) {
                    this->ratinguri[i]=ratinguri[i];
                } else {
                    this->ratinguri[i]=1;
                }
        } else {
            this->numarRatinguri=0;
            this->ratinguri=nullptr;
        }
    }
    ~Film() {
        delete[] this->ratinguri;
    }
    Film(const Film& f):idFilm(++numarFilme) {
        this->titlu=f.titlu;
        this->numarRatinguri=f.numarRatinguri;
        if (f.ratinguri!=nullptr) {
            this->ratinguri=new int[f.numarRatinguri];
            for (int i=0;i<f.numarRatinguri;i++)
                this->ratinguri[i]=f.ratinguri[i];
        } else {
            this->ratinguri=nullptr;
        }
    }
    Film& operator=(const Film& f) {
        if (this!=&f) {
            delete[] this->ratinguri;
            this->titlu=f.titlu;
            this->numarRatinguri=f.numarRatinguri;
            if (f.ratinguri!=nullptr) {
                this->ratinguri=new int[f.numarRatinguri];
                for (int i=0;i<f.numarRatinguri;i++)
                    this->ratinguri[i]=f.ratinguri[i];
            } else {
                this->ratinguri=nullptr;
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, Film& f) {
        out<<"Film: "<<f.idFilm<<" , titlu: "<<f.titlu<<endl;
        for (int i=0;i<f.numarRatinguri;i++)
            out<<" "<<f.ratinguri[i];
        out<<endl;
        return out;
    }
    ///operator!=: două filme sunt diferite dacă diferă titlul sau ratingurile.
    bool operator!=(const Film& f) {
        if (this->titlu!=f.titlu) return true;
        if (this->numarRatinguri!=f.numarRatinguri) return true;
        for (int i=0;i<f.numarRatinguri;i++)
            if (this->ratinguri[i]!=f.ratinguri[i]) return true;
        return false;
    }
    ///operator-= care scade o valoare din fiecare rating, dar un rating nu coboară sub 1.
    Film& operator-=(int valoare) {
        for (int i=0;i<this->numarRatinguri;i++){
            this->ratinguri[i]=this->ratinguri[i]-valoare;
            if (this->ratinguri[i]<1) {
                this->ratinguri[i]=1;
            }
        }
        return *this;
    }
    ///operator- între un film și un număr: returnează un film nou cu ratingurile scăzute (aceeași regulă, minim 1). Filmul inițial rămâne neschimbat.
    Film operator-(int valoare) {
        Film aux=*this;
        aux-=valoare;
        return aux;
    }
    int getIdFilm() {
        return this->idFilm;
    }
    static int getNumarFilme() {
        return numarFilme;
    }
};
int Film::numarFilme=0;
int main() {
    Film f1;
    int f[]={5,9,4};
    Film f2("Matrix",3,f);
    Film f3=f2;
    Film f4;
    f4=f2;
    f4=f4;
    cout<<f2;
    Film f5("Altul",3,f);
    cout<<(f2!=f3)<<endl;
    cout<<(f2!=f5)<<endl;
    Film f6("Test",3,f);
    f6-=3;
    Film f7=f2-3;
    cout<<f7;
    cout<<f2;
    return 0;
}
