#ifndef __HTS221LIB_H__
#define __HTS221LIB_H__

#ifdef __KERNEL__
#include <linux/ioctl.h>
#else
#include <sys/ioctl.h>
#endif

#define HTS_IOC_MAGIC 0xE3

//set the out data rate
/*
  0    --- one-shot
  80  --- 12.5Hz
  143 --- 7Hz
  1000--- 1Hz
  default:0
  */
#define SET_HTS221_ODR		    _IO(HTS_IOC_MAGIC,  0)
//set the resolution of temperature
/*2  --- 0.08degree
   4  ---  0.05degree
   8  ---  0.04degree
   16---  0.03degree
   32 --- 0.02degree
   64 --- 0.015degree
   128 -- 0.01degree
   256 -- 0.007degree
   default:16
 */
#define SET_HTS221_T_RES		_IO(HTS_IOC_MAGIC,  1)
//set the resolution of humidity
/*
    4 ---- 0.4%RH
    8 ---- 0.3%RH
    16 --- 0.2%RH
    32 --- 0.15%RH
    64 --- 0.1%RH
    128 -- 0.07%RH
    256 -- 0.05%RH
    512 -- 0.03%RH
    default:32
  */
#define SET_HTS221_H_RES		_IO(HTS_IOC_MAGIC,  2)
//
#define SET_HTS221_HEATER		_IO(HTS_IOC_MAGIC,  3)
//0:power off 1:power on
#define SET_HTS221_ENABLE		_IO(HTS_IOC_MAGIC,  4)

#endif/*__HTS221LIB_H__*/