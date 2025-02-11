refptr<gl::GLSurface>(gl::init::CreateOffscreenGLSurface(size));
gl::GLContextAttribs attrs;
attrs.version = 3;
attrs.major\_version = 3;
attrs.minor\_version = 0;
attrs.alpha\_size = 8;
attrs.depth\_size = 24;
attrs.stencil\_size = 8;
attrs.antialiasing\_level = 0;
attrs.accum\_red\_size = 0;
attrs.accum\_green\_size = 0;
attrs.accum\_blue\_size = 0;
attrs.accum\_alpha\_size = 0;
attrs.buffer\_size = 0;
attrs.double\_buffer = true;
attrs.depth\_stencil = true;
attrs.aux\_buffers = 0;
attrs.samples = 0;
attrs.sample\_buffers = 0;
attrs.deferred\_deletion = false;
attrs.robustness = gl::GLContextAttribs::ROBUSTNESS\_NO\_RESET\_NOTIFICATION;
attrs.lose\_context\_on\_memory\_pressure = false;

base\_context\_ = new scoped\_refptr<gl::GLContext>(gl::init::CreateGLContext(
base\_share\_group_->get(), base\_surface_->get(), attrs));
g\_gpu\_feature\_info.ApplyToGLContext(base\_context_->get());
#endif
  }
  ++use\_count_;
}