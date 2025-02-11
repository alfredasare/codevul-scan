vec);
cond\_resched();
}

ret2 = filemap\_check\_errors(NODE\_MAPPING(sbi));
if (!ret)
ret = ret2;
return ret;
}

Note: The added boundary check for the 'index' variable in the while loop condition ensures that it does not exceed the allowable range, preventing a buffer overflow.