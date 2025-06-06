#include "tester.h"

void test_ft_strtrim(void)
{
	log_start("ft_strtrim");

	struct {
		const char *s1;
		const char *set;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"  hello  ", " ", "hello", "Trim spaces"},
		{"xxhelloxx", "x", "hello", "Trim x from both sides"},
		{"abc", "abc", "", "Trim all chars"},
		{"test", "", "test", "Empty set"},
		{"xxstrxingxx", "x", "strxing", "Only clear both sides"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char *got = ft_strtrim(test_cases[i].s1, test_cases[i].set);
		int passed = got && strcmp(got, test_cases[i].expected) == 0;

		log_assert(passed,
			"ft_strtrim(\"%s\", \"%s\") | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].s1,
			test_cases[i].set,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			got ? got : "NULL");

		free(got);
	}

	log_end();
}
