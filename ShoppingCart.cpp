#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart(string customerName, string currentDate) {
  this -> customerName = customerName;
  this -> currentDate = currentDate;
}

string ShoppingCart::GetCustomerName() cost {
  return customerName;
}

string ShoppingCart::GetDate() cost {
  return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& item) {
  cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
  bool found = false;
  for (size_t i = 0; i < cartItems.size(); ++i) {
    if (cartItems[i].GetDescription() == itemName) {
    cartItems.erase(cartItems.begin() + i);
    found = true;
    break;
    }
  }

  if (!found) {
    cout << "The item is not found in the cart. Nothing was removed." << endl;
  }
}

void ShoppingCart::ModifyItem(const ItemToPurchase& item) {
  bool found = false;
  for (size_t i = 0; i < cartItems.size(); ++i) {
    if (cartItems[i].GetDescription() == item.GetDescription()) {
      if (!item.GetDescription().empty()) {
        cartItems[i].SetDescription(item.GetDescription());
      }
      if (item.GetPrice() != 0) {
        cartItems[i].SetPrice(item.GetPrice());
      }
      if (item.GetQuantity() != 0) {
        cartItems[i].SetQuantity(item.GetQuantity());
      }
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "Item is not found in the cart. Nothing was modified." << endl;
  }
}

int ShoppingCart::GetNumberItemsInCart() const {
  int totalItems = 0;
  for (size_t i = 0; i < cartItems.size(); ++i) {
    totalItems += cartItems[i].GetQuantity();
  }
  return totalItems;
}

int ShoppingCart::GetCostOfCart() const {
    int totalCost = 0;
    for (size_t i = 0; i < cartItems.size(); ++i) {
        totalCost += (cartItems[i].GetQuantity() * cartItems[i].GetPrice());
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        return;
    }
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
    for (size_t i = 0; i < cartItems.size(); ++i) {
        cartItems[i].PrintItemCost();
    }
    cout << endl << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        return;
    }
    cout << "Item Descriptions" << endl;
    for (size_t i = 0; i < cartItems.size(); ++i) {
        cout << cartItems[i].GetDescription() << ": " << cartItems[i].GetItemDescription() << endl;
    }
}
