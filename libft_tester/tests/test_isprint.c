#include "tester.h"

void test_ft_isprint(void)
{
	log_start("ft_isprint");

	struct {
		int input;
		int expected;
		const char *reason;
	} test_cases[] = {
		{32, 1, "Space (first printable char)"},
		{126, 1, "Tilde (last printable char)"},
		{31, 0, "Non-printable below range"},
		{127, 0, "DEL character"},
		{'A', 1, "Printable letter"},
		{0, 0, "Null character"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		int got = ft_isprint(test_cases[i].input);
		int passed = got == test_cases[i].expected;
		log_assert(
			passed,
			"ft_isprint(%d) | (Reason: %s) expected=%d, got=%d",
			test_cases[i].input, test_cases[i].reason && !passed ? test_cases[i].reason : "-", test_cases[i].expected, got
		);
	}

	log_end();
}
