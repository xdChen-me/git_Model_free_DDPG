/* Copyright 2020-2021 The MathWorks, Inc. */

#ifndef MW_MKLDNN_INPUT_LAYER_IMPL
#define MW_MKLDNN_INPUT_LAYER_IMPL

#include "MWMkldnnCNNLayerImpl.hpp"

class MWCNNLayer;
namespace MWMkldnnTarget
{
class MWTargetNetworkImpl;

class MWInputLayerImpl final : public MWCNNLayerImpl {
  
  public:
    MWInputLayerImpl(MWCNNLayer* layer,
                     MWTargetNetworkImpl* ntwk_impl);
    ~MWInputLayerImpl() {
    }
    void predict() override;
    void cleanup()  override {
    }
    void propagateSize() override;

};
} // namespace MWMkldnnTarget
#endif
