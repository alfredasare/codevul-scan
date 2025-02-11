MojoJpegDecodeAccelerator::MojoJpegDecodeAccelerator(
scoped\_refptr<base::SingleThreadTaskRunner> io\_task\_runner,
mojom::JpegDecodeAcceleratorPtr info)
: io\_task\_runner\_(std::move(io\_task\_runner)) {
if (info && info->is\_valid()) {
jpeg\_decoder\_ = std::move(info);
} else {
// Handle error scenario, e.g., logging or throwing an exception.
}
}