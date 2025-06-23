#include "tester.h"

void test_ft_strlcpy(void)
{
	log_start("ft_strlcpy");

	struct {
		const char *src;
		size_t size;
		const char *expected;
		size_t expected_return;
		const char *reason;
	} test_cases[] = {
		{"hello", 6, "hello", 5, "Basic copy"},
		{"world", 3, "wo", 5, "Truncate"},
		{"", 5, "", 0, "Empty source"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char dest[20] = {0};
		size_t got_return = ft_strlcpy(dest, test_cases[i].src, test_cases[i].size);

		int passed = strcmp(dest, test_cases[i].expected) == 0 && got_return == test_cases[i].expected_return;

		log_assert(passed,
			"ft_strlcpy(\"%s\", size=%zu) | (Reason: %s) expected=\"%s\" [%zu], got=\"%s\" [%zu]",
			test_cases[i].src,
			test_cases[i].size,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			test_cases[i].expected_return,
			dest,
			got_return);
	}

	log_end();
}
