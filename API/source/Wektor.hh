#ifndef SWektor_HH
#define SWektor_HH


#include <iostream>
#include <cmath>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
 template <typename Typ, int ROZMIAR>
class SWektor {
Typ Wek[ROZMIAR];
  public:
  SWektor();
  SWektor<Typ,ROZMIAR> operator += (const SWektor<Typ,ROZMIAR> & W2);
  SWektor<Typ,ROZMIAR> & operator -= (const SWektor<Typ,ROZMIAR> & W2);
  Typ dlugosc();
  bool operator == (const SWektor<Typ,ROZMIAR> & W2) const;
  bool operator != (const SWektor<Typ,ROZMIAR> & W2) const;
  Typ get_Wek(int i) const;
  Typ & set_Wek(int i) ;
  Typ operator[](int i) const;
  Typ &operator[](int i);
  SWektor<Typ,ROZMIAR> operator + (const SWektor<Typ,ROZMIAR> Skl);
  SWektor<Typ,ROZMIAR> operator - (const SWektor<Typ,ROZMIAR> Skl);
  Typ operator * (const SWektor<Typ,ROZMIAR> Skl);
  SWektor<Typ,ROZMIAR> operator / (Typ Skl);
  SWektor<Typ,ROZMIAR> operator * (Typ Skl);
};


  template <typename Typ, int ROZMIAR>
 SWektor<Typ,ROZMIAR>   SWektor<Typ,ROZMIAR>::operator += (const SWektor<Typ,ROZMIAR> & W2)
{
      SWektor<Typ,ROZMIAR> wyn;
      for(int i=0; i<ROZMIAR; i++)
            {
            wyn[i]=Wek[i]+W2[i];
            }
      return wyn;
}
 template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR>  & SWektor<Typ,ROZMIAR>::operator -= (const SWektor<Typ,ROZMIAR> & W2)
{
      
      for(int i=0; i<ROZMIAR; i++)
      {
            Wek[i]=Wek[i]-W2[i];
      }
      return *this;
}

 template <typename Typ, int ROZMIAR>
 SWektor<Typ,ROZMIAR> SWektor<Typ,ROZMIAR>::operator + (const SWektor<Typ,ROZMIAR> Skl)
{
      SWektor<Typ,ROZMIAR> wyn;
      for(int i=0; i<ROZMIAR; i++)
      {
            wyn[i]=Wek[i]+Skl[i];
      }
      return wyn;
}
 template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR> SWektor<Typ,ROZMIAR>::operator - ( const SWektor<Typ,ROZMIAR> Skl)
{
      SWektor<Typ,ROZMIAR> wyn;
      for(int i=0; i<ROZMIAR; i++)
      {
            wyn[i]=Wek[i]-Skl[i];
      }
      return wyn;
      }
 template <typename Typ, int ROZMIAR>
Typ SWektor<Typ,ROZMIAR>::operator * (const SWektor<Typ,ROZMIAR> Skl)
{
      Typ wyn=0;
      for(int i=0; i<ROZMIAR; i++)
      {
        wyn=wyn+Wek[i]*Skl[i];
      }
      return wyn;
}
 template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR> SWektor<Typ,ROZMIAR>::operator / (Typ Skl)
{
      SWektor<Typ,ROZMIAR> wyn;
      for(int i=0; i<ROZMIAR; i++)
      {
        wyn[i]=Wek[i]/Skl;
      }
      return wyn;

}
 template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR> SWektor<Typ,ROZMIAR>::operator * (Typ Skl)
{
      SWektor<Typ,ROZMIAR> wyn;
      for(int i=0; i<ROZMIAR; i++)
      {
        wyn[i]=Wek[i]*Skl;
      }
      return wyn;
}
 template <typename Typ, int ROZMIAR>
Typ SWektor<Typ,ROZMIAR>::get_Wek(int i) const
{
      return Wek[i];
}
 template <typename Typ, int ROZMIAR>
Typ & SWektor<Typ,ROZMIAR>::set_Wek(int i) 
{
      return Wek[i];
}

 template <typename Typ, int ROZMIAR>
Typ SWektor<Typ,ROZMIAR>::operator[](int i) const
{
      return Wek[i];
}
 template <typename Typ, int ROZMIAR>
Typ & SWektor<Typ,ROZMIAR>::operator[](int i) 
{
      return Wek[i];
}

 template <typename Typ, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, SWektor<Typ,ROZMIAR> &Wek)
{
    for(int i=0; i<ROZMIAR; i++)
    Strm>>Wek[i];
    return Strm;
}

 template <typename Typ, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const SWektor<Typ,ROZMIAR> &Wek)
{
      for(int i=0; i<ROZMIAR; i++)
      Strm<<Wek[i]<<" ";
      return Strm;
}

  template <typename Typ, int ROZMIAR>
bool SWektor<Typ,ROZMIAR>::operator == (const SWektor<Typ,ROZMIAR> & W2) const
{
   for(int i=0; i<ROZMIAR; i++)
   if(Wek[i]!=W2[i]) return false;
   return true;
}
 template <typename Typ, int ROZMIAR>
bool SWektor<Typ,ROZMIAR>::operator != (const SWektor<Typ,ROZMIAR> & W2) const
{
   for(int i=0; i<ROZMIAR; i++)
   if(Wek[i]!=W2[i]) return true;
   return false;
}
 template <typename Typ, int ROZMIAR>
SWektor<Typ,ROZMIAR>::SWektor()
 {
   for(int i=0; i<ROZMIAR; i++)
   Wek[i]=0;
 }

#endif
