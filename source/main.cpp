#include <iostream>
#include <catalogue.h>
#include <controller.h>
#include "login.h"
#include <QApplication>

#include <iterator.h>


using namespace ABDK;

Catalogue* mainCat;
Controller* controller;
bool run=true;
void menu();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Login w;

    mainCat = new Catalogue();
    mainCat->load("test2.txt");

    controller = new Controller(&*mainCat);
    w.addListener(&*controller);



    w.show();

    return a.exec();



/*
Project*eg1,*eg2,*eg3;
eg1=new Project();
eg1->name="Bee Movie";
eg1->genre="Animated";
eg1->theCrew.director="Jim";
eg1->theCrew.cast.InsertNode(0,new std::string("Tim"));
eg1->theCrew.cast.InsertNode(0,new std::string("Jim"));
eg1->theCrew.cast.InsertNode(0,new std::string("Tim"));


eg2=new Project();
eg2->name="P2";



//eg3=new Project();





mainCat.addNode(eg1);
mainCat.addNode(eg2);
//mainCat.addNode(eg3);

mainCat.save("test2.txt");*/







//    while(run){
//        menu();
//    }
//    return 0;
}

void menu(){
    int menuVar;
    // std::cout << "Hello! Press 1 to see existing projects or 2 to add a new project" << std::endl;
    std::cout<<"Menu: \n1.) List existing Projects\n2.) Create a Project\n3.) View a Project\n";
    std::cin >> menuVar;

    switch (menuVar) {
    case 1:
    {
        std::cout<<"Catalogue size is: "<<mainCat->size();
        std::cout<<"\nCatalogue:\n";
//        List<std::string> listOfNames= mainCat.names();
        // Node<std::string>* loNNode = listOfNames.head;
        //        while(loNNode!=nullptr){
        //            std::cout<<loNNode->name()<<"\n";
        //            loNNode = loNNode->next;
        //        }

//        List<CrewMember> crewL;
//        crewL.load("outputTest.txt");
//        std::cout<<"crewTest: \n"<<crewL.size()<<std::endl;
//        Iterator<CrewMember> itr2 = Iterator<CrewMember>(crewL.head);
//        while(itr2.hasNext())
//        {
//            std::cout<<itr2.getNext()->name()<<std::endl;
//        }
//        std::cout<<std::endl;




        break;
    }
    case 2:
        break;
    case 3:
    {
        std::cout<<"Which Project?";
        std::string in_;
        std::cin >> in_;
        Iterator<std::string> itr = Iterator<std::string>(controller->GetProjectInfo(in_).head);
        while(itr.hasNext())
        {
            std::cout<<itr.getNext()->name()<<std::endl;
        }





        break;
    }
    case 0:
        run=false;
        break;
    default:
        std::cout<<"Invalid input\n";
        break;
    }
}


//std::string projInfo(Project* proj)
//{
//    if(proj==nullptr){
//        return "NULL";
//    }
//    std::string output = "\nName: "+ proj->name
//            +"\nGenre: "+proj->genre
//            +"\nDirector: "+proj->theCrew.director+"\n";
//    return output;
//}


