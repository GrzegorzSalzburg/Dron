#ifndef SMacierz_HH
#define SMacierz_HH


#include <iostream>
#include "Wektor.hh"
#include <algorithm>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename Typ, int ROZMIAR>
class SMacierz{
  SWektor<Typ,ROZMIAR> Mac[ROZMIAR];
  public:
  Typ wyznacznik();
  SWektor<Typ,ROZMIAR> get_Mac(int i) const;
  SWektor<Typ,ROZMIAR> & set_Mac(int i) ;
  SWektor<Typ,ROZMIAR> operator[](int i) const;
  SWektor<Typ,ROZMIAR> &operator[](int i);  
  SWektor<Typ,ROZMIAR> operator*(const SWektor<Typ,ROZMIAR>  W2);
};

template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR> SMacierz<Typ,ROZMIAR>::get_Mac(int i) const
{
     return Mac[i];
}

template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR> & SMacierz<Typ,ROZMIAR>::set_Mac(int i) 
{
     return Mac[i];
}

template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR> SMacierz<Typ,ROZMIAR>::operator[](int i) const
{
    return Mac[i];
}

template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR> & SMacierz<Typ,ROZMIAR>::operator[](int i) 
{
    return Mac[i];
}

template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR>  SMacierz<Typ,ROZMIAR>::operator*(const SWektor<Typ,ROZMIAR> W2)
{
SWektor<Typ,ROZMIAR> wynik;
  for(int i=0; i<ROZMIAR; i++)
    for(int j=0; j<ROZMIAR; j++)
         wynik[i]=wynik[i]+Mac[j][i]*W2[j];
  return wynik;
 }

template <typename Typ, int ROZMIAR>
Typ SMacierz<Typ,ROZMIAR>::wyznacznik()
{
    SMacierz<Typ,ROZMIAR> Kop = *this;
    int mn=1;
    Typ wyznacznik;
    for(int i=0; i<ROZMIAR-1; i++)
    {
        for(int j=i+1; j<ROZMIAR; j++)
        {
            if(Kop[i][i]==0)
            {std::swap(Kop[i],Kop[j]);
            mn=-mn;
            }
        }
            if(Kop[i][i]==0)
            return 0;
            for(int j=i+1; j<ROZMIAR; j++)
        {
        Kop[j]-=(Kop[i]*(Kop[j][i]/Kop[i][i]));
        } 

      }
      wyznacznik=1;
     

        for(int j=0; j<ROZMIAR; j++)
        {
            wyznacznik=wyznacznik*Kop[j][j];
        } 
return wyznacznik*mn;
}

template <typename Typ, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, SMacierz<Typ,ROZMIAR> &Mac)
{
   for(int i=0; i<ROZMIAR; i++)
   Strm>>Mac[i];

return Strm;
}

template <typename Typ, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const SMacierz<Typ,ROZMIAR> &Mac)
{
    for(int i=0; i<ROZMIAR; i++)
    Strm<<Mac[i]<<std::endl;

return Strm;
}
#endif
