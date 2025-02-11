frmController::isValidEncapsulationType(XfrmEncapType type) {
// Define the supported encapsulation types here.
// For example:
const std::unordered_set<XfrmEncapType> supportedEncapsulationTypes = {
    XfrmEncapType::TYPE1,
    XfrmEncapType::TYPE2,
    // ...
};

return supportedEncapsulationTypes.count(type) > 0;
}