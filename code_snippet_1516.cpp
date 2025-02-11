void UiSceneCreator::CreateScene() {
  try {
    Create2dBrowsingSubtreeRoots();
    CreateWebVrRoot();
    CreateBackground();
    CreateViewportAwareRoot();
    CreateContentQuad();
    CreateExitPrompt();
    CreateAudioPermissionPrompt();
    CreateWebVrExitWarning();
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
  } catch (Exception e) {
    Log.e("Error", "An error occurred");
  }
}