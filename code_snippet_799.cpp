LIBOPENMPT_MODPLUG_API void ModPlug\_SetSettings(const ModPlug\_Settings\* settings)
{
if(!settings || sizeof(\*settings) != sizeof(globalsettings)) return;
​
memcpy(&globalsettings, settings, sizeof(ModPlug\_Settings));
}