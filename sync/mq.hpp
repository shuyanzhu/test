#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

template <typename T> class MessageQueue: private std::queue<T> {
public:
    template <typename... Args> bool enqueue(Args &&...value);
    bool dequeue(T &data);

private:
    std::mutex mutex_;
    std::condition_variable condition_;
};

template <typename T> template <typename... Args> inline bool MessageQueue<T>::enqueue(Args &&...value) {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        this->emplace(std::forward(value)...);
    }
    condition_.notify_all();
    return true;
}

template <typename T> inline bool MessageQueue<T>::dequeue(T &data) {
    std::unique_lock<std::mutex> lock(mutex_);
    condition_.wait(lock, [this] { return !this->empty(); });
    data = this->front();
    this->pop();
    return true;
}