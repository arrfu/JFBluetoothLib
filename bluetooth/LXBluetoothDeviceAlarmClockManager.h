//
//  CGBluetoothDeviceAlarmClockManager.h
//  blueTooth
//
//  Created by ifeegoo on 15/9/10.
//  Copyright (c) 2015年 duluyang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import"LXBluetoothDeviceAlarmManager.h"
//闹钟重复周期
typedef NS_OPTIONS(NSUInteger,CGBluetoothDeviceAlarmClockRepetition)
{
    CGBluetoothDeviceAlarmClockSunday = 1 , //星期日
    CGBluetoothDeviceAlarmClockMonday =1<<1 , //星期一
    CGBluetoothDeviceAlarmClockTuesday =1<<2 , //星期二
    CGBluetoothDeviceAlarmClockWednesday =1<<3, //星期三
    CGBluetoothDeviceAlarmClockThursday =1<<4, //星期四
    CGBluetoothDeviceAlarmClockFriday =1<<5, //星期五
    CGBluetoothDeviceAlarmClockSaturday =1<<6   //星期六
};


typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockBluetoothConnectionMode)
{
    /**
     * 蓝牙自动连接模式。
     */
    CGBluetoothDeviceAlarmClockBluetoothConnectionModeAuto = 1,
    
    /**
     * 蓝牙手动连接模式。
     */
    CGBluetoothDeviceAlarmClockBluetoothConnectionModeManual = 2
};

typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockMode)
{
    /**
     * 增强模式。
     */
    CGBluetoothDeviceAlarmClockModeEnhancement = 1,
    
    /**
     * 标准模式。
     */
    CGBluetoothDeviceAlarmClockModeStandard
};

/**
 * 蓝牙闹钟IOT键功能。
 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockIOTKeyFunction)
{
    /**
     * 蓝牙闹钟IOT键功能：没有设置设备功能。
     */
    CGBluetoothDeviceAlarmClockIOTKeyFunctionNone,
    
    /**
     * 蓝牙闹钟IOT键功能：FM开关。
     */
    CGBluetoothDeviceAlarmClockIOTKeyFunctionOnOffFM,
    
    /**
     * 蓝牙闹钟IOT键功能：小睡模式。
     */
    CGBluetoothDeviceAlarmClockIOTKeyFunctionModeSnooze,
    
    /**
     * 蓝牙闹钟IOT键功能：睡眠模式。
     */
    CGBluetoothDeviceAlarmClockIOTKeyFunctionModeSleep,
    
    /**
     * 蓝牙闹钟IOT键功能：白灯开关。
     */
    CGBluetoothDeviceAlarmClockIOTKeyFunctionOnOffLampWhite,
    
    /**
     * 蓝牙闹钟IOT键功能：彩灯开关附带灯效。
     */
    CGBluetoothDeviceAlarmClockIOTKeyFunctionOnOffLampColorWithEffect,
    
    /**
     * 蓝牙闹钟IOT键功能：彩灯开关附带RGB。
     */
    CGBluetoothDeviceAlarmClockIOTKeyFunctionOnOffLampColorWithRGB,
    
    /**
     * 蓝牙闹钟IOT键功能：休息模式：关闭白光灯、RGB灯，时钟调整到最暗。
     */
    CGBluetoothDeviceAlarmClockIOTKeyFunctionSleep
};

/**
 * 立即触发的蓝牙闹钟类型。
 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockRingReturnMode)
{
    CGBluetoothDeviceAlarmClockRingReturnModeNone = 0,
    /**
     * FM资源
     */
    CGBluetoothDeviceAlarmClockRingReturnModeTypeFM = 1,
    
    /**
     * 内置铃声资源
     */
    CGBluetoothDeviceAlarmClockRingReturnModeTypeInteralRingSource
};


/**
 * 立即触发的蓝牙闹钟类型。
 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockRingRightNowSourceType)
{
    /**
     * FM资源
     */
    CGBluetoothDeviceAlarmClockRingRightNowSourceTypeFM = 1,
    
    /**
     * 内置铃声资源
     */
    CGBluetoothDeviceAlarmClockRingRightNowSourceTypeInteralRingSource
};

/**
 * 蓝牙闹钟时间类型。
 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockTimeType)
{
    /**
     * 蓝牙闹钟时间类型：12小时制。
     */
    CGBluetoothDeviceAlarmClockSleepModeTimeTypeHourTwelve,
    
    /**
     * 蓝牙闹钟时间类型：24小时制。
     */
    CGBluetoothDeviceAlarmClockSleepModeTimeTypeHourTwentyFour,
};

/**
 * 蓝牙闹钟睡眠模式时间级别。
 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockSleepModeTimeLevel)
{
    /**
     * 蓝牙闹钟睡眠模式时间级别0。
     * 说明：0表示当前不处于睡眠模式。如果你想直接退出当前的睡眠模式，你可以直接传这个值。
     */
    CGBluetoothDeviceAlarmClockSleepModeTimeLevelZero,
    
    /**
     * 蓝牙闹钟睡眠模式时间级别1。
     * 说明：级别1只是一次递增过程，如果你想要知道当前的具体时间，需要通过时间间隔来结合级数自己计算。
     */
    CGBluetoothDeviceAlarmClockSleepModeTimeLevelOne,
    
    /**
     * 蓝牙闹钟睡眠模式时间级别2。
     * 说明：级别1只是一次递增过程，如果你想要知道当前的具体时间，需要通过时间间隔来结合级数自己计算。
     */
    CGBluetoothDeviceAlarmClockSleepModeTimeLevelTwo,
    
    /**
     * 蓝牙闹钟睡眠模式时间级别3。
     * 说明：级别1只是一次递增过程，如果你想要知道当前的具体时间，需要通过时间间隔来结合级数自己计算。
     */
    CGBluetoothDeviceAlarmClockSleepModeTimeLevelThree,
    
    /**
     * 蓝牙闹钟睡眠模式时间级别4。
     * 说明：级别1只是一次递增过程，如果你想要知道当前的具体时间，需要通过时间间隔来结合级数自己计算。
     */
    CGBluetoothDeviceAlarmClockSleepModeTimeLevelFour
};

/**
 * 蓝牙闹钟小睡模式时间级别。
 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockSnoozeModeTimeLevel)
{
    /**
     * 蓝牙闹钟小睡模式时间级别0。
     * 说明：0表示当前不处于睡眠模式。如果你想直接退出当前的小睡模式，你可以直接传这个值。
     */
    CGBluetoothDeviceAlarmClockSnoozeModeTimeLevelZero,
    
    /**
     * 蓝牙闹钟小睡模式时间级别1。
     * 说明：级别1只是一次递增过程，如果你想要知道当前的具体时间，需要通过时间间隔来结合级数自己计算。
     */
    CGBluetoothDeviceAlarmClockSnoozeModeTimeLevelOne,
    
    /**
     * 蓝牙闹钟小睡模式时间级别2。
     * 说明：级别1只是一次递增过程，如果你想要知道当前的具体时间，需要通过时间间隔来结合级数自己计算。
     */
    CGBluetoothDeviceAlarmClockSnoozeModeTimeLevelTwo,
    
    /**
     * 蓝牙闹钟小睡模式时间级别3。
     * 说明：级别1只是一次递增过程，如果你想要知道当前的具体时间，需要通过时间间隔来结合级数自己计算。
     */
    CGBluetoothDeviceAlarmClockSnoozeModeTimeLevelThree,
    
    /**
     * 蓝牙闹钟小睡模式时间级别4。
     * 说明：级别1只是一次递增过程，如果你想要知道当前的具体时间，需要通过时间间隔来结合级数自己计算。
     */
    CGBluetoothDeviceAlarmClockSnoozeModeTimeLevelFour
};

/**
 * 蓝牙闹钟IOT键事件。
 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockIOTKeyEvent)
{
    /**
     * 蓝牙闹钟IOT键事件：单击。
     */
    CGBluetoothDeviceAlarmClockIOTKeyEventClickSingle = 1,
    
    /**
     * 蓝牙闹钟IOT键事件：双击。
     */
    CGBluetoothDeviceAlarmClockIOTKeyEventClickDouble = 2,
    
    /**
     * 蓝牙闹钟IOT键事件：长按。
     */
    CGBluetoothDeviceAlarmClockIOTKeyEventClickLong = 3,
    
    /**
     * 蓝牙闹钟IOT键事件：弹起。
     */
    CGBluetoothDeviceAlarmClockIOTKeyEventUp = 4,
    
    /**
     * 蓝牙闹钟IOT键事件：压下。
     */
    CGBluetoothDeviceAlarmClockIOTKeyEventDown = 5
};

/**
 * 蓝牙闹钟自定义功能。原来的功能的自带的功能还是用之前的。
 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceAlarmClockAlarmWithCustomFunction)
{
    CGBluetoothDeviceAlarmUhost = 0,
    CGBluetoothDeviceAlarmCard = 1,
    CGBluetoothDeviceAlarmFM = 2,
    CGBluetoothDeviceAlarmInternal = 3,
    CGBluetoothDeviceAlarmExternal1  = 4,
    CGBluetoothDeviceAlarmExternal2  = 5,
    CGBluetoothDeviceAlarmExternal3  = 6,
    CGBluetoothDeviceAlarmExternal4  = 7,
    CGBluetoothDeviceAlarmSource_count = 8,
    /**
     * 蓝牙闹钟没有附带功能。
     */
    CGBluetoothDeviceAlarmClockAlarmWithCustomFunctionNone = 100,
    
    /**
     * 蓝牙闹钟附带触发iOS设备上的歌曲播放。
     */
    CGBluetoothDeviceAlarmClockAlarmWithCustomFunctionPlayMusic = 101,
    
    /**
     * 蓝牙闹钟附带静音功能。
     */
    CGBluetoothDeviceAlarmClockAlarmWithCustomFunctionMute = 102
};

/**
 * 蓝牙闹钟管理器代理。
 */
@protocol CGBluetoothDeviceAlarmClockManagerDelegate <NSObject>

@optional

//发送提前通知时候的回调
-(void)onBluetoothDeviceAlarmClockNoticeTimeAheadOfAlarmTimeChanged:(NSInteger)index hour:(NSInteger)hour minute:(NSInteger)minute Repetition:(NSMutableArray*)repetition success:(BOOL)success;

//提前通知
-(void)onBluetoothDeviceAlarmClockNotice:(NSInteger)index hour:(NSInteger)hour minute:(NSInteger)minute Repetition:(NSMutableArray*)repetition;

/**
 * 开机时白灯的最大亮度值。
 * 备注：查询和控制的时候，都从这里获取设备返回的结果。
 *
 * @param maxBrightness 开机时白灯的最大亮度值。
 */
- (void)onBluetoothDeviceAlarmClockMaxBrightnessWhiteLampTurnedOnChanged:(NSUInteger)maxBrightness;

/**
 * 频幕亮度变化。
 * 备注：查询和控制的时候，都从这里获取设备返回的结果。
 *
 * @param brightness 频幕亮度。
 */
- (void)onBluetoothDeviceAlarmClockScreenBrightnessChanged:(NSUInteger)brightness;

/**
 * 蓝牙闹钟的时间显示是12小时制还是24小时制。
 * 备注：查询和控制的时候，都从这里获取设备返回的结果。
 *
 * @param timeType 开机时白灯的最大亮度值。
 */
- (void)onBluetoothDeviceAlarmClockTimeTypeChanged:(CGBluetoothDeviceAlarmClockTimeType)timeType;

/**
 * 睡眠模式时间级别。
 * 备注：查询和控制的时候，都从这里获取设备返回的结果。
 *
 * @param timeLevel 睡眠模式时间级别。
 */
- (void)onBluetoothDeviceAlarmClockSleepModeTimeLevelChanged:(CGBluetoothDeviceAlarmClockSleepModeTimeLevel)timeLevel;

/**
 * 睡眠模式时间间隔。
 * 备注：查询和控制的时候，都从这里获取设备返回的结果。
 *
 * @param timeInterval 睡眠模式时间间隔。
 */
- (void)onBluetoothDeviceAlarmClockSleepModeTimeIntervalChanged:(NSUInteger)timeInterval;

/**
 * 小睡模式时间级别。
 * 备注：查询和控制的时候，都从这里获取设备返回的结果。
 *
 * @param timeLevel 小睡模式时间级别。
 */
- (void)onBluetoothDeviceAlarmClockSnoozeModeTimeLevelChanged:(CGBluetoothDeviceAlarmClockSnoozeModeTimeLevel)timeLevel;

/**
 * 小睡模式时间间隔。
 * 备注：查询和控制的时候，都从这里获取设备返回的结果。
 *
 * @param timeInterval 小睡模式时间间隔。
 */
- (void)onBluetoothDeviceAlarmClockSnoozeModeTimeIntervalChanged:(NSUInteger)timeInterval;

/**
 * 睡眠模式状态变化。
 *
 * @param sleepModeStatus TRUE：睡眠模式计时开始。FALSE：睡眠模式计时结束。
 */
- (void)onBluetoothDeviceAlarmClockSleepModeStatusChanged:(Boolean)sleepModeStatus;

/**
 * 小睡模式状态变化。
 *
 * @param snoozeModeStatus TRUE：小睡模式计时开始。FALSE：小睡模式计时结束。
 */
- (void)onBluetoothDeviceAlarmClockSnoozeModeStatusChanged:(Boolean)snoozeModeStatus;

/**
 * IOT键按键事件变化。
 * 备注：这个回调方法只有在这个IOT键的某一按键事件没有设置成控制设备功能的前提下，设备上按键来触发这个方法。
 *
 * @param keyNumber IOT键的编号：1、2、3、4(按下、弹起：手机槽的那个按键)。
 * @param iotKeyEvent IOT键按键事件：单击，双击，长按，按下，弹起。
 */
- (void)onBluetoothDeviceAlarmClockIOTKeyEventChanged:(NSUInteger)keyNumber :(CGBluetoothDeviceAlarmClockIOTKeyEvent)iotKeyEvent;

/**
 * IOT键按键事件变化。
 * 备注：这个回调方法只有在这个IOT键的某一按键事件有设成控制设备功能的前提下，才会回调。同时，如果你想要查询IOT键赋予的功能，如果没有被设置成设备控制的功能，依然是回调到这个地方。
 *
 * @param keyNumber IOT键的编号：1、2、3，4。
 * @param iotKeyEvent IOT键按键事件：单击，双击，长按，按下，弹起。
 * @param iotKeyFunction IOT键功能：CGBluetoothDeviceAlarmClockIOTKeyFunction。
 * @param functionSpecification IOT键功能描述。
 */
- (void)onBluetoothDeviceAlarmClockIOTKeyFunctionChanged:(NSUInteger)keyNumber :(CGBluetoothDeviceAlarmClockIOTKeyEvent)iotKeyEvent :(CGBluetoothDeviceAlarmClockIOTKeyFunction)iotKeyFunction :(NSArray*)functionSpecification;

/**
 * 蓝牙闹钟的贪睡时间。
 * 备注：无论是查询还是设置，都走这个回调。
 *
 * @param snoozeTime 贪睡时间。单位：分钟。
 */
- (void)onBluetoothDeviceAlarmClockAlarmSnoozeTimeChanged:(NSUInteger)snoozeTime;

/**
 * 蓝牙闹钟附带自定义功能。
 * 备注：无论是查询还是设置，都走这个回调。
 *
 * @param alarmIndex 闹钟索引。
 * @param customFunction 自定义功能。
 */
- (void)onBluetoothDeviceAlarmClockAlarmCustomFunctionChanged:(NSUInteger)alarmIndex :(CGBluetoothDeviceAlarmClockAlarmWithCustomFunction) customFunction;

/**
 *
 * @param alarmIndex 闹钟索引。
 * @param customFunction 自定义功能消息
 */
- (void)onBluetoothDeviceAlarmClockAlarmRinging:(NSUInteger)alarmIndex :(CGBluetoothDeviceAlarmClockAlarmWithCustomFunction) customFunction;

/**
 * 蓝牙闹钟附带提前开启白灯。
 * 备注：无论是查询还是设置，都走这个回调。
 *
 * @param alarmIndex 闹钟索引。
 * @param minutesAheadOfTime 提前的分钟数。如果是0，就是没有此功能，或者取消了此功能。
 */
- (void)onBluetoothDeviceAlarmClockAlarmWithWhiteLampOnAheadOfTime:(NSUInteger)alarmIndex : (NSUInteger)minutesAheadOfTime;

/**
 * 蓝牙闹钟的默认FM频道变化。
 * 备注：无论是查询还是设置，都走这个回调。
 *
 * @param channel FM默认频道。
 */
- (void)onBluetoothDeviceAlarmClockFMDefaultChannelChanged:(int)channel;

/**
 * 蓝牙闹钟的模式变化。
 * 备注：无论是查询还是设置，都走这个回调。
 *
 * @param mode 模式。
 */
- (void)onBluetoothDeviceAlarmClockModeChanged:(CGBluetoothDeviceAlarmClockMode)mode;

/**
 * 蓝牙连接的模式变化。
 * 备注：无论是查询还是设置，都走这个回调。
 *
 * @param mode 模式。
 */
- (void)onBluetoothDeviceAlarmClockModeBluetoothConnectionChanged:(CGBluetoothDeviceAlarmClockBluetoothConnectionMode)mode;

/**
 * 蓝牙闹钟的音量。
 * 备注：无论是查询还是设置，都走这个回调。
 *
 * @param alarmVolume 闹钟音量。
 */
- (void)onBluetoothDeviceAlarmClockAlarmVolumeChanged:(int)alarmVolume;

/**
 * 立即触发闹钟的设备返回的结果。
 * @param ringSourceType 闹钟铃声类型。
 * @param ringSourceIndex 闹钟索引。闹钟类型为FM的时候，此处为87500格式。闹钟铃声为内置铃声时，为1/2/3/4/5.
 */
- (void)onBluetoothDeviceAlarmClockAlarmRingingRightNow:(CGBluetoothDeviceAlarmClockRingRightNowSourceType) ringSourceType ringSourceIndex:(int)param;

/**
 * 多少秒之后关闭闹钟事件的触发。
 *
 * @param seconds N秒之后关闭闹钟。
 */
- (void)onBluetoothDeviceAlarmClockAlarmRingTurnedOffTimeChanged:(int)seconds;

- (void)onBluetoothDeviceAlarmClockAlarmRingReturnModeChanged:(CGBluetoothDeviceAlarmClockRingReturnMode) ringSourceType ringSourceIndex:(int)param;

@end

/**
 *  蓝牙闹钟设备管理类。
 *  备注：用来管理蓝牙闹钟类设备的新增自定义功能。
 */
@interface LXBluetoothDeviceAlarmClockManager : NSObject

- (void)getAlarmRingReturnMode;

- (void)setAlarmRingReturnMode:(CGBluetoothDeviceAlarmClockRingRightNowSourceType) ringSourceType ringSourceIndex:(int)param;

/**
 * 获取已经设置的多少秒之后关闭闹钟。0为不自动关闭。
 * 请在 onBluetoothDeviceAlarmClockAlarmRingTurnedOffTimeChanged 中获取设备返回的结果。
 */
- (void)getAlarmRingTurnedOffTime;

/**
 * 设置的多少秒之后关闭闹钟。0为不自动关闭。
 * 请在 onBluetoothDeviceAlarmClockAlarmRingTurnedOffTimeChanged 中获取设备返回的结果。
 */
- (void)setAlarmRingTurnedOffTime:(int)seconds;

/**
 * 立即触发闹钟。
 * 请在：onBluetoothDeviceAlarmClockAlarmRingingRightNow中获取设备返回的结果。
 * @param ringSourceType 闹钟铃声类型。
 * @param ringSourceIndex 闹钟索引。闹钟类型为FM的时候，此处为87500格式。闹钟铃声为内置铃声时，为1/2/3/4/5.
 */
- (void)enableAlarmRightNowWithRingSourceType:(CGBluetoothDeviceAlarmClockRingRightNowSourceType) ringSourceType ringSourceIndex:(int)param;

/**
 * 设置FM默认的频道。87.5MHz,channel = 87500
 * @param channel FM默认频道。
 */
- (void)setFMDefaultChannel:(int)channel;

/**
 * 获取设置好的FM默认的频道。
 * 请在：onBluetoothDeviceAlarmClockFMDefaultChannelChanged 获取设备返回的结果。
 **/
- (void)getFMDefaultChannel;

/**
 * 获取蓝牙闹钟的音量。
 * 请在 onBluetoothDeviceAlarmClockAlarmVolumeChanged 获取设备返回的结果。
 */
- (void)getAlarmVolume;

/**
 * 设置蓝牙闹钟的音量。
 * 请在 onBluetoothDeviceAlarmClockAlarmVolumeChanged 获取设备返回的结果。
 */
- (void)setAlarmVolume:(int)alarmVolume;

/**
 * 获取蓝牙连接的模式。
 * 请在 onBluetoothDeviceAlarmClockModeBluetoothConnectionChanged 获取设备返回的结果。
 */
- (void)getBluetoothConnectionMode;

/**
 * 设置蓝牙连接的模式。
 * 请在 onBluetoothDeviceAlarmClockModeBluetoothConnectionChanged 获取设备返回的结果。
 */
- (void)setBluetoothConnectionMode:(CGBluetoothDeviceAlarmClockBluetoothConnectionMode)mode;



/**
 * 获取蓝牙闹钟的模式。
 * 请在 onBluetoothDeviceAlarmClockModeChanged 获取设备返回的结果。
 */
- (void)getMode;

/**
 * 设置蓝牙闹钟的模式。
 * 请在 onBluetoothDeviceAlarmClockModeChanged 获取设备返回的结果。
 */
- (void)setMode:(CGBluetoothDeviceAlarmClockMode)mode;

/**
 * 查询屏保亮度。
 * 说明：请在 onBluetoothDeviceAlarmClockScreenBrightnessChanged 方法中获取设备返回的结果。
 */
- (void)getScreenBrightness;

/**
 * 设置屏幕的亮度。
 * 说明：请在 onBluetoothDeviceAlarmClockScreenBrightnessChanged 方法中获取设备返回的结果。
 *
 * @param brightness 亮度。
 */
- (void)setScreenBrightness:(NSUInteger)brightness;

/**
 * 查询设置的开机时白灯的最大亮度值。
 * 说明：请在 onBluetoothDeviceAlarmClockMaxBrightnessWhiteLampTurnedOnChanged 方法中获取设备返回的结果。
 *
 */
- (void)getMaxBrightnessWhiteLampTurnedOn;

/**
 * 设置的开机时白灯的最大亮度值。
 * 说明：请在 onBluetoothDeviceAlarmClockMaxBrightnessWhiteLampTurnedOnChanged 方法中获取设备返回的结果。
 *
 * @param maxBrightness 开机时白灯的最大亮度值。
 */
- (void)setMaxBrightnessWhiteLampTurnedOn:(NSUInteger)maxBrightness;

/**
 * 查询当前时间显示是12小时制还是24小时制。
 * 说明：请在 onBluetoothDeviceAlarmClockTimeTypeChanged 方法中获取设备返回的结果。
 *
 */
- (void)getTimeType;

/**
 * 设置当前时间显示是12小时制还是24小时制。
 * 说明：请在 onBluetoothDeviceAlarmClockMaxBrightnessWhiteLampTurnedOnChanged 方法中获取设备返回的结果。
 *
 * @param timeType 枚举：CGBluetoothDeviceAlarmClockTimeType。12小时制还是24小时制。
 */
- (void)setTimeType:(CGBluetoothDeviceAlarmClockTimeType)timeType;

/**
 * 查询当前睡眠模式时间级别。
 * 说明：请在 onBluetoothDeviceAlarmClockSleepModeTimeLevelChanged 方法中获取设备返回的结果。
 *
 */
- (void)getSleepModeTimeLevel;

/**
 * 查询IOT键自定义功能。
 *
 */
- (void)getIOTKeyCustomFucntion:(NSUInteger)keyNumber keyEvent:(CGBluetoothDeviceAlarmClockIOTKeyEvent)keyEvent;

/**
 * @keyFuntionSpecification 这个是附带功能说明：
 * 1.CGBluetoothDeviceAlarmClockIOTKeyFunctionNone
 * 2.CGBluetoothDeviceAlarmClockIOTKeyFunctionOnOffFM
 * 3.CGBluetoothDeviceAlarmClockIOTKeyFunctionModeSnooze
 * 4.CGBluetoothDeviceAlarmClockIOTKeyFunctionModeSleep
 * 以上功能：此参数传递 nil。
 * 5.CGBluetoothDeviceAlarmClockIOTKeyFunctionOnOffLampWhite "NSNumber ＝ 白灯的亮度"
 * 6.CGBluetoothDeviceAlarmClockIOTKeyFunctionOnOffLampColorWithEffect "NSNumber = CGBluetoothDeviceColorLampEffect"
 * 以上功能：此处参数 NSArray 中附带一个 NSNumber.
 * 7.CGBluetoothDeviceAlarmClockIOTKeyFunctionOnOffLampColorWithRGB
 * 以上功能：此处参数 NSArray 中附带3个 NSNumber 来表示R/G/B。
 */
- (void)setIOTKeyCustomFunctionWithKeyNumber:(NSUInteger)keyNumber keyEvent:(CGBluetoothDeviceAlarmClockIOTKeyEvent)keyEvent keyFunction:(CGBluetoothDeviceAlarmClockIOTKeyFunction)iotKeyFunction keyFunctionSpecification:(NSArray*)keyFuntionSpecification;

/**
 * 设置当前睡眠模式时间级别。
 * 说明：请在 onBluetoothDeviceAlarmClockSleepModeTimeLevelChanged 方法中获取设备返回的结果。
 * 备注：这个地方调用者可能有疑惑，为什么没有一个进入或退出模式的方法。这个方法设置的思路是依据设备按键递增事件来考虑的。
 *
 * @param timeLevel 枚举：CGBluetoothDeviceAlarmClockSleepModeTimeLevel。睡眠模式时间级别。
 */
- (void)setSleepModeTimeLevel:(CGBluetoothDeviceAlarmClockSleepModeTimeLevel)timeLevel;

/**
 * 查询当前睡眠模式时间间隔。
 * 说明：请在 onBluetoothDeviceAlarmClockSleepModeTimeIntervalChanged 方法中获取设备返回的结果。
 * 备注：默认的时间间隔是15min。
 */
- (void)getSleepModeTimeInterval;

/**
 * 设置当前睡眠模式时间间隔。
 * 说明：请在 onBluetoothDeviceAlarmClockSleepModeTimeIntervalChanged 方法中获取设备返回的结果。
 * 备注：这个地方调用者可能有疑惑，为什么没有一个进入或退出模式的方法。这个方法设置的思路是依据设备按键递增事件来考虑的。
 *
 * @param timeInterval 枚举：onBluetoothDeviceAlarmClockSleepModeTimeIntervalChanged。睡眠模式时间间隔。
 */
- (void)setSleepModeTimeInterval:(NSUInteger)timeInterval;

/**
 * 查询当前小睡模式时间级别。
 * 说明：请在 onBluetoothDeviceAlarmClockSnoozeModeTimeLevelChanged 方法中获取设备返回的结果。
 *
 */
- (void)getSnoozeModeTimeLevel;

/**
 * 设置当前小睡模式时间级别。
 * 说明：请在 onBluetoothDeviceAlarmClockSnoozeModeTimeLevelChanged 方法中获取设备返回的结果。
 * 备注：这个地方调用者可能有疑惑，为什么没有一个进入或退出模式的方法。这个方法设置的思路是依据设备按键递增事件来考虑的。
 *
 * @param timeLevel 枚举：CGBluetoothDeviceAlarmClockSnoozeModeTimeLevel。小睡模式时间级别。
 */
- (void)setSnoozeModeTimeLevel:(CGBluetoothDeviceAlarmClockSnoozeModeTimeLevel)timeLevel;

/**
 * 查询当前小睡模式时间间隔。
 * 说明：请在 onBluetoothDeviceAlarmClockSnoozeModeTimeIntervalChanged 方法中获取设备返回的结果。
 * 备注：默认的时间间隔是15min。
 */
- (void)getSnoozeModeTimeInterval;

/**
 * 设置当前小睡模式时间间隔。
 * 说明：请在 onBluetoothDeviceAlarmClockSnoozeModeTimeIntervalChanged 方法中获取设备返回的结果。
 * 备注：这个地方调用者可能有疑惑，为什么没有一个进入或退出模式的方法。这个方法设置的思路是依据设备按键递增事件来考虑的。
 *
 * @param timeInterval 枚举：onBluetoothDeviceAlarmClockSnoozeModeTimeIntervalChanged。小睡模式时间间隔。
 */
- (void)setSnoozeModeTimeInterval:(NSUInteger)timeInterval;

/**
 * 查询当前闹钟的贪睡时间。
 * 说明：请在 onBluetoothDeviceAlarmClockAlarmSnoozeTimeChanged 方法中获取设备返回的结果。
 */
- (void)getAlarmSnoozeTime;

/**
 * 设置当前闹钟的贪睡时间。
 * 说明：请在 onBluetoothDeviceAlarmClockAlarmSnoozeTimeChanged 方法中获取设备返回的结果。
 *
 * @param snoozeTime 闹钟的贪睡时间，单位：分钟。
 */
- (void)setAlarmSnoozeTime:(NSUInteger)snoozeTime;

/**
 * 通过闹钟的索引查询此闹钟对应的自定义功能。
 * 说明：请在 onBluetoothDeviceAlarmClockAlarmCustomFunctionChanged 中获取设备返回的结果。
 *
 * @param alarmIndex 闹钟索引。
 */
- (void)getAlarmWithCustomFunctionStatusWithAlarmIndex:(NSUInteger)alarmIndex;

/**
 * 通过闹钟的索引设置此闹钟对应的自定义功能。
 * 说明：请在 onBluetoothDeviceAlarmClockAlarmCustomFunctionChanged 中获取设备返回的结果。
 * ******设置自定义与非自定义闹钟铃声的的时候，在调用炬力的设置接口之后，也还需要调用这个设置接口*******
 * @param alarmIndex 闹钟索引。
 * @param customFunction 自定义功能。
 */
- (void)setAlarmWithCustomFunctionWithAlarmIndex:(NSUInteger)alarmIndex customFunction:(CGBluetoothDeviceAlarmClockAlarmWithCustomFunction)customFunction;

/**
 * 通过闹钟的索引查询此闹钟对应的提前亮白灯的分钟数。
 * 说明：请在 onBluetoothDeviceAlarmClockAlarmWithWhiteLampOnAheadOfTime 中获取设备返回的结果。
 *
 * @param alarmIndex 闹钟索引。
 */
- (void)getAlarmWithWhiteLampOnAheadOfTimeStatusWithAlarmIndex:(NSUInteger)alarmIndex;

/**
 * 通过闹钟的索引设置此闹钟对应的提前亮白灯的分钟数。
 * 说明：请在 onBluetoothDeviceAlarmClockAlarmCustomFunctionChanged 中获取设备返回的结果。
 *
 * @param alarmIndex 闹钟索引。
 * @param minutes 提前亮白灯的分钟数，如果是0就是取消这个功能。
 */
- (void)setAlarmWithWhiteLampOnAheadOfTimeWithAlarmIndex:(NSUInteger)alarmIndex minutesAheadOfTime:(NSUInteger)minutes;

// 设置闹钟提前提醒
+(void)setNoticeTimeAheadOfAlarmTime:(NSInteger)index hour:(NSInteger)hour minute:(NSInteger)minute Repetition:(NSArray*)repetition;

@end
