#include "tester.h"

void test_ft_memset(void)
{
	log_start("ft_memset");

	struct {
		char input[10];
		int c;
		size_t n;
		const char *reason;
	} test_cases[] = {
		{"abcdef", 'x', 3, "Overwrite first 3 chars"},
		{"abcdef", 'z', 0, "Zero fill"},
		{"abcdef", 'y', 6, "Full overwrite"},
	};

	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		char std_buf[10];
		char ft_buf[10];

		memcpy(std_buf, test_cases[i].input, 10);
		memcpy(ft_buf, test_cases[i].input, 10);

		memset(std_buf, test_cases[i].c, test_cases[i].n);
		ft_memset(ft_buf, test_cases[i].c, test_cases[i].n);

		int passed = memcmp(std_buf, ft_buf, 10) == 0;

		log_assert(passed,
			"ft_memset(\"%s\", '%c', %zu) | (Reason: %s)",
			test_cases[i].input, test_cases[i].c, test_cases[i].n,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-");
	}

	log_end();
}
