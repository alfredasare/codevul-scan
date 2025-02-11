HTStyle *LYstyles(int style_number)
{
    get_styles(); // Call get_styles() to initialize styles array
    if (style_number >= 0 && style_number < sizeof(styles) / sizeof(styles[0]))
        return &styles[style_number]; 
    else
        return NULL; 
}