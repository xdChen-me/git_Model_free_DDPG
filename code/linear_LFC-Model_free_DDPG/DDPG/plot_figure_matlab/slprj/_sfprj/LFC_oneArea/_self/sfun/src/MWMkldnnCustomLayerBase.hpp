/* Copyright 2019-2021 The MathWorks, Inc. */

// Target Specific (MKLDNN) header for Custom Layer Base Class
#ifndef MW_MKLDNN_CUSTOM_LAYER_BASE
#define MW_MKLDNN_CUSTOM_LAYER_BASE

#include "MWCNNLayer.hpp"
#include <map>
#include "dnnl.hpp"

namespace MWMkldnnTarget {
class MWTargetNetworkImpl;
}
class MWTensorBase;

class MWMkldnnCustomLayerBase : public MWCNNLayer {

  public:
    MWMkldnnCustomLayerBase();
    ~MWMkldnnCustomLayerBase();

    std::shared_ptr<dnnl::memory> getCustomLayerMemory(MWTensorBase* aTensor);
    int getMaxBufSize();
    void allocate();
    void deallocate();
    void cleanup();

  private:
    std::map<MWTensorBase*, std::shared_ptr<dnnl::memory>> m_customLayerMemory;
    void setCustomLayerMemory(MWTensorBase* aTensor, std::shared_ptr<dnnl::memory> aLayerMemory);
    int maxBufSize = -1;

  protected:
    MWMkldnnTarget::MWTargetNetworkImpl* m_ntwkImpl;

    void setupLayer(MWMkldnnTarget::MWTargetNetworkImpl*);
    void createLayerMemory(MWTensorBase* aTensor,
                           MWTensorBase::DIMSLABEL implLayout[]);
    void setCustomLayerMemoryData(MWTensorBase* aTensor);
    void layerMemoryReorder(MWTensorBase* srcTensor, int bufIndex);

    virtual void cleanupLayer(){};
};

#endif
