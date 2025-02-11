#include <stdarg.h>
#include <stdio.h>
#include <string.h>

struct bpf_verifier_env {
	char log[256];
};

void bpf_verifier_log_write(struct bpf_verifier_env *env, const char *fmt, ...)
{
	va_list args;
	char user_data[64];
	int len;

	if (!bpf_verifier_log_needed(&env->log))