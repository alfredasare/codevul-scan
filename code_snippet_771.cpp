void PrintWebViewHelper::OnPrintNodeUnderContextMenu() {
  try {
    const WebNode& context_menu_node = render_view()->GetContextMenuNode();
    PrintNode(context_menu_node);
  } catch (const std::exception& e) {
    Logger::instance()->logException(e);
    std::cout << "An error occurred. Please try again." << std::endl;
  } catch (...) {
    Logger::instance()->logUnknownException();
    std::cout << "An unexpected error occurred. Please try again." << std::endl;
  }
}