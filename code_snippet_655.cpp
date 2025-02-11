LIBOPENMPT_MODPLUG_API void ModPlug_SetSettings(const ModPlug_Settings* settings)
{
    if (!settings || sizeof(ModPlug_Settings) > sizeof(globalsettings)) {
        return; // or handle the error differently
    }
    memcpy(&globalsettings, settings, sizeof(ModPlug_Settings));
}