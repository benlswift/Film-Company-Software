#include "catalogue.h"
namespace ABDK{
Catalogue::Catalogue()
{

}

List<std::string> Catalogue::namesWithActor(std::string aName)
{
    List<std::string> temp;
    namesInOrderTWithActor(aName,first,temp);
    return temp;
}

void Catalogue::namesInOrderTWithActor(std::string actorName_,CatalogueNode* startPoint, List<std::string>& namesList)
{
    CatalogueNode* ptrTemp = startPoint;
    if ((ptrTemp != nullptr))
    {
        namesInOrderTWithActor(actorName_,ptrTemp->minorNext,namesList);
        if(ptrTemp->project->theCrew.cast.contains(actorName_))
        {
        namesList.InsertNode(0,new std::string(ptrTemp->project->name));
        }
        namesInOrderTWithActor(actorName_,ptrTemp->next,namesList);
    }
}



void Catalogue::namesInOrderT(CatalogueNode* startPoint, List<std::string>& namesList)
{
    CatalogueNode* ptrTemp = startPoint;
    if ((ptrTemp != nullptr))
    {
        namesInOrderT(ptrTemp->minorNext,namesList);
//        namesString += ptrTemp->project->name +"\n";
        namesList.InsertNode(0,new std::string(ptrTemp->project->name));
        namesInOrderT(ptrTemp->next,namesList);
    }
}

List<std::string> Catalogue::names()
{
    List<std::string> temp;
    namesInOrderT(first,temp);
    return temp;
}


//CatalogueNode* Catalogue::index(int index){
// //    CatalogueNode* ptrTemp = first;
// //    while (!(ptrTemp->next==nullptr&&ptrTemp->minorNext==nullptr)){
// //    }

//    CatalogueNode* ptrTemp = first;
//    while ((ptrTemp != childNode) && (ptrTemp != nullptr))
//    {

//        checkAlphabeticalOrder( ptrTemp->project->name , childNode->project->name)
//    if ()
//        {
//            ptrTemp->minorNext=ptrTemp;
//        }
//    else
//        {
//        ptrTemp->next = ptrTemp;
//}
//    }
//    return ptrTemp;

//}












void Catalogue::DeleteNode(CatalogueNode* nodeTogo)
{
    CatalogueNode* ptrPTemp = findParent(nodeTogo);
    if (nodeTogo = ptrPTemp->minorNext)ptrPTemp->minorNext = nodeTogo->next;
    else if (nodeTogo = ptrPTemp->next)ptrPTemp->next = nodeTogo->next;

}

CatalogueNode* Catalogue::findParent(CatalogueNode* childNode)
{
    CatalogueNode* ptrPTemp =nullptr;
    CatalogueNode* ptrTemp = first;
    while ((ptrTemp != childNode) && (ptrTemp != nullptr))
    {
        ptrPTemp = ptrTemp;
       // if (ptrTemp->data > childNode->data) ptrTemp->minorNext=ptrTemp;
        //else ptrTemp->next = ptrTemp;
    if (checkAlphabeticalOrder( ptrTemp->project->name , childNode->project->name))ptrTemp->minorNext=ptrTemp;
    else ptrTemp->next = ptrTemp;

    }
    return ptrPTemp;
}
CatalogueNode* Catalogue::findNode(std::string name_)
{
    CatalogueNode* ptrTemp = first;
    while ((ptrTemp->project->name != name_) && (ptrTemp != nullptr))
    {
       // if (ptrTemp->data > childNode->data) ptrTemp->minorNext=ptrTemp;
        //else ptrTemp->next = ptrTemp;
    if (!checkAlphabeticalOrder( ptrTemp->project->name,name_ ))
    {
        ptrTemp=ptrTemp->minorNext;
    }
        else
    {
        ptrTemp= ptrTemp->next;
    }
        if(ptrTemp==nullptr)
    {
        return ptrTemp;
    }
    }
    return ptrTemp;
}

void Catalogue::addNode(Project* nodeToAdd) {
    CatalogueNode * newNode = new CatalogueNode;
    CatalogueNode * ptrTemp = first;
    CatalogueNode * ptrTemp2 = ptrTemp;
    if (first == nullptr) first = newNode;
    else
    {

        while (ptrTemp != nullptr)
        {
            ptrTemp2 = ptrTemp;
            //if (ptrTemp->data >= data) ptrTemp = ptrTemp->minorNext;
            if (!checkAlphabeticalOrder( ptrTemp->project->name, nodeToAdd->name)) ptrTemp = ptrTemp->minorNext;
            else ptrTemp = ptrTemp->next;
        }
        if (!checkAlphabeticalOrder( ptrTemp2->project->name, nodeToAdd->name))ptrTemp2->minorNext=newNode;
        else ptrTemp2->next=newNode;
    }

    newNode->project = nodeToAdd;
    newNode->minorNext = nullptr;
    newNode->next = nullptr;


}

void Catalogue::sizePreOrderTraversal(CatalogueNode* startPoint,int& currSize)
{
    CatalogueNode* ptrTemp = startPoint;
    if ((ptrTemp != nullptr))
    {
        currSize++;
        sizePreOrderTraversal(ptrTemp->minorNext,currSize);
        sizePreOrderTraversal(ptrTemp->next,currSize);
    }
}

int Catalogue::size(){
    int temp=0;
    sizePreOrderTraversal(first,temp);
    return temp;
}

void Catalogue::preOrderT(CatalogueNode* startPoint,  std::ofstream& myfile)
{
    CatalogueNode* ptrTemp = startPoint;
    if ((ptrTemp != nullptr))
    {
        std::string materials= std::to_string(ptrTemp->project->listOfMaterials.size())+"\n";
        Iterator<Material> itr = Iterator<Material>(ptrTemp->project->listOfMaterials.head);
        while(itr.hasNext())
        {
            materials+=itr.getNext()->elementPtr->to_string();
        }

        myfile << ptrTemp->project->name<<","
               << ptrTemp->project->summary<<","
               << ptrTemp->project->genre<<","
               << ptrTemp->project->releaseDate<<","
               << ptrTemp->project->filmLocations<<","
               << ptrTemp->project->language<<","
               << ptrTemp->project->runTime<<","
               << ptrTemp->project->keywords<<","
               << ptrTemp->project->ticketSales<<","
               <<static_cast<int>(ptrTemp->project->status)<<","
               <<"EOL \n"
               << ptrTemp->project->theCrew.to_string()<<","
               <<"\n"<<materials;

        preOrderT(ptrTemp->minorNext, myfile);
        preOrderT(ptrTemp->next, myfile);
    }

}



//void Catalogue::saveMaterialsRoster(std::string fileName){
//    std::ofstream myfile;
//    myfile.open(fileName);
//    Node<Material>* CurrNode = materialsRoster.head;
//    while(CurrNode){
//        myfile << CurrNode->elementPtr->to_string();
//    }

//    myfile.close();
//}

//void Catalogue::loadMaterialsRoster(std::string fileName){
//    std::string line;
//    std::ifstream myfile(fileName);
//    if (myfile.is_open())
//    {

//        while ( getline(myfile,line) )
//        {
//            materialsRoster.InsertNode(0,new Material(line));
//        }
//        myfile.close();
//    }
//}



void Catalogue::save(std::string fileName){
    std::ofstream myfile;
    myfile.open(fileName);
    preOrderT(first,myfile);

    myfile.close();
}




void Catalogue::load(std::string fileName){
try
    {
    std::string line;
    std::ifstream myfile(fileName);

    if (myfile.is_open())
    {

        while ( getline(myfile,line) )
        {
            Project* temp = new Project(line);

            if(getline(myfile,line))
            {
                temp->theCrew = Crew(line);
            }
            if(getline(myfile,line))
            {
                int numOfMats=std::stoi(line);
                for(int i=0;i<numOfMats;i++)
                {
                    temp->listOfMaterials.InsertNode(0,new Material(line));
                }
            }


            addNode(temp);

        }
        myfile.close();
    }

}

catch (const std::exception& e)
{
save(fileName);
}
}
}
