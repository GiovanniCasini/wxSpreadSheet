#include "Grid.h"

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