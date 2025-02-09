static Image *ReadVIFFImage(const ImageInfo *image_info,
  ExceptionInfo *exception)
{
#define VFF_CM_genericRGB  15
#define VFF_CM_ntscRGB  1
#define VFF_CM_NONE  0
#define VFF_DEP_DECORDER  0x4
#define VFF_DEP_NSORDER  0x8
#define VFF_DES_RAW  0
#define VFF_LOC_IMPLICIT  1
#define VFF_MAPTYP_NONE  0
#define VFF_MAPTYP_1_BYTE  1
#define VFF_MAPTYP_2_BYTE  2
#define VFF_MAPTYP_4_BYTE  4
#define VFF_MAPTYP_FLOAT  5
#define VFF_MAPTYP_DOUBLE  7
#define VFF_MS_NONE  0
#define VFF_MS_ONEPERBAND  1
#define VFF_MS_SHARED  3
#define VFF_TYP_BIT  0
#define VFF_TYP_1_BYTE  1
#define VFF_TYP_2_BYTE  2
#define VFF_TYP_4_BYTE  4
#define VFF_TYP_FLOAT  5
#define VFF_TYP_DOUBLE  9

  typedef struct _ViffInfo
  {
    unsigned char
      identifier,
      file_type,
      release,
      version,
      machine_dependency,
      reserve[3];

    char
      comment[512];

    unsigned int
      rows,
      columns,
      subrows;

    int
      x_offset,
      y_offset;

    float
      x_bits_per_pixel,
      y_bits_per_pixel;

    unsigned int
      location_type,
      location_dimension,
      number_of_images,
      number_data_bands,
      data_storage_type,
      data_encode_scheme,
      map_scheme,
      map_storage_type,
      map_rows,
      map_columns,
      map_subrows,
      map_enable,
      maps_per_cycle,
      color_space_model;
  } ViffInfo;

  double
    min_value,
    scale_factor,
    value;

  Image
    *image;

  int
    bit;

  MagickBooleanType
    status;

  MagickSizeType
    number_pixels;

  register IndexPacket
    *indexes;

  register ssize_t
    x;

  register PixelPacket
    *q;

  register ssize_t
    i;

  register unsigned char
    *p;

  size_t
    bytes_per_pixel,
    max_packets,
    quantum;

  ssize_t
    count,
    y;

  unsigned char
    *pixels;

  unsigned long
    lsb_first;

  ViffInfo
    viff_info;

  /*
    Open image file.
  */
  assert(image_info != (const ImageInfo *) NULL);
  assert(image_info->signature == MagickCoreSignature);
  if (image_info->debug != MagickFalse)
    (void) LogMagickEvent(TraceEvent,GetMagickModule(),"%s",
      image_info->filename);
  assert(exception != (ExceptionInfo *) NULL);
  assert(exception->signature == MagickCoreSignature);
  image=AcquireImage(image_info);
  status=OpenBlob(image_info,image,ReadBinaryBlobMode,exception);
  if (status == MagickFalse)
    {
      image=DestroyImageList(image);
      return((Image *) NULL);
    }
  /*
    Read VIFF header (1024 bytes).
  */
  count=ReadBlob(image,1,&viff_info.identifier);
  do
  {
    /*
      Verify VIFF identifier.
    */
    if ((count != 1) || ((unsigned char) viff_info.identifier != 0xab))
      ThrowReaderException(CorruptImageError,"NotAVIFFImage");
    /*
      Initialize VIFF image.
    */
    (void) ReadBlob(image,sizeof(viff_info.file_type),&viff_info.file_type);
    (void) ReadBlob(image,sizeof(viff_info.release),&viff_info.release);
    (void) ReadBlob(image,sizeof(viff_info.version),&viff_info.version);
    (void) ReadBlob(image,sizeof(viff_info.machine_dependency),
      &viff_info.machine_dependency);
    (void) ReadBlob(image,sizeof(viff_info.reserve),viff_info.reserve);
    count=ReadBlob(image,512,(unsigned char *) viff_info.comment);
    if (count != 512)
      ThrowReaderException(CorruptImageError,"ImproperImageHeader");
    viff_info.comment[511]='\0';
    if (strlen(viff_info.comment) > 4)
      (void) SetImageProperty(image,"comment",viff_info.comment);
    if ((viff_info.machine_dependency == VFF_DEP_DECORDER) ||
        (viff_info.machine_dependency == VFF_DEP_NSORDER))
      image->endian=LSBEndian;
    else
      image->endian=MSBEndian;
    viff_info.rows=ReadBlobLong(image);
    viff_info.columns=ReadBlobLong(image);
    viff_info.subrows=ReadBlobLong(image);
    viff_info.x_offset=ReadBlobSignedLong(image);
    viff_info.y_offset=ReadBlobSignedLong(image);
    viff_info.x_bits_per_pixel=(float) ReadBlobLong(image);
    viff_info.y_bits_per_pixel=(float) ReadBlobLong(image);
    viff_info.location_type=ReadBlobLong(image);
    viff_info.location_dimension=ReadBlobLong(image);
    viff_info.number_of_images=ReadBlobLong(image);
    viff_info.number_data_bands=ReadBlobLong(image);
    viff_info.data_storage_type=ReadBlobLong(image);
    viff_info.data_encode_scheme=ReadBlobLong(image);
    viff_info.map_scheme=ReadBlobLong(image);
    viff_info.map_storage_type=ReadBlobLong(image);
    viff_info.map_rows=ReadBlobLong(image);
    viff_info.map_columns=ReadBlobLong(image);
    viff_info.map_subrows=ReadBlobLong(image);
    viff_info.map_enable=ReadBlobLong(image);
    viff_info.maps_per_cycle=ReadBlobLong(image);
    viff_info.color_space_model=ReadBlobLong(image);
    for (i=0; i < 420; i++)
      (void) ReadBlobByte(image);
    if (EOFBlob(image) != MagickFalse)
      ThrowReaderException(CorruptImageError,"UnexpectedEndOfFile");
    image->columns=viff_info.rows;
    image->rows=viff_info.columns;
    image->depth=viff_info.x_bits_per_pixel <= 8 ? 8UL :
      MAGICKCORE_QUANTUM_DEPTH;
    image->matte=viff_info.number_data_bands == 4 ? MagickTrue : MagickFalse;
    status=SetImageExtent(image,image->columns,image->rows);
    if (status == MagickFalse)
      {
        InheritException(exception,&image->exception);
        return(DestroyImageList(image));
      }
    (void) SetImageBackgroundColor(image);
    /*
      Verify that we can read this VIFF image.
    */
    number_pixels=(MagickSizeType) viff_info.columns*viff_info.rows;
    if (number_pixels != (size_t) number_pixels)
      ThrowReaderException(ResourceLimitError,"MemoryAllocationFailed");
    if (number_pixels == 0)
      ThrowReaderException(CoderError,"ImageColumnOrRowSizeIsNotSupported");
    if ((viff_info.number_data_bands < 1) || (viff_info.number_data_bands > 4))
      ThrowReaderException(CorruptImageError,"ImproperImageHeader");
    if ((viff_info.data_storage_type != VFF_TYP_BIT) &&
        (viff_info.data_storage_type != VFF_TYP_1_BYTE) &&
        (viff_info.data_storage_type != VFF_TYP_2_BYTE) &&
        (viff_info.data_storage_type != VFF_TYP_4_BYTE) &&
        (viff_info.data_storage_type != VFF_TYP_FLOAT) &&
        (viff_info.data_storage_type != VFF_TYP_DOUBLE))
      ThrowReaderException(CoderError,"DataStorageTypeIsNotSupported");
    if (viff_info.data_encode_scheme != VFF_DES_RAW)
      ThrowReaderException(CoderError,"DataEncodingSchemeIsNotSupported");
    if ((viff_info.map_storage_type != VFF_MAPTYP_NONE) &&
        (viff_info.map_storage_type != VFF_MAPTYP_1_BYTE) &&
        (viff_info.map_storage_type != VFF_MAPTYP_2_BYTE) &&
        (viff_info.map_storage_type != VFF_MAPTYP_4_BYTE) &&
        (viff_info.map_storage_type != VFF_MAPTYP_FLOAT) &&
        (viff_info.map_storage_type != VFF_MAPTYP_DOUBLE))
      ThrowReaderException(CoderError,"MapStorageTypeIsNotSupported");
    if ((viff_info.color_space_model != VFF_CM_NONE) &&
        (viff_info.color_space_model != VFF_CM_ntscRGB) &&
        (viff_info.color_space_model != VFF_CM_genericRGB))
      ThrowReaderException(CoderError,"ColorspaceModelIsNotSupported");
    if (viff_info.location_type != VFF_LOC_IMPLICIT)
      ThrowReaderException(CoderError,"LocationTypeIsNotSupported");
    if (viff_info.number_of_images != 1)
      ThrowReaderException(CoderError,"NumberOfImagesIsNotSupported");
    if (viff_info.map_rows == 0)
      viff_info.map_scheme=VFF_MS_NONE;
    switch ((int) viff_info.map_scheme)
    {
      case VFF_MS_NONE:
      {
        if (viff_info.number_data_bands < 3)
          {
            /*
              Create linear color ramp.
            */
            if (viff_info.data_storage_type == VFF_TYP_BIT)
              image->colors=2;
            else
              if (viff_info.data_storage_type == VFF_MAPTYP_1_BYTE)
                image->colors=256UL;
              else
                image->colors=image->depth <= 8 ? 256UL : 65536UL;
            if (AcquireImageColormap(image,image->colors) == MagickFalse)
              ThrowReaderException(ResourceLimitError,"MemoryAllocationFailed");
          }
        break;
      }
      case VFF_MS_ONEPERBAND:
      case VFF_MS_SHARED:
      {
        unsigned char
          *viff_colormap;

        /*
          Allocate VIFF colormap.
        */
        switch ((int) viff_info.map_storage_type)
        {
          case VFF_MAPTYP_1_BYTE: bytes_per_pixel=1; break;
          case VFF_MAPTYP_2_BYTE: bytes_per_pixel=2; break;
          case VFF_MAPTYP_4_BYTE: bytes_per_pixel=4; break;
          case VFF_MAPTYP_FLOAT: bytes_per_pixel=4; break;
          case VFF_MAPTYP_DOUBLE: bytes_per_pixel=8; break;
          default: bytes_per_pixel=1; break;
        }
        image->colors=viff_info.map_columns;
        if ((MagickSizeType) (viff_info.map_rows*image->colors) > GetBlobSize(image))
          ThrowReaderException(CorruptImageError,"InsufficientImageDataInFile");
        if (AcquireImageColormap(image,image->colors) == MagickFalse)
          ThrowReaderException(ResourceLimitError,"MemoryAllocationFailed");
        if ((MagickSizeType) viff_info.map_rows > GetBlobSize(image))
          ThrowReaderException(CorruptImageError,"InsufficientImageDataInFile");
        if ((MagickSizeType) viff_info.map_rows >
            (viff_info.map_rows*bytes_per_pixel*sizeof(*viff_colormap)))
          ThrowReaderException(CorruptImageError,"ImproperImageHeader");
        viff_colormap=(unsigned char *) AcquireQuantumMemory(image->colors,
          viff_info.map_rows*bytes_per_pixel*sizeof(*viff_colormap));
        if (viff_colormap == (unsigned char *) NULL)
          ThrowReaderException(ResourceLimitError,"MemoryAllocationFailed");
        /*
          Read VIFF raster colormap.
        */
        (void) ReadBlob(image,bytes_per_pixel*image->colors*viff_info.map_rows,
          viff_colormap);
        lsb_first=1;
        if (*(char *) &lsb_first &&
            ((viff_info.machine_dependency != VFF_DEP_DECORDER) &&
             (viff_info.machine_dependency != VFF_DEP_NSORDER)))
          switch ((int) viff_info.map_storage_type)
          {
            case VFF_MAPTYP_2_BYTE:
            {
              MSBOrderShort(viff_colormap,(bytes_per_pixel*image->colors*
                viff_info.map_rows));
              break;
            }
            case VFF_MAPTYP_4_BYTE:
            case VFF_MAPTYP_FLOAT:
            {
              MSBOrderLong(viff_colormap,(bytes_per_pixel*image->colors*
                viff_info.map_rows));
              break;
            }
            default: break;
          }
        for (i=0; i < (ssize_t) (viff_info.map_rows*image->colors); i++)
        {
          switch ((int) viff_info.map_storage_type)
          {
            case VFF_MAPTYP_2_BYTE: value=1.0*((short *) viff_colormap)[i]; break;
            case VFF_MAPTYP_4_BYTE: value=1.0*((int *) viff_colormap)[i]; break;
            case VFF_MAPTYP_FLOAT: value=((float *) viff_colormap)[i]; break;
            case VFF_MAPTYP_DOUBLE: value=((double *) viff_colormap)[i]; break;
            default: value=1.0*viff_colormap[i]; break;
          }
          if (i < (ssize_t) image->colors)
            {
              image->colormap[i].red=ScaleCharToQuantum((unsigned char) value);
              image->colormap[i].green=ScaleCharToQuantum((unsigned char)
                value);
              image->colormap[i].blue=ScaleCharToQuantum((unsigned char) value);
            }
          else
            if (i < (ssize_t) (2*image->colors))
              image->colormap[i % image->colors].green=ScaleCharToQuantum(
                (unsigned char) value);
            else
              if (i < (ssize_t) (3*image->colors))
                image->colormap[i % image->colors].blue=ScaleCharToQuantum(
                  (unsigned char) value);
        }
        viff_colormap=(unsigned char *) RelinquishMagickMemory(viff_colormap);
        break;
      }
      default:
        ThrowReaderException(CoderError,"ColormapTypeNotSupported");
    }
    if ((image_info->ping != MagickFalse) && (image_info->number_scenes != 0))
      if (image->scene >= (image_info->scene+image_info->number_scenes-1))
        break;
    if (viff_info.data_storage_type == VFF_TYP_BIT)
      {
        /*
          Create bi-level colormap.
        */
        image->colors=2;
        if (AcquireImageColormap(image,image->colors) == MagickFalse)
          ThrowReaderException(ResourceLimitError,"MemoryAllocationFailed");
        image->colorspace=GRAYColorspace;
      }
    /*
      Allocate VIFF pixels.
    */
    switch ((int) viff_info.data_storage_type)
    {
      case VFF_TYP_2_BYTE: bytes_per_pixel=2; break;
      case VFF_TYP_4_BYTE: bytes_per_pixel=4; break;
      case VFF_TYP_FLOAT: bytes_per_pixel=4; break;
      case VFF_TYP_DOUBLE: bytes_per_pixel=8; break;
      default: bytes_per_pixel=1; break;
    }
    if (viff_info.data_storage_type == VFF_TYP_BIT)
      {
        if (HeapOverflowSanityCheck((image->columns+7UL) >> 3UL,image->rows) != MagickFalse)
          ThrowReaderException(ResourceLimitError,"MemoryAllocationFailed");
        max_packets=((image->columns+7UL) >> 3UL)*image->rows;
      }
    else
      {
        if (HeapOverflowSanityCheck((size_t) number_pixels,viff_info.number_data_bands) != MagickFalse)
          ThrowReaderException(ResourceLimitError,"MemoryAllocationFailed");
        max_packets=(size_t) (number_pixels*viff_info.number_data_bands);
      }
    if ((MagickSizeType) (bytes_per_pixel*max_packets) > GetBlobSize(image))
      ThrowReaderException(CorruptImageError,"ImproperImageHeader");
    pixels=(unsigned char *) AcquireQuantumMemory((size_t) MagickMax(
      number_pixels,max_packets),bytes_per_pixel*sizeof(*pixels));
    if (pixels == (unsigned char *) NULL)
      ThrowReaderException(ResourceLimitError,"MemoryAllocationFailed");
    (void) memset(pixels,0,MagickMax(number_pixels,max_packets)*
      bytes_per_pixel*sizeof(*pixels));
    (void) ReadBlob(image,bytes_per_pixel*max_packets,pixels);
    lsb_first=1;
    if (*(char *) &lsb_first &&
        ((viff_info.machine_dependency != VFF_DEP_DECORDER) &&
         (viff_info.machine_dependency != VFF_DEP_NSORDER)))
      switch ((int) viff_info.data_storage_type)
      {
        case VFF_TYP_2_BYTE:
        {
          MSBOrderShort(pixels,bytes_per_pixel*max_packets);
          break;
        }
        case VFF_TYP_4_BYTE:
        case VFF_TYP_FLOAT:
        {
          MSBOrderLong(pixels,bytes_per_pixel*max_packets);
          break;
        }
        default: break;
      }
    min_value=0.0;
    scale_factor=1.0;
    if ((viff_info.data_storage_type != VFF_TYP_1_BYTE) &&
        (viff_info.map_scheme == VFF_MS_NONE))
      {
        double
          max_value;

        /*
          Determine scale factor.
        */
        switch ((int) viff_info.data_storage_type)
        {
          case VFF_TYP_2_BYTE: value=1.0*((short *) pixels)[0]; break;
          case VFF_TYP_4_BYTE: value=1.0*((int *) pixels)[0]; break;
          case VFF_TYP_FLOAT: value=((float *) pixels)[0]; break;
          case VFF_TYP_DOUBLE: value=((double *) pixels)[0]; break;
          default: value=1.0*pixels[0]; break;
        }
        max_value=value;
        min_value=value;
        for (i=0; i < (ssize_t) max_packets; i++)
        {
          switch ((int) viff_info.data_storage_type)
          {
            case VFF_TYP_2_BYTE: value=1.0*((short *) pixels)[i]; break;
            case VFF_TYP_4_BYTE: value=1.0*((int *) pixels)[i]; break;
            case VFF_TYP_FLOAT: value=((float *) pixels)[i]; break;
            case VFF_TYP_DOUBLE: value=((double *) pixels)[i]; break;
            default: value=1.0*pixels[i]; break;
          }
          if (value > max_value)
            max_value=value;
          else
            if (value < min_value)
              min_value=value;
        }
        if ((min_value == 0) && (max_value == 0))
          scale_factor=0;
        else
          if (min_value == max_value)
            {
              scale_factor=(MagickRealType) QuantumRange/min_value;
              min_value=0;
            }
          else
            scale_factor=(MagickRealType) QuantumRange/(max_value-min_value);
      }
    /*
      Convert pixels to Quantum size.
    */
    p=(unsigned char *) pixels;
    for (i=0; i < (ssize_t) max_packets; i++)
    {
      switch ((int) viff_info.data_storage_type)
      {
        case VFF_TYP_2_BYTE: value=1.0*((short *) pixels)[i]; break;
        case VFF_TYP_4_BYTE: value=1.0*((int *) pixels)[i]; break;
        case VFF_TYP_FLOAT: value=((float *) pixels)[i]; break;
        case VFF_TYP_DOUBLE: value=((double *) pixels)[i]; break;
        default: value=1.0*pixels[i]; break;
      }
      if (viff_info.map_scheme == VFF_MS_NONE)
        {
          value=(value-min_value)*scale_factor;
          if (value > QuantumRange)
            value=QuantumRange;
          else
            if (value < 0)
              value=0;
        }
      *p=(unsigned char) ((Quantum) value);
      p++;
    }
    /*
      Convert VIFF raster image to pixel packets.
    */
    p=(unsigned char *) pixels;
    if (viff_info.data_storage_type == VFF_TYP_BIT)
      {
        /*
          Convert bitmap scanline.
        */
        if (image->storage_class != PseudoClass)
          ThrowReaderException(CorruptImageError,"ImproperImageHeader");
        for (y=0; y < (ssize_t) image->rows; y++)
        {
          q=QueueAuthenticPixels(image,0,y,image->columns,1,exception);
          if (q == (PixelPacket *) NULL)
            break;
          indexes=GetAuthenticIndexQueue(image);
          for (x=0; x < (ssize_t) (image->columns-7); x+=8)
          {
            for (bit=0; bit < 8; bit++)
            {
              quantum=(size_t) ((*p) & (0x01 << bit) ? 0 : 1);
              SetPixelRed(q,quantum == 0 ? 0 : QuantumRange);
              SetPixelGreen(q,quantum == 0 ? 0 : QuantumRange);
              SetPixelBlue(q,quantum == 0 ? 0 : QuantumRange);
              if (image->storage_class == PseudoClass)
                SetPixelIndex(indexes+x+bit,quantum);
             }
            p++;
          }
          if ((image->columns % 8) != 0)
            {
              for (bit=0; bit < (int) (image->columns % 8); bit++)
              {
                quantum=(size_t) ((*p) & (0x01 << bit) ? 0 : 1);
                SetPixelRed(q,quantum == 0 ? 0 : QuantumRange);
                SetPixelGreen(q,quantum == 0 ? 0 : QuantumRange);
                SetPixelBlue(q,quantum == 0 ? 0 : QuantumRange);
                if (image->storage_class == PseudoClass)
                  SetPixelIndex(indexes+x+bit,quantum);
              }
              p++;
            }
          if (SyncAuthenticPixels(image,exception) == MagickFalse)
            break;
          if (image->previous == (Image *) NULL)
            {
              status=SetImageProgress(image,LoadImageTag,(MagickOffsetType) y,
                image->rows);
              if (status == MagickFalse)
                break;
            }
        }
      }
    else
      if (image->storage_class == PseudoClass)
        for (y=0; y < (ssize_t) image->rows; y++)
        {
          q=QueueAuthenticPixels(image,0,y,image->columns,1,exception);
          if (q == (PixelPacket *) NULL)
            break;
          indexes=GetAuthenticIndexQueue(image);
          for (x=0; x < (ssize_t) image->columns; x++)
            SetPixelIndex(indexes+x,*p++);
          if (SyncAuthenticPixels(image,exception) == MagickFalse)
            break;
          if (image->previous == (Image *) NULL)
            {
              status=SetImageProgress(image,LoadImageTag,(MagickOffsetType) y,
                image->rows);
              if (status == MagickFalse)
                break;
            }
        }
      else
        {
          /*
            Convert DirectColor scanline.
          */
          number_pixels=(MagickSizeType) image->columns*image->rows;
          for (y=0; y < (ssize_t) image->rows; y++)
          {
            q=QueueAuthenticPixels(image,0,y,image->columns,1,exception);
            if (q == (PixelPacket *) NULL)
              break;
            for (x=0; x < (ssize_t) image->columns; x++)
            {
              SetPixelRed(q,ScaleCharToQuantum(*p));
              SetPixelGreen(q,ScaleCharToQuantum(*(p+number_pixels)));
              SetPixelBlue(q,ScaleCharToQuantum(*(p+2*number_pixels)));
              if (image->colors != 0)
                {
                  ssize_t
                    index;

                  index=(ssize_t) GetPixelRed(q);
                  SetPixelRed(q,image->colormap[(ssize_t)
                    ConstrainColormapIndex(image,(ssize_t) index)].red);
                  index=(ssize_t) GetPixelGreen(q);
                  SetPixelGreen(q,image->colormap[(ssize_t)
                    ConstrainColormapIndex(image,(ssize_t) index)].green);
                  index=(ssize_t) GetPixelRed(q);
                  SetPixelBlue(q,image->colormap[(ssize_t)
                    ConstrainColormapIndex(image,(ssize_t) index)].blue);
                }
              SetPixelOpacity(q,image->matte != MagickFalse ? QuantumRange-
                ScaleCharToQuantum(*(p+number_pixels*3)) : OpaqueOpacity);
              p++;
              q++;
            }
            if (SyncAuthenticPixels(image,exception) == MagickFalse)
              break;
            if (image->previous == (Image *) NULL)
              {
                status=SetImageProgress(image,LoadImageTag,(MagickOffsetType) y,
                image->rows);
                if (status == MagickFalse)
                  break;
              }
          }
        }
    pixels=(unsigned char *) RelinquishMagickMemory(pixels);
    if (image->storage_class == PseudoClass)
      (void) SyncImage(image);
    if (EOFBlob(image) != MagickFalse)
      {
        ThrowFileException(exception,CorruptImageError,"UnexpectedEndOfFile",
          image->filename);
        break;
      }
    /*
      Proceed to next image.
    */
    if (image_info->number_scenes != 0)
      if (image->scene >= (image_info->scene+image_info->number_scenes-1))
        break;
    count=ReadBlob(image,1,&viff_info.identifier);
    if ((count == 1) && (viff_info.identifier == 0xab))
      {
        /*
          Allocate next image structure.
        */
        AcquireNextImage(image_info,image);
        if (GetNextImageInList(image) == (Image *) NULL)
          {
            status=MagickFalse;
            break;
          }
        image=SyncNextImageInList(image);
        status=SetImageProgress(image,LoadImagesTag,TellBlob(image),
          GetBlobSize(image));
        if (status == MagickFalse)
          break;
      }
  } while ((count != 0) && (viff_info.identifier == 0xab));
  (void) CloseBlob(image);
  if (status == MagickFalse)
    return(DestroyImageList(image));
  return(GetFirstImageInList(image));
}