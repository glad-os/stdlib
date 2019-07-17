/**
 * Copyright 2019 AbbeyCatUK
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "string.h"
#include "stdio.h"


char *strchr( char *str, char c )
{

	while (*str) {
	    if (*str == c)
	      return str;
	    str++;
	  }

	return 0;

}

unsigned int strncmp( const char *str1, const char *str2, unsigned int n )
{

   while(n--)
		if(*str1++!=*str2++)
			return *(unsigned char*)(str1 - 1) - *(unsigned char*)(str2 - 1);
	return 0;

}

void *memmove( void *destaddr, void *sourceaddr, unsigned int length )
{

	char *dest = destaddr;
	const char *source = sourceaddr;

	if (source < dest)

		/* Moving from low mem to hi mem; start at end.  */
		for (source += length, dest += length; length; --length)
			*--dest = *--source;

	else if (source != dest)

		/* Moving from hi mem to low mem; start at beginning.  */
		for (; length; --length)
			*dest++ = *source++;

	return destaddr;

}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// from USPiEnv
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void *memcpy( void *dst, void *src, unsigned int n )
{

	char *pd = (char *) dst;
	char *ps = (char *) src;

	while (n--)
	{
		*pd++ = *ps++;
	}

	return dst;
}

int strlen (const char *pString)
{

	unsigned long nResult = 0;

	while (*pString++)
	{
		nResult++;
	}

	return nResult;

}

int strcmp (const char *pString1, const char *pString2)
{

	while (   *pString1 != '\0'
	       && *pString2 != '\0')
	{
		if (*pString1 > *pString2)
		{
			return 1;
		}
		else if (*pString1 < *pString2)
		{
			return -1;
		}

		pString1++;
		pString2++;
	}

	if (*pString1 > *pString2)
	{
		return 1;
	}
	else if (*pString1 < *pString2)
	{
		return -1;
	}

	return 0;

}

char *strcpy (char *pDest, const char *pSrc)
{

	char *p = pDest;

	while (*pSrc)
	{
		*p++ = *pSrc++;
	}

	*p = '\0';

	return pDest;

}

char *strncpy (char *pDest, const char *pSrc, unsigned long nMaxLen)
{

	char *pResult = pDest;

	while (nMaxLen > 0)
	{
		if (*pSrc == '\0')
		{
			break;
		}

		*pDest++ = *pSrc++;
		nMaxLen--;
	}

	if (nMaxLen > 0)
	{
		*pDest = '\0';
	}

	return pResult;

}

char *strcat (char *pDest, const char *pSrc)
{

	char *p = pDest;

	while (*p)
	{
		p++;
	}

	while (*pSrc)
	{
		*p++ = *pSrc++;
	}

	*p = '\0';

	return pDest;

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char *strncat( char *s, char *ct, unsigned int n )
{

	sprintf( "strncat not done yet\n" );

	return s;

}

char *strstr( char *cs, char *ct )
{

	 if (!*ct) return cs;
	  char *p1 = (char*)cs;
	  while (*p1) {
	    char *p1Begin = p1, *p2 = (char*)ct;
	    while (*p1 && *p2 && *p1 == *p2) {
	      p1++;
	      p2++;
	    }
	    if (!*p2)
	      return p1Begin;
	    p1 = p1Begin + 1;
	  }
	  return 0;

}
