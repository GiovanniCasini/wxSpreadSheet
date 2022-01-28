#include <list>
#include <iostream>
#include "mainwindow.h"
#include <wx/wxprec.h>
#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class AbstractObserver{
    
    public:
        virtual ~AbstractObserver(){};
     
        virtual float Update(int col, float m[][5]) = 0;
};

class Subject{
public:

    virtual ~Subject(){};

    virtual void attach(AbstractObserver* o) = 0;
    virtual void detach(AbstractObserver* o) = 0;
};

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

enum Operation: int{
    SUM = 0,
    MAX = 1,
    MIN = 2,
    PRO = 3,
    MEA = 4
};


float calcola(int op, float matrix[][5]){
    float r;
    
    switch(op){
        case SUM:
            r = 0;
            for(int i = 0; i < 10; i++){
                if (matrix[i][op] != NULL)
                    r += matrix[i][op];
            }
            break;
        case MAX:
            r = INT_MIN;
            for(int i = 0; i < 10; i++){
                if(r < matrix[i][op] && matrix[i][op] != NULL)
                    r = matrix[i][op];
            }
            break;
        case MIN:
            r = INT_MAX;
            for(int i = 0; i < 10; i++){
                if(r > matrix[i][op] && matrix[i][op] != NULL)
                    r = matrix[i][op];
            }
            break;
        case PRO:
            r = 1;
            for(int i = 0; i < 10; i++){
                if (matrix[i][op] != NULL)
                    r *= matrix[i][op];
            }
            break;
        case MEA:
            r = 0;
            float sum = 0;
            int count = 0;
            for(int i = 0; i < 10; i++){
                if (matrix[i][op] != NULL){
                    sum += matrix[i][op];
                    count++;
                }
                r = float(sum) / count;
            }
            break;
    }
    return r;
}

class Observer: public AbstractObserver{
    
    private:
        Subject* sub;

    public:
        Observer(Subject* s){
            sub = s;
            sub->attach(this);
        }
        ~Observer(){
            sub->detach(this);
        }
        float Update(int col, float matrix[][5]) override{
            return calcola(col, matrix);
            
        }
};

