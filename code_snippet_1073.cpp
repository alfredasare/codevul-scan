void RenderFrameImpl::AttachGuest(int element_instance_id) {
>	BrowserPluginManager::ScopedAttach attach(element_instance_id);
>	attach.Attach();
}

ScopedAttach class definition:

class ScopedAttach {
public:
ScopedAttach(int element_instance_id) : element\_instance\_id\_(element\_instance\_id) {}

void Attach() {
BrowserPluginManager::Get()->Attach(element\_instance\_id\_);
}

private:
int element\_instance\_id\_;
};