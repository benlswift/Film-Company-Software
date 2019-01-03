#ifndef MATERIALList_H
#define MATERIALList_H

#include <string>
#include "iterator.h"

#include <iostream>
#include<fstream>

namespace ABDK
{
template <class T>
    class List
	{
	public:
        List(); // constructor
        ~List(); // destructor

		bool IsEmpty() { return head == NULL; }
        Node<T> * InsertNode(int, T*);//given node inserted at given index
        int FindIndex(int);//index of first occurance of id returned
        int FindIndex(std::string);//index of first occurance of name returned
        Node<T>* FindNode(int);//Node ptr of first occurance of id returned
        Node<T>* FindNode(std::string);//Node ptr of first occurance of name returned
        Node<T>* Index(int);//Node ptr at given index returned
        int DeleteNode(int);//deletes node at given index
        void DisplayList(void); // Displays the linked List
        void save(std::string);
        void load(std::string);
        int size();
        bool contains(std::string);
        void push(T);
        void push_back(T);

        Node<T> * head;
	};

    template<class Y>
    void List<Y>::push(Y in_)
    {
        Y* ptr = new Y(in_);
        InsertNode(0,ptr);
    }

template<class Y>
    bool List<Y>::contains(std::string strVar)
    {
        Node<Y>* temp = head;
        while(temp!=nullptr&&temp->name()!="")
        {
            if(temp->elementPtr!=nullptr)
            {
            if(temp->name()==strVar)
            {
                return true;
            }
            }
            temp = temp->next;
        }

        return false;
    }




    template <class Y>
    List<Y>::List()
    {
        head = NULL;
    }

template<class Y>
    int List<Y>::size(){
        int ctr=0;
        Node<Y>* CurrNode = head;
        while(CurrNode){
            ctr++;
            CurrNode=CurrNode->next;
        }
        return ctr;
    }



 template <class Y>
    void List<Y>::save(std::string fileName){
        std::ofstream myfile;
        myfile.open(fileName);
        Node<Y>* CurrNode = head;
        while(CurrNode){
            myfile << CurrNode->elementPtr->to_string();
        CurrNode=CurrNode->next;
        }

        myfile.close();
    }
 template <class Y>
    void List<Y>::load(std::string fileName){
        std::string line;
        std::ifstream myfile(fileName);
        if (myfile.is_open())
        {

            while ( std::getline(myfile,line) )
            {
                InsertNode(0,new Y(line));
            }
            myfile.close();
        }
    }





    template <class Y>
    Node<Y> * List<Y>::Index(int index)
    {
        int CurrIndex =1;
        Node<Y> * CurrNode = head;
        while (CurrNode && index > CurrIndex)
        {
            CurrNode = CurrNode->next;
            CurrIndex++;
        }
        if (CurrNode){
            return CurrNode;
        }
    }


    template <class Y>
    Node<Y> * List<Y>::InsertNode(int index, Y* newVal)
    {
        if (index < 0)
        {
            return NULL;
        }

        int CurrIndex = 1;

        Node<Y> * CurrNode = head;
        Node<Y> * NewNode = new Node<Y>(newVal);

        while (CurrNode && index > CurrIndex)
        {
            CurrNode = CurrNode->next;
            CurrIndex++;
        }

        if (index > 0 && CurrNode == NULL)
        {
            return NULL;
        }



        if (index == 0)
        {
            NewNode->next = head;
            head = NewNode;
        }

        else
        {
            NewNode->next = CurrNode->next;
            CurrNode->next = NewNode;
        }
        return NewNode;
    }

    template <class Y>
    Node<Y>* List<Y>::FindNode(int iD)
    {
        Node<Y> * CurrNode = head;

        while (CurrNode && CurrNode->id != iD)
        {
            CurrNode = CurrNode->next;
        }

        if (CurrNode)
        {
            return CurrNode;
        }

        return nullptr;
    }

    template <class Y>
    Node<Y>* List<Y>::FindNode(std::string toFind)
    {
        Node<Y> * CurrNode = head;

        while (CurrNode && CurrNode->name() != toFind)
        {
            CurrNode = CurrNode->next;
        }

        if (CurrNode)
        {
            return CurrNode;
        }

        return nullptr;
    }

    template <class Y>
    int List<Y>::FindIndex(int iD)
    {
        Node<Y> * CurrNode = head;
        int CurrIndex = 1;

        while (CurrNode && CurrNode->id != iD)
        {
            CurrNode = CurrNode->next;
            CurrIndex++;
        }

        if (CurrNode)
        {
            return CurrIndex;
        }

        return 0;
    }

    template <class Y>
    int List<Y>::FindIndex(std::string nameToFind)
    {
        Node<Y> * CurrNode = head;
        int CurrIndex = 1;

        while (CurrNode && CurrNode->name() != nameToFind)
        {
            CurrNode = CurrNode->next;
            CurrIndex++;
        }

        if (CurrNode)
        {
            return CurrIndex;
        }

        return 0;
    }





    template <class Y>
    int List<Y>::DeleteNode(int iD)
    {
        Node<Y> * PrevNode = NULL;
        Node<Y> * CurrNode = head;
        int CurrIndex = 1;

        while (CurrNode && CurrNode->id != iD)
        {
            PrevNode = CurrNode;
            CurrNode = CurrNode->next;
            CurrIndex++;
        }

        if (CurrNode)
        {
            if (PrevNode)
            {
                PrevNode->next = CurrNode->next;
                delete CurrNode;
            }

            else
            {
                head = CurrNode->next;
                delete CurrNode;
            }
            return CurrIndex;
        }
        return 0;
    }

    template <class Y>
    void List<Y>::DisplayList()
    {
        int num = 0;
        Node<Y> * CurrNode = head;

        while (CurrNode != NULL)
        {
            std::cout <<"Id:\t"<< CurrNode->id << "\tName:\t"<< CurrNode->name() <<std::endl;
            CurrNode = CurrNode->next;
            num++;
        }

        std::cout << "Number of Nodes in the List: " << num << std::endl;
    }

    template <class Y>
    List<Y>::~List()
    {
        Node<Y> * CurrNode = head, *NextNode = NULL;

        while (CurrNode != NULL)
        {
            NextNode = CurrNode->next;
            // destroy the current Node
            delete CurrNode;
            CurrNode = NextNode;
        }
    }

//    template <>
//    class List<String>{

//    }
}

#endif // MATERIALList_H
