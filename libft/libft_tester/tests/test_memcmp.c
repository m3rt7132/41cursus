#include "tester.h"

void test_ft_memcmp(void)
{
	log_start("ft_memcmp");

	struct {
		const char *s1;
		const char *s2;
		size_t n;
		const char *reason;
	} test_cases[] = {
		{"abc", "abc", 3, "Identical strings"},
		{"abc", "abd", 2, "Equal first two chars"},
		{"abc", "abd", 3, "Differ at last character"},
		{"", "", 0, "Empty strings"},
		{"abc", "ABC", 3, "Case-sensitive difference"},
	};

	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		int expected = memcmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
		int got = ft_memcmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);

		int passed = (expected == 0 && got == 0) || (expected * got > 0);

		log_assert(passed,
			"ft_memcmp(\"%s\", \"%s\", %zu) | (Reason: %s) expected=%d, got=%d",
			test_cases[i].s1, test_cases[i].s2, test_cases[i].n,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			expected, got);
	}

	log_end();
}

