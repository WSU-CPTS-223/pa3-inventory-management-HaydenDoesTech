/*******************************************************************************
 * Programmer:             Hayden LaCelle                                      *
 *                         hayden.lacelle@wsu.edu                              *
 * Class:                  CPT_S 223; Section 01                               *
 * Programming Assignment: PA #3 - Inventory Management                        *
 * Date (Finalized):       ##/##/####                                          *
 *                                                                             *
 * Program:     Amazon Product Inventory Management                            *
 * Description: A command line REPL system that allows users to query the      *
 *              Amazon inventory. A user can find if a product exists, or      *
 *              products in a specific category.                               *
 *                                                                             *
 * File:        HashNode.hpp                                                   *
 * Description: This is the file for individual elements in a HashLinkedList.  *
 ******************************************************************************/

 #pragma once // Guard code

 #include "HashData.hpp"

 namespace HashNode
{
    template <class T>
    class HashNode
    {
    public:
        // Default constructor
        HashNode();
        // Destructor - invoked when CommandNode object goes out of scope
        ~HashNode();

        // Setter functions for the class
        void setMpData(HashData* newMpData);
        void setMpNext(HashNode::HashNode<T>* newMpNext);

        // Getter functions for the class
        HashData* getMpData() const;
        HashNode::HashNode<T>* getMpNext() const;
    private:
        HashData* mpData; 
        HashNode::HashNode<T>* mpNext;
    };
}


template <class T>
HashNode::HashNode<T>::HashNode()
{
    mpData = nullptr;
    mpNext = nullptr;
}

template <class T>
HashNode::HashNode<T>::~HashNode()
{
    delete mpData;
}

template <class T>
void HashNode::HashNode<T>::setMpData(HashData* newMpData)
{
    mpData = newMpData;
}

template <class T>
void HashNode::HashNode<T>::setMpNext(HashNode* newMpNext)
{
    mpNext = newMpNext;
}

template <class T>
HashData* HashNode::HashNode<T>::getMpData() const
{
    return mpData;
}

template <class T>
HashNode::HashNode<T>* HashNode::HashNode<T>::getMpNext() const
{
    return mpNext;
}