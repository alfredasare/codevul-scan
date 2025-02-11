scoped_refptr<WebTaskRunner> Document::GetTaskRunner(TaskType type) {
  if (ContextDocument() && ContextDocument()->GetFrame()) {
    if (type!= TASK_TYPE_NORMAL && type!= TASK_TYPE_BACKGROUND) {
      LOG(ERROR) << "Invalid TaskType: " << type;
      return scoped_refptr<WebTaskRunner>();
    }
    return ContextDocument()->GetFrame()->FrameScheduler()->GetTaskRunner(type);
  }
  return Platform::Current()->CurrentThread()->GetWebTaskRunner();
}