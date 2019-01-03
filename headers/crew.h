#ifndef CREW_H
#define CREW_H
#include <string>
#include <list.h>
#include <iterator.h>

namespace ABDK{
//
class Crew
{
public:
    Crew();
    Crew(std::string);
    std::string to_string();
    std::string producer;
    std::string director;
    std::string writer;
    //std::list<std::string> actors;
//    std::string findActor(std::string actor);
    //Cast:
    //a list of actors
    //must be associated with a project
    //each actor can be associated with multiple projects
    //store list of actors in project tree
    std::string editor;
    std::string prodDesigner;
    std::string setDecorator;
    std::string costumeDesigner;
    List<std::string> cast;

};
}
#endif // CREW_H
