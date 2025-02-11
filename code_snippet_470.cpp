OS_POSIX)
FilePath input\_path(sanitized\_path);
PrepareStringForFileOps(input\_path, &filename);
if (filename.length() > 0 && filename[0] == '~')
filename = FixupHomedir(filename);
#endif

GURL file\_url = net::FilePathToFileURL(FilePath(filename));
if (file\_url.is\_valid()) {
return UTF16ToUTF8(net::FormatUrl(file\_url, std::string(),
net::kFormatUrlOmitUsernamePassword, UnescapeRule::NORMAL, NULL,
NULL, NULL));
}

return text;
}