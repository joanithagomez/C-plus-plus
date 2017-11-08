
#include <iostream>
#include <cctype>
using namespace std;

class Upcode
{
private:
string manufNum;
string prodNum;
char checkDigit;
public:
Upcode();
Upcode(string mn, string pn, char cd);
void setProdNum(string pn);
void setManufNum(string mn) {manufNum = mn;}
void setcheckdig(char cd) {checkDigit = cd;}

string getprodNum() const;
bool operator==(const Upcode& rhs);
friend ostream& operator<<(ostream& os, Upcode& rhs);

};

Upcode::Upcode(string mn, string pn, char cd)
{
  setProdNum(pn);
  setManufNum(mn);
  setcheckdig(cd);
}
void Upcode::setProdNum(string pn)
{
  int status = 1;
  if(pn.length() <= 5)
  {
    for(int i = 0; i < 5; i++)
    {
      if(!isdigit(pn[i]))
        status = 0;

    }
    if(status == 1)
      prodNum = pn;
  }
}

string Upcode::getprodNum() const
{ return prodNum; }

bool Upcode::operator==(const Upcode& rhs)
{
  return(manufNum == rhs.manufNum && prodNum == rhs.prodNum && checkDigit == rhs.checkDigit);
}

ostream& operator<<(ostream& os, Upcode& rhs)
{
  os << rhs.manufNum << rhs.prodNum << rhs.checkDigit;
  return os;
}

int main()
{
  Upcode upc("12345", "54321", '9');
  cout << upc << endl;

  return 0;
}
