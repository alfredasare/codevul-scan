c++
#include <cassert>

void incrementRunsFromLeadingWhitespace() {
    assert(m_runsFromLeadingWhitespace < std::numeric_limits<decltype(m_runsFromLeadingWhitespace)>::max());
    m_runsFromLeadingWhitespace++;
}