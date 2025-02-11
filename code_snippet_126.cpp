#include <string.h>

#define PRINTK_BUF_SIZE 4096

static char printk_buf[PRINTK_BUF_SIZE];

asmlinkage int printk(const char *fmt, ...)
{
	va_list args;
	int r;
	char safe_fmt[256];

#ifdef CONFIG_KGDB_KDB
	if (unlikely(kdb_trap_printk)) {
		va_start(args, fmt);
		r = vkdb_printf(fmt, args);
		va_end(args);
		return r;
	}
#endif

	// Limit the length of the format string to prevent buffer overflow
	strncpy(safe_fmt, fmt, sizeof(safe_fmt));
	safe_fmt[sizeof(safe_fmt) - 1] = '\0';

	va_start(args, fmt);
	r = vsnprintf(NULL, 0, safe_fmt, args);
	va_end(args);

	// Use the safe format string with snprintf
	va_start(args, fmt);
	r = snprintf(printk_buf, PRINTK_BUF_SIZE, safe_fmt, args);
	va_end(args);

	return r;
}