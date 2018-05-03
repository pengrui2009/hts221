#ifndef __HTS221LIB_H__
#define __HTS221LIB_H__

#define HTS_IOC_MAGIC 0xE3
 


//设置hts221数据更新速率
#define SET_HTS221_ODR		    _IO(HTS_IOC_MAGIC,  0)
//设置温度数据采集精度
#define SET_HTS221_T_RES		_IO(HTS_IOC_MAGIC,  1)
//设置湿度数据采集精度
#define SET_HTS221_H_RES		_IO(HTS_IOC_MAGIC,  2)
//设置HTS221是否为ONESHOT采集
#define SET_HTS221_ONESHOT		_IO(HTS_IOC_MAGIC,  3)
//设置HTS221是否使能加热器
#define SET_HTS221_HEATER		_IO(HTS_IOC_MAGIC,  4)
//设置HTS221是否使能
#define SET_HTS221_START		_IO(HTS_IOC_MAGIC,  5)
#endif/*__HTS221LIB_H__*/