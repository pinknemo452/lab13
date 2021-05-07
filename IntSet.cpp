#include "IntSet.h"

#include <iostream>
#include <algorithm>

IntSet::IntSet(const int* ints ,const int sizei)
{
	size = sizei;
	set = new int[size];
	for (int i = 0; i < size; i++)
		set[i] = ints[i];
}

IntSet IntSet::operator+(const IntSet& sum) const
{
	int* buff = new int[this->size + sum.size];
	for (int i = 0; i < this->size; i++)
		buff[i] = this->set[i];
	int j = 0;
	for (int i = this->size; i < this->size + sum.size; i++) {
		buff[i] = sum.set[j];
		j++;
	}
	int sizebuff = this->size + sum.size;
	 for (int m = 0; m < sizebuff; m++) {
	 	for (int i = m + 1; i < sizebuff; i++) {
	 		if (buff[m] == buff[i]) {
	 			for (int k = i; k < sizebuff - 1; k++) {
	 				buff[k] = buff[k + 1];
	 			}
	 			sizebuff--;
	 		}
	 	}
	 }
	auto ret = new IntSet(buff, sizebuff);
	delete[] buff;
	return *ret;
}

IntSet IntSet::operator-(const IntSet& sum) const
{
	int* buff = new int[this->size];
	bool flag = false;
	int ssize = 0;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < sum.size; j++) {
			if (this->set[i] == sum.set[j])
				flag = true;
		}
		if (!flag) {
			buff[i] = this->set[i];
			ssize++;
		}
	}
	return IntSet(buff, ssize);
}

IntSet IntSet::operator*(const IntSet& sum) const
{
	int* buff = new int[this->size + sum.size];
	std::sort(&this->set[0], &this->set[this->size]);
	std::sort(&sum.set[0], &sum.set[sum.size]);
	
	return IntSet(buff, std::set_intersection(&this->set[0], &this->set[this->size], &sum.set[0], &sum.set[sum.size], buff) - buff);
}

IntSet& IntSet::operator+=(const IntSet& sum)
{
	return *this = *this + sum;
}

IntSet& IntSet::operator-=(const IntSet& sum)
{
	return *this = *this - sum;
}

IntSet& IntSet::operator=(const IntSet& sum)
{
	if(this != &sum)
	{
		delete this->set;
		this->size = sum.size;
		this->set = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->set[i] = sum.set[i];
	}
	return *this;
}

bool IntSet::operator==(const IntSet& sum) const
{
	if (this->size != sum.size)
		return false;
	std::sort(&this->set[0], &this->set[this->size - 1]);
	std::sort(&sum.set[0], &sum.set[sum.size - 1]);
	for (int i = 0; i < sum.size; i++)
		if (this->set[i] != sum.set[i])
			return false;
	return true;
}

bool IntSet::operator!=(const IntSet& sum) const
{
	return !(*this == sum);
}

bool IntSet::operator>(const IntSet& sum) const
{
	if (this->size <= sum.size)
		return false;
	std::sort(&this->set[0], &this->set[this->size - 1]);
	std::sort(&sum.set[0], &sum.set[sum.size - 1]);
	
	for (int i = 0; i < sum.size; i++) {
		bool flag = false;
		for (int j = 0; j < this->size; ++j)
		{
			if (this->set[j] == sum.set[i])
				flag = true;
		}
		if (!flag)
			return false;

	}
	return true;
}

bool IntSet::operator<(const IntSet& sum) const
{
	return sum > *this;
}

bool IntSet::operator>=(const IntSet& sum) const
{
	return *this > sum || *this == sum;
}

bool IntSet::operator<=(const IntSet& sum) const
{
	return *this < sum || *this == sum;
}

void IntSet::print() const
{
	for (int i = 0; i < this->size; ++i)
		std::cout << this->set[i] << " ";
	std::cout << "\n";
}

void IntSet::operator+(const int sum)
{
	for(int i = 0;i < this->size;i++)
	{
		if (this->set[i] == sum)
			return;
	}
	int* buff = new int[this->size+1];
	for (int i = 0; i < this->size; i++)
		buff[i] = this->set[i];
	buff[this->size] = sum;
	delete[] this->set;
	this->set = new int[++this->size];
	for (int i = 0; i < this->size; i++)
		this->set[i] = buff[i];
}

void IntSet::operator-(const int sum)
{
	for(int i = 0;i < this->size;i++)
		if(this->set[i] == sum)
		{
			std::swap(this->set[i], this->set[this->size - 1]);
			this->size--;
			return;
		}
}


IntSet::~IntSet()
{
	delete[] set;
}
