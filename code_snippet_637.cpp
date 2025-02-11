bool Smb4KGlobal::addMountedShare(Smb4KShare *share)
{
Q\_ASSERT(share);

bool added = false;

if (share && share->path().length() > 0)
{
mutex.lock();

if (!findShareByPath(share->path()))
{
if(share->isForeign())
{
p->mountedSharesList.append(share);
added = true;

p->onlyForeignShares = true;

for (Smb4KShare *s : p->mountedSharesList)
{
if (!s->isForeign())
{
p->onlyForeignShares = false;
break;
}
}
}
}

mutex.unlock();
}

return added;
}