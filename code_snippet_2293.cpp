scoped_refptr<WebTaskRunner> Document::GetTaskRunner(TaskType type) {
if (ContextDocument() && ContextDocument()->GetFrame() && IsValidTaskType(type))
return ContextDocument()->GetFrame()->FrameScheduler()->GetTaskRunner(type);
return Platform::Current()->CurrentThread()->GetWebTaskRunner();
}