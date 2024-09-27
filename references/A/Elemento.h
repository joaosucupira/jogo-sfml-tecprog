#pragma once
template <class TE> class Elemento
{
private:
    Elemento<TE>* pProx;
    TE* item;
public:
    Elemento();
    ~Elemento(); 
    void setProx(Elemento<TE>* pProx) { this->pProx = pProx; }
    void item(TE* item) { this->item = item; }
    Elemento<TE>* getPProx() { return pProx; }
    

};

template<class TE> 
inline Elemento<TE>::Elemento()
{
    pProx = nullptr;
    item = nullptr;
}

template<class TE> 
inline Elemento<TE>::~Elemento()
{
}