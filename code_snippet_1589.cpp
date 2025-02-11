void runSingleTask()
{
    if (m_tasks.isEmpty())
        return;
    if (auto task = m_tasks.takeFirst()) {
        task->run();
    } else {
        // Handle the error case when the removal fails.
        // This could be due to concurrent access or other issues.
    }
}