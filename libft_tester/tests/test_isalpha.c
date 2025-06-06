#include "tester.h"

void test_ft_isalpha(void)
{
	log_start("ft_isalpha");

	struct {
		int input;
		int expected;
		const char *reason;
	} test_cases[] = {
		{'a', 1, "Lowercase letter"},
		{'Z', 1, "Uppercase letter"},
		{'5', 0, "Digit"},
		{'%', 0, "Symbol"},
		{'\t', 0, "Control character"},
		{0, 0, "Null character"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		int got = ft_isalpha(test_cases[i].input);
		int passed = got == test_cases[i].expected;
		log_assert(
			passed,
			"ft_isalpha(%d) | (Reason: %s) expected=%d, got=%d",
			test_cases[i].input, test_cases[i].reason && !passed ? test_cases[i].reason : "-", test_cases[i].expected, got
		);
	}

	log_end();
}