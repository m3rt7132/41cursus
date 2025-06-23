#include "tester.h"

void test_ft_atoi()
{
	log_start("ft_atoi");

	struct {
    	const char *input;
    	const char *reason;
	} test_cases[] = {
    	{"42", "Basic positive number"},
    	{"-42", "Basic negative number"},
    	{"0", "Zero input"},
    	{"+42", "Positive sign"},
    	{"    123", "Leading whitespace"},
    	{"   -00123", "Negative with leading zeros"},
    	{"a42", "Invalid start character"},
    	{"  +00123abc", "Valid number followed by junk"},
    	{"", "Empty string"},
    	{"    ", "Only whitespace"},
    	{"2147483647", "Max int"},
    	{"-2147483648", "Min int"},
    	{"9999999999", "Positive overflow"},
    	{"-9999999999", "Negative overflow"},
    	{"11111111111111111111111111111111111", "Extreme overflow"},
	};
	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; ++i)
	{
		const char *input = test_cases[i].input;
		const char *reason = test_cases[i].reason;
		int expected = atoi(input);
		int got = ft_atoi(input);
		int passed = (expected == got);

		log_assert(passed, "ft_atoi(\"%s\") | (Reason: %s) expected=%d, got=%d", input, 
			reason && !passed ? reason : "-", expected, got);
	}
	log_end();
}
