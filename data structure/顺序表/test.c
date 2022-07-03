#include"SeqList.h"
int main()
{
	SL a;
	SLinit(&a);
	SLpushfront(&a, 1);
	SLpushfront(&a, 2);
	SLpushfront(&a, 6);
	SLpushback(&a, 9);
	SLprint(&a);
	return 0;
}