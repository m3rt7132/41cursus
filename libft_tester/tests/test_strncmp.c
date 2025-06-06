#include "tester.h"

void test_ft_strncmp(void)
{
	log_start("ft_strncmp");

	struct {
		const char *s1;
		const char *s2;
		size_t n;
		int expected;
		const char *reason;
	} test_cases[] = {
		{"abc", "abc", 3, 0, "Equal strings"},
		{"abc", "abd", 2, 0, "Equal first 2"},
		{"abc", "abd", 3, -1, "Diff at 3rd"},
		{"a", "b", 1, -1, "Single char diff"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		int got = ft_strncmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
		int norm_got = (got == 0) ? 0 : (got > 0 ? 1 : -1);
		int norm_expected = (test_cases[i].expected == 0) ? 0 : (test_cases[i].expected > 0 ? 1 : -1);
		int passed = norm_got == norm_expected;

		log_assert(passed,
			"ft_strncmp(\"%s\", \"%s\", %zu) | (Reason: %s) expected=%d, got=%d",
			test_cases[i].s1,
			test_cases[i].s2,
			test_cases[i].n,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			got);
	}

	log_end();
}
