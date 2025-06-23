#include "tester.h"

void test_ft_strchr(void)
{
	log_start("ft_strchr");

	struct {
		const char *input;
		int c;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"hello", 'e', "ello", "Find 'e'"},
		{"hello", 'l', "llo", "Find first 'l'"},
		{"world", 'z', NULL, "Char not in string"},
		{"abc", '\0', "", "Search for null terminator"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char *got = ft_strchr(test_cases[i].input, test_cases[i].c);
		int passed = ((got == NULL && test_cases[i].expected == NULL) ||
			(got && test_cases[i].expected && strcmp(got, test_cases[i].expected) == 0));

		log_assert(passed,
			"ft_strchr(\"%s\", '%c') | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].input,
			test_cases[i].c,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected ? test_cases[i].expected : "NULL",
			got ? got : "NULL");
	}

	log_end();
}
