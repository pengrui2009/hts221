/*****************************************************************************
 Copyright(C) Beijing Carsmart Technology Co., Ltd.
 All rights reserved.
 
 @file   : test_hts221.c
 @brief  : the test function of  the hts221 driver.
 		the driver of hts221 is noblock,we can read data from it at anytime.
 @author : pengrui
 @history:
           2018-05-03    pengrui    Created file
           ...
******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "hts221lib.h"
int main()
{
	int ret = 0;
	int fd = 0;

	ret = open("/dev/hts221", O_RDWR);
	if(ret < 0)
	{
		goto ERR_EXIT;
	}

	fd = ret;
	//SET oneshot mode
	ret = ioctl(fd, SET_HTS221_ODR, 0);
	if(ret < 0)
	{
		goto ERR_EXIT;
	}
	//0.03degree
	ret = ioctl(fd, SET_HTS221_T_RES, 16);
	if(ret < 0)
	{
		goto ERR_EXIT;
	}

	//0.15%RH
	ret = ioctl(fd, SET_HTS221_H_RES, 32);
	if(ret < 0)
	{
		goto ERR_EXIT;
	}

	ret = ioctl(fd, SET_HTS221_HEATER, 1);
	if(ret < 0)
	{
		goto ERR_EXIT;
	}

	ret = ioctl(fd, SET_HTS221_ENABLE, 1);
	if(ret < 0)
	{
		goto ERR_EXIT;
	}
	
	while(1)
	{
		char databuf[8];
		int *pdata;
		float data_t;
		float data_h;

		ret = read(fd, databuf, 8);
		if(ret < 8)
		{
			goto ERR_EXIT;
		}

		pdata = (int *)databuf;
		data_t = pdata[0] *0.03;
		data_h = pdata[1] *0.15;
			
		printf("Temp:%fDegree Heat:%hRH\n", data_t, data_h);

		sleep(1);
	}
ERR_EXIT:

	return ret;
}
