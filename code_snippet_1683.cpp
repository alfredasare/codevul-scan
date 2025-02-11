void UiSceneCreator::CreateScene() {
  if (Create2dBrowsingSubtreeRoots() == nullptr) {
    // Log an error and handle it appropriately
    LOGE("Error creating 2d browsing subtree roots");
    return;
  }

  if (CreateWebVrRoot() == nullptr) {
    // Log an error and handle it appropriately
    LOGE("Error creating WebVR root");
    return;
  }

  // ... add similar null checks for all other objects being created

  // Create the remaining objects as long as none of the previous creations have failed
  CreateBackground();
  CreateViewportAwareRoot();
  CreateContentQuad();
  CreateExitPrompt();
  CreateAudioPermissionPrompt();
  CreateWebVRExitWarning();
  CreateSystemIndicators();
  CreateUrlBar();
  CreateOmnibox();
  CreateWebVrUrlToast();
  CreateCloseButton();
  CreateToasts();
  CreateSplashScreenForDirectWebVrLaunch();
  CreateWebVrTimeoutScreen();
  CreateUnderDevelopmentNotice();
  CreateVoiceSearchUiGroup();
  CreateController();
  CreateKeyboard();
}