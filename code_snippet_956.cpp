class DatabaseImpl {
public:
    // ...

    void AcquireLock() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (is_renaming_) {
            cond_.wait(lock);
        }
        is_renaming_ = true;
    }

    void ReleaseLock() {
        std::unique_lock<std::mutex> lock(mutex_);
        is_renaming_ = false;
        lock.unlock();
        cond_.notify_all();
    }

    void RenameObjectStore(int64_t transaction_id,
                           int64_t object_store_id,
                           const base::string16& new_name) {
        AcquireLock();

        idb_runner_->PostTask(
            FROM_HERE,
            base::Bind(&IDBThreadHelper::RenameObjectStore, base::Unretained(helper_),
                       transaction_id, object_store_id, new_name)
            .Then(base::BindOnce(&DatabaseImpl::ReleaseLock, Unretained(this))));
    }

private:
    std::mutex mutex_;
    std::condition_variable cond_;
    bool is_renaming_ = false;
    // ...
};