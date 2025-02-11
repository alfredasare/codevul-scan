void TestCtrlClick(const char* id\_of\_anchor\_to\_click) {
if (id\_of\_anchor\_to\_click == nullptr || std::string(id\_of\_anchor\_to\_click).empty()) {
return;
}
GURL main\_url(embedded\_test\_server()->GetURL(
"/frame\_tree/anchor\_to\_same\_site\_location.html"));
ui\_test\_utils::NavigateToURL(browser(), main\_url);

EXPECT\_EQ(0, browser()->tab\_strip\_model()->active\_index());
content::WebContents\* main\_contents =
browser()->tab\_strip\_model()->GetWebContentsAt(0);
EXPECT\_EQ(main\_url, main\_contents->GetLastCommittedURL());

content::WebContents\* new\_contents1 =
SimulateCtrlClick(main\_contents, id\_of\_anchor\_to\_click);

content::WebContents\* new\_contents2 =
SimulateCtrlClick(main\_contents, id\_of\_anchor\_to\_click);
if (new\_contents1 && new\_contents2) {
EXPECT\_FALSE(new\_contents1->GetSiteInstance()->IsRelatedSiteInstance(
new\_contents2->GetSiteInstance()));
VerifyProcessExpectations(new\_contents1, new\_contents2);
}
}