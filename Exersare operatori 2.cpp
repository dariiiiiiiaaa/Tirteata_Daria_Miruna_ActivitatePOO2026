//OPERATORUL -
//m - 500 returnează o mașină nouă cu prețul scăzut cu 500.
Masina operator-(float valoare) {
    Masina aux=*this;
    aux.pret=aux.pret-valoare;
    return aux;
}
//m - m2 returnează o mașină nouă cu prețul = diferența prețurilor
Masina operator-(const Masina& alta){
Masina aux=*this;
aux.pret=this->pret-alta.pret;
return aux;
}
//m - 2 returnează o mașină nouă cu anul de fabricație scăzut cu 2.
Masina operator-(int ani) {
    Masina aux=*this;
    aux.anFabricatie=aux.anFabricatie-ani;
    return aux;
}
//OPERATORUL -=
//m -= 500 scade din prețul lui m valoarea 500.
Masina& operator-=(float valoare) {
    this->pret=this->pret-valoare;
    return *this;
}
//m -= m2 scade din prețul lui m prețul lui m2.
Masina& operator-=(const Masina& alta) {
    this->pret=this->pret-alta.pret;
    return *this;
}
// Created by Tirteata Daria-Miruna on 03.11.2026.
