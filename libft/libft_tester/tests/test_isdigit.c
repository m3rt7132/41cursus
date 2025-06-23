#include "tester.h"

void test_ft_isdigit(void)
{
	log_start("ft_isdigit");

	struct {
		int input;
		int expected;
		const char *reason;
	} test_cases[] = {
		{'0', 1, "Digit 0"},
		{'9', 1, "Digit 9"},
		{'a', 0, "Letter"},
		{'$', 0, "Symbol"},
		{-1, 0, "Negative value"},
		{128, 0, "Non-ASCII extended char"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		int got = ft_isdigit(test_cases[i].input);
		int passed = got == test_cases[i].expected;
		log_assert(
			passed,
			"ft_isdigit(%d) | (Reason: %s) expected=%d, got=%d",
			test_cases[i].input, test_cases[i].reason && !passed ? test_cases[i].reason : "-", test_cases[i].expected, got
		);
	}

	log_end();
}
