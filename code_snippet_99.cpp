const int MAX_LEN = 1024; // Adjust this value based on your requirements
if (strnlen(attr.Value(), MAX_LEN) < MAX_LEN && jobAd->LookupString(attr.Value(), &tmp)) {