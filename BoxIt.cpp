#include <iostream>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

class Box
{
private:
	int l, b, h;
public:
	Box()
	{
		l = b = h = 0;
	}
	Box(int length, int breadth, int height)
	{
		l = length;
		b = breadth;
		h = height;
	}
	Box(const Box& p)
	{
		this->l = p.l;
		this->h = p.h;
		this->b = p.b;
	}
	int getLength() { return this->l; }
	int getBreadth() { return this->b; }
	int getHeight() { return this->h; }
	long long int CalculateVolume()
	{
		long long int res = static_cast<long long int>(l) * b * h;
		return res;
	}

	bool operator <  (const Box& p)
	{
		if (this->l < p.l) return true;
		if (this->b < p.b && this->l == p.l) return true;
		if (this->h < p.h && this->b == p.b && this->l == p.l) return true;
		return false;
	}

	friend ostream& operator << (ostream& os, Box& p);

};

ostream& operator << (ostream& os, Box& p)
{
	os << p.l << " " << p.b << " " << p.h;
	return os;
}

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}