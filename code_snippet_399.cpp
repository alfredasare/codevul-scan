void WaitForInterstitialAttach(content::WebContents* web_contents) {
  if (!IsValidShowingInterstitialPageInput(web_contents)) {
    return;
  }
  scoped_refptr<content::MessageLoopRunner> loop_runner(new content::MessageLoopRunner);
  InterstitialObserver observer(web_contents, loop_runner->QuitClosure(), base::Closure());
  loop_runner->Run();
}

bool IsValidShowingInterstitialPageInput(content::WebContents* web_contents) {
  return web_contents!= nullptr && web_contents->ShowingInterstitialPage();
}