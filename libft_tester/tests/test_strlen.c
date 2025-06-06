#include "tester.h"

void test_ft_strlen(void)
{
	log_start("ft_strlen");

	struct {
		const char *s;
		size_t expected;
		const char *reason;
	} test_cases[] = {
		{"", 0, "Empty string"},
		{"abc", 3, "3-letter string"},
		{"longer string test", 18, "Sentence"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		size_t got = ft_strlen(test_cases[i].s);
		int passed = got == test_cases[i].expected;

		log_assert(passed,
			"ft_strlen(\"%s\") | (Reason: %s) expected=%zu, got=%zu",
			test_cases[i].s,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			got);
	}

	log_end();
}
