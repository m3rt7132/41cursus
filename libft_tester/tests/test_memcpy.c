#include "tester.h"

void test_ft_memcpy(void)
{
	log_start("ft_memcpy");

	struct {
		const char *src;
		size_t n;
		const char *reason;
	} test_cases[] = {
		{"hello", 5, "Copy full string"},
		{"world", 3, "Copy first 3 chars"},
		{"abc", 0, "Copy nothing"},
	};

	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		char dest1[10] = {0};
		char dest2[10] = {0};

		memcpy(dest1, test_cases[i].src, test_cases[i].n);
		ft_memcpy(dest2, test_cases[i].src, test_cases[i].n);

		int passed = memcmp(dest1, dest2, test_cases[i].n) == 0;

		log_assert(passed,
			"ft_memcpy(\"%s\", %zu) | (Reason: %s) expected=\"%.*s\", got=\"%.*s\"",
			test_cases[i].src, test_cases[i].n,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			(int)test_cases[i].n, dest1,
			(int)test_cases[i].n, dest2);
	}

	log_end();
}
