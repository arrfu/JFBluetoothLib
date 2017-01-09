//
//  LXBluetoothDeviceOBDManager.h
//  blueTooth
//
//  Created by ifeegoo on 15/12/10.
//  Copyright © 2015年 ifeegoo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LXBluetoothDeviceOBDActivationError)
{
    LXBluetoothDeviceOBDActivationErrorUnknown = 2,
    
    LXBluetoothDeviceOBDActivationErrorVehicleWithoutIgnition,
    
    LXBluetoothDeviceOBDActivationErrorBluetoothDisconnection
};

typedef NS_ENUM(NSUInteger, LXBluetoothDeviceOBDDataType)
{
    LXBluetoothDeviceOBDDataTypeALL = 1,
    
    /**
     电压接口内部需要除以100
     */
    LXBluetoothDeviceOBDDataTypeMAF,
    
    /**
     电压接口内部需要除以100
     */
    LXBluetoothDeviceOBDDataTypeVOL,
    
    /**内部接口需要-50
     */
    LXBluetoothDeviceOBDDataTypeECT,
    
    LXBluetoothDeviceOBDDataTypeSPD,
    
    LXBluetoothDeviceOBDDataTypeRPM,
    
    /**内部接口需要-50
     */
    LXBluetoothDeviceOBDDataTypeIAT
};

typedef NS_ENUM(NSUInteger, LXBluetoothDeviceOBDDataReceivingState)
{
    LXBluetoothDeviceOBDDataReceivingStateStart = 1,
    
    LXBluetoothDeviceOBDDataReceivingStateStop
};

typedef NS_ENUM(NSUInteger, LXBluetoothDeviceOBDDrivingBehaviorMessageType)
{
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeWithoutFault,
    
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeVoltageLow,
    
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeSpeedOver,
    
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeRPMHigh,
    
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeWaterTemperatureLow,
    
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeWaterTemperatureHigh,
    
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeRapidAcceleration,
    
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeRapidDeceleration,
    
    LXBluetoothDeviceOBDDrivingBehaviorMessageTypeIdlingTimeout
};

@protocol LXBluetoothDeviceOBDManagerDelegate <NSObject>

@optional

-(void) bluetoothDeviceOBDDidActivateDevice:(BOOL)ok error:(LXBluetoothDeviceOBDActivationError) error;

-(void) bluetoothDeviceOBDDataReceivingState:(LXBluetoothDeviceOBDDataReceivingState)state didChangeWithDataType:(LXBluetoothDeviceOBDDataType)type whetherSuccessful:(BOOL)successful;

-(void) bluetoothDeviceOBDReceivingDataWithType:(LXBluetoothDeviceOBDDataType) type andValue:(float[])value;

-(void) bluetoothDeviceOBDDidReceiveDataWithType:(LXBluetoothDeviceOBDDataType) type andValue:(float[])value;

/**
 * 实时接收到设备的故障码。本数据是实时直接返回的。
 */
-(void) bluetoothDeviceOBDReceivingFaultMessageWithTime:(long)time andValue:(int)value;

/**
 * 通过查询获取到设备的故障码。本数据是通过APP端查询驾驶行为数据，然后设备返回的。如果你请求的数据是5条，那么返回的数据的数组长度就是＜＝5.当你请求的数据是5条的时候，如果获取的数据实际长度为5.说明设备那边可能还有存储的数据，你可以再次调用获取数据的方法。如果获取的数据实际长度小于5，那么说明目前设备上已经没有数据了，所以我们没有必要再调用获取数据的方法了。
 */
-(void) bluetoothDeviceOBDDidReceiveFaultMessageWithTime:(long[])time andValue:(int[])value;


/**
 * 本数据是实时直接返回的。
 */
-(void) bluetoothDeviceOBDReceivingDrivingBehaviorMessageWithTime:(long)time andType:(LXBluetoothDeviceOBDDrivingBehaviorMessageType)type andValue:(int)value;

/**
 * 本数据是通过APP端查询驾驶行为数据，然后设备返回的。如果你请求的数据是5条，那么返回的数据的数组长度就是＜＝5.当你请求的数据是5条的时候，如果获取的数据实际长度为5.说明设备那边可能还有存储的数据，你可以再次调用获取数据的方法。如果获取的数据实际长度小于5，那么说明目前设备上已经没有数据了，所以我们没有必要再调用获取数据的方法了。
 */
-(void) bluetoothDeviceOBDDidReceiveDrivingBehaviorMessageWithTime:(long[])time andType:(LXBluetoothDeviceOBDDrivingBehaviorMessageType[])type andValue:(int[])value;

/**
 * 返回当前设备的点火状态码值。
 */
- (void) bluetoothDeviceOBDCarIgnitionWithStatusCode:(int)statusCode;

- (void)bluetoothDeviceOBDReceiveCustomCommand:(Byte[])byte;

@end


@interface LXBluetoothDeviceOBDManager : NSObject

/**
 * 激活OBD设备。
 * 说明：请在 LXBluetoothDeviceOBDManagerDelegate 中的 bluetoothDeviceOBDDidActivateDevice:error 方法中获取设备返回的结果。
 *
 */
-(void) activateOBDDevice;


/***
 *
 * 获取OBD设备激活状态。
 */
-(void) getOBDDeviceActivationStatus;

/**
 * 开始接收OBD设备传输过来的数据。
 * 说明：请在 LXBluetoothDeviceOBDManagerDelegate 中的 bluetoothDeviceOBDDataReceivingState:didChangeWhetherSuccessful: bluetoothDeviceOBDReceivingDataWithType:andValue:方法中获取设备返回的状态和数据。
 *
 * @param type OBD数据类型
 */
-(void) startReceivingDataWithType:(LXBluetoothDeviceOBDDataType)type;

/**
 * 停止接收OBD设备传输过来的数据。
 * 说明：请在 LXBluetoothDeviceOBDManagerDelegate 中的 bluetoothDeviceOBDDataReceivingState:didChangeWhetherSuccessful: bluetoothDeviceOBDReceivingDataWithType:andValue:方法中获取设备返回的状态和数据。
 *
 * @param type OBD数据类型
 */
-(void) stopReceivingDataWithType:(LXBluetoothDeviceOBDDataType)type;

/**
 * 查询OBD设备的数据。
 * 说明：请在 LXBluetoothDeviceOBDManagerDelegate 中的 bluetoothDeviceOBDDidReceiveDataWithType:andValue: 方法中获取设备返回的数据。
 *
 * @param type OBD数据类型
 */
-(void) getDataWithType:(LXBluetoothDeviceOBDDataType)type;

/**
 * 获取存储在设备上的OBD故障码值。
 *
 * @param again 是否需要获取当前的数据。true/false：是/否  数量：N。
 */
-(void) getOBDFaultMessageWhetherAgain:(BOOL)again withCount:(int)count;

/**
 * 获取存储在设备上的OBD驾驶行为。
 *
 * @param again 是否需要获取当前的数据。true/false：是/否  数量：N。
 */
-(void) getOBDDrivingBehaviorWhetherAgain:(BOOL)again withCount:(int)count;

/**
 * 获取汽车点火状态。
 */
-(void) getCarIgnitionStatus;


-(void)sendCustomCommand:(Byte[])byte length:(NSInteger)length;

@end
