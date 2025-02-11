HTStyle *LYstyles(int style_number)
{
    if (styles[style_number] == 0 && style_number >= 0 && style_number < NUM_STYLES)
    {
        get_styles();
        if (styles[style_number] == 0) // Check if initialization failed
        {
            // Handle the error or return an error code
            return NULL;
        }
    }
    return styles[style_number];
}