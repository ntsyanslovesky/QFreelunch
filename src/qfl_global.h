#pragma once

#include <qglobal.h>

#if defined(_MSC_VER) /* MSVC Compiler */
/* template-class specialization 'identifier' is already instantiated */
#pragma warning(disable: 4660)
/* inherits via dominance */
#pragma warning(disable: 4250)
#endif // _MSC_VER

// 使用宏，分别实现编译库和编译执行程序
#ifdef QFL_DLL
#if defined(QFL_MAKEDLL)     // create a QFL DLL library 
#define QFL_EXPORT Q_DECL_EXPORT
#else                        // use a QFL DLL library
#define QFL_EXPORT Q_DECL_IMPORT 
#endif
#endif // QFL_DLL

#ifndef QFL_EXPORT
#define QFL_EXPORT
#endif


