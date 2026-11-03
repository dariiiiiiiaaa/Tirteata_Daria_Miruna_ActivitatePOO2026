//OPERATORUL +
//m + 500 returnează o mașină nouă cu prețul mărit cu 500.
Masina operator+(float valoare) {
    Masina aux=*this;
    aux.pret=aux.pret+valoare;
    return aux;
}
//m + 2 returnează o mașină nouă cu anul de fabricație mărit cu 2.
Masina operator+(int ani) {
    Masina aux=*this;
    aux.anFabricatie=aux.anFabricatie+ani;
    return aux;
}
//m + m2 (alt obiect) returnează o mașină nouă cu prețul = suma prețurilor celor două mașini.
Masina operator+(const Masina& alta) {
    Masina aux=*this;
    aux.pret=this->pret+alta.pret;
    return aux;
}
//m + " Sport" returnează o mașină nouă cu textul adăugat la marcă.
Masina operator+(const char* text) {
    Masina aux=*this;
    delete [] aux.marca;
    if (this->marca!=nullptr) {
        aux.marca=new char[strlen(this->marca)+strlen(text)+1];
        strcpy(aux.marca, this->marca;
        strcat(aux.marca, marca);
    }
    else {
        aux.marca=new char[strlen(text)+1];
        strcpy(aux.marca, text);
    }
    return aux;
}
//OPERATORUL +=
//m += 500 crește prețul cu 500.
Masina& operator+=(float valoare) {
    this->pret=this->pret+valoare;
    return *this;
}
//m += 2 crește anul de fabricație cu 2.
Masina& operator+=(int anFabricatie) {
    this->anFabricatie=this->anFabricatie+2;
    return *this;
}
//m += m2 adaugă la prețul lui m prețul lui m2.
Masina& operator+=(const Masina& alta){
this->pret=this->pret+alta.pret;
return *this;
}

// Created by Tirteata Daria-Miruna on 03.11.2026.

