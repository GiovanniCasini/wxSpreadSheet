#include <wx/wxprec.h>
#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class Cell{
    private:
    float value = .0;
    int row;
    int col; 

    public:
    Cell(int x, int y): row(x), col(y){
        
    }
    

    void setValue(float v){
        value = v;
    }

    float getValue(){
        return value;
    }
};