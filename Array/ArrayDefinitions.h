// ----------------------------------------------------------------------------
// ArrayDefinitions.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ARRAY_DEFINITIONS_H
#define ARRAY_DEFINITIONS_H


template <typename T, unsigned int max_size_>
Array<T,max_size_>::Array()
{
  clear();
}

template <typename T, unsigned int max_size_>
Array<T,max_size_>::Array(const T &value)
{
  fill(value);
}

template <typename T, unsigned int max_size_>
Array<T, max_size_>::Array(const T (&values)[max_size_])
{
  fill(values);
}

template <typename T, unsigned int max_size_>
T& Array<T, max_size_>::operator[](const unsigned int i)
{
  return values_[i];
}

template <typename T, unsigned int max_size_>
T& Array<T, max_size_>::at(const unsigned int i)
{
  assert((i>=0) && (i<size_));
  return values_[i];
}

template <typename T, unsigned int max_size_>
T& Array<T, max_size_>::front()
{
  if (!empty())
  {
    return values_[0];
  }
}

template <typename T, unsigned int max_size_>
T& Array<T, max_size_>::back()
{
  if (!empty())
  {
    return values_[size_-1];
  }
}

template <typename T, unsigned int max_size_>
void Array<T, max_size_>::clear()
{
  size_ = 0;
}

template <typename T, unsigned int max_size_>
void Array<T, max_size_>::fill(const T &value)
{
  assign(max_size_,value);
}

template <typename T, unsigned int max_size_>
void Array<T, max_size_>::fill(const T (&values)[max_size_])
{
  assign(max_size_,values);
}

template <typename T, unsigned int max_size_>
void Array<T, max_size_>::assign(const unsigned int n, const T &value)
{
  unsigned int assign_size = n;
  if ((n > size_) && (n <= max_size_))
  {
    size_ = n;
  }
  else if (n > max_size_)
  {
    size_ = max_size_;
    assign_size = max_size_;
  }
  for (unsigned int i=0; i<assign_size; i++)
  {
    values_[i] = value;
  }
}

template <typename T, unsigned int max_size_>
void Array<T, max_size_>::assign(const unsigned int n, const T values[])
{
  unsigned int assign_size = n;
  if ((n > size_) && (n <= max_size_))
  {
    size_ = n;
  }
  else if (n > max_size_)
  {
    size_ = max_size_;
    assign_size = max_size_;
  }
  memcpy((void*) values_, (void*) values, assign_size*sizeof(T));
}

template <typename T, unsigned int max_size_>
void Array<T, max_size_>::push_back(const T &value)
{
  if (size_ < max_size_)
  {
    values_[size_++] = value;
  }
}

template <typename T, unsigned int max_size_>
void Array<T, max_size_>::pop_back()
{
  if (size_ > 0)
  {
    --size_;
  }
}

template <typename T, unsigned int max_size_>
unsigned int Array<T, max_size_>::size()
{
  return size_;
}

template <typename T, unsigned int max_size_>
unsigned int Array<T, max_size_>::max_size()
{
  return max_size_;
}

template <typename T, unsigned int max_size_>
bool Array<T, max_size_>::empty()
{
  return size_ == 0;
}

template <typename T, unsigned int max_size_>
bool Array<T, max_size_>::full()
{
  return size_ == max_size_;
}

#endif
