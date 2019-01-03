#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
//#include <project.h>
namespace ABDK
{
    //Materials are the format of the film:
    //can be single sided DVD, double sided DVD, Blu-ray,VHS or combo box (2 or more DVDs)
    class Material
    {
        //: public Project// error: expected class-name before '{' token ---ARGHHHHHHHHHHHHHHHH!!!!!!!!!!!!!!!!!!!!!!
    public:
        Material(int);
        Material(std::string);//this constructor parses a string to get the values for the material
        std::string to_string();


        int IDNumber;
        std::string title;//may not be project title
        std::string format;
        std::string audioFormat;
        double runTime;//could inherit from project
        std::string language;//could inherit from project
        double price;
        std::string subtitles;
        std::string frameAspect;
        std::string packaging(std::string);//validation for packaging
    };
}

#endif // MATERIAL_H
