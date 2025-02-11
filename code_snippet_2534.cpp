#include <memory>

std::unique_ptr<content::WebContents> web_contents_ = ...;

content::WebContents* web_contents() {
    return web_contents_ ? web_contents_.get() : nullptr;
}