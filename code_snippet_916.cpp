ZEND_API size_t zend\_memory\_peak\_usage(int real\_usage)
{
#if ZEND\_MM\_STAT
 if (real\_usage) {
 return AG(mm\_heap)->real\_peak\_usage;
 } else {
 return AG(mm\_heap)->peak\_usage;
 }
#endif
 return 0;
}