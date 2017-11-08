
#include <iostream>
#include <string>
#include <ctime> //   time_t and struct tm
using namespace std;
int currentYear();

class Date
{
private:
	int month;
	int day;

	// static variable in a class means there will be only
	//     ONE variable in the whole program (NOT ONE FOR
	//      EACH OBJECT)
	static const string monthNames[13];


public:
	int year;

	Date(int m, int d, int y);
	Date(){ month = day = 1; year = 1000; }

	bool setMonth(int m);
	bool setDay(int d);
	bool setYear(int y);

	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getYear() const { return year; }

	friend ostream& operator<<(ostream &os,
		const Date &right)
	{
		os << monthNames[right.month] << " "
			<< right.day << ", " << right.year;// endl?
		return os;
	}

	bool operator<(const Date &right)
	{
		int diff;

		diff = this->year - right.year;
		if (diff == 0){
			diff = this->month - right.month;
			if (diff == 0)
				diff = this->day - right.day;
		}
		return (diff < 0);
	} // end operator<

	bool operator>(const Date &right)
	{
		return (Date)right < (const Date &)(*this);
	}

	bool operator==(const Date &right)
	{
		return month == right.month && day == right.day && year == right.year;
	}

};
const string Date::monthNames[13] = { "", "January", "February", "March",
"April", "May", "June", "July", "August", "September",
"October", "November", "December" };

Date::Date(int m, int d, int y)
{
	if (!setMonth(m))
		month = 1;
	if (!setDay(d))
		day = 1;
	if (!setYear(y))
		year = 1000;
}

bool Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
		return true;
	}
	return false;
}

bool Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
	{
		day = d;
		return true;
	}
	return false;
}

bool Date::setYear(int y)
{

    if(y > 0 && y <= currentYear())
    {
      year = y;
			return true;
	}
	return false;
}

class Pet
{
protected:
	string name;
	Date birthdate;

public:
	Pet(string nm, int mo, int dy, int yr);
	Pet();
	string getName() const {return name; }
	Date getBirthdate() const { return birthdate; }
	void setName(string nm);
	bool setBirthMonth(int mo);
	bool setBirthDay(int dy);
	bool setBirthYear(int yr);
	int currentAge();
	virtual int humanYears() = 0;
	virtual void write(ostream& os);
	virtual void speak(ostream& os)
	{ os << "?"; }

	bool operator<(Pet& right)
	{
		if(this->name == right.name)
			return this->birthdate < right.birthdate;
		else
			return this->name < right.name;

	}

	bool operator>(Pet& right)
		{
			return right < *this;
		}

	bool operator==(Pet& right){
		return (this->name == right.name && this->birthdate == right.birthdate); }

	bool operator!=(Pet& right)
		{ return !(*this == right); }

};

Pet::Pet(string nm, int mo, int dy, int yr)
{
    name = nm;
    birthdate.setMonth(mo);
    birthdate.setYear(yr);
    birthdate.setDay(dy);
}

Pet::Pet()
{
    name = "No Name";
    birthdate.setMonth(1);
    birthdate.setDay(1);
    birthdate.setYear(2000);
}

int Pet::currentAge()
{
		int cuYear = currentYear();
		return  cuYear - birthdate.year;
}

void Pet::write(ostream& os)
{
	os << "Name = " << name << ", Birthdate = " << birthdate;
}

//==================================================
// Derived class: Cat

class Cat : public Pet
{
private:
	bool isIndoor;

public:
	Cat();
	Cat(string nm, int mo, int dy, int yr, bool isIn);
	bool getIsIndoor() const;
	void setIsIndoor(bool isIn);
	int humanYears();
	void speak(ostream& os){ os << " Meow! " ; }
	void write(ostream& os);
};

Cat::Cat(){ isIndoor = false; }

Cat::Cat(string nm, int mo, int dy, int yr, bool isIn):
		Pet(nm, mo, dy, yr){ isIndoor=isIn; }

bool Cat::getIsIndoor() const{ return isIndoor; }

void Cat::setIsIndoor(bool isIn)
{
	isIndoor = isIn;
}

int Cat::humanYears()
{
	int currYears= currentAge();
	if(currYears <= 0 )
		return 0;
	else if(currYears == 1)
		return 15;
	else if(currYears == 2)
		return 24;
	else
		return 24 + 4 * (currYears - 2);
}

void Cat::write(ostream& os)
{
	os << "\nCat ";
	Pet::write(os);
	os << ", isIndoor: " << isIndoor;
}

//==================================================
// Derived class: Dog

class Dog : public Pet
{
private:
	int numTricks;

public:
	Dog();
	Dog(string nm, int mo, int dy, int yr, int num);
	int getNumTricks() const;
	void setNumTricks(int num);
	void speak(ostream& os){ os << " Woof! " ; }
	int humanYears();
  void  write(ostream& os);

};


Dog::Dog(){ numTricks=0; }

Dog::Dog(string nm, int mo, int dy, int yr, int num):Pet(nm, mo, dy, yr){ numTricks=num; }

int Dog::getNumTricks() const{ return numTricks; }

void Dog::setNumTricks(int num)
{
	numTricks = num;
}
int Dog::humanYears()
{
	int dogYears= currentAge();
	if(dogYears <= 0 )
		return 0;
	else if(dogYears == 1)
		return 9;
	else
		return 9 + 7 * (dogYears - 1);
}

void displayPet(Pet *ppet);

int currentYear()
{
	time_t t = time(0);   // get time now
	int currYear;
		struct tm * now = localtime( & t );
		currYear = (now->tm_year + 1900) ;
		return currYear;
}

void Dog::write(ostream& os)
{
	os << "\nDog ";
	Pet::write(os);
	os << ", Number of tricks = " << numTricks << " ";
}
