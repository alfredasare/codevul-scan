#define MAX_SIGNAL_LENGTH 100 // Define the maximum allowed length for the signal

...

if (strlen(signal) > MAX_SIGNAL_LENGTH)
{
    return NULL;
}

new_hook_hsignal->signal = malloc(MAX_SIGNAL_LENGTH + 1);
if (!new_hook_hsignal->signal)
{
    free(new_hook);
    return NULL;
}
strncpy(new_hook_hsignal->signal, signal, MAX_SIGNAL_LENGTH);
new_hook_hsignal->signal[MAX_SIGNAL_LENGTH] = '\0';