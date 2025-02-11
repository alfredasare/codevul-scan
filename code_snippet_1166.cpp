class MyClass {
private:
    PendingFrame m_pendingFrame{};

public:
    MyClass() : m_pendingFrame() {}
    ~MyClass() { m_pendingFrame.~PendingFrame(); }
};