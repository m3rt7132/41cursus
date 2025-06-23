#include "tester.h"

void test_ft_memchr(void)
{
	log_start("ft_memchr");

	struct {
		const char *input;
		int c;
		size_t n;
		const char *reason;
	} test_cases[] = {
		{"hello", 'e', 5, "Found 'e' in 'hello'"},
		{"hello", 'l', 3, "First 'l' within range"},
		{"hello", 'l', 2, "'l' not found in first 2 bytes"},
		{"hello", 'x', 5, "'x' not present"},
		{"", 'a', 0, "Empty string with 0 bytes"},
	};

	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		const char *input = test_cases[i].input;
		int c = test_cases[i].c;
		size_t n = test_cases[i].n;

		void *expected = memchr(input, c, n);
		void *got = ft_memchr(input, c, n);

		int passed = (expected == NULL && got == NULL)
			|| (expected != NULL && got != NULL && *(char *)expected == *(char *)got);

		log_assert(passed,
			"ft_memchr(\"%s\", '%c', %zu) | (Reason: %s) expected=%p, got=%p",
			input, c, n,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			expected, got);
	}

	log_end();
}
