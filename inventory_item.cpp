#include <iostream>
#include <string>

using namespace std;

class InventoryItem {
  string m_name;
  double m_price;

public:

  bool friend operator<(const InventoryItem &item1, const InventoryItem &item2);

  InventoryItem() {}

  InventoryItem(const char* name) : m_name(name), m_price(0.0) { }

  InventoryItem(const char* name, double price) : m_name(name), m_price(price) { }

  string name() const { return m_name; }
  double price() const { return m_price; }

  InventoryItem increasePrice(double increase) {
    m_price += increase;
    return *this;
  }

  InventoryItem decreasePrice(double increase) {
    m_price -= increase;
    return *this;
  }

  bool operator>(const InventoryItem &item )
  {
    // this == address of current object
    // so current object is *this
    // member m_price of current object is *this.m_price;
    return (*this).m_price > item.m_price;
  }
};


bool operator<(const InventoryItem &item1, const InventoryItem &item2) {
  return item1.m_price < item2.m_price;
}

int main() {

  InventoryItem inventory[3] = {"Hammer", "Wrench", InventoryItem("Pliers", 1.5)};

  InventoryItem item, item1, item2;

  for(int idx = 0; idx < 3; idx++) {
    item = inventory[idx];
    cout << item.name() << ": " << item.price() << endl;
  }


  item = inventory[2];
  cout << item.increasePrice(2.0).decreasePrice(1.0).price() << endl;

  item1 = inventory[1];
  item2 = inventory[2];

  if(item1 < item2) {
    cout << "item1 is cheaper than item2" << endl;
  } else {
    cout << "item1 is not cheaper than item2" << endl;
  }


  string foo = "Joanita", bar = "Gomez";

  cout << "Normal: " << (foo + bar) << endl;
  cout << "Manually calling operator: " << operator+(foo, bar) << endl;


}
