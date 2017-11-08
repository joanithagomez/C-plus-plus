#ifndef STOCK
#define STOCK
#include <string>
using namespace std;
class Stock
{
private:
    string symbol;		// Trading symbol of the stock
     NumberQueue sharePrices;   // Current price per share
public:
    Stock(){ symbol=""; sharePrices = NULL}
    Stock(string sym){ symbol=sym; }
    void setSymbol(string sym){ symbol = sym; }
    void addPrice(double newPrice)
    {

	  }
    string getSymbol() const{ return symbol; }
    double removeOldestSharePrice() const{ //YOU WRITE THIS}
    void displayStockPrices() const { //YOU WRITE THIS}
};
#endif
