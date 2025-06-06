#include "tester.h"

void test_ft_isascii(void)
{
	log_start("ft_isascii");

	struct {
		int input;
		int expected;
		const char *reason;
	} test_cases[] = {
		{0, 1, "Lower bound"},
		{127, 1, "Upper bound"},
		{128, 0, "Out of ASCII range"},
		{-1, 0, "Negative value"},
		{'A', 1, "ASCII character"},
		{255, 0, "Extended character"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		int got = ft_isascii(test_cases[i].input);
		int passed = got == test_cases[i].expected;
		log_assert(
			passed,
			"ft_isascii(%d) | (Reason: %s) expected=%d, got=%d",
			test_cases[i].input, test_cases[i].reason && !passed ? test_cases[i].reason : "-", test_cases[i].expected, got
		);
	}

	log_end();
}
