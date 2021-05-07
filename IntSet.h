#ifndef INTSET_H
#define INTSET_H
class IntSet
{
public:
	IntSet(const int* ints, int sizei);
	IntSet operator+(const IntSet& sum) const;
	IntSet operator-(const IntSet& sum) const;
	IntSet operator*(const IntSet& sum) const;
	IntSet& operator+=(const IntSet& sum);
	IntSet& operator-=(const IntSet& sum);
	IntSet& operator=(const IntSet& sum);
	bool operator==(const IntSet& sum) const;
	bool operator!=(const IntSet& sum) const;
	bool operator>(const IntSet& sum) const;
	bool operator<(const IntSet& sum) const;
	bool operator>=(const IntSet& sum) const;
	bool operator<=(const IntSet& sum) const;
	void print() const;
	
	void operator+(int sum);
	void operator-(int sum);
	~IntSet();
private:
	int size;
	int* set;	
};
#endif

