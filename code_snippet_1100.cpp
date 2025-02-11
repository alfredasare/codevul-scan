c++
ssize_t InputDispatcher::InputState::findKeyMemento(const KeyEntry* entry) const {
    for (size_t i = 0; i < mKeyMementos.size() && i < SIZE_MAX; i++) {
        const KeyMemento& memento = mementoList.at(i);
        if (memento.deviceId == entry->deviceId
            && memento.source == entry->source
            && memento.keyCode == entry->keyCode
            && memento.scanCode == entry->scanCode) {
            return i;
        }
    }
    return -1;
}