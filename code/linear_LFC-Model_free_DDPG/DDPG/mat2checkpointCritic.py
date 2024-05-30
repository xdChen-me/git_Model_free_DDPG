import os
import numpy as np
import h5py
import collections
from mindspore import Tensor, save_checkpoint

from mindspore.common.initializer import initializer
from mindspore.common.parameter import Parameter



curr_path = os.path.dirname(os.path.abspath(__file__))  # 当前文件所在绝对路径

load_path = curr_path + '\\FCnnloadCritic\\'
load_path_processed = curr_path + '\\FCnnloadprocessedCritic\\'

b_hid2hid = h5py.File(load_path+'b_hid2hid.mat')
w_hid2hid = h5py.File(load_path+'w_hid2hid.mat')
b_in2hid = h5py.File(load_path+'b_in2hid.mat')
w_in2hid = h5py.File(load_path+'w_in2hid.mat')
b_hid2out = h5py.File(load_path+'b_hid2out.mat')
w_hid2out = h5py.File(load_path+'w_hid2out.mat')

print(b_hid2hid.keys())

b_hid2hid_data = b_hid2hid['b_hid2hid'][:].transpose()
w_hid2hid_data = w_hid2hid['w_hid2hid'][:].transpose()
b_in2hid_data = b_in2hid['b_in2hid'][:].transpose()
w_in2hid_data = w_in2hid['w_in2hid'][:].transpose()
b_hid2out_data = b_hid2out['b_hid2out'][:].transpose()
w_hid2out_data = w_hid2out['w_hid2out'][:].transpose()


b_hid2hid_tensor = Tensor(b_hid2hid_data).squeeze(1)
w_hid2hid_tensor = Tensor(w_hid2hid_data)
b_in2hid_tensor = Tensor(b_in2hid_data).squeeze(1)
w_in2hid_tensor = Tensor(w_in2hid_data)
b_hid2out_tensor = Tensor(b_hid2out_data).squeeze(1)
w_hid2out_tensor = Tensor(w_hid2out_data)

# 创建一个Parameter对象
b_hid2hid_tensor_param = Parameter(b_hid2hid_tensor, name='bias2')
w_hid2hid_tensor_param = Parameter(w_hid2hid_tensor, name='weight2')

b_in2hid_tensor_param = Parameter(b_in2hid_tensor, name='bias1')
w_in2hid_tensor_param = Parameter(w_in2hid_tensor, name='weight1')

b_hid2out_tensor_param = Parameter(b_hid2out_tensor, name='bias3')
w_hid2out_tensor_param = Parameter(w_hid2out_tensor, name='weight3')


# 构建checkpoint文件

new_enc_dict = collections.OrderedDict()

new_enc_dict['linear1.weight'] = w_in2hid_tensor_param
new_enc_dict['linear1.bias'] = b_in2hid_tensor_param
new_enc_dict['linear2.weight'] = w_hid2hid_tensor_param
new_enc_dict['linear2.bias'] = b_hid2hid_tensor_param
new_enc_dict['linear3.weight'] = w_hid2out_tensor_param
new_enc_dict['linear3.bias'] = b_hid2out_tensor_param

save_checkpoint(new_enc_dict, load_path_processed+'initial_for_ms.ckpt')
