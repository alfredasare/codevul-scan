DEFUN (show_ip_bgp_vpnv4_rd,
       show_ip_bgp_vpnv4_rd_cmd,
       "show ip bgp vpnv4 rd ASN:nn_or_IP-address:nn",
       SHOW_STR
       IP_STR
       BGP_STR
       "Display VPNv4 NLRI specific information\n"
       "Display information for a route distinguisher\n"
       "VPN Route Distinguisher\n")
{
  int ret;
  struct prefix_rd prd;
  char buffer[256];

  ret = strncpy(buffer, argv[0], sizeof(buffer) - 1); // Secure string copy
  buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination
  if (strlen(buffer) >= sizeof(buffer) - 1)
    {
      vty_out (vty, "%% Malformed Route Distinguisher%s", VTY_NEWLINE);
      return CMD_WARNING;
    }
  return bgp_show_mpls_vpn (vty, buffer, bgp_show_type_normal, NULL, 0);
}