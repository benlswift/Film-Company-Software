#include "node.h"
namespace ABDK{
Node<Material>::Node(Material * ptr)
{
elementPtr=ptr;
id=elementPtr->IDNumber;
}

std::string Node<Material>::name(){
    return elementPtr->title;
}

Node<CrewMember>::Node(CrewMember * ptr)
{
elementPtr=ptr;
id=elementPtr->iD;
}

std::string Node<CrewMember>::name(){
    return elementPtr->name;
}



Node<int>::Node(int inputInt){
id =inputInt;
}



std::string Node<int>::name(){
 return std::to_string(id);
}

Node<std::string>::Node(std::string* str_)
{
    elementPtr=str_;
}

std::string Node<std::string>::name()
{
    if(elementPtr!=nullptr)
    {
        return *elementPtr;
    }
    else
    {
        return "";
    }
}





}
