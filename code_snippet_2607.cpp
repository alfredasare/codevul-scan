compact->escape\_str = NULL;
if      (!strcmp(compact->escape\_mode\_str, "none")) compact->escape\_str = none\_escape\_str;
else if (!strcmp(compact->escape\_mode\_str, "c"   )) compact->escape\_str = c\_escape\_str;
else if (!strcmp(compact->escape\_mode\_str, "csv" )) compact->escape\_str = csv\_escape\_str;