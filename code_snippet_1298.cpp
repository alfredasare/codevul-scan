parallel(&padata\_local, &ctx->cb\_cpu, &pdecrypt);
if (!err)
return -EINPROGRESS;

return err;
}

This fix creates a local copy of the `padata` structure, initializes it with the values from `pcrypt_request_padata(preq)`, and then uses the local copy in the call to `pcrypt_do_parallel`. This avoids the TOCTOU vulnerability by ensuring that the values used in the function call do not change during the execution of the function.