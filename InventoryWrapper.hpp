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
 * Description: This is the header file for the inventory application. It      *
 *              holds function declarations for displaying/validating commands *
 *              and their actions, as well as the initialization of the        *
 *              program.                                                       *
 ******************************************************************************/

 #pragma once // Guard code

 #include <iostream>
 #include <string>
 #include "HashLinkedList.hpp"

 using namespace std;

 class InventoryWrapper
 {
    public:
        // Constructor for the wrapper
        InventoryWrapper();

        void printHelp(); // Prints out the supported list of commands
        bool validCommand(string line); // Makes sure a user-entered command is valid
        void evalCommand(string line); // Chooses what to do based on an entered command
        void bootStrap(); // Bootstrap operations
    private:
        HashLinkedList::HashLinkedList<T>* hashTable[4064];
 };