#include <assert.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

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
    MyVector(size_t capacity = DEFAULT_CAPACITY)
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

    //	Assignment operator
	MyVector& operator=(const MyVector& rhs) 
    {
		if (this != &rhs)
		{
			reserve(rhs.capacity());

			for (size_t i = 0; i < rhs.size(); i++)
            {
				elements_[i] = rhs[i];
			}
			this->capacity_ = rhs.capacity();
			this->size_ = rhs.size();
			return *this;
		}
    }
	// Operator overload to at()
	T& operator[](size_t index) const 
    {
		return at(index);			
	}

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
        if (index > this->size_)
            throw std::range_error("Gave index out of range.");
        T &value = this->elements_[index];
        return value;
    }

    // Reserve capacity
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
            delete[] *newElements_;
        }
    }

    // Change specific index in array
    T &set(size_t index, const T &element)
    {
        if (index >= capacity()) throw std::range_error("You have selected an invalid index");
        this->elements_[index] = element;
        return this->at(index);
    }

    // add an element to end of array
    T &push_back(const T &element)
    {

    }

    // remove an element from the back
    size_t pop_back()
    {
    }

    // insert an element in a spot of the array
    T &insert(size_t index, const T &element)
    {
        if (this->size_ >= this->capacity_) reserve(2 * this->capacity_);
        if (this->size_ == index) this->elements_[index] = element;
        if (this->size_ < index) throw std::range_error("Invalid index");
        for (int i = this->size_; i != index; i--)
        {
            elements_[i + 1] = elements_[i];
        }
        elements_[index] = element;
        this->size_++;
        auto addedValue = at(index);
        return addedValue;
    }

    // erase an element at a given index
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