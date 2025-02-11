// Limit master_volume within the array bounds
master_volume = (master_volume < sizeof(_WM_lin_volume) / sizeof(_WM_lin_volume[0])) ? master_volume : (sizeof(_WM_lin_volume) / sizeof(_WM_lin_volume[0])) - 1;

_WM_MasterVolume = _WM_lin_volume[master_volume];

return (0);