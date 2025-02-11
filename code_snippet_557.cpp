views::View* GetAncestralInputView(views::View* view) {
if (view->GetRuntimeClass() == views::Combobox::GetRuntimeClass())
return view;

return view->GetAncestorWithClassName(ExpandingTextfield::kViewClassName);
}