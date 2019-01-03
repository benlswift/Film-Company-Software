#include "crewmember.h"
namespace ABDK {


CrewMember::CrewMember()
{

}

CrewMember::CrewMember(std::string strToParse){
iD=std::stoi(getNextValue(strToParse));
name=getNextValue(strToParse);
}


std::string CrewMember::to_string(){
    return std::to_string(iD) +", "+ name+",EOL \n";
}
}
