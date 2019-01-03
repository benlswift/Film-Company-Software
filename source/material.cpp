#include "material.h"
#include <abdkutility.h>

namespace ABDK
{
    Material::Material(int id_)
	{
        IDNumber = id_;
    }

    Material::Material(std::string strToParse){
        IDNumber=std::stoi(getNextValue(strToParse));
        title=getNextValue(strToParse);
        format=getNextValue(strToParse);
        audioFormat=getNextValue(strToParse);
        runTime=std::stod(getNextValue(strToParse));
        language=getNextValue(strToParse);
        price=std::stod(getNextValue(strToParse));
        subtitles=getNextValue(strToParse);
        frameAspect=getNextValue(strToParse);
    }

std::string Material::to_string(){
return std::to_string(IDNumber)+","+title+","+format+","+
        audioFormat+","+std::to_string(runTime)+","+language+
        ","+std::to_string(price)+","+subtitles+","+frameAspect+
        ",EOL \n";
}

    std::string Material::packaging(std::string format)
    {
        return "plastic";
    }








}
