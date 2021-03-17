#pragma once

#include <mutex>

using namespace std;
class BaseObj
{
protected:
    mutex myMutex;
public:
    
    void lock()
    {
        myMutex.lock();
    };

    bool tryLock()
    {
        return myMutex.try_lock();
    };

    void unLock()
    {
        myMutex.unlock();
    };
};
