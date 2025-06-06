#include "tester.h"

void test_ft_memmove(void)
{
	log_start("ft_memmove");

	struct {
		char input[20];
		size_t dst_offset;
		size_t src_offset;
		size_t n;
		const char *reason;
	} test_cases[] = {
		{"abcdef", 0, 3, 3, "Copy 'def' to beginning"},
		{"abcdef", 2, 0, 4, "Overlap: dst > src"},
		{"abcdef", 0, 2, 4, "Overlap: dst < src"},
		{"abcdef", 0, 0, 6, "Same location"},
		{"abcdef", 0, 2, 0, "Zero length"},
	};

	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		char std_buf[20];
		char ft_buf[20];

		memcpy(std_buf, test_cases[i].input, sizeof(test_cases[i].input));
		memcpy(ft_buf, test_cases[i].input, sizeof(test_cases[i].input));

		memmove(std_buf + test_cases[i].dst_offset, std_buf + test_cases[i].src_offset, test_cases[i].n);
		ft_memmove(ft_buf + test_cases[i].dst_offset, ft_buf + test_cases[i].src_offset, test_cases[i].n);

		int passed = memcmp(std_buf, ft_buf, 20) == 0;

		log_assert(passed,
			"ft_memmove(dst=%zu, src=%zu, %zu bytes) | (Reason: %s)\nexpected=\"%s\", got=\"%s\"",
			test_cases[i].dst_offset, test_cases[i].src_offset, test_cases[i].n,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			std_buf, ft_buf);
	}

	log_end();
}
