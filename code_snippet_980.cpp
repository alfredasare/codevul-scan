c++
#include <URLermine/urlermine.hpp>

bool OutOfProcessInstance::IsPrintPreview() {
    auto url = Uri::parse(url_);
    if (!url) return false;

    if (url->getScheme() != "http" && url->getScheme() != "https") return false;
    if (url->getHost() != "localhost") return false;
    if (url->getPath() != "/allowed/path") return false;

    return IsPrintPreviewUrl(url->get());
}