file = fopen(CONFIG\_FILE, "w");
if (!config\_file) {
perror("Error opening the configuration file for writing.");
fclose(config\_file);
exit(EXIT\_FAILURE);
}

size\_t bytes\_written = fwrite(config\_buffer, sizeof(char), bytes\_read, config\_file);
if (bytes\_written != bytes\_read) {
perror("Error writing the configuration file.");
fclose(config\_file);
exit(EXIT\_FAILURE);
}

// Close the configuration file.
fclose(config\_file);
}

act\_dump\_config() {
safe\_dump\_config();
}