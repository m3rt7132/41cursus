#include "tester.h"

void test_ft_isalnum(void)
{
	log_start("ft_isalnum");

	struct {
		int input;
		int expected;
		const char *reason;
	} test_cases[] = {
		{'a', 1, "Lowercase letter"},
		{'Z', 1, "Uppercase letter"},
		{'5', 1, "Digit"},
		{'%', 0, "Non-alphanumeric character"},
		{'\n', 0, "Control character"},
		{0, 0, "Null character"},
		{127, 0, "DEL character"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		int got = ft_isalnum(test_cases[i].input);
		int passed = got == test_cases[i].expected;
		log_assert(
			passed,
			"ft_isalnum(%d) | (Reason: %s) expected=%d, got=%d",
			test_cases[i].input, test_cases[i].reason && !passed ? test_cases[i].reason : "-", test_cases[i].expected, got
		);
	}

	log_end();
}