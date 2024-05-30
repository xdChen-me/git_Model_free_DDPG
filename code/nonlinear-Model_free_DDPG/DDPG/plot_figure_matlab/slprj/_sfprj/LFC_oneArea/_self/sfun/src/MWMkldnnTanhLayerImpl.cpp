#include "MWMkldnnTanhLayerImpl.hpp"
#include "MWMkldnnCNNLayerImpl.hpp"
#include "MWCNNLayer.hpp"
#include "MWMkldnnTargetNetworkImpl.hpp"
#include "MWMkldnnUtils.hpp"
#include "dnnl.hpp"
#include <cstdarg>
#include <cassert>
 class MWTensorBase; namespace MWMkldnnTarget { 
MWTanhLayerImpl::MWTanhLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { } 
MWTanhLayerImpl::~MWTanhLayerImpl() { } void MWTanhLayerImpl::propagateSize() { 
clearLayerMapsAndVectors(); MWMkldnnUtils::reorderInputsTo(this); float aplha = 
0.0; 
setLayerMemory(std::make_shared<dnnl::memory>(getReorderedIpMemory()->get_desc(), 
*dMxIKDGTITyhdLqIHBLA->eng)); tanh_d = 
std::unique_ptr<dnnl::eltwise_forward::desc>(new dnnl::eltwise_forward::desc( 
dnnl::prop_kind::forward_inference, dnnl::algorithm::eltwise_tanh, 
getReorderedIpMemory()->get_desc(), aplha)); tanh_pd = 
std::unique_ptr<dnnl::eltwise_forward::primitive_desc>( new 
dnnl::eltwise_forward::primitive_desc(*tanh_d, *dMxIKDGTITyhdLqIHBLA->eng)); 
tanh = std::unique_ptr<dnnl::eltwise_forward>(new 
dnnl::eltwise_forward(*tanh_pd)); pipeline_memory_args.push_back( 
{{DNNL_ARG_FROM, *getReorderedIpMemory()}, {DNNL_ARG_TO, *getLayerMemory()}}); 
pipeline.push_back(*tanh); } void MWTanhLayerImpl::predict() { 
executeInputsReorderPrimitive(); auto s = 
dnnl::stream(*dMxIKDGTITyhdLqIHBLA->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_TANH_TAP
 reorderedLayerOutputTap(0);
#endif
 } } 