static void _yy_push_state(int new_state TSRMLS_DC)
{
    int stack_size = sizeof(int);
    void *stack_element = malloc(stack_size);
    if (!stack_element) {
        zend_error(E_ERROR, "Memory allocation failed");
        return;
    }

    // Validate the input parameter
    if (new_state < 0 || new_state > YYMAXDEPTH) {
        zend_error(E_ERROR, "Invalid state value");
        free(stack_element);
        return;
    }

    // Store the new state value in the stack element
    *(int *)stack_element = new_state;

    // Push the stack element onto the stack
    zend_stack_push(&SCNG(state_stack), stack_element, stack_size);

    free(stack_element);
}