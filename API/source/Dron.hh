#pragma once
#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"

using drawNS::APIGnuPlot3D;
using drawNS::Point3D;
using std::cout;
using std::endl;
using std::vector;
using namespace std;

class Dron
{
  std::shared_ptr<drawNS::Draw3DAPI> &api;
  Granaistoslup *sruba1;
  Granaistoslup *sruba2;
  Prostopadloscian *korpus;

public:
double get_promien(){korpus->promien();}
Wektor3D get_srodek2(){return korpus->get_srodek();}
  Dron(std::shared_ptr<drawNS::Draw3DAPI> &api) : api(api)
  {
    korpus = new Prostopadloscian(10, 10, 10, api);
    sruba1 = new Granaistoslup(3, 3, 3, api);
    sruba2 = new Granaistoslup(3, 3, 3, api);
  }

  void start()
  {

    double przes = 1;

    for (int i = 0; i < przes; i++)
    {
      korpus->ruch(0, 0);
      korpus->rysuj();
      sruba2->przesun(korpus->get_wirz(0, 3));
      sruba2->ruch(0, 0);
      sruba2->rysuj();

      sruba1->przesun(korpus->get_wirz(0, 2));
      sruba1->ruch(0, 0);
      sruba1->rysuj();
    }
  }

  void obrot()
  {


      korpus->ruch(0, 1);
      sruba1->przesun(korpus->get_wirz(0, 2));
      sruba2->przesun(korpus->get_wirz(0, 3));
      sruba1->ruch(0, 1);
      sruba2->ruch(0, 1);
      sruba1->osx(0, 10);
      sruba2->osx(0, -10);
      sruba1->rysuj();
      sruba2->rysuj();
      korpus->rysuj();
      usleep(60000);
    
  }
 void obrot_ujem()
  {


      korpus->ruch(0, -1);
      sruba1->przesun(korpus->get_wirz(0, 2));
      sruba2->przesun(korpus->get_wirz(0, 3));
      sruba1->ruch(0, -1);
      sruba2->ruch(0, -1);
      sruba1->osx(0, 10);
      sruba2->osx(0, -10);
      sruba1->rysuj();
      sruba2->rysuj();
      korpus->rysuj();
      usleep(60000);
    
  }
  void przesun_(double kat)
  {


      korpus->pion(1, kat);
      sruba1->pion(1, kat);
      sruba2->pion(1, kat);
      sruba1->rysuj();
      sruba2->rysuj();
      sruba1->osx(0, 10);
      sruba2->osx(0, -10);
      korpus->rysuj();
      usleep(100000);
    
  }
};
