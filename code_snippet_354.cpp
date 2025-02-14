c++
#include "third_party/blink/renderer/platform/security/sanitizer.h"

void FrameLoader::StopAllLoaders() {
  if (frame_->GetDocument()->PageDismissalEventBeingDispatched() !=
      Document::kNoDismissal)
    return;

  if (in_stop_all_loaders_)
    return;

  base::AutoReset<bool> in_stop_all_loaders(&in_stop_all_loaders_, true);

  for (Frame* child = frame_->Tree().FirstChild(); child;
       child = child->Tree().NextSibling()) {
    if (child->IsLocalFrame()) {
      KURL url = Sanitizer::SanitizeURL(ToLocalFrame(child)->Loader().GetDocumentLoader()->ProvisionalURL(),
                                        blink::WebSanitizer::DisallowAll());

      ToLocalFrame(child)->Loader().StopAllLoaders();
    }
  }

  frame_->GetDocument()->CancelParsing();
  if (document_loader_)
    document_loader_->StopLoading();
  if (!protect_provisional_loader_)
    DetachDocumentLoader(provisional_document_loader_);
  frame_->GetNavigationScheduler().Cancel();
  DidFinishNavigation();

  TakeObjectSnapshot();
}