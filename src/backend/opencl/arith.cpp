/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <af/dim4.hpp>
#include <af/defines.h>
#include <Array.hpp>
#include <binary.hpp>
#include <arith.hpp>
#include <complex>
#include <err_opencl.hpp>

namespace opencl
{
    template<typename T, af_op_t op>
    Array<T>* arithOp(const Array<T> &lhs, const Array<T> &rhs)
    {
        return createBinaryNode<T, T, op>(lhs, rhs);
    }

#define INSTANTIATE(T)                                                  \
    template Array<T>* arithOp<T, af_add_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_sub_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_mul_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_div_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_min_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_max_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_pow_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_rem_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_mod_t>(const Array<T> &lhs, const Array<T> &rhs); \
    template Array<T>* arithOp<T, af_atan2_t>(const Array<T> &lhs, const Array<T> &rhs); \

    INSTANTIATE(float)
    INSTANTIATE(double)
    INSTANTIATE(cfloat)
    INSTANTIATE(cdouble)
    INSTANTIATE(int)
    INSTANTIATE(uint)
    INSTANTIATE(char)
    INSTANTIATE(uchar)
}
