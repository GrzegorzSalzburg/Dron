#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Powierzchnia.hh"
#include "Dno.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"
#include "Przeszkoda_Pret.hh"
#include "Przeszkod_Plaszczyzna.hh"
#include "Przeszkoda_Prostopadloscienna.hh"
using drawNS::APIGnuPlot3D;
using drawNS::Point3D;
using std::cout;
using std::endl;
using std::vector;
using namespace std;

void wait4key()
{
  do
  {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while (std::cin.get() != '\n');
}

int main()
{
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-60, 60, -60, 60, -60, 60, 0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  std::vector<std::shared_ptr<Przeszkoda>> tab;
  tab.push_back(make_shared<Przeszkoda_Plaszczyzna>(0, 10, 10, api));
  tab.push_back(make_shared<Przeszkoda_Pret>(0, 10, 0, api));
  tab.push_back(make_shared<Przeszkoda_Prostopadloscian>(20, 20, 10, api));

  for (int i = 0; i < tab.size(); i++)
  {
    tab[i]->ruch(rand() % 30 + 20, rand() % 360);
    tab[i]->rysuj();
  }
  Powierzchnia po(api);
  Dno d(api);

  d.rysuj();
  po.rysuj();

  Dron dron(api);
  dron.start();

  char opcja;

  while (1)
  {
    cout << "wybierz opcje:" << endl;
    cout << "p - przesuniecie" << endl;
    cout << "o - obrot" << endl;
    cout << "k - koniec" << endl;

    std::cin >> opcja;

    switch (opcja)
    {

    case 'p':
    {
      cout << "Podaj przesuniecie" << endl;
      double przesu;
      cin >> przesu;
      cout << "Podaj kat" << endl;
      double kat;
      cin >> kat;
int i;
      for (int k = 0; k < przesu; k++)
      {
        tab[2]->kolizja(dron);
        for ( i = 0; i < tab.size() && !tab[i]->kolizja(dron); i++);
        if(i>2)
          i=0;
   if( tab[i]->kolizja(dron))
   {
     break;
   }

        dron.przesun_(kat);
      }
      break;
    }

    case 'o':
    {
      std::cout << "Podaj kat" << std::endl;
      double k;
      std::cin >> k;
      if(k>0)
      for (int i = 0; i < k; i++)
      {
        dron.obrot();
      }
      else
       for (int i = 0; i < -k; i++)
      {
        dron.obrot_ujem();
      }
      break;
    }
    case 'k':
    {
      return 1;

      break;
    }
    }
  }
}
