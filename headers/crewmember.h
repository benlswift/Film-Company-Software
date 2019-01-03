#ifndef CREWMEMBER_H
#define CREWMEMBER_H
#include <string>
#include <abdkutility.h>
namespace ABDK {


class CrewMember
{
public:
    CrewMember();
    int iD;
    std::string name;
    std::string to_string();
    CrewMember(std::string);
};
}
#endif // CREWMEMBER_H
