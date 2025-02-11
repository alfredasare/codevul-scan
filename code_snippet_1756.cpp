IPC\_BEGIN\_MESSAGE\_MAP(PrintWebViewHelper, message)
IPC\_MESSAGE\_HANDLER(PrintMsg\_PrintPages, OnPrintPages)
IPC\_MESSAGE\_HANDLER(PrintMsg\_PrintForSystemDialog, OnPrintForSystemDialog)
IPC\_MESSAGE\_HANDLER(PrintMsg\_InitiatePrintPreview, OnInitiatePrintPreview)
IPC\_MESSAGE\_HANDLER(PrintMsg\_PrintNodeUnderContextMenu, OnPrintNodeUnderContextMenu)
IPC\_MESSAGE\_HANDLER(PrintMsg\_PrintPreview, OnPrintPreview)
IPC\_MESSAGE\_HANDLER(PrintMsg\_PrintForPrintPreview, OnPrintForPrintPreview)
IPC\_MESSAGE\_HANDLER(PrintMsg\_PrintingDone, OnPrintingDone)
IPC\_MESSAGE\_HANDLER(PrintMsg\_ResetScriptedPrintCount, ResetScriptedPrintCount)
IPC\_MESSAGE\_HANDLER(PrintMsg\_SetScriptedPrintingBlocked, SetScriptedPrintBlocked)
IPC\_MESSAGE\_UNHANDLED() {
LOG(ERROR) << "Unhandled message received: " << message.type();
handled = false;
}
}
return handled;