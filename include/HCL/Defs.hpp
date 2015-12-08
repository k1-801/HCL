#pragma once

#ifndef HCL_DEFS_HPP
#define HCL_DEFS_HPP

/**
 * This file is a part of Haont Common Library (HCL)
 * Contains definitions and macroses used in library
 *
 * HCL_CONCAT(a, b): keyword concatenation macro
 * HCL_CONCAT(a): quotation keyword wrapper
 *
 * @project HCL
 * @author k1-801
 */

#define HCL_CONCAT(a, b) a##b
#define HCL_STRING(a) #a

#endif // HCL_DEFS_HPP

