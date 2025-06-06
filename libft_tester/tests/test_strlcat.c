#include "tester.h"

void test_ft_strlcat(void)
{
	log_start("ft_strlcat");

	struct {
		char dest[20];
		const char *src;
		size_t size;
		const char *expected;
		size_t expected_return;
		const char *reason;
	} test_cases[] = {
		{"abc", "def", 10, "abcdef", 6, "Basic cat"},
		{"abc", "def", 3, "abc", 6, "Size too small"},
		{"", "test", 0, "", 4, "Zero size"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char dest[20];
		strcpy(dest, test_cases[i].dest);

		size_t got_return = ft_strlcat(dest, test_cases[i].src, test_cases[i].size);
		int passed = strcmp(dest, test_cases[i].expected) == 0 && got_return == test_cases[i].expected_return;

		log_assert(passed,
			"ft_strlcat(\"%s\", \"%s\", %zu) | (Reason: %s) expected=\"%s\" [%zu], got=\"%s\" [%zu]",
			test_cases[i].dest,
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
