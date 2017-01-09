//
//  LXBluetoothDeviceOBDManager.h
//  blueTooth
//
//  Created by ifeegoo on 15/12/10.
//  Copyright © 2015年 ifeegoo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LXBluetoothDeviceFMSenderMessageType)
{
    LXBluetoothDeviceFMSenderMessageTypeInternetConnectionFailure,
    LXBluetoothDeviceFMSenderMessageTypeDeviceBatteryLow,
    LXBluetoothDeviceFMSenderMessageTypeLastSong,
    LXBluetoothDeviceFMSenderMessageTypeAlbumChangedFailure,
    LXBluetoothDeviceFMSenderMessageTypeAppConnected
};

typedef NS_ENUM(NSUInteger, LXBluetoothDeviceFMSenderAlbumStatusType)
{
    LXBluetoothDeviceFMSenderAlbumStatusTypePrevious,
    LXBluetoothDeviceFMSenderAlbumStatusTypeNext
};

@protocol LXBluetoothDeviceFMSenderManagerDelegate <NSObject>

@optional

/**
 * 设备返回的当前设备支持的频段范围。
 * @param start 频段范围的起始值。87500
 * @param end 频段范围的结束值。108000
 */
- (void)bluetoothDeviceFMSenderBandRangeWithStart:(int)start andEnd:(int)end;

/**
 * 返回当前设备的状态。
 * @param on:true:开 false:关
 * @param frequency 当前设备的频率 87500 - 108000
 */
- (void)bluetoothDeviceFMSenderDidUpdateStatusWhetherOn:(BOOL)on currentFrequency:(int)frequency;

/**
 * 车载MP3上反馈的专辑状态的变化。
 */
- (void)bluetoothDeviceFMSenderDidUpdateAlbumStatusWithType:(LXBluetoothDeviceFMSenderAlbumStatusType)type;

/*
 * 唤醒。
 */
- (void)bluetoothDeviceFMSenderDidWakeUp;

/**
 * 设备返回语音提示的状态变化。
 */
- (void)bluetoothDeviceFMSenderDidUpdateVoicePromptStatusWhetherOn:(BOOL)on;


/**
 * 是否开启设备主动发送PLAY键消息。
 */
- (void)bluetoothDeviceFMSenderDidUpdatePlayKeySendingStatusWhetherOn:(BOOL)on;


/**
 * 是否开启设备主动发送PLAY键消息。
 */
- (void)bluetoothDeviceFMSenderDidReceiveIsSupportSearchEmptyFrequency:(BOOL)support;

@end

@interface LXBluetoothDeviceFMSenderManager : NSObject


+ (LXBluetoothDeviceFMSenderManager*) sharedInstance;


/**
 * 获取当前频段范围。
 * 请在 bluetoothDeviceFMSenderBandRangeWithStart:andEnd: 方法中获取设备回调的结果。
 */
- (void)getBandRange;

/**
 * 获取当前车载MP3的状态。
 * 请在 bluetoothdeviceFMSenderDidUpdateStatusWhetherOn:currentFrequency: 方法中获取设备回调的结果。
 */
- (void)getStatus;

/**
 * 设置当前车载MP3的频率。
 * 请在 bluetoothdeviceFMSenderDidUpdateStatusWhetherOn:currentFrequency: 方法中获取设备回调的结果。
 */
- (void)setFrequency:(int)frequency;

/**
 * 打开当前车载MP3。
 * 请在 bluetoothdeviceFMSenderDidUpdateStatusWhetherOn 方法中获取设备回调的结果。
 */
- (void)turnOn;

/**
 * 关闭当前车载MP3。
 * 请在 bluetoothdeviceFMSenderDidUpdateStatusWhetherOn 方法中获取设备回调的结果。
 */
- (void)turnOff;

/**
 * APP发送消息给车载MP3。
 */
- (void)sendMessageWithType:(LXBluetoothDeviceFMSenderMessageType)type;

/**
 * 获取设备语音提醒的状态。
 */
- (void)getVoicePromptStatus;

- (void)turnOnVoicePrompt;

- (void)turnOffVoicePrompt;

/**
 * 获取播放键信息发送状态。
 */
- (void)getPlayKeySendingStatus;

- (void)turnOffPlayKeySending;

- (void)turnOnPlayKeySending;


/**
 查询是否支持搜索空频点
 */
- (void)getIsSupportSearchEmptyFrequency;

/**
 搜索附近空频点
 */
- (void)searchEmptyFrequency;

@end
