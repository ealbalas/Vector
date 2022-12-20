#include <assert.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

// Creating a vector class. This will be a dynamically allocated array.

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
          elements_(new T[other.capacity_]())
    {
        copyOther(other);
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
			copyOther(rhs);
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
        if (this->size_ == 0) return true;
    }

    // Get a value at given index
    T &at(size_t index) const
    {
        if (index > this->size_) throw std::range_error("Gave index out of range.");
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
            delete[] newElements_;
        }
    }

    // Change specific index in array
    T &set(size_t index, const T &element)
    {
        if (index >= capacity()) throw std::range_error("You have selected an invalid index");
        this->elements_[index] = element;
        return this->at(index);
    }

    // First element of the array
    T &front()
    {
        return at(0);
    }

    // Last element in the array
    T &end()
    {
        auto lastIndex = this->size_ - 1;
        return at(lastIndex);
    }


    // add an element to end of array
    T &push_back(const T &element)
    {
        insert(this->size_, element);
        return this->elements_[this->size()];
    }

    // remove an element from the back
    size_t pop_back()
    {
        erase(this->size_ - 1);
        return size();
    }

    // insert an element in a spot of the array
    T &insert(size_t index, const T &element)
    {
        if (this->size_ >= this->capacity_) reserve(2 * this->capacity_);
        if (this->size_ < index) throw std::range_error("Invalid index");
        for (int i = this->size_; i != index; i--)
        {
            elements_[i] = elements_[i - 1];
        }
        elements_[index] = element;
        this->size_++;
        return elements_[index];
    }

    // erase an element at a given index
    size_t erase(size_t index)
    {
        if(this->size_ <= index) throw std::range_error("Invalid index");
        this->elements_[index].~T();
        for (int i = index; i < this->size_ - 1; i++)
        {
            elements_[i] = elements_[i + 1];
        }
        this->size_--;
        return size();
    }

    // swap function. swap the values of 2 elements with given index
    void swap(size_t index1, size_t index2)
    {
        auto value1 = this->at(index1);
        auto value2 = this->at(index2);
        this->set(index1, value2);
        this->set(index2, value1);
    }

    //
    void clear()
    {
        for (int i = 0; i < this->size_; i++)
        {
            elements_[i].~T();
        }
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

    // Helper function for changing capacity
    void changeCapacity(size_t c)
    {
    }

    // Helper function for copying array
    void copyOther(const MyVector &other)
    {
        for (int i = 0; i < other.size_; i++)
        {
            this->elements_[i] = other[i];
        }
    }
};