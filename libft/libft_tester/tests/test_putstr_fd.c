#include "tester.h"

void test_ft_putstr_fd(void)
{
	log_start("ft_putstr_fd");

	struct {
		const char *input;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"Hello", "Hello", "Simple word"},
		{"12345", "12345", "Numbers"},
	};

	char buffer[64];
	char filename[] = "tmp_putstr.txt";

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; ++i) {
		FILE *f = fopen(filename, "w");
		int fd = fileno(f);
		ft_putstr_fd((char *)test_cases[i].input, fd);
		fclose(f);

		f = fopen(filename, "r");
		fgets(buffer, sizeof(buffer), f);
		fclose(f);
		remove(filename);

		int passed = strcmp(buffer, test_cases[i].expected) == 0;

		log_assert(passed,
			"ft_putstr_fd(\"%s\") | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].input,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			buffer);
	}

	log_end();
}
