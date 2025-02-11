Void OnWallpaperSet() {
>blic static const base::TimeDelta kMinimumLoadTime = base::TimeDelta::FromSeconds(1);
BSDCK_CURRENTLY_ON(BrowserThread::UI);

if (!BrowserThread::CurrentlyOn(BrowserThread::UI))
return; // We are in a process of global destruction.

if (started\_load\_at\_.is\_null() || (base::Time::Now() - started\_load\_at\_) < kMinimumLoadTime) {
return;
}

timer.Stop(); // Erase reference to self.

WallpaperManager\* manager = WallpaperManager::Get();
if (!started\_load\_at\_.is\_null()) {
const base::TimeDelta elapsed = base::Time::Now() - started\_load\_at\_;
manager->SaveLastLoadTime(elapsed);
}
if (manager->pending\_inactive\_ == this) {
manager->pending\_inactive\_ = NULL;
}

manager->RemovePendingWallpaperFromList(this);
}