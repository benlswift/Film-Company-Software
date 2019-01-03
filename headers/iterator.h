#ifndef ITERATOR_H
#define ITERATOR_H

#include <node.h>

namespace ABDK {


template<class T>
class Iterator
{
    Node<T> * currNode;
public:
    Iterator(Node<T> *);
    bool hasNext();
    Node<T> * getNext();
};

template<class Y>
Iterator<Y>::Iterator(Node<Y> * in_)
{
    currNode=in_;
}




template<class Y>
bool Iterator<Y>::hasNext(){
    if(currNode!=nullptr){
        return true;
    }
    else
    {
        return false;
    }
}

template<class Y>
Node<Y> * Iterator<Y>::getNext()
{
    Node<Y>* temp = currNode;
    currNode=currNode->next;
    return temp;
}







}
#endif // ITERATOR_H
