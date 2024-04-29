#include "iostream"
using namespace std;

class Shap{
   float area;
   public:
   Shap(float a): area(a){}

   Shap operator+(Shap &obj){
    return this->area + obj.area;
   }
   float getarea(){
    return area;
   }


};
int main(int argc, char const *argv[])
{
    Shap Shap1(10.9),Shap2(2.0);
     Shap Shap3 = Shap1 + Shap2;
     cout<<Shap3.getarea()<<endl;
    
    return 0;
}
