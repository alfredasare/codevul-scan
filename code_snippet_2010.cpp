static int avi_extract_stream_metadata(AVFormatContext *s, AVStream *st)
{
    //...
    
    case MKTAG('C', 'A', 'S', 'I'):
        avpriv_request_sample(s, "Invalid RIFF stream data tag type", NULL);
        break;
    case MKTAG('Z', 'o', 'r', 'a'):
        avpriv_request_sample(s, "Invalid RIFF stream data tag type", NULL);
        break;
    default:
        break;
    }
    
    return 0;
}