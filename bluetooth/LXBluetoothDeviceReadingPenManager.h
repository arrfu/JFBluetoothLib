//
//  CGBluetoothDeviceReadingPenManager.h
//  blueTooth
//
//  Created by duluyang on 15/5/19.
//  Copyright (c) 2015年 duluyang. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SLBluetoothDeviceReadingPenDelegate <NSObject>

@required
/**
 *  SLBluetoothDeviceReadingPenDelegate 代理方法 获取点读笔的码值
 *
 *  @param value 返回的码值
 */
- (void)SLvalueOfBook:(int)value;


/**
 * 通过getReadingTime获取的时间返回。
 *
 * @param minute 返回的分钟数。
 */
- (void)onBluetoothDeviceReadingPenReadingTime:(int)minute;

@end


@interface LXBluetoothDeviceReadingPenManager : NSObject

- (void)getReadingTime;

@end
