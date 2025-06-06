#include "tester.h"

void test_ft_strjoin(void)
{
	log_start("ft_strjoin");

	struct {
		const char *s1;
		const char *s2;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"Hello", "World", "HelloWorld", "Basic join"},
		{"", "Test", "Test", "First empty"},
		{"Test", "", "Test", "Second empty"},
		{"", "", "", "Both empty"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char *got = ft_strjoin(test_cases[i].s1, test_cases[i].s2);
		int passed = got && strcmp(got, test_cases[i].expected) == 0;

		log_assert(passed,
			"ft_strjoin(\"%s\", \"%s\") | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].s1,
			test_cases[i].s2,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			got ? got : "NULL");

		free(got);
	}

	log_end();
}
