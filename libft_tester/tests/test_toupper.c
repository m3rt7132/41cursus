#include "tester.h"

void test_ft_toupper(void)
{
	log_start("ft_toupper");

	struct {
		int input;
		int expected;
		const char *reason;
	} test_cases[] = {
		{'a', 'A', "Lowercase a"},
		{'z', 'Z', "Lowercase z"},
		{'A', 'A', "Uppercase A"},
		{'1', '1', "Non-letter"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		int got = ft_toupper(test_cases[i].input);
		int passed = got == test_cases[i].expected;

		log_assert(passed,
			"ft_toupper('%c') | (Reason: %s) expected='%c', got='%c'",
			test_cases[i].input,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			got);
	}

	log_end();
}
