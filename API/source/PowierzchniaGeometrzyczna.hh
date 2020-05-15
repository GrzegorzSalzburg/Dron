#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <vector>
#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

using namespace std;


class PowierzchniaGeometrzyczna
{
    protected:
    vector<vector<Wektor3D> > Punkty;
     vector<vector<Wektor3D> > Punkty_kop;
     vector<vector<Point3D> > punktyPoint;
    Macierz3x3 M;
    
    Wektor3D wek;
    double kat;
    public:
    void M_Z()
    {
        M[0][0]=cos(kat);
        M[0][1]=-sin(kat);
        M[0][2]=0;
        M[1][0]=sin(kat);
        M[1][1]=cos(kat);
        M[1][2]=0;
        M[2][0]=0;
        M[2][1]=0;
        M[2][2]=1;
    }
    void M_Y()
    {
        M[0][0]=cos(kat);
        M[0][1]=0;
        M[0][2]=sin(kat);

        M[1][0]=0;
        M[1][1]=1;
        M[1][2]=0;

        M[2][0]=-sin(kat);
        M[2][1]=0;
        M[2][2]=cos(kat);
    }

    void zmien_pozycje(double kat,double kat_wznoszenia ,double przesuniecie)
    {
        Wektor3D przes;
        przes[0]=przesuniecie;
        this->kat+=kat*M_PI/180;
        M_Z();
        przes=M*przes;
        for(int i=0; i<Punkty.size();i++)
        {
            for(int j=0; j<Punkty.size();j++)
            {
                Punkty_kop[i][j]=(M*Punkty[i][j])+przes;
                punktyPoint[i][j][0]=Punkty_kop[i][j][0];
                 punktyPoint[i][j][1]=Punkty_kop[i][j][1];
                  punktyPoint[i][j][2]=Punkty_kop[i][j][2];
            }
        }
       
    }



};