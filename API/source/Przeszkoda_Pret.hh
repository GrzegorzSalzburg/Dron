#pragma once
#include "Przeszkoda.hh"
class Przeszkoda_Pret : public Przeszkoda
{

public:
 

virtual bool kolizja(Dron &dron)
{
    if(promien()+dron.get_promien()>=sqrt( pow(dron.get_srodek2()[0]-przes[0],2) + pow(dron.get_srodek2()[1]-przes[1],2)+ pow(dron.get_srodek2()[2]-przes[2],2)))
    {
      
        return true;
    }
    return false;
}
  Przeszkoda_Pret(double x, double y, double z,std::shared_ptr<drawNS::Draw3DAPI> &api):Przeszkoda( x,  y,  z,api)
  {}
};