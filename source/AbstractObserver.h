
class AbstractObserver{
    
    public:
        virtual ~AbstractObserver(){};
     
        virtual float Update(int col, float m[][5]) = 0;
};