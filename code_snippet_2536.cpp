bool allowed_to_execute(const_os_ptr op) {
    return r_has_attr(op, a_execute) &&
           ref_type_uses_access(r_type(op)) &&
           (r_has_attr(op, a_executable) || !r_has_type(op, t_dictionary));
}

check_for_exec(const_os_ptr op) {
    if (!allowed_to_execute(op)) {
        return_error(gs_error_operationnotallowed);
    }
    return 0;
}