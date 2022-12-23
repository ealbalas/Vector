#include <assert.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

// Creating a vector class. This will be a dynamically allocated array.
// Will be using template to allow use of multiple types
template <typename T>
class MyVector
{
public:
    /***********
     * Constants
     * **********/

    // Default capacity. If no capacity is given this will be the default.
    static constexpr size_t DEFAULT_CAPACITY = 64;
    // Minimum capacity. This will be the minimum value for capacity
    static constexpr size_t MINIMUM_CAPACITY = 8;

    /***************************
     * Constructors/Destructors
     ****************************/

    // Default Constructor. Will be set to default capacity if one is not given. Allocating memory for array of elements.
    MyVector(size_t capacity = DEFAULT_CAPACITY)
        : size_(),
          capacity_(capacity),
          elements_(new T[capacity]())
    {}
    // Copy Constructor. This will be used to copy existing vector into new vectors. It will use the helper function to copy the values
    MyVector(const MyVector &other)
        : size_(other.size_),
          capacity_(other.capacity_),
          elements_(new T[other.capacity_]())
    {
        copyOther(other);
    }
    // Destructor. This will call the clear function and set the elements_ to nullptr if its not already set.
    ~MyVector()
    {
        clear();
        if (this->elements_ != nullptr) this->elements_ = nullptr;
    }
    /**************
     * Operators
     * ************/

    //	Assignment operator. This will overload the '=' operator to set lhs vector equal to rhs vector.
    MyVector &operator=(const MyVector &rhs)
    {
        if (this != &rhs)
        {
            reserve(rhs.capacity());
            copyOther(rhs);
            this->capacity_ = rhs.capacity();
            this->size_ = rhs.size();
            return *this;
        }
    }
    // Operator overload to at(). This will allow us to use brackets to find item in array at given index.
    T &operator[](size_t index) const
    {
        return at(index);
    }

    /**************
     * Accessors
     **************/

    // Access the size of vector. Since size_ is a private memeber we will have a function to access this value.
    size_t size() const
    {
        return this->size_;
    }

    // Access the capacity of vector. Since capacity_ is a private member we will have a function to access this value.
    size_t capacity() const
    {
        return this->capacity_;
    }

    // Check if vector is empty. Create a function to check if vector is empty. Help clean up code.
    bool empty() const
    {
        if (this->size_ == 0) return true;
        return false;
    }

    // Get a value at given index. Checks to make sure the index isnt out of range. if it isnt then we will pull item at this index.
    T &at(size_t index) const
    {
        if (index > this->size_)
            throw std::range_error("Gave index out of range.");
        T &value = this->elements_[index];
        return value;
    }

    // Reserve capacity. This function will help change the capacity after checking to make sure the current capacity doesnt have the necessary space.
    void reserve(size_t capacity)
    {
        if (this->capacity_ < capacity)
        {
            T *newElements_ = new T[capacity]();
            for (int i = 0; i < size(); i++)
            {
                newElements_[i] = this->elements_[i];
            }
            this->elements_ = newElements_;
            this->capacity_ = capacity;
            delete[] newElements_;
        }
    }

    // Shrink to fit capacity. This function can be used to shrink the current capacity so we dont save allocated memeory unnecessary 
    void shrink_to_fit()
    {
        if (!empty())
            if (this->size_ < this->capacity_)
                this->capacity_ = this->size_;
    }

    // Change specific index in array. This will allow us change a value at a given index. this will happen at constant time.
    T &set(size_t index, const T &element)
    {
        if (index >= capacity())
            throw std::range_error("You have selected an invalid index");
        this->elements_[index] = element;
        return this->at(index);
    }

    // First element of the array. Returns a reference to the value in the front of the array.
    T &front()
    {
        return at(0);
    }

    // Last element in the array. This returns a reference to the value in the end of the array
    T &end()
    {
        auto lastIndex = this->size_ - 1;
        return at(lastIndex);
    }

    // add an element to end of array. This function adds a value at the end of the array. Uses insert function.
    T &push_back(const T &element)
    {
        insert(this->size_, element);
        return this->elements_[this->size()];
    }

    // remove an element from the back. This function removes an element at the end of the array. Uses erase function.
    size_t pop_back()
    {
        erase(this->size_ - 1);
        return size();
    }

    // insert an element in a spot of the array. this will allow us to enter any element at any spot. This happens at O(n) since we will have to shift elements
    T &insert(size_t index, const T &element)
    {
        if (this->size_ >= this->capacity_)
            reserve(2 * this->capacity_);
        if (this->size_ < index)
            throw std::range_error("Invalid index");
        for (int i = this->size_; i != index; i--)
            elements_[i] = elements_[i - 1];
        elements_[index] = element;
        this->size_++;
        return elements_[index];
    }

    // erase an element at a given index. this will allow us to erase an element at any spot. this happens at O(n) since we will have to shift elements 
    size_t erase(size_t index)
    {
        if (this->size_ <= index)
            throw std::range_error("Invalid index");
        this->elements_[index].~T();
        for (int i = index; i < this->size_ - 1; i++)
        {
            elements_[i] = elements_[i + 1];
        }
        this->size_--;
        return size();
    }

    // swap function. swap the values of 2 elements with given index. This will allow us swap 2 values with given index. This happens at O(1) since we know the locations of both values that need to be swapped.
    void swap(size_t index1, size_t index2)
    {
        auto value1 = this->at(index1);
        auto value2 = this->at(index2);
        this->set(index1, value2);
        this->set(index2, value1);
    }

    // iterate through whole array and call destructor on each element
    void clear()
    {
        for (int i = 0; i < this->size_; i++)
            elements_[i].~T();
        this->size_ = 0;
        this->capacity_ = 0;
    }

private:
    // To keep track of how many elements are in vector
    size_t size_ = 0;
    // To keep track of capacity of vector
    size_t capacity_ = 0;
    // Our internal array of element of type T. Starts off as nullptr
    T *elements_ = nullptr;

    // Helper function for copying array
    void copyOther(const MyVector &other)
    {
        for (int i = 0; i < other.size_; i++)
        {
            this->elements_[i] = other[i];
        }
    }
};