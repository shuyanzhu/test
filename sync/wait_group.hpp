#include <condition_variable>
#include <mutex>
#include <thread>

class WaitGroup {
public:
    WaitGroup() = default;
    WaitGroup(const WaitGroup &) = delete;
    WaitGroup &operator=(const WaitGroup &) = delete;
    void add(int i) {
        std::unique_lock<std::mutex> lock(mutex_);
        cnt_ += i;
        if (cnt_ == 0) {
            condition_.notify_all();
        }
    }
    void done() { add(-1); };
    void wait() {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return cnt_ == 0; });
    }

private:
    std::mutex mutex_;
    std::condition_variable condition_;
    int cnt_{ 0 };
};