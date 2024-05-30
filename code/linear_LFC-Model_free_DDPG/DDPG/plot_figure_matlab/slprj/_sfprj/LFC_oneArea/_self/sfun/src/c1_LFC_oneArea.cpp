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
  "#LFC_oneArea:309:306"               /* pathName */
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
    "789ced5dcd6fe3441477d1ae5840bb742fb0c0650f8b385474dbf47bb96cf39d366db2499bad52af12279e266efc55db69930aa1fc07ec814fad8400c1012438"
    "207160e10f40820b5c76056724fe042e081cdbd3c64e5c2775ea3ad37987bad367bfdf9b37ceefcdccb353622cb1364610c4354297f1cff4e355d8368ecf1066",
    "b1eac78ce36b963694cbc425d37550ffae712c0bbc021a8adee0290e1c5d490b1cc353bcb2d1140121015960f701ad697618166c301cc87636d6db2d2edaa13a"
    "6ab455eddf435550ae65eb1c2155e5630fd9cec6513c7eb6e9efa53ee3012c6dc2721ed46f27b6220f6e7194c252254910945ba422086c496890729592004dd2",
    "6c59a08154285132303726b4dfc909468da0c4532cc90a141d06404c024ae219beb20e940341aa4d8a1dfd6ab9ecd72b0efd827acdb7c91ede187ae84fd1a53f"
    "972ced637f744d598d6227de953177789fdbe299f5db89d083d01d322d091589e2c29442916bcb1bc9e52099ad8ba2202969aa5ca32a40263381a9c074a9307d",
    "e2c0cbfa4522bc483fa740b30585922a4091e1dd70b747c849bb9b82701e8717fb8c8bf5787cfe15edf8cb6f4fc6bcc4239ebc71d5533c43ce0baf6163afdffb"
    "fa251bbc718b7e6fad9652f8fd54247018deacd64abbe15ae83078ec47da01c7c90fc2a6ed957dcc0fbdf9c1edfdf5b2435ca05ecf1bda4fc3934d856165d7f9",
    "c22a767e40b96639f1b4fdfec4010feacfed7ee80a35d9f597f6bde015affd99f0384ffcfeeb9ca77886a09e279abb742499d997eef3f9c0418e6b4a817c2918"
    "47274f146dae3f2b1e421defe929f1a0fdba031ed46f6f3e08df21b5aca72e2f69596549501075d625d50522df6028816634122cec085241a444204d932cc3ab",
    "09b2908c86de5c53556c614702a0100ea763a4f6436405a5b0c354eaaab923c364a9549a54d77684779ff72f843f3ce5cfa9a5bf5ef7120f0aeafcb9b5140f4e"
    "c5efad54b602ca1ccdafaf2e65725c08f3a755fae517f19478d0fe354bdb8a07f532508ca9d3bab699e5d77d971b2ee7b5df39f803f5db8994df173a63d631eb",
    "8c53d1260ea8f019ea785ef1f5667e3d371fcb8677d7e37b9bbb95669a9a49976398afad72d6f34f68ffb22d9eae513ff3753fef8b8fbbe4e7af1cfc81fa11e1"
    "e73accdf1785b750c7c3bc3c1cfb459bebfd3a8f7ece010feacb14cb667b7cee5b2ef1fdc6d3df38f803f5a3c0d39d637651780c753cccd3c3b1ef5d5df1bc78",
    "a2bb9024810a232b400a0311f034e0cb0c90715dd17c22ae2bea52b4e92fae2bf6896708ea7902f5ba22ce13bdf344cba6dffdc6e55587b8403dcd1afe4e7235"
    "96e679e3b02c32667f8aa7f4c72afde68b7f4e8907edbfe78007f5679c2ff4075df5133aef8da3b093137ac0c9a3b8eb778257bcf636e56d9e683dbefdb79778",
    "5050cf13b9406d8f67b796d3f1549a0581add988b0318bd07aa26873bd5ff7e39fb5c5d335a24a1d4c59f1ed3e8f5bfefdd0c11fa8f7d73e8f312a2a05233b4f"
    "fff2d1aca77886a0cebfcc82b8915a61020bc1d5f8dc623813cbef8148041dfec57ca04bcb651cfcf23e9155facd8bf87d01fc3ed199e019827a9e40fd7d229c",
    "277479e8320eb71de200f57a9e80afc44e324295e26956756db2ccf393095eac2bedd8a42520aa1d92ce2d6fdc7499377e70c083faf3ca1bc76f254f1c8f81aa"
    "e479f26ed728905d7f81e904dd75c77fffce7b8a6708eaf9241b99aa4ead1cb094b853ae553705109d5f6f20f4dc3cce27bae0baf16078d03eae1b9bfbefbbbc",
    "80ebc69ae0baf160f68b36d78ffa73a0325096f97255902cf82d97f8c3de7772cbcb1f3bf803f5fecacb47a383fe7c1dd7093419362f8b2b958c3093e338bab9"
    "125a65a5e061a57e1fa1f97ad1e67abfd669af58dac778ba669f62199a52805f79d8edfae823077fa0de5f3c0c47655244957f5b6fcde27931317cfe5d8a2ee5",
    "e682593654cbc7f723ab81c344425940a84e5bb4b9deaff362bbfe8d5b8e2a25ac313c13a4947235cb1cfa968fddce8b3f75f007eafdc5c7d6d1419797f1bc58"
    "97a13f3f934e37e7a2b5bdb034173d68cab1bdf0d67c18a1fd8a9b2e79e1b18dfd718b5ee585887f78a1f77b938c51f5d2aa606dde28b579c31caf8736f1c0f5",
    "d3c1f0a07d5c3fd56564f30eae9f6a82eba783d9f730ef8c02718840e2ea0a4870aa514d8bdfcf359f88ebacba146dfa3bb2f903d75935c175d6c1ece375cb60"
    "eb169c3f06c3c3f9a3773c70fed005e78f93719cfc206cdab81e61d643fb2f38e0417dfbbbbfd2c63bbc9df82d97f87eab473c72f007eafd558fe8181d638187",
    "2c2fe37a8426c3e6e599fd4c2ab6b99fe1e619660194cab9e4426611a1f7b4302f9879c16dbd61ca211e507f72bd2155572c3b56a35a6ff8d1010feafd586fe8"
    "1e05b2fb4f88e795d6fb1f2c78890705f5bc524fc41b82b87aaf1113d28bd26a32570f073378bedf25fdf254eb9478d07ebfdf932603a5fd600bfcca3645252c",
    "11480a03e4e1fae3b7ef6bfedac11fa8f7579eb71f2dafbfb7013f377ab6789eedd3845279565ccc4f2fcc2c1f6ead6dc4f9192919c6bc6d15bff176c78c3f2a"
    "48a1baac085c926a0209f3b626fee26dfbd1f29ab79fbee3f13ece55f2baa77886a0cedbd57a4ca5eb7c6a36113d60a6761bc22c1795a3e8f0b677ebf4d1a9cf",
    "ea8b75738116eff39805eff3e07d9eb6e07d1e5df03ecf60f6ddf2c64f36f6c72d7a5f3e57da83383a1f2cd5d5e6ef71c7cf050d8607ede3e782ccfdf75bfec0"
    "cf05e9829f0b1acc3e5eb70cb66ec1f963303c9c3f7ac703e70f5d70fe3819c7c90fc2a68d6abdc2edb85d77c0837a514f0539505604a94d43163f5a2efd1876",
    "9de2864b7efedec11fa8f7579da2771eef35761785d750c7c3ff177838f68b36d7fbf57d80e71df0a0be5db90c031628c08cdf7289efb7baf2b70efe40fd28f0"
    "75e7985d141e431d0ff3b43bfbff037cb3dd35", "" };

  c1_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c1_data[0], 41256U, &c1_nameCaptureInfo);
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
      "D:\\work\\mindspore_program\\Chenxiaodi\\code_for_paper1\\linear_LFC-Model_free_DDPG\\DDPG\\plot_figure_mindspore\\slprj\\_sfprj\\LFC_oneA"
      "rea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_1_w.bin",
      "D:\\work\\mindspore_program\\Chenxiaodi\\code_for_paper1\\linear_LFC-Model_free_DDPG\\DDPG\\plot_figure_mindspore\\slprj\\_sfprj\\LFC_oneA"
      "rea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_1_b.bin", "CB", 1);
    (static_cast<MWReLULayer *>(layers[2]))->createReLULayer<real32_T, real32_T>
      (targetImpl, layers[1]->getOutputTensor(0), 0, "FLOAT", 1, "CB", -1);
    (static_cast<MWFCLayer *>(layers[3]))->createFCLayer(targetImpl, layers[2]
      ->getOutputTensor(0), 256, 256,
      "D:\\work\\mindspore_program\\Chenxiaodi\\code_for_paper1\\linear_LFC-Model_free_DDPG\\DDPG\\plot_figure_mindspore\\slprj\\_sfprj\\LFC_oneA"
      "rea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_2_w.bin",
      "D:\\work\\mindspore_program\\Chenxiaodi\\code_for_paper1\\linear_LFC-Model_free_DDPG\\DDPG\\plot_figure_mindspore\\slprj\\_sfprj\\LFC_oneA"
      "rea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_2_b.bin", "CB", 0);
    (static_cast<MWReLULayer *>(layers[4]))->createReLULayer<real32_T, real32_T>
      (targetImpl, layers[3]->getOutputTensor(0), 0, "FLOAT", 1, "CB", -1);
    (static_cast<MWFCLayer *>(layers[5]))->createFCLayer(targetImpl, layers[4]
      ->getOutputTensor(0), 256, 1,
      "D:\\work\\mindspore_program\\Chenxiaodi\\code_for_paper1\\linear_LFC-Model_free_DDPG\\DDPG\\plot_figure_mindspore\\slprj\\_sfprj\\LFC_oneA"
      "rea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_3_w.bin",
      "D:\\work\\mindspore_program\\Chenxiaodi\\code_for_paper1\\linear_LFC-Model_free_DDPG\\DDPG\\plot_figure_mindspore\\slprj\\_sfprj\\LFC_oneA"
      "rea\\_self\\sfun\\src\\cnn_bbb0_LFC_oneArea0_fc_3_b.bin", "CB", 1);
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
  const char* encStrCodegen [50] = {
    "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",
    ""
  };

  static char newstr [3669] = "";
  newstr[0] = '\0';
  for (i = 0; i < 50; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_LFC_oneArea(SimStruct *S)
{
  const char* newstr = sf_c1_LFC_oneArea_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1340789524U));
  ssSetChecksum1(S,(1723483316U));
  ssSetChecksum2(S,(3414973159U));
  ssSetChecksum3(S,(1199792037U));
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
