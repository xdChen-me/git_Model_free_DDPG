/* Copyright 2019-2021 The MathWorks, Inc. */

#ifndef MW_MKLDNN_TANH_LAYER_IMPL
#define MW_MKLDNN_TANH_LAYER_IMPL

#include "MWMkldnnCNNLayerImpl.hpp"
#include "dnnl.hpp"
#include <memory>

class MWCNNLayer;
namespace MWMkldnnTarget
{
class MWTargetNetworkImpl;
/*
 *  Codegen class for Keras tanh Layer
 */
class MWTanhLayerImpl final : public MWCNNLayerImpl {
  public:
    MWTanhLayerImpl(MWCNNLayer*, MWTargetNetworkImpl*);
    ~MWTanhLayerImpl();

    void propagateSize() override;
    void predict() override;

  private:
    std::unique_ptr<dnnl::eltwise_forward::desc> tanh_d;
    std::unique_ptr<dnnl::eltwise_forward::primitive_desc> tanh_pd;
    std::unique_ptr<dnnl::eltwise_forward::primitive> tanh;
};
} // namespace MWMkldnnTarget
#endif
