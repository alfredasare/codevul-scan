#include <string.h>

#define MAX_LYRIC_LENGTH 256 // Adjust this value to your specific needs

void _WM_do_meta_text(struct _mdi *mdi, struct _event_data *data) {
/* placeholder function so we can record tempo in the event stream
 * for conversion function _WM_Event2Midi */
#ifdef DEBUG_MIDI
    uint8_t ch = data->channel;
    MIDI_EVENT_SDEBUG(__FUNCTION__, ch, data->data.string);
#endif
    if (mdi->extra_info.mixer_options & WM_MO_TEXTASLYRIC && data->data.string != NULL) {
        size_t len = strlen(data->data.string);
        if (len >= MAX_LYRIC_LENGTH) {
            // Truncate the string if it exceeds the maximum allowed length
            len = MAX_LYRIC_LENGTH - 1;
        }
        strncpy(mdi->lyric, data->data.string, len);
        mdi->lyric[len] = '\0'; // Ensure null termination
    }

    return;
}