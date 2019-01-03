#include "project.h"
namespace ABDK{
Project::Project(std::string line)
{
    name = getNextValue(line);
    summary = getNextValue(line);
    genre = getNextValue(line);
    releaseDate = getNextValue(line);
    filmLocations = getNextValue(line);
    language = getNextValue(line);
    runTime = std::stod(getNextValue(line));
    keywords = getNextValue(line);
    ticketSales =std::stoi(getNextValue(line));
    status =static_cast<Status>(std::stoi(getNextValue(line)));
}

Project::Project()
{

}

}
