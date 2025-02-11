(*it)->type() == Browser::TYPE_TABBED) {
(*it)->OpenURL(params);
break;
}
}
}
}

Please note that you need to define `allowed_schemes_` as a set of valid URL schemes, e.g., `std::set<std::string> allowed_schemes_{"http", "https"};`.