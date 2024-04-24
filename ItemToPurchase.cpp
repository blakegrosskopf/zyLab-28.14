#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
  itemName = name;
  itemDescription = description;
  itemPrice = price;
  itemQuantity = quantity;
}

void ItemToPurchase::SetDescription(string description){
  itemDescription = description;
}

string ItemToPurchase::GetDescription() const{
  return itemDescription;
}

void ItemToPurchase::PrintItemCost() const{
  court<<itemName<<" "<<itemQuanttiy<<" @$"<<itemPrice<<" =$"<<(itemQuantity * itemPrice)<<endl;
}

void ItemToPurchase::PrintItemDescription() const{
  court<<itemName<<": " << itemDescription <<endl;
}
