#include "testing.h"

/*
**		GUIDELINE TO UNITY TESTING
**
** 1.	Test file shall be named like test_feature.c i.e. test_parsing.c
** 2.	It has a specific Header file: #include "testing.h"
** 3.	Inside Main, should return (0) for no  errors or (1) in case of errors.
** 4.	Everything printed out will be collected in a logfile (FD 1 or FD 2);
**
*/

int main(void)
{
	prt(1, "Test 1: OK");
	prt(2, "Test 2: OK");
	return (0);
}
