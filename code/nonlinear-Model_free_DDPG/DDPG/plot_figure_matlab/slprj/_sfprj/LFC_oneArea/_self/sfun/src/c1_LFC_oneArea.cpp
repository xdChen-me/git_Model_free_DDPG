/* Include files */

#include "LFC_oneArea_sfun.h"
#include "c1_LFC_oneArea.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

#include <cstring>

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
const int32_T CALL_EVENT = -1;

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtRSInfo c1_emlrtRSI = { 1,  /* lineNo */
  "matlabCodegenHandle",               /* fcnName */
  "D:\\appInstall\\MATLAB\\R2021b\\toolbox\\coder\\coder\\+coder\\+internal\\matlabCodegenHandle.p"/* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 1,/* lineNo */
  "DeepLearningNetwork",               /* fcnName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2021b_1\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearnin"
  "gNetwork\\DeepLearningNetwork.p"    /* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 2,/* lineNo */
  "Predict/MLFB",                      /* fcnName */
  "#LFC_oneArea:309:310"               /* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 1,/* lineNo */
  "deepNetwork",                       /* fcnName */
  "D:\\appInstall\\MATLAB\\R2021b\\toolbox\\nnet\\deep_blocks\\+deep\\+blocks\\+internal\\deepNetwork.p"/* pathName */
};

static emlrtRSInfo c1_e_emlrtRSI = { 69,/* lineNo */
  "loadDeepLearningNetwork",           /* fcnName */
  "D:\\appInstall\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\loadDeepLearningNetwork.m"/* pathName */
};

static emlrtRSInfo c1_f_emlrtRSI = { 1,/* lineNo */
  "loadDeepLearningNetwork",           /* fcnName */
  "D:\\appInstall\\MATLAB\\R2021b\\toolbox\\shared\\dlcoder_base\\dlcoder_base\\+coder\\+internal\\loadDeepLearningNetwork.p"/* pathName */
};

static emlrtRSInfo c1_g_emlrtRSI = { 1,/* lineNo */
  "predict",                           /* fcnName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2021b_1\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearnin"
  "gNetwork\\predict.p"                /* pathName */
};

static emlrtRSInfo c1_h_emlrtRSI = { 1,/* lineNo */
  "callPredict",                       /* fcnName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2021b_1\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearnin"
  "gNetwork\\callPredict.p"            /* pathName */
};

/* Function Declarations */
static void initialize_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static void initialize_params_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static void enable_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct *chartInstance);
static void disable_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct *chartInstance);
static void c1_update_jit_animation_state_c1_LFC_oneArea
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static void ext_mode_exec_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_LFC_oneArea
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance);
static void set_sim_state_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void sf_gateway_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static void mdl_start_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static void mdl_terminate_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c1_LFC_oneArea
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_LFC_oneArea
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance);
static void initSimStructsc1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static void c1_DeepLearningNetwork_delete(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj);
static void c1_DeepLearningNetwork_callDelete(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj);
static void c1_DeepLearningNetwork_setup(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj);
static real32_T c1_DeepLearningNetwork_predict(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj, real_T c1_varargin_1[3]);
static void c1_DeepLearningNetwork_callPredictForCustomLayers
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj);
static real32_T c1_emlrt_marshallIn(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_b_out_1_predict, const char_T *c1_identifier);
static real32_T c1_b_emlrt_marshallIn(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint8_T c1_c_emlrt_marshallIn(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_LFC_oneArea, const char_T
  *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_slStringInitializeDynamicBuffers(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);
static void c1_chart_data_browse_helper(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig);
static void init_dsm_address_info(SFc1_LFC_oneAreaInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c1_st, (const char_T *)"neural_network_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_network_not_empty = false;
  chartInstance->c1_is_active_c1_LFC_oneArea = 0U;
  chartInstance->c1_network.matlabCodegenIsDeleted = true;
}

static void initialize_params_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
}

static void enable_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_jit_animation_state_c1_LFC_oneArea
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance)
{
}

static void c1_do_animation_call_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_LFC_oneArea
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", chartInstance->c1_out_1_predict, 1,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_LFC_oneArea, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_out_1_predict = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 0)), "out_1_predict");
  chartInstance->c1_is_active_c1_LFC_oneArea = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_LFC_oneArea");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void sf_gateway_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
  c1_bbb0_LFC_oneArea0 *c1_b_iobj_0;
  c1_bbb0_LFC_oneArea0 *c1_iobj_0;
  c1_bbb0_LFC_oneArea0 *c1_net;
  c1_bbb0_LFC_oneArea0 *c1_obj;
  c1_bbb0_LFC_oneArea0 *c1_this;
  c1_cell_wrap_3 c1_inputs[1];
  c1_cell_wrap_3 c1_r;
  int32_T c1_i;
  int32_T c1_i1;
  real32_T c1_b_out_1_predict;
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c1_i = 0; c1_i < 3; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U,
                      (*chartInstance->c1_in_1)[c1_i]);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_r.f1[c1_i1] = (*chartInstance->c1_in_1)[c1_i1];
  }

  c1_inputs[0] = c1_r;
  if (!chartInstance->c1_network_not_empty) {
    c1_iobj_0 = &chartInstance->c1_network;
    c1_b_iobj_0 = c1_iobj_0;
    c1_obj = c1_b_iobj_0;
    c1_net = c1_obj;
    c1_this = c1_net;
    c1_net = c1_this;
    c1_DeepLearningNetwork_setup(chartInstance, c1_net);
    c1_net->matlabCodegenIsDeleted = false;
    chartInstance->c1_network_not_empty = true;
  }

  c1_b_out_1_predict = c1_DeepLearningNetwork_predict(chartInstance,
    &chartInstance->c1_network, c1_inputs[0].f1);
  *chartInstance->c1_out_1_predict = c1_b_out_1_predict;
  c1_do_animation_call_c1_LFC_oneArea(chartInstance);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                    *chartInstance->c1_out_1_predict);
}

static void mdl_start_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
}

static void mdl_terminate_c1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
}

static void mdl_setup_runtime_resources_c1_LFC_oneArea
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    11U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 217);
}

static void mdl_cleanup_runtime_resources_c1_LFC_oneArea
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance)
{
  c1_bbb0_LFC_oneArea0 *c1_obj;
  c1_obj = &chartInstance->c1_network;
  if (!c1_obj->matlabCodegenIsDeleted) {
    c1_obj->matlabCodegenIsDeleted = true;
    c1_DeepLearningNetwork_delete(chartInstance, c1_obj);
  }

  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void initSimStructsc1_LFC_oneArea(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
}

static void c1_DeepLearningNetwork_delete(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj)
{
  c1_DeepLearningNetwork_callDelete(chartInstance, c1_obj);
}

static void c1_DeepLearningNetwork_callDelete(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj)
{
  if (c1_obj->isInitialized) {
    c1_obj->cleanup();
  }
}

const mxArray *sf_c1_LFC_oneArea_get_eml_resolved_functions_info()
{
  const mxArray *c1_nameCaptureInfo = NULL;
  const char_T *c1_data[18] = {
    "789ced5d4f6fe3441477d1ae5840bb940b2c70e961250e15d9366d9aee72d9264ed2b469934dda6c957a9538c93471e3d8aeeda44985506e1c5924fe6a250448"
    "1c16090e4848b0f00190e0029745f005f6237041e0c49e2676e23aa953d799ce3bd49d3cfbfddebc717f6f669e9d1253d18d298220ae11aacc7ca11eaf6aed69",
    "edf80ca117a37e4a3bbe6e6843b94c5cd25d07f5ef69c702cfc9a021ab0d8eae82e32b8b7c95e1684ede6a0a801081c4b37550ec68f618166c315590ea6d6cb6"
    "5bd5708feab8d156b57f0f9641a192aa5509b12c753d647b1bc7f1f8c5a4bf97868c0730b409c37950bf1bdd09ddbf51a56596ce8b3c2fdfa0649e67f37c8392",
    "cab4088a54912df0452066f3b404f48dd9ceefd42ca34450e468966279ba480220c4002d720c57da04f2212f563c424fbf5a36fbf5aa45bfa0bee39b6780379a"
    "1efa93b3e9cf2543bbeb8faa292851ecc5bb32650fef4b533cbd7e371abc1fbc4d2544be24d2559296696a63652bb612a0523541e0453941172a74094854d23b",
    "e79dcf67e74f1c7849bd488017a9e7648b6c56a6c51290257837dc191072caeca620acc7e1c521e3623c76cfbfd239fefafb932927f188276f5c75144f93f3c2"
    "6b98d81bf6be7ed9046fdaa03fd8a8c465ae1e0f798fc8ed7225bf4f56824781ae1f090b1c2b3f0893b653f6313f0ce607bbf7d72b1671817a356f747e6a9e6c",
    "cb0c2bd9ce174631f303ca35c389a7edf7671678507f6ef7435fa8a9be4fdaf78253bcf677d4e13cf1c76f3e47f134413d4f34f78ba158b22edee332dec374b5"
    "297a33f9c02a3a79226772fd59f110ea784f4f8907edbf6b8107f5bbdbf7c9db5427eb09b4a0d0e51e2f662525efb14afe0334150b07b32499886495c5675152",
    "3814502cc329ba2ce0ea6ded9b1b0a3db2d93d1100c389595f565dc751edcf2981e5e5ec1e53aa299aaeb17c3eef51ce72ecefff11ff97a37c3a13fee17d27f1"
    "a0a0cea7f183b93dae99c837966b2bf37ec177d757ba5b09633e35cab07c239c120fdabf66681bf1a05e02b23695daec6c6eb9751fe6bacd79ee7716fe40fd6e",
    "34eef685cf9471cc7ae3943389032a7c863a9e537cbd9dd94c2f4552e4fee6eac1f67ea999a017128508e66ba39cf57c14dabf6c8aa76a94bff99a9bf7c9a76d"
    "f2f3230b7fa07e42f8b906f3f745e12dd4f1302f8fc77ecee47ab7cea39fb3c083fa02cdb2a9017ff72d9bf86ee3e96f2cfc81fa49e0e9de31bb283c863a1ee6",
    "e9f1d877aece785e3cd15f581241899164209240005c1170050648b8cea83f11d71955c999f417d71987c4d304f53c817a9d11e789c179a265d2ef61e3f29a45"
    "5ca0bec86afe7aaa15b6c871da614560f4fee44ee98f5186cd17ff9c120fdaffc0020feacf385fa80553f584de7be338ecd4ac1a70ea38eeea9de014afbd4d3b",
    "9b275a8f6f3e75120f0aea7922edad1c70ecce4a62359e6081776731c46f2d22b49ec8995cefd6fdf8674df1548da050075390c7c6f7e3dee7b1cbbf1f5bf803"
    "f5eedae7d14645a16064e7e95f3d5c74144f13d4f997f10b5bf135c6eb0facaffa96c964247300422174f817f3812a2d9b7170cbfb454619362fe2f707f0fb45",
    "6782a709ea7902f5f78b709e50e581cd38dcb48803d4ab7902be22eb61f832cd1559c5354f81e33c514ea8c9edd8244420281d12cf2d6fccd8cc1b3f5ae041fd"
    "79e58dee5bcab3dd3150941c47dde91b05aaef13984ed05d77fcf7ef92a3789aa09e4f52a1b9f2dcda214b0b7b854a799b07e1a5cd4610e713d4f209ae1b8f86",
    "07ede3bab1beffaecb0bb86edc115c371ecd7ecee4fa497f0e5402f20a5728f3a201bf65137fdcfb4e7679f9530b7fa0de5d79f97874d09fafe33a4147c6cdcb"
    "c25a29c92fa4abd562732db8ce8a81a352ed1e42f3f59cc9f56eadd35e31b4bb78aaa64eb34c9196815b79d8eefae8130b7fa0de5d3c0c47c523a0cabfadb716",
    "f1bc98183fffde0adf4afb02293658c9acd643ebdea36854f62354a7cd995cefd679b159ffa60d47851236188e09d072a19c628e5ccbc776e7c59f5bf803f5ee"
    "e263e3e8a0cbcb785eaccad89f9f49249abe70e580147de1c3a614392077964884f62b666cf2c26313fbd306bdc20b21f7f0c2e0f72619adead5a982b57923df",
    "e60d7dbc1e98c403d74f47c383f671fd549589cd3bb87eda115c3f1dcdbe8379671288430062b52683685531dad1e2f773f527e23aab2a3993fe4e6cfec075d6"
    "8ee03aeb68f6f1ba65b4750bce1fa3e1e1fc31381e387fa882f3c7c938567e10266d5c8fd0eba1fd172cf0a0befddd5f09ed1dde5efc964d7cb7d5231e5af803",
    "f5eeaa47f48c8eb6c0439697713da223e3e6e5857a321ed9ae27ab4b0ce307f9423ae64f2e23f49e16e6053d2fd8ad37cc59c403ea4fae37c46bb261c76a52eb"
    "0d3f59e041bd1beb0dfda340f57f84785e697df891df493c28a8e7955a74b5c10beb771b113eb12caec7d2353290c4f3fd3e1996a75aa7c483f687fd9e3409c8",
    "ed075be057b6c90a6109409419208dd71fb77d5ff3d716fe40bdbbf2bcf96839fdbd0df8b9d1b3c5736c9f2618cfb0c27266debfb072b4b3b1b5ca2d883112f3"
    "b651dcc6db3d33fe302f066b92cc576374138898b73be22ede361f2da779fbcf771cdec7b94abde4289e26a8f376b91651e83a135f8c860f99b9fd06bf580d4b",
    "08fd5f41e7d6e993539f5517ebfa022ddee7d10bdee7c1fb3c6dc1fb3caae07d9ed1ecdbe58d9f4dec4f1bf4ae7cae740071f43e58aaaaf5dfe38e9f0b1a0d0f"
    "dac7cf05e9fbefb6fc819f0b52053f17349a7dbc6e196ddd82f3c76878387f0c8e07ce1faae0fc71328e951f84491bd57a85dd717bc9020fea053515a44141e6",
    "c5360d19fc68d9f463dc758aeb36f9f97b0b7fa0de5d758ac1797cd0d85d145e431d0fff5fe0f1d8cf995cefd6f7019eb7c083fa76e592042c90811ebf6513df"
    "6d75e56f2dfc81fa49e0ebde31bb283c863a1ee6697bf6ff0776dee4d2", "" };

  c1_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c1_data[0], 41272U, &c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_DeepLearningNetwork_setup(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj)
{
  c1_bbb0_LFC_oneArea0 *c1_b_obj;
  c1_obj->setup(chartInstance);
}

static real32_T c1_DeepLearningNetwork_predict(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj, real_T c1_varargin_1[3])
{
  c1_bbb0_LFC_oneArea0 *c1_b_obj;
  c1_cell_wrap_3 c1_dataInputs[1];
  c1_cell_wrap_3 c1_r;
  c1_cell_wrap_7 c1_dataInputsSingle[1];
  c1_cell_wrap_9 c1_inMiniBatchGroup[1];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real32_T c1_miniBatch[3];
  real32_T c1_outMiniBatchGroup[1];
  real32_T c1_outdata[1];
  real32_T c1_b_inData;
  real32_T c1_b_miniBatch;
  real32_T c1_inData;
  real32_T c1_outMiniBatch;
  boolean_T c1_isImageInput[1];
  for (c1_i = 0; c1_i < 3; c1_i++) {
    c1_r.f1[c1_i] = c1_varargin_1[c1_i];
  }

  c1_dataInputs[0] = c1_r;
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_dataInputsSingle[0].f1[c1_i1] = (real32_T)c1_dataInputs[0].f1[c1_i1];
  }

  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    c1_miniBatch[c1_i2] = c1_dataInputsSingle[0].f1[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    c1_dataInputsSingle[0].f1[c1_i3] = c1_miniBatch[c1_i3];
  }

  c1_isImageInput[0] = false;
  if (c1_isImageInput[0]) {
    for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
      c1_miniBatch[c1_i5] = c1_dataInputsSingle[0].f1[c1_i5];
    }

    for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
      c1_inMiniBatchGroup[0].f1[c1_i7] = c1_miniBatch[c1_i7];
    }
  } else {
    for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
      c1_miniBatch[c1_i4] = c1_dataInputsSingle[0].f1[c1_i4];
    }

    for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
      c1_inMiniBatchGroup[0].f1[c1_i6] = c1_miniBatch[c1_i6];
    }
  }

  c1_b_obj = c1_obj;
  memcpy(c1_obj->getInputDataPointer(0), c1_inMiniBatchGroup[0].f1,
         c1_obj->getLayerOutputSize(0, 0));
  c1_obj->predict();
  memcpy(&c1_outMiniBatchGroup[0], c1_obj->getLayerOutput(7, 0),
         c1_obj->getLayerOutputSize(7, 0));
  c1_DeepLearningNetwork_callPredictForCustomLayers(chartInstance, c1_b_obj);
  c1_b_miniBatch = c1_outMiniBatchGroup[0];
  c1_inData = c1_b_miniBatch;
  c1_b_inData = c1_inData;
  c1_outMiniBatch = c1_b_inData;
  c1_outdata[0] = c1_outMiniBatch;
  c1_outMiniBatchGroup[0] = c1_outdata[0];
  return c1_outMiniBatchGroup[0];
}

static void c1_DeepLearningNetwork_callPredictForCustomLayers
  (SFc1_LFC_oneAreaInstanceStruct *chartInstance, c1_bbb0_LFC_oneArea0 *c1_obj)
{
}

static real32_T c1_emlrt_marshallIn(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_b_out_1_predict, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y;
  c1_thisId.fIdentifier = const_cast<const char_T *>(c1_identifier);
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_out_1_predict),
    &c1_thisId);
  sf_mex_destroy(&c1_b_out_1_predict);
  return c1_y;
}

static real32_T c1_b_emlrt_marshallIn(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real32_T c1_f;
  real32_T c1_y;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_f, 0, 1, 0U, 0, 0U, 0);
  c1_y = c1_f;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_LFC_oneArea, const char_T
  *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  c1_thisId.fIdentifier = const_cast<const char_T *>(c1_identifier);
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_LFC_oneArea), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_LFC_oneArea);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_u;
  uint8_T c1_y;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_u, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_b_u;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_slStringInitializeDynamicBuffers(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
}

static void c1_chart_data_browse_helper(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig)
{
  real32_T c1_f;
  *c1_mxData = NULL;
  *c1_mxData = NULL;
  *c1_isValueTooBig = 0U;
  switch (c1_ssIdNumber) {
   case 4U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_in_1, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 5U:
    c1_f = *chartInstance->c1_out_1_predict;
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", &c1_f, 1, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

void c1_bbb0_LFC_oneArea0::allocate()
{
  int32_T c1_idx;
  targetImpl->allocate(2, layers, numLayers, 0);
  for (c1_idx = 0; c1_idx < 8; c1_idx++) {
    layers[c1_idx]->allocate();
  }

  (static_cast<MWTensor<real32_T> *>(inputTensors[0]))->setData(layers[0]
    ->getLayerOutput(0));
}

void c1_bbb0_LFC_oneArea0::postsetup()
{
  targetImpl->postSetup();
}

c1_bbb0_LFC_oneArea0::c1_bbb0_LFC_oneArea0()
{
  numLayers = 8;
  isInitialized = false;
  targetImpl = 0;
  layers[0] = new MWInputLayer;
  layers[0]->setName("input");
  layers[1] = new MWFCLayer;
  layers[1]->setName("fc_1");
  layers[2] = new MWReLULayer;
  layers[2]->setName("relu_1");
  layers[2]->setInPlaceIndex(0, 0);
  layers[3] = new MWFCLayer;
  layers[3]->setName("fc_2");
  layers[4] = new MWReLULayer;
  layers[4]->setName("relu_2");
  layers[4]->setInPlaceIndex(0, 0);
  layers[5] = new MWFCLayer;
  layers[5]->setName("fc_3");
  layers[6] = new MWTanhLayer;
  layers[6]->setName("layer");
  layers[6]->setInPlaceIndex(0, 0);
  layers[7] = new MWOutputLayer;
  layers[7]->setName("regressionoutput");
  layers[7]->setInPlaceIndex(0, 0);
  targetImpl = new MWMkldnnTarget::MWTargetNetworkImpl;
  inputTensors[0] = new MWTensor<real32_T>;
  inputTensors[0]->setHeight(1);
  inputTensors[0]->setWidth(1);
  inputTensors[0]->setChannels(3);
  inputTensors[0]->setBatchSize(1);
  inputTensors[0]->setSequenceLength(1);
}

void c1_bbb0_LFC_oneArea0::deallocate()
{
  int32_T c1_idx;
  targetImpl->deallocate();
  for (c1_idx = 0; c1_idx < 8; c1_idx++) {
    layers[c1_idx]->deallocate();
  }
}

void c1_bbb0_LFC_oneArea0::setSize()
{
  int32_T c1_idx;
  for (c1_idx = 0; c1_idx < 8; c1_idx++) {
    layers[c1_idx]->propagateSize();
  }

  allocate();
  postsetup();
}

void c1_bbb0_LFC_oneArea0::resetState()
{
}

void c1_bbb0_LFC_oneArea0::setup(SFc1_LFC_oneAreaInstanceStruct *chartInstance)
{
  if (isInitialized) {
    resetState();
  } else {
    targetImpl->preSetup();
    (static_cast<MWInputLayer *>(layers[0]))->createInputLayer(targetImpl,
      inputTensors[0], "CB", 0);
    (static_cast<MWFCLayer *>(layers[1]))->createFCLayer(targetImpl, layers[0]
      ->getOutputTensor(0), 3, 256,
      "D:\\work\\paper_for_singlearea\\LFC_DDPG_mindspore\\linear_env\\LFC-Model_free_DDPG_mindspore_5_matlab\\DDPG\\plot_figure_mindspore\\slp"
      "rj\\_sfprj\\LFC_oneArea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_1_w.bin",
      "D:\\work\\paper_for_singlearea\\LFC_DDPG_mindspore\\linear_env\\LFC-Model_free_DDPG_mindspore_5_matlab\\DDPG\\plot_figure_mindspore\\slp"
      "rj\\_sfprj\\LFC_oneArea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_1_b.bin",
      "CB", 1);
    (static_cast<MWReLULayer *>(layers[2]))->createReLULayer<real32_T, real32_T>
      (targetImpl, layers[1]->getOutputTensor(0), 0, "FLOAT", 1, "CB", -1);
    (static_cast<MWFCLayer *>(layers[3]))->createFCLayer(targetImpl, layers[2]
      ->getOutputTensor(0), 256, 256,
      "D:\\work\\paper_for_singlearea\\LFC_DDPG_mindspore\\linear_env\\LFC-Model_free_DDPG_mindspore_5_matlab\\DDPG\\plot_figure_mindspore\\slp"
      "rj\\_sfprj\\LFC_oneArea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_2_w.bin",
      "D:\\work\\paper_for_singlearea\\LFC_DDPG_mindspore\\linear_env\\LFC-Model_free_DDPG_mindspore_5_matlab\\DDPG\\plot_figure_mindspore\\slp"
      "rj\\_sfprj\\LFC_oneArea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_2_b.bin",
      "CB", 0);
    (static_cast<MWReLULayer *>(layers[4]))->createReLULayer<real32_T, real32_T>
      (targetImpl, layers[3]->getOutputTensor(0), 0, "FLOAT", 1, "CB", -1);
    (static_cast<MWFCLayer *>(layers[5]))->createFCLayer(targetImpl, layers[4]
      ->getOutputTensor(0), 256, 1,
      "D:\\work\\paper_for_singlearea\\LFC_DDPG_mindspore\\linear_env\\LFC-Model_free_DDPG_mindspore_5_matlab\\DDPG\\plot_figure_mindspore\\slp"
      "rj\\_sfprj\\LFC_oneArea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_3_w.bin",
      "D:\\work\\paper_for_singlearea\\LFC_DDPG_mindspore\\linear_env\\LFC-Model_free_DDPG_mindspore_5_matlab\\DDPG\\plot_figure_mindspore\\slp"
      "rj\\_sfprj\\LFC_oneArea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_3_b.bin",
      "CB", 1);
    (static_cast<MWTanhLayer *>(layers[6]))->createTanhLayer(targetImpl, layers
      [5]->getOutputTensor(0), "CB", -1);
    (static_cast<MWOutputLayer *>(layers[7]))->createOutputLayer(targetImpl,
      layers[6]->getOutputTensor(0), "CB", -1);
    outputTensors[0] = layers[7]->getOutputTensor(0);
    setSize();
  }

  isInitialized = true;
}

void c1_bbb0_LFC_oneArea0::predict()
{
  int32_T c1_idx;
  for (c1_idx = 0; c1_idx < 8; c1_idx++) {
    layers[c1_idx]->predict();
  }
}

void c1_bbb0_LFC_oneArea0::cleanup()
{
  int32_T c1_idx;
  deallocate();
  for (c1_idx = 0; c1_idx < 8; c1_idx++) {
    layers[c1_idx]->cleanup();
  }

  if (targetImpl) {
    targetImpl->cleanup();
  }

  isInitialized = false;
}

real32_T *c1_bbb0_LFC_oneArea0::getLayerOutput(int32_T c1_layerIndex, int32_T
  c1_portIndex)
{
  return targetImpl->getLayerOutput(layers, c1_layerIndex, c1_portIndex);
}

int32_T c1_bbb0_LFC_oneArea0::getLayerOutputSize(int32_T c1_layerIndex, int32_T
  c1_portIndex)
{
  return layers[c1_layerIndex]->getOutputTensor(c1_portIndex)->getNumElements() *
    sizeof(real32_T);
}

real32_T *c1_bbb0_LFC_oneArea0::getInputDataPointer(int32_T c1_index)
{
  return (static_cast<MWTensor<real32_T> *>(inputTensors[c1_index]))->getData();
}

real32_T *c1_bbb0_LFC_oneArea0::getInputDataPointer()
{
  return (static_cast<MWTensor<real32_T> *>(inputTensors[0]))->getData();
}

real32_T *c1_bbb0_LFC_oneArea0::getOutputDataPointer(int32_T c1_index)
{
  return (static_cast<MWTensor<real32_T> *>(outputTensors[c1_index]))->getData();
}

real32_T *c1_bbb0_LFC_oneArea0::getOutputDataPointer()
{
  return (static_cast<MWTensor<real32_T> *>(outputTensors[0]))->getData();
}

int32_T c1_bbb0_LFC_oneArea0::getBatchSize()
{
  return inputTensors[0]->getBatchSize();
}

c1_bbb0_LFC_oneArea0::~c1_bbb0_LFC_oneArea0()
{
  int32_T c1_idx;
  if (isInitialized) {
    cleanup();
  }

  for (c1_idx = 0; c1_idx < 8; c1_idx++) {
    delete layers[c1_idx];
  }

  if (targetImpl) {
    delete targetImpl;
  }

  delete inputTensors[0];
}

static void init_dsm_address_info(SFc1_LFC_oneAreaInstanceStruct *chartInstance)
{
}

static void init_simulink_io_address(SFc1_LFC_oneAreaInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_in_1 = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_out_1_predict = (real32_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_LFC_oneArea_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2633746620U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(474642329U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3756338719U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1582384317U);
}

mxArray *sf_c1_LFC_oneArea_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("dltargets.mkldnn.mkldnnApi"));
  return(mxcell3p);
}

mxArray *sf_c1_LFC_oneArea_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("#__setup__");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_LFC_oneArea_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = sf_mex_decode(
    "eNrlls1qg0AQgNfSll6S6Cn/r9BnKBWkQrSlTehZdGlDjIqutLn1cfpoPfbYY80aN+MgkUAhMF1"
    "YZJdhPz7HHYdptsOK0S3mp87YZfG8KqbGynEB1gbY38Z/scPxZyj+BsSfN8R3Qby+W3tB8BTnqc"
    "+tZcizci9p4Wp/wHWeTdedeRueXvtJQsu3g7gd6WuZQJeUr464uvS1oyQXSnl7zveJfN+P9L1r4"
    "RqIa0jf+1xAYYL3uIe4Pen9yGeLvTV937kXvdL0bb7Hcx5lcXrrZZzaPe4jbl/6OqswiKJdtbbX"
    "Sajy/HMi748jvR9auCPEHQHvfdVW6upcKv5jxB0Df1DFay+Akv8QcYfAX1Xzevr/jb+q7g3+VOr"
    "eAHEHwL/qyit9SnmfIu60lvf0hQuXi7c4XYHcU/KfIO4E+KukW54v4nRTffr0+/bSfyGWYUa03h"
    "3635l5JuK1zH7V4sm4X0+XG8E="
    );
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_LFC_oneArea(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPhDBxMDABqQ4IEwwYIXyGaFijHBxFri4AhCXVBakgsSLi5I9U4B0XmIumJ9YWuG"
    "Zl5YPNt+CAWE+GxbzGZHM54SKQ8AHe8r0iziA9Dsg6WfBop8XSb8AlJ9fWhJvGF9QlJqSmVwCCy"
    "coTb57FBwo0w+x34OAfyTQ/APiZxbHJyaXZJalxicbxvu4Ocfn56U6FqUmwvwFAMCEHJI="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_LFC_oneArea_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sgrHOKxptK6r7zqQdj2gJj";
}

static void sf_opaque_initialize_c1_LFC_oneArea(void *chartInstanceVar)
{
  initialize_params_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*)
    chartInstanceVar);
  initialize_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_LFC_oneArea(void *chartInstanceVar)
{
  enable_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_LFC_oneArea(void *chartInstanceVar)
{
  disable_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_LFC_oneArea(void *chartInstanceVar)
{
  sf_gateway_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_LFC_oneArea(SimStruct* S)
{
  return get_sim_state_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_LFC_oneArea(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_LFC_oneArea(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_LFC_oneAreaInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_LFC_oneArea_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*)
      chartInstanceVar);
    ((SFc1_LFC_oneAreaInstanceStruct*) chartInstanceVar)->
      ~SFc1_LFC_oneAreaInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_LFC_oneArea(void *chartInstanceVar)
{
  mdl_start_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c1_LFC_oneArea(void *chartInstanceVar)
{
  mdl_terminate_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_LFC_oneArea(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc1_LFC_oneArea((SFc1_LFC_oneAreaInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_LFC_oneArea_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [51] = {
    "eNrtXU1sG8cVpgzbsZPKdYqicdoC9SFACriVJeo3adFa/JNoUSItSrShrMEud4fkiLuzy5lZShS",
    "K1rceiwJp48BFYAQoEAdIUAQIkDi5FghQH9peEjSXHnPMsZeindldUqvhz9piJXKtJUBRszvv7b",
    "w373vz5u3sTmQsvRphnwvs+9mvI5Gz7Pcc+56KOJ8zbnnM83WOn4687Ja/ZETI0nMylnUS6ftBs",
    "g7WATE0i0IDpVHZ6FoNojLAACmsrmlg2osbgbqlQVRLWUjh/MjNKlSq+aphaWqM0cpqFmlNxs20",
    "aI7xSUAMFJoCQKVVbFiVakqTK+0WY7oTrwKlRiy9nwgE0Lxl8maRVUuj0NRAchcoaUSozFpM9tu",
    "WpzIFcbrbU0wuKcm3Khq6qUEZdZW2KpM8MJmCKdg0VfY3a1EmlFhNqcqYxkBVbgCSgTWbp4GAyB",
    "MSdqIEkUwNDGUtqWtxTtjZtpzG2rNqqEDroxDWthgGcs00IKK9+z+fYpImkVzSQAKUrEpvbnlQt",
    "3jnFyDYAbin3spxowGwXAFZ1POitkKSu3Zvta2ksxqFOijIeFFh/UeA2tN6meWQvMz6CWwwil7V",
    "gC1kmmxg2GDq7cnN0tPcMv0gY+lOZxO/aja3ZAP064U2t5SC4rKmkZ7VNgwzAxpAs7kmZCr3r+Z",
    "w7V6PEKhuGEzB3Lx7o8FCkHW8Wy1uIBV27a6GUMH2O2vMsRysqViEGnqcGW8ik+k83VktjSjAZV",
    "kB3bwAliEBTGe2entzUyHhfc8qslZRu3ndKjsW4lcrQsoWSuwYuMZ00seJ7IvAe7RnRaBWGPIos",
    "EGQZF1XkDWr86I6qbAuZ4DZJAxbPbmxarzL/eopslIFKvdDUAOrDF2sbhfVEe4BF1nLGpA2E4Ao",
    "GJpdOt9i4GTeijd+o2mCTVRDxg5KYUPPu0OB0wsAMKOUMYKoEmNuDjdT7Oodl8WgvmEjtY9/bn3",
    "4+DgZ2R8fv/EY42OL7hLoP65+T6Abd8u/5fozmFXu0v3Rc9/UDJ2JhihXBBOFjakN13OVoeOf8t",
    "7CGi/pKc+pdoGf4v/bdp9ndo+rHl1p3oItz12PHk53kQd45Lnoll9L30refkmXqSaXsGHQlyRqG",
    "FrJ2JUIc9FAlVRNYQaMiyWZgIOFK/b/0hXI8YlkTdIMWU14ungNUA6SCdNtX86nfS8K7XvR1jO7",
    "xkQXrj36vxvf0wf4nrYHH073hQ/d20J73rb1Fb8df1XKYaPCvBt3q9Lq4kZmMSa5wUdOVmocS9J",
    "6dDI6VSpO9VUocYjMFpFTp6hqRSrjCqCkpeVrXVQg9VK2q5cFj3zf9MHFuHv8r3//fGwQ+sjnL4",
    "8PRB8ZrP1e+mWf/v2O0L+8XF+tZSlqZJPRvcRmtVbaTtTiezGH3w89/Ma68It4fg9T/2m3R7/+e",
    "EGQ74U2/u2/LsdNCll05If7iKDfix49/82nHW8JdG8NU88doksdR7iOD4uXL9MD4v0fj2aDjPfm",
    "tprMrDfwTbQV3SnoTRzdKsWWjwfvh7Xf46b7yEevvxHoePm1zduJVyXbK5iyycy+bOAiYX5BY/4",
    "ByFImFS8mErmlIguWVMKwACQWJrJzRYAa/OyP7eltsYwBECoWZ4tOvCLx45KpGbRYhhWLndlnVi",
    "qVJlitQ9vVA+OfA+Hicuqj3wUZF9n6ZBk1c6XdBWtxat6cvTFbuVFLjTYurvnIeUGgu+BkjVxXu",
    "mYH8UcZp37lw/cDge8H9riTHfUBfkzU4ajYfRBxt7m1Vphbyie215brm9uVZk6ezilLo427BR85",
    "zwh0ZxzcWUc9L/yXD98HAt8HwcGbZUZCnJ00nPmNb+cFuvN2nk/T8oK9DAtv7wl83wsI3rw6DPE",
    "WPLwdLq+SHZkJPwYVSCjACWACpAKkQEDCvEqYVwnzKicT737j93cF+XhZ1dzrTug1TUXI/Vk04e",
    "BxyWc+7XldoHv96HHvJIicCl6dt9UgXXEUILX14Gj4sHj5pTwY3u88vPpVkPFeiNbqSLu1mFvO5",
    "jQQvTWTNDZmAj5vfUag42WTmR5U6JHG0X54ekPg+8bIxdGulhikhjZ+/uneTJDxBOfNjex1GJ2P",
    "rSzPLiTWl7bqIJk8Hjw9bfY3jHUH/fxOuO4gXHcwSusOnja8/8JHnquCPFfbeG8tZZqARlVGqsY",
    "uMaGwYLm91jKH+WpfgAfC/9c+7ftYoPt4iPjfX911ZV8n7CSLnK91aEXqODIxaJ564Djgv/+ZC7",
    "JfyCcnq5PXdzTZLCu16qYBUnNru/HQLxzGL4R5sjBPFubJhnMfigC6iJSqgY/hPpQfvt4U+L45c",
    "n6rra3hj58Bn0eb1yvrxnRB19Xm9fiKhmN7FetmPNh5qXMC3Tn74RsN8ufPhpmXuivwvTtyuGpp",
    "acIcFp7u/GQm0OPVK6lXCrOxvBavbS03kivRvXSazieDPV5dFOj4l5nSKkQwJlOlmod7YJjj1X2",
    "B7/2Rw5WoreHhK/B531yuOZuq1RN4NrXTJEv1xK25xDHFg355iYdCex86dpgc9fU70M1G2NkJbq",
    "clbqf7cof5ojBfFOaLhuY/gmCoJsC6RUFatx+pZmfD9VdhXinMK4VxhDeOCP1A6AdCP3D08/XnB",
    "Lrn3Occcu7arGHnl+8JfO+N3Hzdoy03kAnn64fD13RjPbu02VjX5yCcByWlkJlfXzimdRtPqx36",
    "zccnBbkmfefj+y/BakX0Rzkf/0Sg+2RE5+OdWpE6Dw3ZP9z5/R/mg+wfrPTyrmGu3NhdMnILeCV",
    "TsBKx9REffw/zfAF/+yLcA61HFigzdDZnprD1dq9hPnf4rsD33VG839tDe4Ouqzzp96ua8eyWZi",
    "5sTc1PL+7dWt1YRtM4k3j68OcZSVMGjttvHszITYBD/D1ZHCJob1D8ffGrAePjcen5IOOvai0x2",
    "G1lZ9KpHTi5vWvM6CmSGo08VPc4LTh5KCdYO5iICuPnMH4O4+fj8R+fCu39dFTvZ3UxVO8NLef0",
    "/vOvYR47zGOHeewwjgj9QOgHQj8w+HzeT87nBTpeNh1oFoBCDezZvWGY76f8UOD7YSQY7+/qpsv",
    "wPV7he/Na13lWoHvWzaclgAYoGH7+7H2B7/uR4Lw3r6XDEG/Bw9v/A6fnT/XX0yn231gXnI4L1z",
    "kt0J11dXSlPvkt+iPyx/tn3mmsXFr+6SDX//OpJ9tnrfU+6e9H3A2t2hsUNTr2BTps/5MKXs6u7",
    "Jp0ZQ7P79VvqNvRyvVtt3982ntKaG/r+GX2pXx3Gs4fK2m+O01rCxvZcrZFE+39rI8+zh+w969/",
    "Phj9t689jt8eF/TFy4ZFi1NFs70S6EIP/D5Zey5fG4z+8fr/kiAPL0NSlPn2S6CoTBX5S/MNBBY",
    "xkC8MgLeQLth0YydQvsfZ1+u46SLHTDeofEcdL4xq/D9qcoi//foz0tGfoyuX971mjxM//cAt/y",
    "zS2ooyXoWa2mW7Qfc0m2KUu50dVXt9pn/9Z4T6//aJD/4i2DcvD3WTHaKZeFsqkjL/8QQn7BDQy",
    "hLfJlNiAaakIFQslUqT3gBmslhWWKRWmihBdILl3znR8kdPeP9HD/Q/F66f/I8E+R8FRX7kpISc",
    "jcj59LJTG64aTqgdTJ9wHEwfwMGTxhGt+5ATPI5wt4Dfml5EstYk0Fn/2Dqcw3xvcs+p454P/Q+",
    "90aVk",
    ""
  };

  static char newstr [3681] = "";
  newstr[0] = '\0';
  for (i = 0; i < 51; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_LFC_oneArea(SimStruct *S)
{
  const char* newstr = sf_c1_LFC_oneArea_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(305164587U));
  ssSetChecksum1(S,(2624793716U));
  ssSetChecksum2(S,(1990722976U));
  ssSetChecksum3(S,(1011357771U));
}

static void mdlRTW_c1_LFC_oneArea(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_LFC_oneArea(SimStruct *S)
{
  SFc1_LFC_oneAreaInstanceStruct *chartInstance;
  chartInstance = (SFc1_LFC_oneAreaInstanceStruct *)utMalloc(sizeof
    (SFc1_LFC_oneAreaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_LFC_oneAreaInstanceStruct));
  chartInstance = new (chartInstance) SFc1_LFC_oneAreaInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && ssGetNumContStates(ssGetRootSS(S)) > 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_LFC_oneArea;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_LFC_oneArea;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_LFC_oneArea;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c1_LFC_oneArea;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_LFC_oneArea;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_LFC_oneArea;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_LFC_oneArea;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_LFC_oneArea;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_LFC_oneArea;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_LFC_oneArea;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_LFC_oneArea;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_LFC_oneArea;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c1_JITStateAnimation,
    chartInstance->c1_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_LFC_oneArea(chartInstance);
}

void c1_LFC_oneArea_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_LFC_oneArea(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_LFC_oneArea(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_LFC_oneArea(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_LFC_oneArea_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
