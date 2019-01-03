#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include <list.h>
#include <crew.h>
namespace ABDK{

class Project
{
public:
    List<Material> listOfMaterials;

    Project(std::string);
    Project();
    std::string name;
    std::string summary;
    std::string genre;
    std::string releaseDate;
    std::string filmLocations;
    std::string language;
    double runTime =0;
    std::string keywords;
    int ticketSales =0;//needs validation - unreleased material shouldn't allow ticket sales
    Crew theCrew;//add the crew
    enum Status {unreleased=1,released=2,nowplaying=3} status = unreleased;
};

}

#endif // PROJECT_H

