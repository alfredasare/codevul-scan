dquot_dirty(dquot);
ret = ext4\_write\_dquot(dquot);
} else {
ret = dquot\_mark\_dquot\_dirty(dquot);
}

/* Release the write lock */
fcntl(quota\_file->f\_dentry->d\_inode->i\_ino, F\_SETLK, &flock);
return ret;
}

Note that releasing the lock should always succeed, so it's not necessary to check for errors.