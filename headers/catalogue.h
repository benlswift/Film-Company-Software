#ifndef CATALOGUE_H
#define CATALOGUE_H
#include<cataloguenode.h>
#include <abdkutility.h>
#include<iterator.h>
#include <string>

#include <iostream>
#include <fstream>

namespace ABDK{

class Catalogue
{
public:

    Catalogue();
    CatalogueNode *current, *temp, *trail, *p, *q =nullptr;
    CatalogueNode *first =nullptr;
    void addNode(Project*);
    CatalogueNode* findParent(CatalogueNode* childNode);
    CatalogueNode* findNode(std::string name_);
    void DeleteNode(CatalogueNode* nodeToGo);
    void save(std::string fileName);
    void load(std::string fileName);
    int size();
    List<std::string> namesWithActor(std::string);
    List<std::string> names();

private:
    void preOrderT(CatalogueNode* startPoint,  std::ofstream& myfile);
    void sizePreOrderTraversal(CatalogueNode* startPoint,int& currSize);
    void namesInOrderT(CatalogueNode* startPoint, List<std::string>&);
    void namesInOrderTWithActor(std::string actorName_,CatalogueNode* startPoint, List<std::string>& namesList);

};
}

#endif // CATALOGUE_H
