///////////////////////////////////////////////////////////////////////////////
/*

TurboSphere Portable Runtime
noreturn.h

Copyright (c) 2012-2014 Martin McDonough.

All rights reserved.


Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

   3. The name of the author may not be used to endorse or promote products
    derived from this software without specific prior written permission.

Permission is granted to anyone to use this software for any purpose, including
 commercial applications, and to alter it and redistribute it freely, subject
 to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software in a
    product, an acknowledgment in the product documentation would be
    appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software. This notice may not be
    removed or altered from any source distribution.


THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
    WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
  OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
                                  OF SUCH DAMAGE.

/////
// What is in this file:

 - Cross-compiler definitions for a non-returning function.
      The compiler will give an error if a function declared with this has a
      return value. Useful for finalizing functions.

/////
// Usage:

TS_NORETURN void ExitFunc(...);

// Functions specified with TS_NORETURN must not have a return type.
// They can be used as callbacks regardless of the specified return type of the
// callback type.

*/
///////////////////////////////////////////////////////////////////////////////

#ifndef TS_NORETURN_HEAD
#define TS_NORETURN_HEAD

#ifdef _MSC_VER
#define TS_NORETURN __declspec(noreturn)
#elif defined __GNUC__
#define TS_NORETURN __attribute__((noreturn))
#else
#define TS_NORETURN
#endif

#endif
