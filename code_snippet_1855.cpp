#include <pthread.h>
#include <pwd.h>

change_identity(const struct passwd *pw) {
  pthread_mutex_t identity_mutex = PTHREAD_MUTEX_INITIALIZER;

  pthread_mutex_lock(&identity_mutex);
  if (setgid(pw->pw_gid))
    err(EXIT_FAILURE, _("cannot set group id"));
  if (setuid(pw->pw_uid))
    err(EXIT_FAILURE, _("cannot set user id"));
  pthread_mutex_unlock(&identity_mutex);
}