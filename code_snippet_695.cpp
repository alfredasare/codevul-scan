static void free_Var(Var* var) {
    if (var!= NULL) {
        free(var->szKey);
        free(var->Value);
        free(var);
    } else {
        printf("Error: Attempted to free a null pointer\n");
    }
}