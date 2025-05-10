#include <iostream>
#include <utility>
#include <vector>
#include <cstdint>


// Perfect forwarding means: 
//-Forward the exact value CATEGORY (lvalue or rvalue) and the TYPE of the argument to some other function.

class FrameBuffer {

public:
    // Default constructor
    FrameBuffer() : width_(0), height_(0) {}

    // Constructor with diemensions
    FrameBuffer(int w, int h) 
        : width_(w), 
          height_(h), 
          data_(w * h * 3) {
            std::cout << "Constructed from dimensions\n";
          }

    // Perfect forwarding constructor
    template<typename Container, typename... Args>
    FrameBuffer(Container&& data, int w, int h, Args&&... args)
        : data_(std::forward<Container>(data)),
          width_(w),
          height_(h) {
            std::cout << "Constructed from container with perfect forwarding\n";
          }

    // Move constructor 
    FrameBuffer(FrameBuffer&& other) noexcept
        : data_(std::move(other.data_)), 
          width_(other.width_), 
          height_(other.height_){
            std::cout << "Move constructed\n"; 
            other.width_ = 0; 
            other.height_ = 0; 
          }
    // Delete the copy constructor (to force the move awareness)
    FrameBuffer(const FrameBuffer&) = delete; 
    
    // Move assignment 
    FrameBuffer& operator=(FrameBuffer&& other) noexcept
    {
      std::cout << "Move assigment\n"; 
      if (this !=&other) {
        data_ = std::move(other.data_); 
        width_ = other.width_; 
        height_ = other.height_; 
        other.width_ = 0; 
        other.height_ = 0;  
      }

      return *this; 
    }

    void info() {
      std::cout << "This container's height: " << height_ << std::endl; 
      std::cout << "This container's width: " << width_ << std::endl; 
      std::cout << "This container's size: " << data_.size() << std::endl;  
    }

private:
    int width_; 
    int height_;
    std::vector<uint8_t> data_;

};


int main() {
    std::cout << "Check Check" << std::endl; 

    return 0; 
}