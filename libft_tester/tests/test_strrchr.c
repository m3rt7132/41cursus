#include "tester.h"

void test_ft_strrchr(void)
{
	log_start("ft_strrchr");

	struct {
		const char *s;
		int c;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"hello world", 'o', "orld", "Last 'o'"},
		{"hello world", 'h', "hello world", "First char"},
		{"hello", 'z', NULL, "Char not found"},
		{"hello\0world", '\0', "", "Null terminator"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		const char *got = ft_strrchr(test_cases[i].s, test_cases[i].c);
		const char *expected = test_cases[i].expected;

		int passed = (got == NULL && expected == NULL) ||
					 (got && expected && strcmp(got, expected) == 0);

		log_assert(passed,
			"ft_strrchr(\"%s\", '%c') | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].s,
			test_cases[i].c,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			expected ? expected : "NULL",
			got ? got : "NULL");
	}

	log_end();
}
