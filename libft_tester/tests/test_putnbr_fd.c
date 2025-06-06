#include "tester.h"

void test_ft_putnbr_fd(void)
{
	log_start("ft_putnbr_fd");

	struct {
		int input;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{0, "0", "Zero"},
		{42, "42", "Positive number"},
		{-42, "-42", "Negative number"},
		{2147483647, "2147483647", "INT_MAX"},
		{-2147483648, "-2147483648", "INT_MIN"},
	};

	char buffer[64];
	char filename[] = "tmp_putnbr.txt";

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; ++i) {
		FILE *f = fopen(filename, "w");
		int fd = fileno(f);
		ft_putnbr_fd(test_cases[i].input, fd);
		fclose(f);

		f = fopen(filename, "r");
		fgets(buffer, sizeof(buffer), f);
		fclose(f);
		remove(filename);

		// fgets null terminator sonrası çöp karakter alabilir
		buffer[strcspn(buffer, "\n")] = '\0';

		int passed = strcmp(buffer, test_cases[i].expected) == 0;

		log_assert(passed,
			"ft_putnbr_fd(%d) | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].input,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			buffer);
	}

	log_end();
}
