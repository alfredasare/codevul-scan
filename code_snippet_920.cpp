++
void MediaControlTextTrackListElement::defaultEventHandler(Event* event) {
  if (event->type() == EventTypeNames::change) {
    Node* target = event->target()->toNode();
    if (!target ||!target->isElementNode()) {
      return;
    }

    String nodeName = target->nodeName();
    if (!nodeName.isSafeForPathTraversal()) {
      return;
    }

    mediaControls().disableShowingTextTracks();
    int trackIndex = 0;
    if (nodeName.startsWith(trackIndexAttrName())) {
      trackIndex = Integer::parseInt(nodeName.substring(trackIndexAttrName().length()));
    }
    if (trackIndex!= trackIndexOffValue) {
      DCHECK_GE(trackIndex, 0);
      mediaControls().showTextTrackAtIndex(trackIndex);
      mediaElement().disableAutomaticTextTrackSelection();
    }

    event->setDefaultHandled();
  }
  MediaControlDivElement::defaultEventHandler(event);
}