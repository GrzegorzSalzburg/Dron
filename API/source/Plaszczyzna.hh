#ifndef PLASZ_HH
#define PLASZ_HH
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include <vector>
#include <cmath>
using drawNS::APIGnuPlot3D;
using drawNS::Point3D;
using std::cout;
using std::endl;
using std::vector;

class Plaszczyzna
{

protected:
    vector<vector<Wektor3D>> krzywa;
    vector<vector<Wektor3D>> kop_krzywa;
    std::shared_ptr<drawNS::Draw3DAPI> &api;
    int id;

public:
    Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> &api) : api(api)
    {
    }

    virtual void rysuj();
};

#endif