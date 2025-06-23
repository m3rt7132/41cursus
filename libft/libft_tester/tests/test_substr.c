#include "tester.h"

void test_ft_substr(void)
{
	log_start("ft_substr");

	struct {
		const char *s;
		unsigned int start;
		size_t len;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"hello world", 0, 5, "hello", "Start at 0, len 5"},
		{"hello world", 6, 5, "world", "Start at 6"},
		{"hello", 10, 2, "", "Start out of bounds"},
		{"abcdef", 2, 10, "cdef", "Len longer than string"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char *got = ft_substr(test_cases[i].s, test_cases[i].start, test_cases[i].len);
		int passed = got && strcmp(got, test_cases[i].expected) == 0;

		log_assert(passed,
			"ft_substr(\"%s\", %u, %zu) | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].s,
			test_cases[i].start,
			test_cases[i].len,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			got ? got : "NULL");

		free(got);
	}

	log_end();
}
