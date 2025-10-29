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
 * File:        HashData.cpp                                                   *
 * Description: Source file for constructors and functions for inventory data. *
 ******************************************************************************/
 
 #include "HashData.hpp"
 #include <iostream>
 #include <string>

 using namespace std;

// Constructor
HashData::HashData(string newUniqueId, string newProductName, string newBrandName, string newASIN, string newCategory,
            string newUpcEanCode, string newListPrice, string newSellingPrice, string newQuantity, string newModelNumber,
            string newAboutProduct, string newProductSpec, string newTechnicalDetails, string newShippingWeight,
            string newProductDimensions, string newImage, string newVariants, string newSku, string newProductUrl, 
            string newStock, string newProductDetails, string newDimensions, string newColor, string newIngredients,
            string newDirectionToUse, string newIsAmazonSeller, string newSizeQuantityVariant, string newProductDescription)
            {
                uniqueId = newUniqueId;
                productName = newProductName;
                brandName = newBrandName;
                asin = newASIN;
                category = newCategory;
                upcEanCode = newUpcEanCode;
                listPrice = newListPrice;
                sellingPrice = newSellingPrice;
                quantity = newQuantity;
                modelNumber = newModelNumber;
                aboutProduct = newAboutProduct;
                productSpec = newProductSpec;
                technicalDetails = newTechnicalDetails;
                shippingWeight = newShippingWeight;
                productDimensions = newProductDimensions;
                image = newImage;
                variants = newVariants;
                sku = newSku;
                productUrl = newProductUrl;
                stock = newStock;
                productDetails = newProductDetails;
                dimensions = newDimensions;
                color = newColor;
                ingredients = newIngredients;
                directionToUse = newDirectionToUse;
                isAmazonSeller = newIsAmazonSeller;
                sizeQuantityVariant = newSizeQuantityVariant;
                productDescription = newProductDescription; 
            }

// Getter functions for the class
string HashData::getUniqueId() const { return uniqueId; }
string HashData::getProductName() const { return productName; }
string HashData::getBrandName() const { return brandName; }
string HashData::getASIN() const { return asin; }
string HashData::getCategory() const { return category; }
string HashData::getUpcEanCode() const { return upcEanCode; }
string HashData::getListPrice() const { return listPrice; }
string HashData::getSellingPrice() const { return sellingPrice; }
string HashData::getQuantity() const { return quantity; }
string HashData::getModelNumber() const { return modelNumber; }
string HashData::getAboutProduct() const { return aboutProduct; }
string HashData::getProductSpec() const { return productSpec; }
string HashData::getTechnicalDetails() const { return technicalDetails; }
string HashData::getShippingWeight() const { return shippingWeight; }
string HashData::getProductDimensions() const { return productDimensions; }
string HashData::getImage() const { return image; }
string HashData::getVariants() const { return variants; }
string HashData::getSku() const { return sku; }
string HashData::getProductUrl() const { return productUrl; }
string HashData::getStock() const { return stock; }
string HashData::getProductDetails() const { return productDetails; }
string HashData::getDimensions() const { return dimensions; }
string HashData::getColor() const { return color; }
string HashData::getIngredients() const { return ingredients; }
string HashData::getDirectionToUse() const { return directionToUse; }
string HashData::getIsAmazonSeller() const { return isAmazonSeller; }
string HashData::getSizeQuantityVariant() const { return sizeQuantityVariant; }
string HashData::getProductDescription() const { return productDescription; }

// Setter functions for the class
void HashData::setUniqueId(string newValue) { uniqueId = newValue; }
void HashData::setProductName(string newValue) { productName = newValue; }
void HashData::setBrandName(string newValue) { brandName = newValue; }
void HashData::setASIN(string newValue) { asin = newValue; }
void HashData::setCategory(string newValue) { category = newValue; }
void HashData::setUpcEanCode(string newValue) { upcEanCode = newValue; }
void HashData::setListPrice(string newValue) { listPrice = newValue; }
void HashData::setSellingPrice(string newValue) { sellingPrice = newValue; }
void HashData::setQuantity(string newValue) { quantity = newValue; }
void HashData::setModelNumber(string newValue) { modelNumber = newValue; }
void HashData::setAboutProduct(string newValue) { aboutProduct = newValue; }
void HashData::setProductSpec(string newValue) { productSpec = newValue; }
void HashData::setTechnicalDetails(string newValue) { technicalDetails = newValue; }
void HashData::setShippingWeight(string newValue) { shippingWeight = newValue; }
void HashData::setProductDimensions(string newValue) { productDimensions = newValue; }
void HashData::setImage(string newValue) { image = newValue; }
void HashData::setVariants(string newValue) { variants = newValue; }
void HashData::setSku(string newValue) { sku = newValue; }
void HashData::setProductUrl(string newValue) { productUrl = newValue; }
void HashData::setStock(string newValue) { stock = newValue; }
void HashData::setProductDetails(string newValue) { productDetails = newValue; }
void HashData::setDimensions(string newValue) { dimensions = newValue; }
void HashData::setColor(string newValue) { color = newValue; }
void HashData::setIngredients(string newValue) { ingredients = newValue; }
void HashData::setDirectionToUse(string newValue) { directionToUse = newValue; }
void HashData::setIsAmazonSeller(string newValue) { isAmazonSeller = newValue; }
void HashData::setSizeQuantityVariant(string newValue) { sizeQuantityVariant = newValue; }
void HashData::setProductDescription(string newValue) { productDescription = newValue; }