#include "crew.h"
#include "cataloguenode.h"
#include <iostream>
#include <fstream>
namespace ABDK{
Crew::Crew()
{

}

Crew::Crew(std::string toParse)
{
    int noOfActors = std::stoi(getNextValue(toParse));
    producer=getNextValue(toParse);
    director=getNextValue(toParse);
    writer=getNextValue(toParse);
    editor=getNextValue(toParse);
    prodDesigner=getNextValue(toParse);
    setDecorator=getNextValue(toParse);
    costumeDesigner=getNextValue(toParse);

    for(int i = 0;i<noOfActors;i++)
    {
        cast.InsertNode(0,new std::string(getNextValue(toParse)));
    }
}

std::string Crew::to_string()
{
    std::string output = std::to_string(cast.size())+",";
    output+=producer+",";
    output+=director+",";
    output+=writer+",";
    output+=editor+",";
    output+=prodDesigner+",";
    output+=setDecorator+",";
    output+=costumeDesigner+",";
    Iterator<std::string> itr = Iterator<std::string>(cast.head);
    while(itr.hasNext())
    {
        output+=itr.getNext()->name()+",";
    }
    return output;
}


//std::string Crew::findActor(std::string actor)
//{
//    //find actor in project tree
//    //return all projects with that actor
//    CatalogueNode * currNode = start;
//    int CurrIndex = 1;

//    while (currNode && currNode->project->theCrew.cast[CurrIndex] != actor)
//    {
//        currNode = currNode->next;
//        CurrIndex++;
//    }

//    if (currNode->project->theCrew.cast[CurrIndex] == actor)
//    {
//        return CurrIndex;
//    }

//    return currNode->project;
//    return 0;
//}
}

