//
//  CGSoundBoxManager.h
//  blueTooth
//
//  Created by duluyang on 15/6/16.
//  Copyright (c) 2015年 duluyang. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CGBluetoothDeviceSoundBoxDeviceScene)
{
    CGBluetoothDeviceSoundBoxDeviceSceneMusic = 1,
    CGBluetoothDeviceSoundBoxDeviceSceneTheater
};


@protocol CGSoundBoxDelegate <NSObject>

@optional
/**
 *   查询方法回调代理
 *
 *  @param state      灯效状态
 *  @param value      灯效开关 1/2 开关
 *  @param effect     所处灯效 1、2、3、4、5
 *  @param brightness 灯效亮度 1-N
 */
- (void)CGSelectSoundBoxEffectState:(int)state withSwitch:(int)value effect:(int)effect brightness:(int)brightness;
/**
 *  控制方法回调代理
 *
 *  @param state      灯效状态
 *  @param value      灯效开关 1/2 开关
 *  @param effect     所处灯效 1、2、3、4、5
 *  @param brightness 灯效亮度 1-N
 */
- (void)CGControlSoundBoxEffectState:(int)state withSwitch:(int)value effect:(int)effect brightness:(int)brightness;


/**
 *  查询是否有喜爱列表
 *
 *  @param state      1有，2无
 *  @param indexarray  喜爱列表的索引
 */
- (void)CGselectLoveState:(int)state indexArray:(NSArray*)indexarray;


/**
 *  添加喜爱，取消喜爱回调方法
 *
 *  @param love      1喜爱，2取消
 *  @param value  1成功，2失败
 *  @param index  音乐序号
 */
- (void)CGcontrolAddloveSong:(int)love success:(int)value index:(int)index;

/**
 * 设备场景变化的回调方法。
 * 备注：无论是查询还是控制，都是从这里返回结果的。
 *
 * @param success 进入场景是否成功。True:成功。False:失败。
 * @param deviceScene 设备场景。
 */
- (void)onBluetoothDeviceSoundBoxDeviceSceneStatusChanged:(Boolean)success scene:(CGBluetoothDeviceSoundBoxDeviceScene)deviceScene;

@end



@interface LXBluetoothDeviceSoundBoxManager : NSObject

/**
 *   查询音箱，灯效状态、灯效开关、所处灯效、灯效亮度
 */
- (void)selectSoundBoxEffect;

/**
 *  控制灯效开关
 *
 *  @param value 1开，2关
 */
- (void)controlLightTurnOnOff:(int)value;
/**
 *  控制灯效
 *
 *  @param value 1、2、3、4、5
 */
- (void)controlLightEffect:(int)value;
/**
 *  控制灯亮度
 *
 *  @param value 1、2、3、4
 */
- (void)controlBrightness:(int)value;

/**
 *  查询是否有喜爱列表
 */
- (void)selectLoveSong;


/**
 *  添加喜爱歌曲
 *
 *  @param value 1喜爱，2取消喜爱
 *  @param index 歌曲序列号
 */
- (void)addLove:(int)value index:(int)index;

- (void)setDeviceScene:(CGBluetoothDeviceSoundBoxDeviceScene)deviceScene;

- (void)getDeviceSceneStatus;

@end
