
// size_t getheap(size_t align)
// {
// 	//497
// 	//496
// 	return ((align / sizeof(int)) * sizeof(int));
// }

// int main(int argc __attribute__ ((unused)), char **argv)
// {
// 	if (!argv[1])
// 		return (0);
// 	ft_putendl_fd(argv[1], 2);	
// }

/* void test_ft_calloc(void)
{
	void *p1 = ft_calloc(10, sizeof(int));
	assert(p1 != NULL);

	// Bellek sıfırlandı mı kontrolü
	for (size_t i = 0; i < 10 * sizeof(int); i++)
		assert(((unsigned char *)p1)[i] == 0);
	free(p1);

	// nmemb = 0
	void *p2 = ft_calloc(0, 4);
	assert(p2 != NULL);
	free(p2);

	// size = 0
	void *p3 = ft_calloc(4, 0);
	assert(p3 != NULL);
	free(p3);

	// Overflow testi
	void *p4 = ft_calloc(SIZE_MAX, 2);
	assert(p4 == NULL);  // overflow kontrolü doğruysa NULL döner

	printf("✓ ft_calloc passed all tests\n");
}

//memchr
void test_case(const char *testname, const void *s, int c, size_t n)
{
	void *std_res = memchr(s, c, n);
	void *ft_res = ft_memchr(s, c, n);

	if (std_res == ft_res)
		printf("[OK]   %s\n", testname);
	else
		printf("[FAIL] %s → expected %p but got %p\n", testname, std_res, ft_res);
}

int main(void)
{
	char str[] = "hello world";

	test_case("Found char", str, 'o', 11);        // 2 tane o var
	test_case("Char not found", str, 'x', 11);
	test_case("Search length 0", str, 'h', 0);
	test_case("Search in middle", str + 3, 'o', 5);
	test_case("Char = '\\0'", "abc\0def", '\0', 7);
	test_case("Char in last position", str, 'd', 11);
	test_case("Binary data", "\xff\x00\x01\x02", 0x00, 4);
}

//memmove
void print_result(const char *testname, const char *expected, const char *actual, size_t len)
{
	if (memcmp(expected, actual, len) == 0)
		printf("[OK]   %s\n", testname);
	else
		printf("[FAIL] %s → expected \"%s\", got \"%s\"\n", testname, expected, actual);
}

void test_memmove()
{
	char buffer1[100];
	char buffer2[100];

	// CASE 1: Normal copy (non-overlapping)
	strcpy(buffer1, "abcdef");
	strcpy(buffer2, "abcdef");
	memmove(buffer1 + 2, buffer1, 3);     // "ababcf"
	ft_memmove(buffer2 + 2, buffer2, 3);
	print_result("Non-overlapping copy", buffer1, buffer2, 6);
	// src destten küçükse 
	// CASE 2: Overlapping copy (src < dest)
	strcpy(buffer1, "123456");
	strcpy(buffer2, "123456");
	memmove(buffer1 + 2, buffer1, 4);     // "121234"
	ft_memmove(buffer2 + 2, buffer2, 4);
	print_result("Overlap: src < dest", buffer1, buffer2, 6);

	// CASE 3: Overlapping copy (dest < src)
	strcpy(buffer1, "abcdef");
	strcpy(buffer2, "abcdef");
	memmove(buffer1, buffer1 + 2, 4);     // "cdefef"
	ft_memmove(buffer2, buffer2 + 2, 4);
	print_result("Overlap: dest < src", buffer1, buffer2, 6);

	// CASE 4: Zero length
	strcpy(buffer1, "zero");
	strcpy(buffer2, "zero");
	memmove(buffer1 + 1, buffer1, 0);     // No change
	ft_memmove(buffer2 + 1, buffer2, 0);
	print_result("Zero length", buffer1, buffer2, 4);

	// CASE 5: src == dest
	strcpy(buffer1, "same");
	strcpy(buffer2, "same");
	memmove(buffer1, buffer1, 4);         // No change
	ft_memmove(buffer2, buffer2, 4);
	print_result("Same src and dest", buffer1, buffer2, 4);

	// CASE 6: NULL inputs with size == 0
	// void *r1 = memmove(NULL, NULL, 0);    // Should return NULL or not crash
	// void *r2 = ft_memmove(NULL, NULL, 0);
	// if (r1 == r2)
	// 	printf("[OK]   NULL input with size 0\n");
	// else
	// 	printf("[FAIL] NULL input with size 0 → expected %p, got %p\n", r1, r2);
} */