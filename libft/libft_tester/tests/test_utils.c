#include "tester.h"
#include <time.h>
#include <stdarg.h>

FILE *log_file = NULL;

__attribute__((constructor))
void init_log_file(void) {
	char *log_name = generate_log_filename();
    log_file = fopen(log_name, "w");
    if (!log_file) {
		perror("Could not open log file");
        exit(EXIT_FAILURE);
    }
}

__attribute__((destructor))
void close_log_file(void) {
    if (log_file)
        fclose(log_file);
}

void log_start(const char *func_name) {
    fprintf(log_file, "====/-\\ Testing %s /-\\====\n", func_name);
    printf("\033[1;34m[     RUN     ] %s\033[0m\n", func_name);
}

void log_assert(int passed, const char *format, ...) {
	va_list args;
    va_start(args, format);
	
    if (passed) {
		printf("\033[1;32m[   OK   ]\033[0m ");
        vprintf(format, args);
        printf("\n");
        fprintf(log_file, "[OK] ");
        va_start(args, format); // yeniden başlatmak gerekiyor
        vfprintf(log_file, format, args);
        fprintf(log_file, "\n");
    } else {
		printf("\033[1;31m[  FAILED  ]\033[0m ");
        vprintf(format, args);
		printf("\n");
        fprintf(log_file, "[FAIL] ");
        va_start(args, format);
        vfprintf(log_file, format, args);
		fprintf(log_file, "\n");
        // assert(0 && "Assertion failed");
    }
    va_end(args);
}

void log_end(void) {
	fprintf(log_file, "\n");
}

void log_info(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    // Terminale yaz (mavi)
    printf("\033[0;34m[INFO]\033[0m ");
    vprintf(fmt, args);
    printf("\n");

    // Log dosyasına yaz
    if (log_file) {
        va_start(args, fmt);  // yeniden başlat
        fprintf(log_file, "[INFO] ");
        vfprintf(log_file, fmt, args);
        fprintf(log_file, "\n");
    }
    va_end(args);
}

void log_error(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    printf("\033[0;31m[ERROR]\033[0m ");
    vprintf(fmt, args);
    printf("\n");

    if (log_file) {
        va_start(args, fmt);
        fprintf(log_file, "[ERROR] ");
        vfprintf(log_file, fmt, args);
        fprintf(log_file, "\n");
    }

    va_end(args);
}

void log_warn(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    printf("\033[0;33m[WARN]\033[0m ");
    vprintf(fmt, args);
    printf("\n");

    if (log_file) {
        va_start(args, fmt);
        fprintf(log_file, "[WARN] ");
        vfprintf(log_file, fmt, args);
        fprintf(log_file, "\n");
    }

    va_end(args);
}

size_t getheap(size_t align)
{
	return ((align / sizeof(int)) * sizeof(int));
}

char *generate_log_filename(void)
{
	static char filename[64];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    snprintf(filename, sizeof(filename),
             "logs/test_%02d-%02d_%02d-%02d.txt",
            /*  t->tm_year + 1900,*/ t->tm_mon + 1, t->tm_mday,
             t->tm_hour, t->tm_min);
    return filename;
}
