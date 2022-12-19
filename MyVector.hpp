#include <assert.h>
#include <iostream>
#include <string>

template <typename T>
class MyVector
{
public:
    /***********
     * Constants
     * **********/

    // Default capacity
    static constexpr size_t DEFAULT_CAPACITY = 64;
    // Minimum capacity
    static constexpr size_t MINIMUM_CAPACITY = 8;

    /***************************
     * Constructors/Destructors
     ****************************/

    // Default Constructor. Will be set to default capacity if one is not given. Allocating memory for array of elements.
    MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY)
        : size_(),
          capacity_(capacity),
          elements_(new T[capacity]())
    {
    }
    // Copy Constructor
    MyVector(const MyVector &other)
        : size_(other.size_),
          capacity_(other.capacity_),
          elements_(new T[other.capacity]())
    {
        for (int i = 0; i < other.size_; i++)
        {
            elements_[i] = other[i];
        }
    }
    // Destructor
    ~MyVector()
    {
        delete[] elements_;
    }
    /**************
     * Operators
     * ************/

    /**************
     * Accessors
     **************/

    // Access the size of vector
    size_t size() const
    {
        return this->size_;
    }

    // Access the capacity of vector
    size_t capacity() const
    {
        return this->capacity_;
    }

    // Check if vector is empty
    bool empty() const
    {
        if (this->size_ == 0)
            return true;
    }

    // Get a value at given index
    T &at(size_t index) const
    {
        if (index > this.size_)
            throw std::range_error("Gave index out of range.");
        T &value = this.elements_[index];
        return value;
    }

    // Reserve capacity
    void reserve(size_t capacity)
    {
        if (capacity_ < capacity)
    }

    // Change specific index in array
    T &set(size_t index, const T &element)
    {
    }

    //
    T &push_back(const T &element)
    {
    }

    //
    size_t pop_back()
    {
    }

    //
    T &insert(size_t index, const T &element)
    {
    }

    //
    size_t erase(size_t index)
    {
    }

    //
    void clear()
    {
    }

private:
    // To keep track of how many elements are in vector
    size_t size_ = 0;
    // To keep track of capacity of vector
    size_t capacity_ = 0;
    // Our internal array of element of type T. Starts off as nullptr
    T *elements_ = nullptr;

    // Helper function for changing capacity
    void changeCapacity(size_t c)
    {
    }

    // Helper function for copying array
    void copyOther(const MyVector &other)
    {
    }
};