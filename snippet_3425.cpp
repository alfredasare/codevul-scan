static double FxEvaluateSubexpression(FxInfo *fx_info,
  const PixelChannel channel,const ssize_t x,const ssize_t y,
  const char *expression,size_t *depth,double *beta,ExceptionInfo *exception)
{
#define FxMaxParenthesisDepth  58

  char
    *q,
    subexpression[MagickPathExtent];

  double
    alpha,
    gamma;

  register const char
    *p;

  *beta=0.0;
  if (exception->severity >= ErrorException)
    return(0.0);
  while (isspace((int) ((unsigned char) *expression)) != 0)
    expression++;
  if (*expression == '\0')
    return(0.0);
  *subexpression='\0';
  p=FxOperatorPrecedence(expression,exception);
  if (p != (const char *) NULL)
    {
      (void) CopyMagickString(subexpression,expression,(size_t)
        (p-expression+1));
      alpha=FxEvaluateSubexpression(fx_info,channel,x,y,subexpression,depth,
        beta,exception);
      switch ((unsigned char) *p)
      {
        case '~':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          *beta=(double) (~(size_t) *beta);
          return(*beta);
        }
        case '!':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(*beta == 0.0 ? 1.0 : 0.0);
        }
        case '^':
        {
          *beta=pow(alpha,FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,
            beta,exception));
          return(*beta);
        }
        case '*':
        case ExponentialNotation:
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(alpha*(*beta));
        }
        case '/':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          if (*beta == 0.0)
            {
              (void) ThrowMagickException(exception,GetMagickModule(),
                OptionError,"DivideByZero","`%s'",expression);
              return(0.0);
            }
          return(alpha/(*beta));
        }
        case '%':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          *beta=fabs(floor((*beta)+0.5));
          if (*beta == 0.0)
            {
              (void) ThrowMagickException(exception,GetMagickModule(),
                OptionError,"DivideByZero","`%s'",expression);
              return(0.0);
            }
          return(fmod(alpha,*beta));
        }
        case '+':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(alpha+(*beta));
        }
        case '-':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(alpha-(*beta));
        }
        case LeftShiftOperator:
        {
          gamma=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          *beta=(double) ((size_t) (alpha+0.5) << (size_t) (gamma+0.5));
          return(*beta);
        }
        case RightShiftOperator:
        {
          gamma=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          *beta=(double) ((size_t) (alpha+0.5) >> (size_t) (gamma+0.5));
          return(*beta);
        }
        case '<':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(alpha < *beta ? 1.0 : 0.0);
        }
        case LessThanEqualOperator:
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(alpha <= *beta ? 1.0 : 0.0);
        }
        case '>':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(alpha > *beta ? 1.0 : 0.0);
        }
        case GreaterThanEqualOperator:
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(alpha >= *beta ? 1.0 : 0.0);
        }
        case EqualOperator:
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(fabs(alpha-(*beta)) < MagickEpsilon ? 1.0 : 0.0);
        }
        case NotEqualOperator:
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(fabs(alpha-(*beta)) >= MagickEpsilon ? 1.0 : 0.0);
        }
        case '&':
        {
          gamma=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          *beta=(double) ((size_t) (alpha+0.5) & (size_t) (gamma+0.5));
          return(*beta);
        }
        case '|':
        {
          gamma=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          *beta=(double) ((size_t) (alpha+0.5) | (size_t) (gamma+0.5));
          return(*beta);
        }
        case LogicalAndOperator:
        {
          p++;
          if (alpha <= 0.0)
            {
              *beta=0.0;
              return(*beta);
            }
          gamma=FxEvaluateSubexpression(fx_info,channel,x,y,p,depth,beta,
            exception);
          *beta=(gamma > 0.0) ? 1.0 : 0.0;
          return(*beta);
        }
        case LogicalOrOperator:
        {
          p++;
          if (alpha > 0.0)
            {
             *beta=1.0;
             return(*beta);
            }
          gamma=FxEvaluateSubexpression(fx_info,channel,x,y,p,depth,beta,
            exception);
          *beta=(gamma > 0.0) ? 1.0 : 0.0;
          return(*beta);
        }
        case '?':
        {
          (void) CopyMagickString(subexpression,++p,MagickPathExtent);
          q=subexpression;
          p=StringToken(":",&q);
          if (q == (char *) NULL)
            {
              (void) ThrowMagickException(exception,GetMagickModule(),
                OptionError,"UnableToParseExpression","`%s'",subexpression);
              return(0.0);
            }
          if (fabs(alpha) >= MagickEpsilon)
            gamma=FxEvaluateSubexpression(fx_info,channel,x,y,p,depth,beta,
              exception);
          else
            gamma=FxEvaluateSubexpression(fx_info,channel,x,y,q,depth,beta,
              exception);
          return(gamma);
        }
        case '=':
        {
          char
            numeric[MagickPathExtent];

          q=subexpression;
          while (isalpha((int) ((unsigned char) *q)) != 0)
            q++;
          if (*q != '\0')
            {
              (void) ThrowMagickException(exception,GetMagickModule(),
                OptionError,"UnableToParseExpression","`%s'",subexpression);
              return(0.0);
            }
          ClearMagickException(exception);
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          (void) FormatLocaleString(numeric,MagickPathExtent,"%g",*beta);
          (void) DeleteNodeFromSplayTree(fx_info->symbols,subexpression);
          (void) AddValueToSplayTree(fx_info->symbols,ConstantString(
            subexpression),ConstantString(numeric));
          return(*beta);
        }
        case ',':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(alpha);
        }
        case ';':
        {
          *beta=FxEvaluateSubexpression(fx_info,channel,x,y,++p,depth,beta,
            exception);
          return(*beta);
        }
        default:
        {
          gamma=alpha*FxEvaluateSubexpression(fx_info,channel,x,y,p,depth,beta,
            exception);
          return(gamma);
        }
      }
    }
  if (strchr("(",(int) *expression) != (char *) NULL)
    {
      (*depth)++;
      if (*depth >= FxMaxParenthesisDepth)
        (void) ThrowMagickException(exception,GetMagickModule(),OptionError,
          "ParenthesisNestedTooDeeply","`%s'",expression);
      (void) CopyMagickString(subexpression,expression+1,MagickPathExtent);
      subexpression[strlen(subexpression)-1]='\0';
      gamma=FxEvaluateSubexpression(fx_info,channel,x,y,subexpression,depth,
        beta,exception);
      (*depth)--;
      return(gamma);
    }
  switch (*expression)
  {
    case '+':
    {
      gamma=FxEvaluateSubexpression(fx_info,channel,x,y,expression+1,depth,beta,
        exception);
      return(1.0*gamma);
    }
    case '-':
    {
      gamma=FxEvaluateSubexpression(fx_info,channel,x,y,expression+1,depth,beta,
        exception);
      return(-1.0*gamma);
    }
    case '~':
    {
      gamma=FxEvaluateSubexpression(fx_info,channel,x,y,expression+1,depth,beta,
        exception);
      return((~(size_t) (gamma+0.5)));
    }
    case 'A':
    case 'a':
    {
      if (LocaleNCompare(expression,"abs",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(fabs(alpha));
        }
#if defined(MAGICKCORE_HAVE_ACOSH)
      if (LocaleNCompare(expression,"acosh",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          return(acosh(alpha));
        }
#endif
      if (LocaleNCompare(expression,"acos",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(acos(alpha));
        }
#if defined(MAGICKCORE_HAVE_J1)
      if (LocaleNCompare(expression,"airy",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          if (alpha == 0.0)
            return(1.0);
          gamma=2.0*j1((MagickPI*alpha))/(MagickPI*alpha);
          return(gamma*gamma);
        }
#endif
#if defined(MAGICKCORE_HAVE_ASINH)
      if (LocaleNCompare(expression,"asinh",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          return(asinh(alpha));
        }
#endif
      if (LocaleNCompare(expression,"asin",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(asin(alpha));
        }
      if (LocaleNCompare(expression,"alt",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(((ssize_t) alpha) & 0x01 ? -1.0 : 1.0);
        }
      if (LocaleNCompare(expression,"atan2",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          return(atan2(alpha,*beta));
        }
#if defined(MAGICKCORE_HAVE_ATANH)
      if (LocaleNCompare(expression,"atanh",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          return(atanh(alpha));
        }
#endif
      if (LocaleNCompare(expression,"atan",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(atan(alpha));
        }
      if (LocaleCompare(expression,"a") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'B':
    case 'b':
    {
      if (LocaleCompare(expression,"b") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'C':
    case 'c':
    {
      if (LocaleNCompare(expression,"ceil",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(ceil(alpha));
        }
      if (LocaleNCompare(expression,"clamp",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          if (alpha < 0.0)
            return(0.0);
          if (alpha > 1.0)
            return(1.0);
          return(alpha);
        }
      if (LocaleNCompare(expression,"cosh",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(cosh(alpha));
        }
      if (LocaleNCompare(expression,"cos",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(cos(alpha));
        }
      if (LocaleCompare(expression,"c") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'D':
    case 'd':
    {
      if (LocaleNCompare(expression,"debug",5) == 0)
        {
          const char
            *type;

          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          if (fx_info->images->colorspace == CMYKColorspace)
            switch (channel)
            {
              case CyanPixelChannel: type="cyan"; break;
              case MagentaPixelChannel: type="magenta"; break;
              case YellowPixelChannel: type="yellow"; break;
              case AlphaPixelChannel: type="opacity"; break;
              case BlackPixelChannel: type="black"; break;
              default: type="unknown"; break;
            }
          else
            switch (channel)
            {
              case RedPixelChannel: type="red"; break;
              case GreenPixelChannel: type="green"; break;
              case BluePixelChannel: type="blue"; break;
              case AlphaPixelChannel: type="opacity"; break;
              default: type="unknown"; break;
            }
          (void) CopyMagickString(subexpression,expression+6,MagickPathExtent);
          if (strlen(subexpression) > 1)
            subexpression[strlen(subexpression)-1]='\0';
          if (fx_info->file != (FILE *) NULL)
            (void) FormatLocaleFile(fx_info->file,"%s[%.20g,%.20g].%s: "
               "%s=%.*g\n",fx_info->images->filename,(double) x,(double) y,type,
               subexpression,GetMagickPrecision(),alpha);
          return(0.0);
        }
      if (LocaleNCompare(expression,"drc",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return((alpha/(*beta*(alpha-1.0)+1.0)));
        }
      break;
    }
    case 'E':
    case 'e':
    {
      if (LocaleCompare(expression,"epsilon") == 0)
        return(MagickEpsilon);
#if defined(MAGICKCORE_HAVE_ERF)
      if (LocaleNCompare(expression,"erf",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(erf(alpha));
        }
#endif
      if (LocaleNCompare(expression,"exp",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(exp(alpha));
        }
      if (LocaleCompare(expression,"e") == 0)
        return(2.7182818284590452354);
      break;
    }
    case 'F':
    case 'f':
    {
      if (LocaleNCompare(expression,"floor",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          return(floor(alpha));
        }
      break;
    }
    case 'G':
    case 'g':
    {
      if (LocaleNCompare(expression,"gauss",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          gamma=exp((-alpha*alpha/2.0))/sqrt(2.0*MagickPI);
          return(gamma);
        }
      if (LocaleNCompare(expression,"gcd",3) == 0)
        {
          MagickOffsetType
            gcd;

          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          gcd=FxGCD((MagickOffsetType) (alpha+0.5),(MagickOffsetType) (*beta+
            0.5));
          return(gcd);
        }
      if (LocaleCompare(expression,"g") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'H':
    case 'h':
    {
      if (LocaleCompare(expression,"h") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      if (LocaleCompare(expression,"hue") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      if (LocaleNCompare(expression,"hypot",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          return(hypot(alpha,*beta));
        }
      break;
    }
    case 'K':
    case 'k':
    {
      if (LocaleCompare(expression,"k") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'I':
    case 'i':
    {
      if (LocaleCompare(expression,"intensity") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      if (LocaleNCompare(expression,"int",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(floor(alpha));
        }
      if (LocaleNCompare(expression,"isnan",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          return(!!IsNaN(alpha));
        }
      if (LocaleCompare(expression,"i") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'J':
    case 'j':
    {
      if (LocaleCompare(expression,"j") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
#if defined(MAGICKCORE_HAVE_J0)
      if (LocaleNCompare(expression,"j0",2) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+2,depth,
            beta,exception);
          return(j0(alpha));
        }
#endif
#if defined(MAGICKCORE_HAVE_J1)
      if (LocaleNCompare(expression,"j1",2) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+2,depth,
            beta,exception);
          return(j1(alpha));
        }
#endif
#if defined(MAGICKCORE_HAVE_J1)
      if (LocaleNCompare(expression,"jinc",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          if (alpha == 0.0)
            return(1.0);
          gamma=(2.0*j1((MagickPI*alpha))/(MagickPI*alpha));
          return(gamma);
        }
#endif
      break;
    }
    case 'L':
    case 'l':
    {
      if (LocaleNCompare(expression,"ln",2) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+2,depth,
            beta,exception);
          return(log(alpha));
        }
      if (LocaleNCompare(expression,"logtwo",6) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+6,depth,
            beta,exception);
          return(log10(alpha))/log10(2.0);
        }
      if (LocaleNCompare(expression,"log",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(log10(alpha));
        }
      if (LocaleCompare(expression,"lightness") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'M':
    case 'm':
    {
      if (LocaleCompare(expression,"MaxRGB") == 0)
        return(QuantumRange);
      if (LocaleNCompare(expression,"maxima",6) == 0)
        break;
      if (LocaleNCompare(expression,"max",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(alpha > *beta ? alpha : *beta);
        }
      if (LocaleNCompare(expression,"minima",6) == 0)
        break;
      if (LocaleNCompare(expression,"min",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(alpha < *beta ? alpha : *beta);
        }
      if (LocaleNCompare(expression,"mod",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          gamma=alpha-floor((alpha/(*beta)))*(*beta);
          return(gamma);
        }
      if (LocaleCompare(expression,"m") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'N':
    case 'n':
    {
      if (LocaleNCompare(expression,"not",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return((alpha < MagickEpsilon));
        }
      if (LocaleCompare(expression,"n") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'O':
    case 'o':
    {
      if (LocaleCompare(expression,"Opaque") == 0)
        return(1.0);
      if (LocaleCompare(expression,"o") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'P':
    case 'p':
    {
      if (LocaleCompare(expression,"phi") == 0)
        return(MagickPHI);
      if (LocaleCompare(expression,"pi") == 0)
        return(MagickPI);
      if (LocaleNCompare(expression,"pow",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(pow(alpha,*beta));
        }
      if (LocaleCompare(expression,"p") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'Q':
    case 'q':
    {
      if (LocaleCompare(expression,"QuantumRange") == 0)
        return(QuantumRange);
      if (LocaleCompare(expression,"QuantumScale") == 0)
        return(QuantumScale);
      break;
    }
    case 'R':
    case 'r':
    {
      if (LocaleNCompare(expression,"rand",4) == 0)
        {
#if defined(MAGICKCORE_OPENMP_SUPPORT)
        #pragma omp critical (MagickCore_FxEvaluateSubexpression)
#endif
          alpha=GetPseudoRandomValue(fx_info->random_info);
          return(alpha);
        }
      if (LocaleNCompare(expression,"round",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          return(floor(alpha+0.5));
        }
      if (LocaleCompare(expression,"r") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'S':
    case 's':
    {
      if (LocaleCompare(expression,"saturation") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      if (LocaleNCompare(expression,"sign",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(alpha < 0.0 ? -1.0 : 1.0);
        }
      if (LocaleNCompare(expression,"sinc",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          if (alpha == 0)
            return(1.0);
          gamma=sin((MagickPI*alpha))/(MagickPI*alpha);
          return(gamma);
        }
      if (LocaleNCompare(expression,"sinh",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(sinh(alpha));
        }
      if (LocaleNCompare(expression,"sin",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(sin(alpha));
        }
      if (LocaleNCompare(expression,"sqrt",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(sqrt(alpha));
        }
      if (LocaleNCompare(expression,"squish",6) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+6,depth,
            beta,exception);
          return((1.0/(1.0+exp(-alpha))));
        }
      if (LocaleCompare(expression,"s") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'T':
    case 't':
    {
      if (LocaleNCompare(expression,"tanh",4) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+4,depth,
            beta,exception);
          return(tanh(alpha));
        }
      if (LocaleNCompare(expression,"tan",3) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+3,depth,
            beta,exception);
          return(tan(alpha));
        }
      if (LocaleCompare(expression,"Transparent") == 0)
        return(0.0);
      if (LocaleNCompare(expression,"trunc",5) == 0)
        {
          alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,depth,
            beta,exception);
          if (alpha >= 0.0)
            return(floor(alpha));
          return(ceil(alpha));
        }
      if (LocaleCompare(expression,"t") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'U':
    case 'u':
    {
      if (LocaleCompare(expression,"u") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'V':
    case 'v':
    {
      if (LocaleCompare(expression,"v") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'W':
    case 'w':
    {
      if (LocaleNCompare(expression,"while",5) == 0)
        {
          do
          {
            alpha=FxEvaluateSubexpression(fx_info,channel,x,y,expression+5,
              depth,beta,exception);
          } while (fabs(alpha) >= MagickEpsilon);
          return(*beta);
        }
      if (LocaleCompare(expression,"w") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'Y':
    case 'y':
    {
      if (LocaleCompare(expression,"y") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    case 'Z':
    case 'z':
    {
      if (LocaleCompare(expression,"z") == 0)
        return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
      break;
    }
    default:
      break;
  }
  q=(char *) expression;
  alpha=InterpretSiPrefixValue(expression,&q);
  if (q == expression)
    return(FxGetSymbol(fx_info,channel,x,y,expression,exception));
  return(alpha);
}
