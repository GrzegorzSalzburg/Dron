#include "PowierzchniaGeometrzyczna.hh"



class Prostopadloscian: public PowierzchniaGeometrzyczna
{
std::shared_ptr<drawNS::Draw3DAPI> &api;
public:
Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &api):api(api)
{
double szerokosc =10;
double wysokosc= 10;
double dlugosc =20;
    Punkty.resize(2);
    Punkty_kop.resize(2);
        
    for(int i=0; i<Punkty_kop.size(); i++)
    {
        Punkty[i].resize(4);
    Punkty_kop[i].resize(4);
         
    }
    cout<<Punkty.size();
    cout<<Punkty[0].size();
      for(int i=0; i<Punkty.size();i++)
        {
            for(int j=0; j<Punkty[i].size();j++)
            {
                Punkty[i][j][0]-= dlugosc/2;
                Punkty[i][j][1]-= szerokosc/2;
                Punkty[i][j][2]-= wysokosc/2;
            }
        }
   
    Punkty[0][1][2]+= wysokosc;

    Punkty[0][2][1]+= szerokosc;
    Punkty[0][2][2]+= wysokosc;
 
    Punkty[0][3][1]+= szerokosc;
///////////////////
Punkty[1][0][0]+= dlugosc;
    
    Punkty[1][1][0]+= dlugosc;
    Punkty[1][1][2]+= wysokosc;

Punkty[1][2][0]+= dlugosc;
    Punkty[1][2][1]+= szerokosc;
    Punkty[1][2][2]+= wysokosc;
 
 Punkty[1][3][0]+= dlugosc;
    Punkty[1][3][1]+= szerokosc;

Punkty_kop=Punkty;
    
   for(int i=0; i<Punkty.size();i++)
        {
            std::vector<drawNS::Point3D> krzywa;
            for(int j=0; j<Punkty[i].size();j++)
            {
                drawNS::Point3D a(Punkty[i][j][0],Punkty[i][j][1],Punkty[i][j][2]);
                krzywa.push_back(a);
              
            }
            punktyPoint.push_back(krzywa);
        }
}
void wyswietl()
{
   api->draw_polyhedron(punktyPoint,"blue");
}

};