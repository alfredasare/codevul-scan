n ret;
}

*pHandle = (effect\_handle\_t<pContext);

pContext->mState = LOUDNESS\_ENHANCER\_STATE\_INITIALIZED;

ALOGV(" LELib\_Create context is %p", pContext);

return 0;

}

Note: Please replace MIN\_SESSION\_ID, MAX\_SESSION\_ID, MIN\_IO\_ID, and MAX\_IO\_ID with the actual valid ranges for sessionId and ioId in your application.