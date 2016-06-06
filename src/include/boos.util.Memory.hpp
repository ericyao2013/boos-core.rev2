/** 
 * Class of static methods to manipulate memory.
 * 
 * @author    Sergey Baigudin, baigudin@mail.ru
 * @copyright 2016 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_UTIL_MEMORY_HPP_
#define BOOS_UTIL_MEMORY_HPP_

#include "boos.Types.hpp"

namespace util
{
  class Memory
  {
    
  public:
  
    /** 
     * Copies a block of memory.
     *
     * @param dst pointer to the destination array where the content is to be copied, 
     *            type-casted to a pointer of type void*.
     * @param src pointer to the source of data to be copied, type-casted to a pointer of type const void*.
     * @param len number of bytes to copy.
     * @return destination is returned.
     */
    static void* memcpy(void* dst, const void* src, size_t len)
    {
      uint8* sp  = reinterpret_cast<uint8*>(const_cast<void*>(src));
      uint8* dp  = reinterpret_cast<uint8*>(dst);
      while(len--) *dp++ = *sp++;
      return dst;
    }
    
    /** 
     * Fills a block of memory.
     *
     * @param dst pointer to the destination block of memory to fill.
     * @param val value to be set. The value is passed as an int, but the function fills 
     *            the block of memory using the unsigned char conversion of this value.
     * @param len Number of bytes to be set to the value.
     * @return destination is returned.
     */
    static void* memset(void* dst, int32 val, size_t len)
    {
      const uint8 uc = val;
      uint8* su = (uint8*)dst;
      for (; 0 < len; ++su, --len) *su = uc;
      return dst;
    }
    
    /** 
     * Gets a string length.
     *
     * @param str pointer to C-string.
     * @return the length of string.
     */
    static size_t strlen(const char* str)
    {
      size_t n = 0;
      while(*str++) n++;
      return n;
    }
    
    /** 
     * Copies a string.
     *
     * @param dst pointer to the destination array where the content is to be copied.
     * @param src C-string to be copied.     
     * @return destination is returned.     
     */
    static char* strcpy(char* dst, const char* src)
    {
      char* d = dst - 1;     
      const char* s = src  - 1;     
      while(*++d = *++s);
      return dst;
    }
    
    /** 
     * Concatenates strings.
     *
     * @param dst pointer to the destination array, which should contain a C string, 
     *            and be large enough to contain the concatenated resulting string.
     * @param src C-string to be appended. This should not overlap destination.
     * @return destination is returned.     
     */
    static char* strcat(char* dst, const char* src)
    {
      char* s1 = dst - 1;
      const char* s2 = src - 1;
      while(*++s1);
      s1--;
      while(*++s1 = *++s2);
      return dst;
    }
    
    /** 
     * Compares two strings.
     *
     * @param str1 C-string to be compared.
     * @param str2 C-string to be compared.
     * @return a value indicating the relationship between the strings.
     */
    static int32 strcmp(const char* str1, const char* str2)
    {
      int32 c1, res;
      while(true)
      {
        c1 = *str1++;
        res = c1 - *str2++;
        if((c1 == 0) || (res != 0)) break;
      }
      return res;
    }
    
  };
}
#endif // BOOS_UTIL_MEMORY_HPP_

