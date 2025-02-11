class ImageBitmapLoader : public base::RefCounted<ImageBitmapLoader> {
 public:
  explicit ImageBitmapLoader(scoped_refptr<base::SingleThreadTaskRunner> task_runner);

  // ...

 private:
  friend class base::RefCounted<ImageBitmapLoader>;
  base::WeakPtrFactory<ImageBitmapLoader> weak_ptr_factory_;
  // ...
};

void ImageBitmapFactories::ImageBitmapLoader::ScheduleAsyncImageBitmapDecoding(
    DOMArrayBuffer* array_buffer) {
  auto task_runner = Thread::Current()->GetTaskRunner();
  weak_ptr_factory_.Init(this);
  background_scheduler::PostOnBackgroundThread(
      FROM_HERE,
      CrossThreadBind(
          &ImageBitmapFactories::ImageBitmapLoader::DecodeImageOnDecoderThread,
          weak_ptr_factory_.GetWeakPtr(), std::move(task_runner),
          WrapCrossThreadPersistent(array_buffer), options_->premultiplyAlpha(),
          options_->colorSpaceConversion()));
}