void HTMLInputElement::postDispatchEventHandler(Event* event, ClickHandlingState* dataFromPreDispatch)
{
    if (!dataFromPreDispatch)
        return;
    m\_inputTypeView->didDispatchClick(event, *dataFromPreDispatch);
}