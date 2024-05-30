#include "MWMkldnnOutputLayerImpl.hpp"
#include "MWMkldnnCNNLayerImpl.hpp"
#include "MWCNNLayer.hpp"
#include "MWMkldnnTargetNetworkImpl.hpp"
#include "MWMkldnnUtils.hpp"
#include "dnnl.hpp"
#include <memory>
 class MWTensorBase; namespace MWMkldnnTarget { 
MWOutputLayerImpl::MWOutputLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { } 
MWOutputLayerImpl::~MWOutputLayerImpl() { } void 
MWOutputLayerImpl::propagateSize() { clearLayerMapsAndVectors(); MWTensorBase* 
ipTensor = getLayer()->getInputTensor(0); auto prevMemoryDesc = 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor)->get_desc(); format_type 
formatTag = MWMkldnnUtils::getformatType(prevMemoryDesc, ipTensor); bool 
isSequenceIp = (formatTag == format_type::TNC_FORMAT); format_type reorderIpTo 
= isSequenceIp ? (format_type::TNC_FORMAT) : (format_type::NCHW_FORMAT); 
MWMkldnnUtils::reorderInputsTo(this, reorderIpTo); 
setLayerMemory(std::make_shared<dnnl::memory>(getReorderedIpMemory()->get_desc(), 
*dMxIKDGTITyhdLqIHBLA->eng)); } void MWOutputLayerImpl::predict() { MWCNNLayer* 
outputLayer = getLayer(); int UdmcwaUkepxfZrpdpcAN = 
outputLayer->getInPlaceIndex(0); assert(UdmcwaUkepxfZrpdpcAN != -1); 
executeInputsReorderPrimitive(); } } 