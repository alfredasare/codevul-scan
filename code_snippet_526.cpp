bool Smb4KGlobal::addMountedShare(std::unique_ptr<Smb4KShare> share)
{
  Q_ASSERT(share);

  bool added = false;

  if (share && share.get()) 
  {
    mutex.lock();

    if (!findShareByPath(share->path()))
    {
      p->mountedSharesList.push_back(std::move(share)); 
      added = true;

      p->onlyForeignShares = true;
    
      for (auto& s : p->mountedSharesList)
      {
        if (!s->isForeign())
        {
          p->onlyForeignShares = false;
          break;
        }
      }
    }
    else
    {
    }

    mutex.unlock();
  }
  else
  {
  }

  return added;
}