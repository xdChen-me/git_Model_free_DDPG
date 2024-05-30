/* Copyright 2017-2021 The MathWorks, Inc. */

#ifndef MW_MKLDNN_TARGET_NETWORK_IMPL
#define MW_MKLDNN_TARGET_NETWORK_IMPL

#include "MWTargetNetworkImplBase.hpp"
#include "dnnl.hpp"

#include <vector>

class MWCNNLayer;
class MWTensorBase;
namespace MWMkldnnTarget
{

#define MW_TARGET_TYPE_MKLDNN 1

class MWTargetNetworkImpl final : public MWTargetNetworkImplBase {
  public:
    MWTargetNetworkImpl();
    ~MWTargetNetworkImpl() {
    }
    void allocate(int numBufsToAlloc, MWCNNLayer* layers[], int numLayers, int numPermuteBufs);
    void deallocate() override;
    void preSetup() override;
    void postSetup() {
    }
    void cleanup() override {}

    std::vector<float*> memBuffer;
    float* getLayerOutput(MWCNNLayer* layers[], int layerIndex, int portIndex);
    float* getLayerActivation(MWTensorBase*);

    std::unique_ptr<dnnl::engine> eng;
    float* getBufferPtr(int bufferIndex);

    void setReorderLayerMemory(std::shared_ptr<dnnl::memory> other);
    void setReorderPrim(std::shared_ptr<dnnl::reorder> other);
    std::shared_ptr<dnnl::memory> getReorderLayerMemory();
    std::shared_ptr<dnnl::reorder> getReorderPrim();

    float* getPermuteBuffer(int index); // used for input reordering for custom layers

    bool isAVX512;

  private:
    std::shared_ptr<dnnl::memory> reorderLayerMemory;
    std::shared_ptr<dnnl::reorder> reorderPrim; // to handle the reorder
    std::vector<float*> nNULvWnBXnnWdpEkHPAH;
};
} // namespace MWMkldnnTarget
#endif
