#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

void calcola(int op, float matrix[][5], float* r,  wxGrid* g){
    switch(op){
        case 0:
            *r = 0;
            for(int i = 0; i < 10; i++){
                if (matrix[i][op] != NULL)
                    *r += matrix[i][op];
            }
            break;
        case 1:
            *r = INT_MIN;
            for(int i = 0; i < 10; i++){
                if(*r < matrix[i][op] && matrix[i][op] != NULL)
                    *r = matrix[i][op];
            }
            break;
        case 2:
            *r = INT_MAX;
            for(int i = 0; i < 10; i++){
                if(*r > matrix[i][op] && matrix[i][op] != NULL)
                    *r = matrix[i][op];
            }
            break;
        case 3:
            *r = 1;
            for(int i = 0; i < 10; i++){
                if (matrix[i][op] != NULL)
                    *r *= matrix[i][op];
            }
            break;
        case 4:
            *r = 0;
            float sum = 0;
            int count = 0;
            for(int i = 0; i < 10; i++){
                if (matrix[i][op] != NULL){
                    sum += matrix[i][op];
                    count++;
                }
                *r = float(sum) / count;
            }
            break;
    }
}

class Observer{
    public:
        void Update(int col, float matrix[][5], float* r, wxGrid* g){
            calcola(col, matrix, r, g);

            if(g != nullptr){
                g->SetCellValue(0,col,std::to_string(*r));
            } 
        }
};