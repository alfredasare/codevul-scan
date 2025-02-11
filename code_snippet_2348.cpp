check_for_exec(const_os_ptr op)
{
    if (!r_has_attr(op, a_execute) && /* only true if noaccess */
        ref_type_uses_access(r_type(op)) &&
        (r_has_attr(op, a_executable) || !r_has_type(op, t_dictionary))
        ) {
        return_error(gs_error_invalid_operation); // Custom error message
    }
    return 0;
}