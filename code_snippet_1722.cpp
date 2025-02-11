static struct oz_hcd *oz_hcd_claim(void)
{
	struct oz_hcd *ozhcd;

	spin_lock_bh(&g_hcdlock);
	ozhcd = g_ozhcd;
	if (ozhcd == NULL) {
		spin_unlock_bh(&g_hcdlock);
		return NULL;
	}
	if (ozhcd->hcd == NULL) {
		spin_unlock_bh(&g_hcdlock);
		return NULL;
	}
	usb_get_hcd(ozhcd->hcd);
	spin_unlock_bh(&g_hcdlock);
	return ozhcd;
}