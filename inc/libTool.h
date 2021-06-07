#pragma once
#pragma region Include
#include <Windows.h>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <cwchar>
#include <cerrno>
#include <memory.h>
#include <climits>
#include <cfloat>
#include <cstddef>

#include <array>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>

#include <hash_set>
#include <hash_map>

#include <algorithm>
#include <functional>
#include <limits>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <memory>

#if _MSC_VER >= 1600
// vs2010 开始支持 typeindex
#include <typeindex>
// vs2010 开始支持 stdint.h 和 cstdint
#include <stdint.h>
#endif

#include <mbctype.h>


#include <sys/timeb.h>
#include <sys/types.h>
#include <sys/stat.h>
#pragma endregion

#pragma region TypeDef
typedef bool bol;

typedef   signed __int8  i08;
typedef   signed __int16 i16;
typedef   signed __int32 i32;
typedef   signed __int64 i64;
typedef unsigned __int8  u08;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;

typedef   signed long slong;
typedef unsigned long ulong;

#ifdef _WIN64
typedef u64 szt;
#else
typedef u32 szt;
#endif

typedef      float  f32;
typedef      double f64;
typedef long double fld;

typedef char    c08;
typedef wchar_t c16;

typedef szt size_t;

typedef std::string  qAStr;
typedef std::wstring qWStr;

#undef DEFINE_TYPE_COMMON

#define DEFINE_TYPE_COMMON(TYPE)                 \
typedef std::vector< TYPE        > TYPE##Vector; \
typedef std::map   < TYPE , TYPE > TYPE##Map   ; \
typedef std::set   < TYPE        > TYPE##Set   ; \
typedef std::pair  < TYPE , TYPE > TYPE##Pair  ; \

DEFINE_TYPE_COMMON(bol);

DEFINE_TYPE_COMMON(i08);
DEFINE_TYPE_COMMON(i16);
DEFINE_TYPE_COMMON(i32);
DEFINE_TYPE_COMMON(i64);
DEFINE_TYPE_COMMON(u08);
DEFINE_TYPE_COMMON(u16);
DEFINE_TYPE_COMMON(u32);
DEFINE_TYPE_COMMON(u64);

DEFINE_TYPE_COMMON(slong);
DEFINE_TYPE_COMMON(ulong);

DEFINE_TYPE_COMMON(szt);

DEFINE_TYPE_COMMON(f32);
DEFINE_TYPE_COMMON(f64);
DEFINE_TYPE_COMMON(fld);

DEFINE_TYPE_COMMON(c08);
DEFINE_TYPE_COMMON(c16);

DEFINE_TYPE_COMMON(qAStr);
DEFINE_TYPE_COMMON(qWStr);

typedef std::vector<i32Pair    > i32PairVector;
typedef std::vector<f64Pair    > f64PairVector;
typedef std::vector<i32Vector  > i32VectorVector;
typedef std::vector<f64Vector  > f64VectorVector;
typedef std::vector<qAStrVector> qAStrVectorVector;

#undef DEFINE_TYPE_COMMON
#pragma endregion

#pragma region 值比较
inline bol __miszero(f64 m, f64 tol) { return ((m >= 0) ? m : (-m)) < tol; }

#undef MEQf_Tol
#undef MNEf_Tol
#undef MLTf_Tol
#undef MLEf_Tol
#undef MGTf_Tol
#undef MGEf_Tol

#define MEQf_Tol(l, r, tol) ( __miszero(((l) - (r)) ,   (tol)))
#define MNEf_Tol(l, r, tol) (!__miszero(((l) - (r)) ,   (tol)))
#define MLTf_Tol(l, r, tol)            (((l) - (r)) <= -(tol))
#define MLEf_Tol(l, r, tol)            (((l) - (r)) <  +(tol))
#define MGTf_Tol(l, r, tol)            (((l) - (r)) >= +(tol))
#define MGEf_Tol(l, r, tol)            (((l) - (r)) >  -(tol))

#undef MEQf_0
#undef MNEf_0
#undef MLTf_0
#undef MLEf_0
#undef MGTf_0
#undef MGEf_0

#undef MEQf
#undef MNEf
#undef MLTf
#undef MLEf
#undef MGTf
#undef MGEf

#define MEQf_0(m) ( __miszero((m) ,  +1E-06))
#define MNEf_0(m) (!__miszero((m) ,  +1E-06))
#define MLTf_0(m)            ((m) <= -1E-06)
#define MLEf_0(m)            ((m) <  +1E-06) 
#define MGTf_0(m)            ((m) >= +1E-06)
#define MGEf_0(m)            ((m) >  -1E-06)

#define MEQf(l, r) MEQf_0((l) - (r))
#define MNEf(l, r) MNEf_0((l) - (r))
#define MLTf(l, r) MLTf_0((l) - (r))
#define MLEf(l, r) MLEf_0((l) - (r))
#define MGTf(l, r) MGTf_0((l) - (r))
#define MGEf(l, r) MGEf_0((l) - (r))

#undef MEQf12
#undef MNEf12
#undef MLTf12
#undef MLEf12
#undef MGTf12
#undef MGEf12

#define MEQf12(l, r) ( __miszero(((l) - (r)) ,  +1E-12))
#define MNEf12(l, r) (!__miszero(((l) - (r)) ,  +1E-12))
#define MLTf12(l, r)            (((l) - (r)) <= -1E-12)
#define MLEf12(l, r)            (((l) - (r)) <  +1E-12)
#define MGTf12(l, r)            (((l) - (r)) >= +1E-12)
#define MGEf12(l, r)            (((l) - (r)) >  -1E-12)

#undef MEQf06
#undef MNEf06
#undef MLTf06
#undef MLEf06
#undef MGTf06
#undef MGEf06

#define MEQf06(l, r) ( __miszero(((l) - (r)) ,  +1E-6))
#define MNEf06(l, r) (!__miszero(((l) - (r)) ,  +1E-6))
#define MLTf06(l, r)            (((l) - (r)) <= -1E-6)
#define MLEf06(l, r)            (((l) - (r)) <  +1E-6)
#define MGTf06(l, r)            (((l) - (r)) >= +1E-6)
#define MGEf06(l, r)            (((l) - (r)) >  -1E-6)

#undef MEQf03
#undef MNEf03
#undef MLTf03
#undef MLEf03
#undef MGTf03
#undef MGEf03

#define MEQf03(l, r) ( __miszero(((l) - (r)) ,  +1E-3))
#define MNEf03(l, r) (!__miszero(((l) - (r)) ,  +1E-3))
#define MLTf03(l, r)            (((l) - (r)) <= -1E-3)
#define MLEf03(l, r)            (((l) - (r)) <  +1E-3)
#define MGTf03(l, r)            (((l) - (r)) >= +1E-3)
#define MGEf03(l, r)            (((l) - (r)) >  -1E-3)

#undef MEQi_0
#undef MNEi_0
#undef MLTi_0
#undef MLEi_0
#undef MGTi_0
#undef MGEi_0

#undef MEQi
#undef MNEi
#undef MLTi
#undef MLEi
#undef MGTi
#undef MGEi

#define MEQi_0(m) ((m) == 0)
#define MNEi_0(m) ((m) != 0)
#define MLTi_0(m) ((m) <  0)
#define MLEi_0(m) ((m) <= 0)
#define MGTi_0(m) ((m) >  0)
#define MGEi_0(m) ((m) >= 0)

#define MEQi(l, r) ((l) == (r))
#define MNEi(l, r) ((l) != (r))
#define MLTi(l, r) ((l) <  (r))
#define MLEi(l, r) ((l) <= (r))
#define MGTi(l, r) ((l) >  (r))
#define MGEi(l, r) ((l) >= (r))

#undef MIsClampf_0_0
#undef MIsClampf_0_1
#undef MIsClampf_1_0
#undef MIsClampf_1_1

#undef MIsClampi_0_0
#undef MIsClampi_0_1
#undef MIsClampi_1_0
#undef MIsClampi_1_1

#define MIsClampf_0_0(m,a,b) ( MLTf( (a), (m) ) && MLTf( (m), (b) ) )
#define MIsClampf_0_1(m,a,b) ( MLTf( (a), (m) ) && MLEf( (m), (b) ) )
#define MIsClampf_1_0(m,a,b) ( MLEf( (a), (m) ) && MLTf( (m), (b) ) )
#define MIsClampf_1_1(m,a,b) ( MLEf( (a), (m) ) && MLEf( (m), (b) ) )

#define MIsClampi_0_0(m,a,b) ( MLTi( (a), (m) ) && MLTi( (m), (b) ) )
#define MIsClampi_0_1(m,a,b) ( MLTi( (a), (m) ) && MLEi( (m), (b) ) )
#define MIsClampi_1_0(m,a,b) ( MLEi( (a), (m) ) && MLTi( (m), (b) ) )
#define MIsClampi_1_1(m,a,b) ( MLEi( (a), (m) ) && MLEi( (m), (b) ) )
#pragma endregion