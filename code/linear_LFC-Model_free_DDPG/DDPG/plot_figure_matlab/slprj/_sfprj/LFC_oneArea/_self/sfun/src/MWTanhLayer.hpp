/* Copyright 2018-2021 The MathWorks, Inc. */

// Target Agnostic header for Keras' Tanh Layer
#ifndef MW_TANH_LAYER
#define MW_TANH_LAYER

#include "MWCNNLayer.hpp"

class MWTargetNetworkImplBase;
class MWTensorBase;

/**
  * Codegen class for Keras Tanh Layer
**/
class MWTanhLayer : public MWCNNLayer
{
  public:
    MWTanhLayer();
    ~MWTanhLayer();

    /** Create a new Tanh Layer */
    void createTanhLayer(MWTargetNetworkImplBase*, MWTensorBase*, const char*, int);
    void propagateSize();
};
#endif
