#include "MWMkldnnReLULayerImpl.hpp"
#include "MWMkldnnCNNLayerImpl.hpp"
#include "MWCNNLayer.hpp"
#include "MWMkldnnTargetNetworkImpl.hpp"
#include "MWMkldnnUtils.hpp"
#include "dnnl.hpp"
#include <memory>
 class MWTensorBase; namespace MWMkldnnTarget { 
MWReLULayerImpl::MWReLULayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { } 
MWReLULayerImpl::~MWReLULayerImpl() { } void MWReLULayerImpl::propagateSize() { 
clearLayerMapsAndVectors(); MWMkldnnUtils::reorderInputsTo(this); const float 
negative_slope = 0.0; 
setLayerMemory(std::make_shared<dnnl::memory>(getReorderedIpMemory()->get_desc(), 
*dMxIKDGTITyhdLqIHBLA->eng)); relu_d = 
std::unique_ptr<dnnl::eltwise_forward::desc>(new dnnl::eltwise_forward::desc( 
dnnl::prop_kind::forward_inference, dnnl::algorithm::eltwise_relu, 
getReorderedIpMemory()->get_desc(), negative_slope)); relu_pd = 
std::unique_ptr<dnnl::eltwise_forward::primitive_desc>( new 
dnnl::eltwise_forward::primitive_desc(*relu_d, *dMxIKDGTITyhdLqIHBLA->eng)); 
relu = std::unique_ptr<dnnl::eltwise_forward>(new 
dnnl::eltwise_forward(*relu_pd)); pipeline_memory_args.push_back( 
{{DNNL_ARG_FROM, *getReorderedIpMemory()}, {DNNL_ARG_TO, *getLayerMemory()}}); 
pipeline.push_back(*relu); } void MWReLULayerImpl::predict() { 
executeInputsReorderPrimitive(); auto s = 
dnnl::stream(*dMxIKDGTITyhdLqIHBLA->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_RELU_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } } 