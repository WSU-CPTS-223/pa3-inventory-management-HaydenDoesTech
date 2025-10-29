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
 * File:        InventoryWrapper.hpp                                           *
 * Description: This is the source file for the inventory application. It      *
 *              holds function declarations for displaying/validating commands *
 *              and their actions, as well as the initialization of the        *
 *              program.                                                       *
 ******************************************************************************/

#include "InventoryWrapper.hpp"
#include <fstream>
#include <string>
#include "HashNode.hpp"
#include <cstring>

using namespace std;

// Constructor
InventoryWrapper::InventoryWrapper()
{
    // Inventory ID's are 32 characters long... 32 characters * 127 characters in the ASCII table = 4064 spots in the hashtable array
    // 10,002 items in the .csv file... Array of linked lists!
    ;
}

void InventoryWrapper::printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool InventoryWrapper::validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void InventoryWrapper::evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        int uniqueIdIndexConv = 0;
        string uniqueIdLooked = "";
        for (int character = 5; character < strlen(line) - 1; ++character) // Ignore "find " when finding the index of the searched unique ID
        {
            uniqueIdIndexConv = uniqueIdIndexConv + line[character];
            uniqueIdLooked = uniqueIdLooked + line[character];
        }

        if (hashTable[uniqueIdIndexConv] == nullptr)
        {
            cout << "\nSorry, no item with that ID exists.\n" << endl;
        }
        else
        {
            int itemFound = 0;

            HashNode::HashNode<HashData>* currentPointer = hashTable[uniqueIdIndexConv].getHead();
            while (currentPointer != nullptr && itemFound != 1)
            {
                if (currentPointer->getMpData()->getUniqueId() == uniqueIdLooked)
                {
                    cout << "\nItem found!\n\n  Unique ID: " + currentPointer->getMpData()->getUniqueId() + "\n  Product Name: " + 
                            currentPointer->getMpData()->getProductName() + "\n  Brand Name: " + currentPointer->getMpData()->getBrandName() 
                            + "\n  ASIN: " + currentPointer->getMpData()->getASIN() + "\n  Category: " + currentPointer->getMpData()->getCategory() 
                            + "\n  UPC/EAN Code: " + currentPointer->getMpData()->getUpcEanCode() + "\n  List Price: " + currentPointer->getMpData()->getListPrice()
                            + "\n  Selling Price: " + currentPointer->getMpData()->getSellingPrice() + "\n  Quantity: " + currentPointer->getMpData()->getQuantity()
                            + "\n  Model Number: " + currentPointer->getMpData()->getModelNumber() + "\n  About Product: " + currentPointer->getMpData()->getAboutProduct()
                            + "\n  Product Specifications: " + currentPointer->getMpData()->getProductSpec() + "\n  Technical Details: " + currentPointer->getMpData()->getTechnicalDetails()
                            + "\n  Shipping Weight: " + currentPointer->getMpData()->getShippingWeight() + "\n  Product Dimensions: " + currentPointer->getMpData()->getProductDimensions()
                            + "\n  Image: " + currentPointer->getMpData()->getImage() + "\n  Variants: " + currentPointer->getMpData()->getVariants() + "\n  SKU: "
                            + currentPointer->getMpData()->getSku() + "\n  Product URL: " + currentPointer->getMpData()->getProductUrl() + "\n  Stock: "
                            + currentPointer->getMpData()->getStock() + "\n  Product Details: " + currentPointer->getMpData()->getProductDetails()
                            + "\n  Dimensions: " + currentPointer->getMpData()->getDimensions() + "\n  Color: " + currentPointer->getMpData()->getColor() 
                            + "\n  Ingredients: " + currentPointer->getMpData()->getIngredients() + "\n  Direction to Use: " + currentPointer->getMpData()->getDirectionToUse() 
                            + "\n  Is Amazon Seller?: " + currentPointer->getMpData()->getIsAmazonSeller() + "\n  Size/Quantity/Variant: " + currentPointer->getMpData()->getSizeQuantityVariant()
                            + "\n  Product Description: " + currentPointer->getMpData()->getProductDescription() << endl;

                    itemFound = 1;
                }
                else
                {
                    currentPointer = currentPointer->getMpNext();
                }
            }

            // If we have gone through everything and the ID does not exist, fallback to the error message
            if (currentPointer == nullptr && itemFound == 0)
            {
                cout << "\nSorry, no item with that ID exists.\n" << endl;
            }
        }

    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        cout << "\nListings for inventory search query: " << endl;
        string inventoryLooked = "";
        for (int character = 14; character < strlen(line) - 1; ++character) // Ignore "listInventory " when finding the category of all items
        {
            inventoryLooked = inventoryLooked + line[character];
        }

        for (int i = 0; i < 4064; i++)
        {
            HashNode::HashNode<HashData>* currentPointer = hashTable[i].getHead();
            while (currentPointer != nullptr)
            {
                // rfind returns string::npos if the string is not found -- https://www.geeksforgeeks.org/cpp/stdstringrfind-in-c-with-examples/
                if (currentPointer->getMpData()->getCategory().rfind(inventoryLooked) != string::npos)
                {
                    cout << "Unique ID: " + currentPointer->getMpData()->getUniqueId() + " | Product Name: " + currentPointer->getMpData()->getProductName() << endl;
                }
                currentPointer = currentPointer->getMpNext();
            }
        }
    }
}

void InventoryWrapper::bootStrap()
{
    cout << "\n We are loading the Query System, one moment..." << endl;
    // Read from CSV
    fstream inventoryFile;
    inventoryFile.open("inventory.csv");

    // Temporary variables used for creating nodes in the list
    string uniqueId, productName, brandName, asin, category, upcEanCode, listPrice,
    sellingPrice, quantity, modelNumber, aboutProduct, productSpec, technicalDetails,
    shippingWeight, productDimensions, image, variants, sku, productUrl, stock,
    productDetails, dimensions, color, ingredients, directionToUse, isAmazonSeller,
    sizeQuantityVariant, productDescription;
    int uniqueIdIndexConv = 0;

    char* convertedLine = new char[7000]; // strtok is a C function, so we have to convert our lines in the
                                          // inventory.csv file to a C string for it to be compatible

	// This will hold individual lines of inventory.csv (changes for each line)
    string line = "";

    getline(inventoryFile, line); // Skip header

    while (getline(inventoryFile, line))
    {
        free(convertedLine); // Clears convertedLine's memory use, if there is any
        convertedLine = new char[7000];
        int chars = 0;
        // We do this to add a null terminator at the end of the C string array. Otherwise, it wouldn't
		// be considered a string array (at least in C).
		for (; line[chars] != '\0'; ++chars)
		{
			convertedLine[chars] = line[chars];
		}
		convertedLine[chars] = '\0';

        // Grab unique ID, and do an ASCII converstion to determine index
        uniqueId = strtok(convertedLine, ",");
        for (int character = 0; character < strlen(uniqueId) - 1; ++character) 
        {
            uniqueIdIndexConv = uniqueIdIndexConv + uniqueId[character];
        }

        // * All future strtok calls from now on will check if the value has quotation marks.
        // If they do, a ", delimiter will be used. Otherwise, the normal , delimiter will be
        // used.
        if (convertedLine[strlen(uniqueId) - 1 + 1] == '"')
        {
            productName = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            productName = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + 1] == '"')
        {
            brandName = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            brandName = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + 1] == '"')
        {
            asin = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            asin = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + 1] == '"')
        {
            category = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            category = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + 1] == '"')
        {
            upcEanCode = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            upcEanCode = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 + 1] == '"')
        {
            listPrice = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            listPrice = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + 1] == '"')
        {
            sellingPrice = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            sellingPrice = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + 1] == '"')
        {
            quantity = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            quantity = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + 1] == '"')
        {
            modelNumber = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            modelNumber = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + 1] == '"')
        {
            aboutProduct = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            aboutProduct = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + 1] == '"')
        {
            productSpec = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            productSpec = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 1] == '"')
        {
            technicalDetails = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            technicalDetails = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + 1] == '"')
        {
            shippingWeight = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            shippingWeight = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + 1] == '"')
        {
            productDimensions = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            productDimensions = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + 1] == '"')
        {
            image = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            image = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + 1] == '"')
        {
            variants = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            variants = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + 1] == '"')
        {
            sku = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            sku = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 1] == '"')
        {
            productUrl = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            productUrl = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + 1] == '"')
        {
            stock = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            stock = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + strlen(stock) - 1 + 1] == '"')
        {
            productDetails = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            productDetails = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + strlen(stock) - 1 + strlen(productDetails) - 1 + 1] == '"')
        {
            dimensions = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            dimensions = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + strlen(stock) - 1 + strlen(productDetails) - 1 + strlen(dimensions) - 1 + 1] == '"')
        {
            color = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            color = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + strlen(stock) - 1 + strlen(productDetails) - 1 + strlen(dimensions) - 1 + strlen(color) - 1 + 1] == '"')
        {
            ingredients = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            ingredients = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + strlen(stock) - 1 + strlen(productDetails) - 1 + strlen(dimensions) - 1 + strlen(color) - 1 + strlen(ingredients) - 1 + 1] == '"')
        {
            directionToUse = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            directionToUse = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + strlen(stock) - 1 + strlen(productDetails) - 1 + strlen(dimensions) - 1 + strlen(color) - 1 + strlen(ingredients) - 1 + 
            strlen(directionToUse) - 1 + 1] == '"')
        {
            isAmazonSeller = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            isAmazonSeller = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + strlen(stock) - 1 + strlen(productDetails) - 1 + strlen(dimensions) - 1 + strlen(color) - 1 + strlen(ingredients) - 1 + 
            strlen(directionToUse) - 1 + strlen(isAmazonSeller) - 1 + 1] == '"')
        {
            sizeQuantityVariant = strtok(NULL, "\","); // NULL tells strtok we are still working with the same line
        }
        else
        {
            sizeQuantityVariant = strtok(NULL, ",");
        }

        if (convertedLine[strlen(uniqueId) - 1 + strlen(productName) - 1 + strlen(brandName) - 1 + strlen(asin) - 1 + strlen(category) - 1 + strlen(upcEanCode) - 1 
            + strlen(listPrice) - 1 + strlen(sellingPrice) - 1 + strlen(quantity) - 1 + strlen(modelNumber) - 1 + strlen(aboutProduct) - 1 + strlen(productSpec) - 1 + 
            strlen(technicalDetails) - 1 + strlen(shippingWeight) - 1 + strlen(productDimensions) - 1 + strlen(image) - 1 + strlen(variants) - 1 + strlen(sku) - 1 + 
            strlen(productUrl) - 1 + strlen(stock) - 1 + strlen(productDetails) - 1 + strlen(dimensions) - 1 + strlen(color) - 1 + strlen(ingredients) - 1 + 
            strlen(directionToUse) - 1 + strlen(isAmazonSeller) - 1 + strlen(sizeQuantityVariant) - 1 + 1] == '"')
        {
            productDescription = strtok(NULL, '"\0'); // \0 (null terminator) to indicate that we reached the end of the line 
        }
        else
        {
            productDescription = strtok(NULL, "\0");
        }

        hashTable[uniqueIdIndexConv].insertItem(uniqueId, productName, brandName, asin, category, upcEanCode, listPrice,
                                    sellingPrice, quantity, modelNumber, aboutProduct, productSpec, technicalDetails,
                                    shippingWeight, productDimensions, image, variants, sku, productUrl, stock,
                                    productDetails, dimensions, color, ingredients, directionToUse, isAmazonSeller,
                                    sizeQuantityVariant, productDescription);
    }

    inventoryFile.close();

    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
}