info.si_errno = 0;
info.si_code = TRAP\_HWBKPT;
info.si\_addr = (void __user *)address;
force\_sig\_info(SIGTRAP, &info, current);
}
}

Note: The provided fix assumes that the `validate_address` function is added to the codebase and checks the validity of the user-space address before delivering the signal.