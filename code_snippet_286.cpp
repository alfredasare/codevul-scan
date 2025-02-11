`void ProfileSyncService::RemoveObserver(Observer* observer) {`
`std::unique_ptr<Observer> deleter{observer};`
`observers_.RemoveObserver(deleter.get());`
`}`