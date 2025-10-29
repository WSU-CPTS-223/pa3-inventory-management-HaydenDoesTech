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
 * File:        HashLinkedList.hpp                                             *
 * Description: This is the file that will hold the outline for the linked     *
 *              lists which will be included in all indexes of the inventory   *
 *              array.                                                         *
 ******************************************************************************/

 #pragma once // Guard code

 #include "HashNode.hpp"
 #include "HashData.hpp"
 #include <string>

 using namespace std;

 namespace HashLinkedList
 {
    template <class T>
    class HashLinkedList
    {
    public:
        // Default constructor
        HashLinkedList();
        // Destructor - invoked when HashLinkedList object goes out of scope
        ~HashLinkedList();
        // Getter functions for the private members of the class
        HashNode::HashNode<T>* getHead();
        bool isEmpty();
        // Setter functions for the class
        void setHead(HashNode::HashNode<T>* newHead);
        void insertItem(string newUniqueId, string newProductName, string newBrandName, string newASIN, string newCategory,
            string newUpcEanCode, string newListPrice, string newSellingPrice, string newQuantity, string newModelNumber,
            string newAboutProduct, string newProductSpec, string newTechnicalDetails, string newShippingWeight,
            string newProductDimensions, string newImage, string newVariants, string newSku, string newProductUrl, 
            string newStock, string newProductDetails, string newDimensions, string newColor, string newIngredients,
            string newDirectionToUse, string newIsAmazonSeller, string newSizeQuantityVariant, string newProductDescription);
    private:
        HashNode::HashNode<T>* head;
    };
 }

template <class T>
HashLinkedList::HashLinkedList<T>::HashLinkedList()
{
    head = nullptr;
}

template <class T>
HashLinkedList::HashLinkedList<T>::~HashLinkedList()
{
    delete head;
}

template <class T>
HashNode::HashNode<T>* HashLinkedList::HashLinkedList<T>::getHead()
{
    return head;
}

template <class T>
bool HashLinkedList::HashLinkedList<T>::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }

    return false;
}

template <class T>
void HashLinkedList::HashLinkedList<T>::setHead(HashNode::HashNode<T>* newHead)
{
    head = newHead;
}

template <class T>
void HashLinkedList::HashLinkedList<T>::insertItem(string newUniqueId, string newProductName, string newBrandName, string newASIN, string newCategory,
            string newUpcEanCode, string newListPrice, string newSellingPrice, string newQuantity, string newModelNumber,
            string newAboutProduct, string newProductSpec, string newTechnicalDetails, string newShippingWeight,
            string newProductDimensions, string newImage, string newVariants, string newSku, string newProductUrl, 
            string newStock, string newProductDetails, string newDimensions, string newColor, string newIngredients,
            string newDirectionToUse, string newIsAmazonSeller, string newSizeQuantityVariant, string newProductDescription)
            {
                HashNode::HashNode<T>* previousPointer = nullptr;
                HashNode::HashNode<T>* currentPointer = head; 
                
                while (currentPointer != nullptr)
                {
                    previousPointer = currentPointer;
                    currentPointer = currentPointer->getMpNext();
                }

                // If it is nullptr, we are making the first item in the linked list, so we will set it as the head
                if (currentPointer == nullptr)
                {
                    head = new HashNode::HashNode<T>;

                    HashData* newData = new HashData(newUniqueId, newProductName, newBrandName, newASIN, newCategory, newUpcEanCode, newListPrice, 
                        newSellingPrice, newQuantity, newModelNumber, newAboutProduct, newProductSpec, newTechnicalDetails, newShippingWeight,
                        newProductDimensions, newImage, newVariants, newSku, newProductUrl, newStock, newProductDetails, newDimensions, newColor, 
                        newIngredients, newDirectionToUse, newIsAmazonSeller, newSizeQuantityVariant, newProductDescription);

                    head->setMpData(newData);
                }
                else 
                {
                    currentPointer = new HashNode::HashNode<T>;

                    HashData* newData = new HashData(newUniqueId, newProductName, newBrandName, newASIN, newCategory, newUpcEanCode, newListPrice, 
                        newSellingPrice, newQuantity, newModelNumber, newAboutProduct, newProductSpec, newTechnicalDetails, newShippingWeight,
                        newProductDimensions, newImage, newVariants, newSku, newProductUrl, newStock, newProductDetails, newDimensions, newColor, 
                        newIngredients, newDirectionToUse, newIsAmazonSeller, newSizeQuantityVariant, newProductDescription);

                    currentPointer->setMpData(newData);
                    previousPointer->setMpNext(currentPointer);
                }
            }