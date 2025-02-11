(pw)) {
err(EXIT_FAILURE, "_('User is not trusted')");
return;
}

if (setgid(pw->pw\_gid))
err(EXIT_FAILURE, _"(cannot set group id)");
if (setuid(pw->pw\_uid))
err(EXIT\_FAILURE, _"(cannot set user id)");
}

Note: The `is_trusted_user` function in this example simply checks if the UID and GID are 0 (root). In practice, you should implement a more robust validation function based on your specific requirements and trust model.