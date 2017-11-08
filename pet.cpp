
// in Date.h:
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;

// static variable in a class means there will be only
//     ONE variable in the whole program (NOT ONE FOR
//      EACH OBJECT)
    static const string monthNames[13];


public:
	Date(int m, int d, int y);
	Date(){ month=day=1; year=1000; }

	bool setMonth(int m);
	bool setDay(int d);
	bool setYear(int y);

	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getYear() const { return year; }

	friend ostream& operator<<( ostream &os,
				const Date &right)
	{
		os << monthNames[right.month] << " " << right.day << ", " << right.year;// endl?
		return os;
	}

	bool operator<( const Date &right )
	{
		int diff;

		diff = this->year - right.year;
		if( diff == 0 ){
			diff = this->month - right.month;
			if( diff == 0 )
				diff = this->day - right.day;
		}
		return (diff < 0);
	} // end operator<

	bool operator>( const Date &right )
	{
		return (Date)right < (const Date &)(*this);
	}

};
const string Date::monthNames[13]={"","January", "February", "March",
		 "April", "May", "June", "July", "August", "September",
		 "October", "November", "December"};

Date::Date(int m, int d, int y)
{
	if( !setMonth(m) )
		month = 1;
	if( !setDay(d) )
		day = 1;
	if( !setYear(y) )
		year = 1000;
}

bool Date::setMonth(int m)
{
    if( m >= 1 && m <= 12)
    {
        month = m;
        return true;
    }
    return false;
}

bool Date::setDay(int d)
{
    if( d >= 1 && d <= 31)
    {
        day = d;
        return true;
    }
    return false;
}

bool Date::setYear(int y)
{
    if( y >= 1000 && y <= 2100 )
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
	virtual void speak() ;
};


Pet::Pet(string nm, int mo, int dy, int yr)
{
    name = nm;
    birthdate.setMonth(mo);//can't do: birthdate.month=

    birthdate.setYear(yr);
    birthdate.setDay(dy);
}

 void Pet::speak()
{
	cout << " ? " << endl;
}

Pet::Pet()
{
    name = "No Name";
    birthdate.setMonth(1);
    birthdate.setDay(1);
    birthdate.setYear(2000);
}

void Pet::setName(string nm)
{
    name = nm;
}

bool Pet::setBirthMonth(int mo)
{
    return birthdate.setMonth(mo);
}

bool Pet::setBirthDay(int dy)
{
    return birthdate.setDay(dy);
}

bool Pet::setBirthYear(int yr)
{
	time_t t = time(0);   // get time now
	int currentYear;
    	struct tm * now = localtime( & t );
    	currentYear = (now->tm_year + 1900) ;

	if(yr > 0 && yr <= currentYear)
    return birthdate.setYear(yr);
}




class Cat : public Pet

{
private:
	bool isIndoor;

public:
	Cat() : Pet()
	{ isIndoor = false; }

	Cat(string name, int day, int mo, int yr, bool indoor) : Pet(name, day, mo, yr)
	{ isIndoor = indoor; }

	//Accessor
	bool getIsIndoor()
	{ return isIndoor; }

	//mutator
	void setIsIndoor(bool val)
	{ isIndoor = val; }

	 void speak()
	{ cout << "Meow" << endl; }
};




class Dog : public Pet

{
private:
	int numTricks;

public:
	Dog() : Pet()
	{ numTricks = 0; }

	Dog(string name, int day, int mo, int yr, int tricks) : Pet(name, day, mo, yr)
	{ numTricks = tricks; }

	//Accessor
	int getnumTricks()
	{ return numTricks; }

	//mutator
	void setnumTricks(int num)
	{ numTricks = num; }

	 void speak()
	{ cout<< "Woof" << endl; }

};


void displayPet(Pet *pet)
{
	cout << pet->getName() <<  "'s birthdate is "	<< pet->getBirthdate() << endl;
	pet->speak();
}


int main()
{

		Cat* cat = new Cat("Brownie", 1,11,1996, true);
		Dog* dog = new Dog("Spot", 10, 11, 2012, 2);

		displayPet(cat);
		displayPet(dog);


  /*  Pet myPet("Spot", 10, 11, 2012);
    Pet pet2; // calls default constructor
		Cat mycat("Brownie", 1,11,1996 true);
		Dog mydog("Puppy", 1, 2, 2001, 12);
		cout << mydog.getName() << "'s birthdate is "	<< mydog.getBirthdate()	<< ".He can do " << mydog.getnumTricks() << " tricks!" << endl;
		cout << mycat.getName() << "'s birthdate is "	<< mycat.getBirthdate()	<< endl;

    pet2.setName("Fluffy");
    pet2.setBirthMonth(4);
    pet2.setBirthDay(5);
    pet2.setBirthYear(2006);

    cout << myPet.getName() << "'s birthdate is "	<< myPet.getBirthdate()	<< endl;
    cout << pet2.getName() <<  "'s birthdate is " << pet2.getBirthdate()	<< endl;
*/
    return 0;

}
