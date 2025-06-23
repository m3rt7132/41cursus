#include "tester.h"

void test_ft_strnstr(void)
{
	log_start("ft_strnstr");

	struct {
		const char *big;
		const char *little;
		size_t len;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"Hello World", "World", 11, "World", "Normal match"},
		{"Hello World", "World", 5, NULL, "Partial search fails"},
		{"Hello World", "", 11, "Hello World", "Empty little returns big"},
		{"", "a", 0, NULL, "Empty big with len 0"},
		{"abc", "abcd", 3, NULL, "Needle longer than haystack"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		const char *got = ft_strnstr(test_cases[i].big, test_cases[i].little, test_cases[i].len);
		const char *expected = test_cases[i].expected;

		int passed = (got == NULL && expected == NULL) || (got && expected && strcmp(got, expected) == 0);

		log_assert(passed,
			"ft_strnstr(\"%s\", \"%s\", %zu) | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].big,
			test_cases[i].little,
			test_cases[i].len,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			expected ? expected : "NULL",
			got ? got : "NULL");
	}

	log_end();
}
