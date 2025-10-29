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
 * File:        HashData.hpp                                                   *
 * Description: Header file for constructors and functions for inventory data. *
 ******************************************************************************/

#pragma once // Guard code

#include <iostream>
#include <string>

using namespace std;

class HashData
{
public:
    // Making a prerequisite that when the Data constructor is invoked, it will have inventory data. Realistically,
    // it wouldn't make much sense to have a default constructor when this is supposed to be comprised of individual
    // commands.

    // Constructor
    HashData(std::string newUniqueId, std::string newProductName, std::string newBrandName, std::string newASIN, std::string newCategory,
             std::string newUpcEanCode, std::string newListPrice, std::string newSellingPrice, std::string newQuantity, std::string newModelNumber,
             std::string newAboutProduct, std::string newProductSpec, std::string newTechnicalDetails, std::string newShippingWeight,
             std::string newProductDimensions, std::string newImage, std::string newVariants, std::string newSku, std::string newProductUrl, 
             std::string newStock, std::string newProductDetails, std::string newDimensions, std::string newColor, std::string newIngredients,
             std::string newDirectionToUse, std::string newIsAmazonSeller, std::string newSizeQuantityVariant, std::string newProductDescription);

    // Getter functions for the class
    std::string getUniqueId() const;
    std::string getProductName() const;
    std::string getBrandName() const;
    std::string getASIN() const;
    std::string getCategory() const;
    std::string getUpcEanCode() const;
    std::string getListPrice() const;
    std::string getSellingPrice() const;
    std::string getQuantity() const;
    std::string getModelNumber() const;
    std::string getAboutProduct() const;
    std::string getProductSpec() const;
    std::string getTechnicalDetails() const;
    std::string getShippingWeight() const;
    std::string getProductDimensions() const;
    std::string getImage() const;
    std::string getVariants() const;
    std::string getSku() const;
    std::string getProductUrl() const;
    std::string getStock() const;
    std::string getProductDetails() const;
    std::string getDimensions() const;
    std::string getColor() const;
    std::string getIngredients() const;
    std::string getDirectionToUse() const;
    std::string getIsAmazonSeller() const;
    std::string getSizeQuantityVariant() const;
    std::string getProductDescription() const; 

    // Setter functions for the class
    void setUniqueId(std::string newValue);
    void setProductName(std::string newValue);
    void setBrandName(std::string newValue);
    void setASIN(std::string newValue);
    void setCategory(std::string newValue);
    void setUpcEanCode(std::string newValue);
    void setListPrice(std::string newValue);
    void setSellingPrice(std::string newValue);
    void setQuantity(std::string newValue);
    void setModelNumber(std::string newValue);
    void setAboutProduct(std::string newValue);
    void setProductSpec(std::string newValue);
    void setTechnicalDetails(std::string newValue);
    void setShippingWeight(std::string newValue);
    void setProductDimensions(std::string newValue);
    void setImage(std::string newValue);
    void setVariants(std::string newValue);
    void setSku(std::string newValue);
    void setProductUrl(std::string newValue);
    void setStock(std::string newValue);
    void setProductDetails(std::string newValue);
    void setDimensions(std::string newValue);
    void setColor(std::string newValue);
    void setIngredients(std::string newValue);
    void setDirectionToUse(std::string newValue);
    void setIsAmazonSeller(std::string newValue);
    void setSizeQuantityVariant(std::string newValue);
    void setProductDescription(std::string newValue); 

private:
    std::string uniqueId, productName, brandName, asin, category, upcEanCode, listPrice,
    sellingPrice, quantity, modelNumber, aboutProduct, productSpec, technicalDetails,
    shippingWeight, productDimensions, image, variants, sku, productUrl, stock,
    productDetails, dimensions, color, ingredients, directionToUse, isAmazonSeller,
    sizeQuantityVariant, productDescription;
};