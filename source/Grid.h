#include "Subject.h"
#include <list>
#include <iostream>
#include "mainwindow.h"
#include <wx/wxprec.h>
#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

const int dim1 = 10;
const int dim2 = 5;

const int dim1R = 1;
const int dim2R = 5;

class Griglia : public Subject{
    private:
        std::list<AbstractObserver*> observers;
        wxGrid* grid = nullptr;
        float matrix[dim1][dim2] {};
        wxGrid* gridR = nullptr;
        float matrixR[dim1R][dim2R] {};

    public:
        virtual ~Griglia(){}
        Griglia(){}

        Griglia(wxGrid* g, wxGrid* gR): grid(g), gridR(gR){
            matrixR[0][3] = 1;
        }

        void attach(AbstractObserver* o) override{
            observers.push_back(o);
        }

        void detach(AbstractObserver* o) override{
            observers.remove(o);
        }

         void notify(int col){
            std::list<AbstractObserver*>::iterator iterator = observers.begin();
            while(iterator != observers.end()){
                float r = (*iterator)->Update(col, matrix);
                matrixR[0][col] = r;
                if(gridR != nullptr)
                    gridR->SetCellValue(0,col,std::to_string(r));
            
            
                ++iterator;
            }
        }

        void setGridValue(int x, int y, float v){
            matrix[x][y] = v;
            notify(y);

        }

       

        wxGrid* getGrid(){
            return grid;
        }

        auto getMatrix(){
            return matrixR;
        }
};


