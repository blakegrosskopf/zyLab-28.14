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
