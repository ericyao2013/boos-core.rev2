/** 
 * Memory allocator for target library.
 * 
 * @author    Sergey Baigudin, baigudin@mail.ru
 * @copyright 2016 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_TARGET_ALLOCATOR_HPP_
#define BOOS_TARGET_ALLOCATOR_HPP_

#include "boos.Allocator.hpp"

namespace target
{
  class Allocator
  {
    
  public:

    /**
     * Allocates memory.
     *
     * @param size number of bytes to allocate.
     * @return allocated memory address or a null pointer.
     */    
    static void* alloc(size_t size)
    {
      return ::Allocator::alloc(size);
    }
    
    /**
     * Frees an allocated memory.
     *
     * @param ptr address of allocated memory block or a null pointer.
     */      
    static void free(void* ptr)
    {
      ::Allocator::free(ptr);    
    }

  };
}
#endif // BOOS_TARGET_ALLOCATOR_HPP_
