main(int argc, char *argv[]) {
    BufFilePtr inputraw, input, output;
    int c;
    char* input_path = argv[1]; // assume the input file path is passed as a command-line argument

    // Validate and sanitize the input file path
    if (strchr(input_path, '/')!= NULL) { // check for directory traversal sequences
        printf("Error: Invalid file path\n");
        return 1;
    }
    if (strcmp(input_path + strlen(input_path) - 4, ".zip")!= 0) { // restrict file extensions
        printf("Error: Invalid file extension\n");
        return 1;
    }

    inputraw = BufFileOpenRead(input_path);
    input = BufFilePushCompressed(inputraw);
    output = BufFileOpenWrite("output.txt"); // restrict the output file name and path
    while ((c = BufFileGet(input))!= BUFFILEEOF)
        BufFilePut(c, output);
    BufFileClose(input, FALSE);
    BufFileClose(output, FALSE);
    return 0;
}