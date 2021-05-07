#include "IntSet.h"

int main()
{
	int arr[3]{ 1,2,3 };
	int ar[3]{ 4,2,6 };
	IntSet s(arr, 3),ss(ar,3);
	auto sss = s * ss;
	sss.print();
	return 0;
}
