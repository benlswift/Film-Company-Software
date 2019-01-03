    #ifndef NODE_H
#define NODE_H
#include "material.h"
#include <crewmember.h>
#include <string>
namespace ABDK{

template <class T>
class Node
{

public:
    Node();
    Node* next;
    int id;
    T * elementPtr;
    std::string name();
};

template<>
class Node<std::string>
{
public:
    Node(std::string*);
    Node* next;
    std::string * elementPtr;
    int id;
    std::string name();
};


template<>
class Node<Material>
{
public:
    Node(Material*);
    Node* next;
    Material * elementPtr;
    int id;
    std::string name();
};

template<>
class Node<CrewMember>
{
public:
    Node(CrewMember*);
    Node* next;
    CrewMember * elementPtr;
    int id;
    std::string name();
};

template<>
class Node<int>
{
public:
    Node(int);
    Node* next;
    int id;
    std::string name();
};

//template<>
//class Node<String>
//{
//public:
//    Node* next;

//};


}
#endif // NODE_H
