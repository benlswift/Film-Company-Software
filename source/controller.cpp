#include "controller.h"
namespace ABDK {



Controller::Controller()
{

}



Controller::Controller(Model* model_)
{
    model=model_;
    model->load(savefilename);
}

bool Controller::checkPw(std::string u_,std::string p_)
{
    if(u_=="admin"&&p_=="admin")
    {
        return true;
    }
    else
    {
        return false;
    }
}

List<std::string> Controller::allProjInfo(Project* proj)
{
    List<std::string> outputL;
    if(proj==nullptr){
        return outputL;
    }

    outputL.InsertNode(0,new std::string(proj->summary));
    outputL.InsertNode(0,new std::string(proj->name));
    outputL.InsertNode(0,new std::string(proj->genre));
    outputL.InsertNode(0,new std::string(proj->language));
    outputL.InsertNode(0,new std::string(proj->filmLocations));
    outputL.InsertNode(0,new std::string(proj->keywords));



    return outputL;
}

List<std::string> Controller::GetAllProjectInfo(std::string proName)
{
    return allProjInfo(model->findNode(proName)->project);

}


List<std::string> Controller::projInfo(Project* proj)
{
    List<std::string> outputL;
    if(proj==nullptr){
        return outputL;
    }
    Iterator<Material> itr2 = Iterator<Material>(proj->listOfMaterials.head);
    while(itr2.hasNext())
    {
        outputL.InsertNode(0,new std::string(itr2.getNext()->elementPtr->format));
    }
    outputL.InsertNode(0,new std::string("Available in the following formats:"));
    outputL.InsertNode(0,new std::string("Director:\t"+proj->theCrew.director));
    outputL.InsertNode(0,new std::string("Genre:\t"+proj->genre));
    outputL.InsertNode(0,new std::string("Name:\t"+proj->name));


    return outputL;
}


List<std::string> Controller::GetProjectInfo(std::string proName)
{
    return projInfo(model->findNode(proName)->project);

}

std::string Controller::GetProjectInfoString(std::string proName_)
{
    std::string output="";
    List<std::string> tempL = GetProjectInfo(proName_);
    Iterator<std::string> itr = Iterator<std::string>(tempL.head);
    output += "Name: "+itr.getNext()->name()
            +"Genre: "+itr.getNext()->name()
            +"Director: "+itr.getNext()->name();
    while(itr.hasNext())
    {
        output+=itr.getNext()->name();
    }
    return output;
}

void Controller::addProject(std::string name_,
                            std::string description_,
                            std::string genre_,
                            std::string language_,
                            std::string location_,
                            std::string keywords_
                            )
{
    Project * pNew = new Project();
    pNew->name=name_;
    pNew->summary=description_;
    pNew->genre=genre_;
    pNew->language=language_;
    pNew->filmLocations=location_;
    pNew->keywords=keywords_;
    model->addNode(pNew);
    model->save(savefilename);

}

List<std::string> Controller::getProjectsOfActor(std::string aName)
{
    return model->namesWithActor(aName);
}

List<std::string> Controller::getProjectNames()
{
    return model->names();
}

void Controller::addMaterial(std::string pName,
                             std::string title_,
                             std::string format_,
                             std::string audioformat_,
                             double runTime_,
                             std::string language_,
                             double price_,
                             std::string subtitles_,
                             std::string frameAspect_
                             )
{
    Project * pTmp = model->findNode(pName)->project;
    Material * mNew = new Material(99);
    mNew->title=title_;
    mNew->format=format_;
    mNew->audioFormat=audioformat_;
    mNew->runTime=runTime_;
    mNew->language=language_;
    mNew->price=price_;
    mNew->subtitles=subtitles_;
    mNew->frameAspect=frameAspect_;
    pTmp->listOfMaterials.InsertNode(0,mNew);
    model->save(savefilename);
}


void Controller::addCrew(std::__cxx11::string pName,
                         std::__cxx11::string producer,
                         std::__cxx11::string director,
                         std::__cxx11::string writer,
                         std::__cxx11::string editor,
                         std::__cxx11::string prodDesigner,
                         std::__cxx11::string setDecorator,
                         std::__cxx11::string costumeDesigner)
{
    Project * pTmp = model->findNode(pName)->project;
    Crew  cNew;
    cNew.producer=producer;
    cNew.director=director;
    cNew.writer=writer;
    cNew.editor=editor;
    cNew.prodDesigner=prodDesigner;
    cNew.costumeDesigner=costumeDesigner;
    pTmp->theCrew=cNew;
}


}
