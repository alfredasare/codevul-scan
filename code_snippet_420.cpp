bool ImageInputType::canBeSuccessfulSubmitButton()
{
    // Perform an actual check to determine if the image input type can be successful for submission
    return m_imageInputElement && m_imageInputElement->hasAttr("alt");
}