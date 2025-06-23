#include "tester.h"

void test_ft_strdup(void)
{
	log_start("ft_strdup");

	struct {
		const char *input;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"hello", "hello", "Basic string"},
		{"", "", "Empty string"},
		{"1234567890", "1234567890", "Digits"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char *got = ft_strdup(test_cases[i].input);
		int passed = got && strcmp(got, test_cases[i].expected) == 0;

		log_assert(passed,
			"ft_strdup(\"%s\") | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].input,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			got ? got : "NULL");

		free(got);
	}

	log_end();
}
