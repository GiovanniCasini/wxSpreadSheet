#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class Observer{
    public:
        void Update(wxGrid a, wxGrid b){
            auto size = a.GetSize();
            float sum = 0;
            for(int i=0;i<size.GetWidth();i++){
                for(int j=0;j<size.GetHeight();j++){
                    if(a.GetCellValue(i,j) != "")
                        sum += wxAtof(a.GetCellValue(i,j));
                }

            }
            b.SetCellValue(0,0,std::to_string(sum));
        }
};