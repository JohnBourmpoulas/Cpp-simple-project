#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Shop {
private:
    char *itemName;
    string itemId;
    float itemCost;
public:
    Shop(): itemId("Unknown"), itemCost(0){
        itemName = new char[10];
        strcpy(itemName,"Unknown");
    }

    Shop(char *itemName, string itemId, float itemCost):itemId(itemId), itemCost(itemCost){
        itemName = new char[strlen(itemName) + 1];
        strcpy(this->itemName, itemName);
    }

    void set_Shop(){
        fstream shop_file;
        shop_file.open("shop/shop_db.txt",ios::app);
        shop_file << "Shop List" <<endl;

        cout <<"Enter Name: " <<endl;
        cin.getline(itemName,10);
        shop_file << "Item Name: " <<itemName <<endl;

        cout <<"Enter Item ID: " <<endl;
        cin >> itemId;
        shop_file << "Item ID: " << itemId <<endl;

        cout <<"Enter Item Cost: " <<endl;
        cin >> itemCost;
        shop_file << "Item Cost: " << itemCost <<endl;
        shop_file.close();
    }

    virtual void display(){
        cout <<"Item Name: " << itemName <<endl;
        cout <<"Item ID: " << itemId <<endl;
        cout <<"Item Cost: " << itemCost <<endl;
    }

    ~Shop(){
        delete [] itemName;
    }
};