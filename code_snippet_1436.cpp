void runSingleTask()
{
    synchronized (m_tasks) {
        if (m_tasks.isEmpty()) {
            return;
        }
        Task task = m_tasks.pollFirst();
        if (task!= null) {
            task.run();
        }
    }
}