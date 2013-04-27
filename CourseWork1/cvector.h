#ifndef CVECTOR_H
#define CVECTOR_H


template <class T>
class cVector
{
    private:
        int size_; // size of array
        T *values_;
    public:
        cVector()
        {
            size_=0;
            values_ = 0;
        }
        cVector(int size) // Zero-based array
        {
            size_ = size;
            values_ = new T[size];
        }
        cVector(int size, const T &value) //initialize to constant value
        {
            size_ = size;
            values_ = new T[size];

            for(int i=0;i<size;i++)
            {
                values_[i] = value;
            }
        }

        cVector(int size, const T *a) // Initialize to array
        {
            size_ = size;
            values_ = new T[size];
            for(int i=0;i<size;i++)
            {
                values_[i] = a[i];
            }
        }
        cVector(const cVector &rhs) // Copy constructor
        {
            size_ = rhs.size();
            values_ = new T[size_];
            for(int i=0;i<size_;i++)
            {
                values_[i] = rhs[i];
            }
        }

        cVector & operator=(const cVector &rhs) //assignment
        {            

            return new cVector(rhs);
        }

        inline T & operator[](const int index) //i'th element
        {
            if(index<size_)
                return values_[index];
        }
        inline const T & operator[](const int index) const
        {
            if(index<size_)
                return values_[index];
        }
        inline int size() const
        {
            return size_;
        }
        void resize(int newSize) // resize (contents not preserved)
        {
            T* oldValues = new T[size_];
            for(int i=0;i<size_;i++)
                oldValues[i] = values_[i];
            size_ = newSize;
            delete[] values_;
            values_ = new T[size_];
            for(int i=0;i<size_;i++)
                values_[i] = oldValues[i];
        }

        void assign(int newSize, const T &value) // resize and assign constant value
        {
            delete[] values_;
            size_ = newSize;
            values_ = new T[size_];
            for(int i=0;i<size_;i++)
                values_[i] = *(value);
        }

        ~cVector()
        {
            delete [] values_;
        }
};
#endif // CVECTOR_H
