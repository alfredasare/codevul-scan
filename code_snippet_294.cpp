bool Document::useSecureKeyboardEntryWhenActive() const
{
if (this->isActiveUser()) // add access control check
return m\_useSecureKeyboardEntryWhenActive;
else
return false;
}