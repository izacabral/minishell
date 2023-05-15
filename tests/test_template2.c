#include "unit_test.h"

/*
**		GUIDELINE TO UNITY TESTING
**
** 1.	Test file shall be named like test_feature.c i.e. test_parsing.c
** 2.	It has a specific Header file: #include "unit_test.h"
** 3.	Inside Main, should return (0) for no  errors or (1) in case of errors.
** 4.	Everything printed out will be collected in a logfile (FD 1 or FD 2);
**
*/
int	test1(void)
{
	prt(2, "Test 1: OK");
	return (0);
}

int	test2(void)
{
	prt(2, "Test 2: KO");
	return (1);
}

int	main(void)
{
	int	error;

	error = 0;
	error += test1();
	error += test2();
	return (error);
}
