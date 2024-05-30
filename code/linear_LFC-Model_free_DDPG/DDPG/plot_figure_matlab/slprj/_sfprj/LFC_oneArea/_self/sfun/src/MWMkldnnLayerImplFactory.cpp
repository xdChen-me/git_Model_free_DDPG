#include "MWLayerImplFactory.hpp"
#include "MWMkldnnLayerImplFactory.hpp"
#include "MWCNNLayerImplBase.hpp"
#include "MWMkldnnCNNLayerImpl.hpp"
#include "MWMkldnnTargetNetworkImpl.hpp"
 class MWCNNLayer;
#ifndef CREATE_INPUT_LAYER_IMPL_DEFINITION
#define CREATE_INPUT_LAYER_IMPL_DEFINITION

#include "MWMkldnnInputLayerImpl.hpp"
MWCNNLayerImplBase* MWMkldnnLayerImplFactory::createInputLayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2) {
return new MWMkldnnTarget::MWInputLayerImpl(arg1,
static_cast<MWMkldnnTarget::MWTargetNetworkImpl*>(arg2));
}

#endif

#ifndef CREATE_FC_LAYER_IMPL_DEFINITION
#define CREATE_FC_LAYER_IMPL_DEFINITION

#include "MWMkldnnFCLayerImpl.hpp"
MWCNNLayerImplBase* MWMkldnnLayerImplFactory::createFCLayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2,
int arg3,
int arg4,
const char* arg5,
const char* arg6) {
return new MWMkldnnTarget::MWFCLayerImpl(arg1,
static_cast<MWMkldnnTarget::MWTargetNetworkImpl*>(arg2),
arg3,
arg4,
arg5,
arg6);
}

#endif

#ifndef CREATE_RELU_LAYER_IMPL_DEFINITION
#define CREATE_RELU_LAYER_IMPL_DEFINITION

#include "MWMkldnnReLULayerImpl.hpp"
MWCNNLayerImplBase* MWMkldnnLayerImplFactory::createReLULayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2) {
return new MWMkldnnTarget::MWReLULayerImpl(arg1,
static_cast<MWMkldnnTarget::MWTargetNetworkImpl*>(arg2));
}

#endif

#ifndef CREATE_TANH_LAYER_IMPL_DEFINITION
#define CREATE_TANH_LAYER_IMPL_DEFINITION

#include "MWMkldnnTanhLayerImpl.hpp"
MWCNNLayerImplBase* MWMkldnnLayerImplFactory::createTanhLayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2) {
return new MWMkldnnTarget::MWTanhLayerImpl(arg1,
static_cast<MWMkldnnTarget::MWTargetNetworkImpl*>(arg2));
}

#endif

#ifndef CREATE_OUTPUT_LAYER_IMPL_DEFINITION
#define CREATE_OUTPUT_LAYER_IMPL_DEFINITION

#include "MWMkldnnOutputLayerImpl.hpp"
MWCNNLayerImplBase* MWMkldnnLayerImplFactory::createOutputLayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2) {
return new MWMkldnnTarget::MWOutputLayerImpl(arg1,
static_cast<MWMkldnnTarget::MWTargetNetworkImpl*>(arg2));
}

#endif
