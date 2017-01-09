//
//  CGColorLightManager.h
//  blueTooth
//
//  Created by duluyang on 15/6/1.
//  Copyright (c) 2015年 duluyang. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger,LXBluetoothDeviceColorLampSupportedFunction)
{
    LXBluetoothDeviceColorLampSupportedFunctionDefault,
    LXBluetoothDeviceColorLampSupportedFunctionColdAndWarmLightModification,
    LXBluetoothDeviceColorLampSupportedFunctionColorBrightnessModification,
    LXBluetoothDeviceColorLampSupportedFunctionBootStatusSetting,
    LXBluetoothDeviceColorLampSupportedFunctionGroupRF433,
    LXBluetoothDeviceColorLampSupportedFunctionGroup24G,
    LXBluetoothDeviceColorLampSupportedFunctionGroupRF433Paired
};
//命令返回模式 查询，或者反馈
typedef NS_ENUM(NSUInteger,LXBluetoothDeviceCommanTyle)
{
    LXBluetoothDeviceCommanTyleCheck = 1, //查询
    LXBluetoothDeviceCommanTyleFeckBack = 2 //反馈
    
};
//分组模式中组的
typedef NS_OPTIONS(NSUInteger,LXBluetoothDeviceGroup)
{
    LXBluetoothDeviceGroupOne = 1 , //组1
    LXBluetoothDeviceGroupTwo =1<<1 , //组2
    LXBluetoothDeviceGroupThree =1<<2 , //组3
    LXBluetoothDeviceGroupFour =1<<3, //组4
    LXBluetoothDeviceGroupFive =1<<4, //组5
    LXBluetoothDeviceGroupSix =1<<5, //组6
    LXBluetoothDeviceGroupSeven =1<<6, //组7
    LXBluetoothDeviceGroupEight  =1<<7//组8
};

//2.4G设备
typedef NS_OPTIONS(NSUInteger,LXBluetoothDevice24GIndex)
{
    LXBluetoothDevice24GIndexOne = 1 , //组1
    LXBluetoothDevice24GIndexTwo =1<<1 , //组2
    LXBluetoothDevice24GIndexThree =1<<2 , //组3
    LXBluetoothDevice24GIndexFour =1<<3, //组4
    LXBluetoothDevice24GIndexFive =1<<4, //组5
    LXBluetoothDevice24GIndexSix =1<<5, //组6
    LXBluetoothDevice24GIndexSeven =1<<6, //组7
    LXBluetoothDevice24GIndexEight  =1<<7//组8
};

//2.4G设备从灯状态
typedef NS_OPTIONS(NSUInteger,LXBluetoothDevice24GSunLampState)
{
    LXBluetoothDevice24GSunLampStateOnline = 1, // 在线
    LXBluetoothDevice24GSunLampStateOffline = 2 //离线
};

//设置开灯模式
typedef NS_ENUM(NSUInteger,LXBluetoothDeviceOpenLightType)
{
    LXBluetoothDeviceOpenLightTypeWihte  =1, //白灯模式
    LXBluetoothDeviceOpenLightTypeColor  =2, //彩灯模式
    LXBluetoothDeviceOpenLightTypeCustomWhite =3, //自定义白灯模式
    LXBluetoothDeviceOpenLightTypeCustomCustomColor =4 //自定义彩灯模式
};

//灯的类型（主从）
typedef NS_ENUM(NSUInteger,LXBluetoothDeviceLampType)
{
    LXBluetoothDeviceLampTypeMain  =1, //主灯
    LXBluetoothDeviceLampTypeSun  =2, //从灯
    
    LXBluetoothDeviceLampTypeMainSun =3 //主从灯模式
};

//灯的控制
typedef NS_ENUM(NSUInteger,LXBluetoothDeviceLampControlType)
{
    LXBluetoothDeviceLampControlTypeGeneral  =1, //普通控制
    LXBluetoothDeviceLampControlTypeA2dp  =2 //a2dp
};



@protocol CGColorLightDelegate <NSObject>

@optional

/**
 *  是否支持冷暖白
 *
 *  @return
 */
-(void)bluetoothDeviceColorLampSupportWarm:(BOOL)isSupport;

/*
 返回2.4G设备从灯修改名字后的信息
 */
-(void)bluetoothDeviceColorLamp24GSunLampWithName:(NSString*)sunLampName macString:(NSString*)macString sunLampId:(int)sunLampId;

/*
 返回2.4G设备从灯状态，在线，离线
 从灯名字， mac地址六位，从灯id
 commanTyle， 命令类型，反馈，查询
 */
-(void)bluetoothDeviceColorLamp24GSunLampWithState:(LXBluetoothDevice24GSunLampState)sunLampState sunLampName:(NSString*)sunLampName macString:(NSString*)macString sunLampId:(int)sunLampId commanTyle:(LXBluetoothDeviceCommanTyle)commanTyle;

/**
 *  返回2.4G设备的受控的情况
 device24GIndex:受控灯的序号
 controlType： 从灯控制类型，a2dp 或者普通灯控
 * deviceLampType 主灯模式，从灯模式， 主从灯模式
 commanTyle 命令类型：查询，反馈
 */
-(void)bluetoothDeviceColorLamp24GControlledDeviceWithIndex:(LXBluetoothDevice24GIndex)device24GIndex controlType:(LXBluetoothDeviceLampControlType)controlType  mainSun:(LXBluetoothDeviceLampType)deviceLampType commanTyle:(LXBluetoothDeviceCommanTyle)commanTyle ;

/**
 *  查询冷暖白
 * commanTyle 1查询，2反馈
 */
-(void)bluetoothDeviceColorLampWarmStateWithBrightness:(int)Brightness commanTyle:(int)commanTyle ;


/**
 *  查询回调返回。
 *
 *  @param switchValue 灯效开关
 *  @param Brightness  灯效亮度
 *  @param red         红色
 *  @param green       绿色
 *  @param blue        蓝色
 *  @param lampEffect  音效
 *  @param lampswitch  灯开关
 */
- (void)CGselectLampEffectDelegateState:(int)switchValue Brightness:(int)Brightness red:(int)red green:(int)green blue:(int)blue lampEffect:(int)lampEffect;

/**
 *  控制回调返回
 *
 *  @param switchValue 灯开关
 *  @param Brightness  灯效亮度
 *  @param red         红色
 *  @param green       绿色
 *  @param blue        蓝色
 *  @param lampEffect  灯效
 */
- (void)CGcontrolLampEffectDelegateStateSwitch:(int)switchValue Brightness:(int)Brightness red:(int)red greed:(int)green blue:(int)blue lampEffect:(int)lampEffect ;


/**
 *  查询回调返回,带有灯效速度的设备
 *
 *  @param switchValue 灯效开关
 *  @param Brightness  灯效亮度
 *  @param red         红色
 *  @param green       绿色
 *  @param blue        蓝色
 *  @param lampEffect  灯效
 *  @param speed1      灯效速度1
 *  @param speed2      灯效速度2
 *  @param speed3      灯效速度3
 *  @param speed4      灯效速度4
 */
- (void)CGselectLampEffectDelegateState:(int)switchValue Brightness:(int)Brightness red:(int)red green:(int)green blue:(int)blue lampEffect:(int)lampEffect speed1:(int)speed1 speed2:(int)speed2 speed3:(int)speed3 speed4:(int)speed4;

/**
 *  控制回调返回,带有灯效速度的设备
 *
 *  @param switchValue 灯效开关
 *  @param Brightness  灯效亮度
 *  @param red         红色
 *  @param green       绿色
 *  @param blue        蓝色
 *  @param lampEffect  音效
 *  @param speed1      灯效速度1
 *  @param speed2      灯效速度2
 *  @param speed3      灯效速度3
 *  @param speed4      灯效速度4
 */

- (void)CGcontrolLampEffectDelegateStateSwitch:(int)switchValue Brightness:(int)Brightness red:(int)red greed:(int)green blue:(int)blue lampEffect:(int)lampEffect speed1:(int)speed1 speed2:(int)speed2 speed3:(int)speed3 speed4:(int)speed4;

/**
 *  查询传感器的回调方法
 *
 *  @param sensor 传感器类型
 *  @param value  开关状态
 */
- (void)CGselectSensorState:(int)sensor switchValue:(int)value;
/**
 *  控制传感器的回调方法
 *
 *  @param sensor 传感器类型
 *  @param value  开关状态
 */
- (void)CGcontrolSensorState:(int)sensor switchValue:(int)value;
/**
 *  获取闹钟序列号
 *
 *  @param bumber 闹钟序列号，范围（1，2，3，4）
 */
-(void)CGAlarmNumber:(int)bumber;


//彩灯呼吸开关灯回调


/**
 *  获取台灯工作时长
 *
 *  @param data
 */
- (void)CGSelectWorkTime:(NSArray*)data;

/**
 *  查询普通灯回调
 *
 *  @param switchValue 开关状态
 *  @param Brightness  灯亮度
 */
- (void)CGSelectCommonLightTurnOnOFF:(int)switchValue Brightness:(int)Brightness;

/**
 *  控制灯开关和亮度的回调
 *
 *  @param switchValue  开关状态
 *  @param Brightness  灯亮度
 */
-(void)CGControlCommonLightTurnOnOff:(int)switchValue Brightness:(int)Brightness;

/**
 *查询是否支持设备彩色亮度1支持／2不支持
 */
-(void)bluetoothDeviceColorLampIsSupportBrightness:(int) value;

/**
 *设备分组信息 LXGroupLampModel
 */
-(void)bluetoothDeviceColorLampDeviceIntoGroup:(NSMutableArray*) groupArray;

/**
 *查询设备主从灯设置信息
 groupStyle = 1,只控制主灯，2，只控制从灯，3，主从灯一起控制， deviceGroup控制的从灯的组数
 */
-(void)bluetoothDeviceColorLampMainSubWith:(int)groupStyle mainSub:(LXBluetoothDeviceGroup)deviceGroup;



//开灯模式回调  1查询，2反馈
-(void)bluetoothDeviceColorLampOpenLightModel:(LXBluetoothDeviceOpenLightType) openLampStyle brightness:(int)brightness r:(int)r g:(int)g b:(int)b warm:(int)warm commandTyle:(int)commandTyle;

/*
 * 返回的是否支持某种设备自定义功能。返回的字典中key是 LXBluetoothDeviceColorLampSupportedFunction,value 如果是1表示支持这种功能，如果是0表示不支持这种功能。
 */
- (void)bluetoothDeviceColorLampSupportedFunctionStatusDidReceive:(NSDictionary*)dictionary;

@end

/**
 *固件端：
 1.设备只支持一种呼吸灯效（单色呼吸/四色呼吸/其他呼吸等）
 APP端：统一发送 灯效  1
 固件端：根据产品要求，自行选择呼吸灯效的种类。
 2.设备支持两种呼吸 （例如蜗灯的单色呼吸/四色呼吸）
 APP端：单色呼吸 发送  1/ 四色呼吸 发送 11
 固件端：内置两种灯效处理逻辑。

 */
typedef NS_ENUM(NSUInteger, CGBluetoothDeviceColorLampEffect)
{
    CGBluetoothDeviceColorLampEffectNormal,
    CGBluetoothDeviceColorLampEffectBreath,
    CGBluetoothDeviceColorLampEffectRandom,
    CGBluetoothDeviceColorLampEffectRhythm,
    CGBluetoothDeviceColorLampEffectRainbow,
    CGBluetoothDeviceColorLampEffectPulse,
    CGBluetoothDeviceColorLampEffectFlashing,
    CGBluetoothDeviceColorLampEffectCandle
};

//设置分组
typedef NS_ENUM(NSUInteger,LXBluetoothDeviceLampGroupType)
{
    LXBluetoothDeviceLampGroupTypeIntoGroups =1, //设置分组
    LXBluetoothDeviceLampGroupTypeDeleteGroups =2, //删除分组
    LXBluetoothDeviceLampGroupTypeDeleteAllGroups =3, //删除所有分组
    LXBluetoothDeviceLampGroupTypeModifyGroups =4, //修改分组
    LXBluetoothDeviceLampGroupTypeRestGroups = 5 //重置分组
    
};



@interface LXBluetoothDeviceColorLampManager : NSObject



/**
 *  查询彩灯状态:开关、亮度、色彩、灯效
 */
- (void)selectLampEffect;

/**
 *  控制彩灯开关 value值，YES开，ON关
 */
- (void)controlColorLightTurnOnOff:(BOOL)value;

/**
 *  查询彩灯状态，带有灯效快慢的设备
 */
- (void)selectLampEffectWithSpeed;

/**
 *  控制彩灯音效的开关
 *
 *  @param date  设置YES为开，设置NO为关
 */
- (void)controlLampEffectSwitch:(BOOL)date;


/**
 *  设置彩灯灯效亮度
 *
 *  @param value 大于0
 */
- (void)controlLampEffectBrightness:(int)value;

/**
 *  控制彩灯色彩
 *
 *  @param red   0-255
 *  @param green 0-255
 *  @param blue  0-255
 */
- (void)controlColorWithRed:(int)red green:(int)green blue:(int)blue;

/**
 *  控制灯效
 *
 *  @param effect 灯效参数  具体参考 LampEffectType
 */
- (void)controlLampEffect:(int)effect;


/**
 *  控制灯效 带有灯效快慢
 *
 *  @param effect 灯效参数  具体参考 LampEffectType
 *  @param speed  灯效果快慢
 */
- (void)controlLampeffect:(int)effect speed:(int)speed;


/**
 *  查询指定传感器的开关状态
 *
 *  @param value 值为1表示传感器，值为2表示光线传感器
 */
- (void)selectSensor:(int)value;

/**
 *  控制指定传感器的开关状态
 *
 *  @param value 值为1表示传感器，值为2表示光线传感器
 *  @param onOff  值为1表示开，值为0表示关
 */
- (void)controlSensorState:(int)value turn:(BOOL)onOff;

/**
 *  呼吸灯开关
 *
 *  @param value 0关，1开
 */
- (void)colorLightBreathTurnOnOff:(int)value;

/**
 *  获取闹钟的序列号，需要在闹钟正在闹的时候调用
 */
- (void)getAlarmNumber;

/**
 *  获取台灯工作时间
 *
 *  @param index  获取的数据的游标，1当前位置(相当于再次获取)2下一位置
 *  @param num 要求返回的数据量
 */
- (void)getLightWorkTime:(int)index returnNum:(int)num;

/**
 *  查询普通灯的状态，开关和亮度状态
 */
- (void)selectCommonLightState;
/**
 *  控制普通灯的开关
 *
 *  @param value 1开，2关
 */
- (void)controlCommonLightTurnOnOff:(int)value;
/**
 *  控制普通灯的亮度
 *
 *  @param value 亮度值
 */
- (void)controlCommonLightBrightness:(int)value;

/**
 *  查询冷暖白状态
 */
- (void)getWarmState;

/**
 *  设置冷暖白值
 */
- (void)setWarmState:(int)warmValue;


//控制彩灯亮度
-(void)setColorLampBrightness:(int)value r:(int)r g:(int)g b:(int)b;

//查询是否支持彩灯，直接亮度查询
-(void)getIsSupportColorLampBrightness;

/*
 *设置分组
 *删除分组
 *删除所有
 *修改分组
 */
-(void)setGroup:(LXBluetoothDeviceLampGroupType)groupStyle groupIndex:(int)groupIndex groupName:(NSString*)groupName;

/*
 *重置所有分组RF433;
 */
-(void)resetAllGroupSubColorLampsRF433;

/**
 *  查询分组信息
 */
- (void)getGroupState;

//设置主从灯1只控制主灯，2只控制从灯，3主灯从灯都控制，
-(void)setMainSubLamp:(int)switchValue group:(LXBluetoothDeviceGroup)bluetoothDeviceGroup;

//查询主从灯控制信息
-(void)getMainSubLampState;

//设置开灯模式
-(void)setOpenLightModel:(LXBluetoothDeviceOpenLightType) openLampStyle brightness:(int)brightness r:(int)r g:(int)g b:(int)b warm:(int)warm;

//查询开机模式
-(void)getOpenLampState;


#pragma mark - 2.4G
//查询受控设备 2.4G
-(void)get24GControlledDevice;

//设置受控设备
-(void)set24GDevice:(LXBluetoothDeviceLampControlType)lampControlType MainOSun:(LXBluetoothDeviceLampType)lampType sunLamp:(LXBluetoothDevice24GIndex)Device24GIndex;

//查询2.4g从灯在线，离线信息
-(void)get24GSunLampState;

//修改2.4g从灯名字
-(void)modifySunLampName:(NSString*)sunLampName macString:macString index:(int)index ;

/**
 *  是否支持冷暖白
 */
-(void)checkSupportWarm;

- (void)setSubRF433ColorLampPaired;

- (void)getSupportedFunctionStatus;

@end
