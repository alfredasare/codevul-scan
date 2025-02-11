ContentsObserver(WebContents* web_contents, FrameDeletionObserver* parent_observer)
: WebContentsObserver(web_contents ? web_contents : nullptr),
parent_observer_(parent_observer ? parent_observer : nullptr) {}