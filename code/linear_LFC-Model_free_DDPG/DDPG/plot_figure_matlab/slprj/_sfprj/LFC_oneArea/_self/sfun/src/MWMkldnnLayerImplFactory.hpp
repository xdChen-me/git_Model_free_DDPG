/* Copyright 2021 The MathWorks, Inc. */

#ifndef MW_MKLDNN_LAYER_IMPL_FACTORY
#define MW_MKLDNN_LAYER_IMPL_FACTORY

#include "MWLayerImplFactory.hpp"

class MWCNNLayerImplBase;

class MWMkldnnLayerImplFactory final : public MWLayerImplFactory {

  public:
    
    MWMkldnnLayerImplFactory() {}
    virtual ~MWMkldnnLayerImplFactory() {}

    // auto-emit createLayerImpl declarations here

#ifndef CREATE_INPUT_LAYER_IMPL_DECLARATION
#define CREATE_INPUT_LAYER_IMPL_DECLARATION

MWCNNLayerImplBase* createInputLayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2);


#endif

#ifndef CREATE_FC_LAYER_IMPL_DECLARATION
#define CREATE_FC_LAYER_IMPL_DECLARATION

MWCNNLayerImplBase* createFCLayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2,
int arg3,
int arg4,
const char* arg5,
const char* arg6);


#endif

#ifndef CREATE_RELU_LAYER_IMPL_DECLARATION
#define CREATE_RELU_LAYER_IMPL_DECLARATION

MWCNNLayerImplBase* createReLULayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2);


#endif

#ifndef CREATE_TANH_LAYER_IMPL_DECLARATION
#define CREATE_TANH_LAYER_IMPL_DECLARATION

MWCNNLayerImplBase* createTanhLayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2);


#endif

#ifndef CREATE_OUTPUT_LAYER_IMPL_DECLARATION
#define CREATE_OUTPUT_LAYER_IMPL_DECLARATION

MWCNNLayerImplBase* createOutputLayerImpl(MWCNNLayer* arg1,
MWTargetNetworkImplBase* arg2);


#endif
};
#endif