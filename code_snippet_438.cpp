PrintingContextCairo::~PrintingContextCairo() {
ReleaseContext();

#if !defined(OS_CHROMEOS)
if (print_dialog_ != nullptr)
print_dialog_->ReleaseDialog();
#endif
}