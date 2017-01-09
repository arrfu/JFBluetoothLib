//
//  LXBluetoothDevicePiggyBankManager.h
//  LXBluetoothDemo
//
//  Created by 李宏远 on 16/9/19.
//  Copyright © 2016年 李宏远. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 设备存款类型
 */
typedef enum {
    LXPiggyBankMoneyDeposit = 1, // 存入
    LXPiggyBankMoneyOut = 2, // 取出
    LXPiggyBankMoneySingleToWhole = 3, // 零转整
    LXPiggyBankMoneySCustom = 4 // 正常设置
    
}PiggyBankMoneyType;


/**
 灯光状态
 */
typedef enum {
    LXPiggyBankLightStateClose = 0, // 关闭
    LXPiggyBankLightStateOpen = 1, // 打开
   // LXPiggyBankLightStateBlink = 2, // 闪烁
    
}PiggyBankLightState;


@protocol LXBluetoothDevicePiggyBankDelegate <NSObject>
@optional


- (void)bluetoothDevicePiggerBankMoneyDidChangedWithRealMoney:(float)real totalMoney:(float)total;

// 查询灯光状态 和震动传感器开关共用
- (void)bluetoothDevicePiggerBankLightStateFadeback:(PiggyBankLightState)lightState shakeSensorSwitchOn:(BOOL)on;

- (void)bluetoothDevicePiggerBankVerificationCode:(Byte[])verificationCode;


@end

@interface LXBluetoothDevicePiggyBankManager : NSObject

+ (LXBluetoothDevicePiggyBankManager *)sharedInstance;


/**
 *  查询存钱罐控制权验证码
 */
- (void)getBluetoothDevicePiggyBankVerificationCode;



/**
 *  查询存取钱罐设备存钱方法
 */
- (void)getBluetoothDevicePiggyBankMoney;

/**
 *  查询存钱罐灯光状态方法 / 查询震动开关
 */
- (void)getBluetoothDevicePiggyBankLightStateAndshakeSensorState;


/**
 *  设置存钱罐设备的灯光状态 / 震动传感器开关
 *
 *  @param lightState 灯光状态 分关闭/打开 默认关闭
 *  @param on 震动传感器开关 YES开 NO关
 */
- (void)setBluetoothDevicePiggyBankLightState:(PiggyBankLightState)lightState shakeSensorState:(BOOL)on;


/**
 *  设置存钱罐设备存取钱的方法
 *
 *  @param setMoneyType 存取钱类型, 分为存入/支出/零换整/正常设置
 *  @param real         实际存钱数
 *  @param total        总存钱数
 */
- (void)setBluetoothDevicePiggyBankMoneyWithType:(PiggyBankMoneyType)setMoneyType realMoney:(float)real totlalMoney:(float)total;



/**
 *  设置存钱罐控制权验证码
 *
 *  @param verificationCode 四个字节长度 */
- (void)setBluetoothDevicePiggyBankVerificationCode:(Byte[])verificationCode;




@end

