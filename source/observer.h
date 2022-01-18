#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class Observer{
    public:
        void Update(wxGrid &a, wxGrid &b){
            int sum = 0;
            float mean;
            int max = -100000000;
            int min = 100000000;
            int prod = 1;
            int count = 0;
            for(int i = 0; i < a.GetNumberRows(); i++){
                for(int j = 0; j < a.GetNumberCols(); j++){
                    if(a.GetCellValue(i,j) != ""){
                        auto value = wxAtoi(a.GetCellValue(i,j));
                        count++;
                        sum += value;
                        prod *= value;
                        if(value > max)
                            max = value;
                        if(value < min)
                            min = value;
                    }
                }
            }
            mean = float(sum / count);

            b.SetCellValue(0,0,std::to_string(sum));
            b.SetCellValue(0,1,std::to_string(mean));
            b.SetCellValue(0,2,std::to_string(max));
            b.SetCellValue(0,3,std::to_string(min));
            b.SetCellValue(0,4,std::to_string(prod));
        }
};