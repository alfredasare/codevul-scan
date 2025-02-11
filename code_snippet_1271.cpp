missions;
go to out;
}
if (perm\_ok != NULL)
\*perm\_ok = 1;

r = sshkey\_load\_private\_type\_fd(fd, type, passphrase, keyp, commentp);
out:
close(fd);
return r;
}