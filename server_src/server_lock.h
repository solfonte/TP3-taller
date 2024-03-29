#ifndef __LOCK_H__
#define __LOCK_H__

#include <mutex>

class Lock{
  private:
    std::mutex& m;
  public:
    explicit Lock(std::mutex& m);
    ~Lock();
};

#endif
