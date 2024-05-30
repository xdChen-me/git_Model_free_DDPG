/* Copyright 2020-2021 The MathWorks, Inc. */

#ifndef MW_MKLDNN_OUTPUT_LAYER_IMPL
#define MW_MKLDNN_OUTPUT_LAYER_IMPL

#include "MWMkldnnCNNLayerImpl.hpp"

class MWCNNLayer;
namespace MWMkldnnTarget
{
class MWTargetNetworkImpl;

class MWOutputLayerImpl final : public MWCNNLayerImpl {
  public:
    MWOutputLayerImpl(MWCNNLayer*, MWTargetNetworkImpl*);
    ~MWOutputLayerImpl();
    void propagateSize() override;
    void predict() override;

};
} // namespace MWMkldnnTarget
#endif
