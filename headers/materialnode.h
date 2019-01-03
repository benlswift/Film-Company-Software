#ifndef MATERIALNODE_H
#define MATERIALNODE_H

#include "material.h"
#include "node.h"


namespace ABDK
{
    class Material_Node //: public Node
	{
	public:
        //std::string data; // data
        Material_Node();
        Material * material_ptr;
        //Material_Node * next; // pointer to next
	};
}

#endif // MATERIALNODE_H
