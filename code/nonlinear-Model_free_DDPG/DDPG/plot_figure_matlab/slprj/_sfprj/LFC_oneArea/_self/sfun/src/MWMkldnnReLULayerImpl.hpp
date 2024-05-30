/* Copyright 2020-2021 The MathWorks, Inc. */

#ifndef MW_MKLDNN_RELU_LAYER_IMPL
#define MW_MKLDNN_RELU_LAYER_IMPL

#include "MWMkldnnCNNLayerImpl.hpp"
#include "dnnl.hpp"
#include <memory>

class MWCNNLayer;
namespace MWMkldnnTarget
{
class MWTargetNetworkImpl;

// ReLULayer
class MWReLULayerImpl final : public MWCNNLayerImpl {
  public:
    MWReLULayerImpl(MWCNNLayer*, MWTargetNetworkImpl*);
    ~MWReLULayerImpl();

    void predict() override;
    void propagateSize() override;

  private:
    // ReLU Layer related config params
    std::unique_ptr<dnnl::eltwise_forward::desc> relu_d;
    std::unique_ptr<dnnl::eltwise_forward::primitive_desc> relu_pd;
    std::unique_ptr<dnnl::eltwise_forward::primitive> relu;
};
} // namespace MWMkldnnTarget
#endif
