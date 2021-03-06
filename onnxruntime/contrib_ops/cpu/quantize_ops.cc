// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "core/providers/cpu/tensor/quantize_linear.h"
#include "core/providers/common.h" 


namespace onnxruntime {
namespace contrib {

ONNX_CPU_OPERATOR_TYPED_MS_KERNEL(
    DequantizeLinear,
    1,
    uint8_t,
    KernelDefBuilder()
        .TypeConstraint("axis", DataTypeImpl::GetType<int64_t>())
        .TypeConstraint("x", DataTypeImpl::GetTensorType<uint8_t>())
        .TypeConstraint("x_scale", DataTypeImpl::GetTensorType<float>())
        .TypeConstraint("x_zero_point", DataTypeImpl::GetTensorType<uint8_t>())
        .TypeConstraint("y", DataTypeImpl::GetTensorType<float>()),
    DequantizeLinear<uint8_t>);

ONNX_CPU_OPERATOR_TYPED_MS_KERNEL(
    DequantizeLinear,
    1,
    int8_t,
    KernelDefBuilder()
        .TypeConstraint("axis", DataTypeImpl::GetType<int64_t>())
        .TypeConstraint("x", DataTypeImpl::GetTensorType<int8_t>())
        .TypeConstraint("x_scale", DataTypeImpl::GetTensorType<float>())
        .TypeConstraint("x_zero_point", DataTypeImpl::GetTensorType<int8_t>())
        .TypeConstraint("y", DataTypeImpl::GetTensorType<float>()),
    DequantizeLinear<int8_t>);

ONNX_CPU_OPERATOR_TYPED_MS_KERNEL(
    QuantizeLinear,
    1,
    uint8_t,
    KernelDefBuilder()
        .TypeConstraint("axis", DataTypeImpl::GetType<int64_t>())
        .TypeConstraint("x", DataTypeImpl::GetTensorType<float>())
        .TypeConstraint("y_scale", DataTypeImpl::GetTensorType<float>())
        .TypeConstraint("y_zero_point", DataTypeImpl::GetTensorType<uint8_t>())
        .TypeConstraint("y", DataTypeImpl::GetTensorType<uint8_t>()),
    QuantizeLinear<uint8_t>);

} // namespace contrib
}  // namespace onnxruntime
