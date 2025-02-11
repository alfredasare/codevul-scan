class XDisplay; // Forward declaration

class ScopedDisplay {
public:
    ScopedDisplay(XDisplay* display = nullptr) : m_display(display) {}
    ~ScopedDisplay() { if (m_display) XCloseDisplay(m_display); }

    XDisplay* get() const { return m_display; }
    XDisplay* release() { XDisplay* temp = m_display; m_display = nullptr; return temp; }
    void reset(XDisplay* display = nullptr) { if (m_display) XCloseDisplay(m_display); m_display = display; }
    XDisplay& operator*() const { return *m_display; }
    XDisplay* operator->() const { return m_display; }

private:
    XDisplay* m_display;
};

XDisplay* GetXDisplay() {
    // Implementation details of getting X Display
    // ...
}

bool XDisplayExists() {
    ScopedDisplay display(GetXDisplay());
    return (display.get() != nullptr);
}