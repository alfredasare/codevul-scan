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
size_t len;
char asn_ip[64]; /* Ensure a large enough size for the input string */
int ret;
struct prefix_rd prd;

len = strlen(argv[0]);
if (len >= sizeof(asn_ip)) /* Check if the input string is too long */
{
vty_out (vty, "%% Input string is too long%s", VTY_NEWLINE);
return CMD_WARNING;
}

strlcpy(asn_ip, argv[0], sizeof(asn_ip)); /* Use strlcpy for safe string copying */

ret = str2prefix_rd (asn_ip, &prd);
if (! ret)
{
vty_out (vty, "%% Malformed Route Distinguisher%s", VTY_NEWLINE);
return CMD_WARNING;
}
return bgp_show_mpls_vpn (vty, &prd, bgp_show_type_normal, NULL, 0);
}