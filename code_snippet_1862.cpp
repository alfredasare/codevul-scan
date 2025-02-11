void CGaiaCredentialBase::DisplayErrorInUI(LONG status,
LONG substatus,
BSTR status\_text) {
if (status != STATUS\_SUCCESS) {
if (events\_ && status\_text)
events-\>SetFieldString(this, FID\_DESCRIPTION, status\_text);
}
}