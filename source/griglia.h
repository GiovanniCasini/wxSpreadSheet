#include <list>
#include <iostream>
#include "mainwindow.h"
#include "cella.h"
#include "observer.h"
#include <wx/wxprec.h>
#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

const int dim1 = 10;
const int dim2 = 5;

const int dim1R = 1;
const int dim2R = 5;

class Griglia{
    private:
        std::vector<Observer*> observers;
        wxGrid* grid = nullptr;
        float matrix[dim1][dim2] {};
        wxGrid* gridR = nullptr;
        float matrixR[dim1R][dim2R] {};

    public:
        Griglia(Observer* o){
            attach(o);
        }

        Griglia(wxGrid* g, wxGrid* gR, Observer* o): grid(g), gridR(gR){
            matrixR[0][3] = 1;
            attach(o);
        }

        void attach(Observer* o){
            observers.push_back(o);
        }

        void setGridValue(int x, int y, float v){
            matrix[x][y] = v;
            float result = matrixR[0][y];
            notify(y, &result, v);
            matrixR[0][y] = result;

        }

        void notify(int col, float* result, float v){
            int i = 0;
            while(i < observers.size()){
                observers[i]->Update(col, matrix, result, gridR);
                i++;
            }
        }

        wxGrid* getGrid(){
            return grid;
        }

        auto getMatrix(){
            return matrixR;
        }
};



