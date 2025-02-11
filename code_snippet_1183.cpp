static void hwsim_check_chanctx_magic(struct ieee80211_chanctx_conf *ctx)
{
    if (!ctx ||!ctx->def.chan || ctx->def.chan->center_freq < 0 || ctx->def.width < 0 ||
        ctx->def.center_freq1 < 0 || ctx->def.center_freq2 < 0) {
        printk(KERN_ERR "Invalid channel context control\n");
        return;
    }
    wiphy_dbg(hw->wiphy,
          "change channel context control: %d MHz/width: %d/cfreqs:%d/%d MHz\n",
          ctx->def.chan->center_freq, ctx->def.width,
          ctx->def.center_freq1, ctx->def.center_freq2);
}