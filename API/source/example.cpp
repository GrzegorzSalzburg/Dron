#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Powierzchnia.hh"
#include "Dno.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"

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
      dron.przesun_();
      break;
    }

    case 'o':
    {
      dron.obrot();

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
