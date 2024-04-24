#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   /* Type your code here */
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   switch (option) {
     case 'a': {
         string name, description;
         int price, quantity;
         cout << "ADD ITEM TO CART" << endl;
         cout << "Enter the item name: ";
         getline(cin >> ws, name);
         cout << "Enter the item description: ";
         getline(cin >> ws, description);
         cout << "Enter the item price: ";
         cin >> price;
         cout << "Enter the item quantity: ";
         cin >> quantity;
         ItemToPurchase newItem(name, description, price, quantity);
         theCart.AddItem(newItem);
         break;
     }
     case 'd': {
         string name;
         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove: ";
         getline(cin >> ws, name);
         theCart.RemoveItem(name);
         break;
     }
     case 'c': {
         string name;
         int newQuantity;
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name: ";
         getline(cin >> ws, name);
         cout << "Enter the new quantity: ";
         cin >> newQuantity;
         ItemToPurchase modifiedItem(name, "", 0, newQuantity);
         theCart.ModifyItem(modifiedItem);
         break;
     }
     case 'i': {
         theCart.PrintDescriptions();
         break;
     }
     case 'o': {
         theCart.PrintTotal();
         break;
     }
     case 'q': {
         // Quit
         cout << "Exiting program." << endl;
         break;
     }
     default: {
         cout << "Invalid option! Please select from the menu." << endl;
         break;
     }
   }
}

int main() {
   /* Type your code here */
   
   return 0;
}
