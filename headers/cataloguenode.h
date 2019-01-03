#ifndef CATALOGUENODE_H
#define CATALOGUENODE_H
#include <project.h>

namespace ABDK{
class CatalogueNode //: public Node
{
public:
    CatalogueNode();
    CatalogueNode* next;

    CatalogueNode* minorNext;
    Project* project;
};
}
#endif // CATALOGUENODE_H
