#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
  public:
    ItemToPurchase(string name = "none", string description = "none", int price = 0, int quantity = 0);
    void SetDescription(string description);
    string GetItemDescription() const;
    int GetQuantity() const;
    int GetPrice() const;
    void PrintItemCost() const;
    void PrintItemDescription() const;
    
  private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};
#endif
