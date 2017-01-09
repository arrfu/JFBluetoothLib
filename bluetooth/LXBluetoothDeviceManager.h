/*!
 *  @header BluetoothDeviceManager.h
 *
 *  @abstract 蓝牙BLE设备扫描及连接对象、全局控制对象、Bluz控制对象
 *
 *  @author Actions Semi.
 */
//  BluetoothDeviceManager.h
//  blueTooth
//
//  Created by duluyang on 15/4/28.
//  Copyright (c) 2015年 duluyang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BluzDevice.h"
#import "BluzManager.h"
#import "GlobalManager.h"
#import "LXBluetoothDeviceEntry.h"
#import "LXBluetoothDeviceReadingPenManager.h"
#import "LXBluetoothDeviceMusicManager.h"
#import "LXBluetoothDeviceRadioManager.h"
#import "LXBluetoothDeviceAuxManager.h"
#import "LXBluetoothDeviceAlarmManager.h"
#import "LXBluetoothDeviceColorLampManager.h"
#import "LXBluetoothDeviceSoundBoxManager.h"
#import "LXBluetoothDeviceAlarmClockManager.h"
#import "LXBluetoothDeviceOBDManager.h"
#import "LXBluetoothDeviceFMSenderManager.h"
#import "LXGroupLampModel.h"
#import "LXBluetoothDevicePiggyBankManager.h"
#import "LXBluetoothDeviceLEDPanelManager.h"

typedef NS_ENUM(NSUInteger, LXDeviceType) {
    DEFAULT = 0,  // 默认
    LAMP_COMMON, // 普通蓝牙灯
    LAMP_COLOR, // 蓝牙彩灯
    FM_SENDER, // 蓝牙车载Mp3
    STORY_MACHINE, // 蓝牙故事机
    SOUND_BOX, // 蓝牙音箱
    REMOTE_CONTROLLER, //蓝牙遥控器
    READING_PEN, // 蓝牙点读笔
    ALARM_CLOCK, // 蓝牙闹钟
    CAR_OBD, // 智能积木
    BUILDING_BLOCK, // 通用蓝牙设备
    PIGGY_BANK, // 小猪班克设备
    LED_PANEL // LEDPanel设备
};

typedef NS_ENUM(NSUInteger, LXModifyFMBandType) {
    AddFMBand = 1,  // 添加FM频道
    DeleteFMBand    // 修改FM频道
};

typedef NS_ENUM(NSUInteger, LXBluetoothDeviceMode)
{
    LXBluetoothDeviceModeDefault,
    
    /**
     * TWS模式
     */
    LXBluetoothDeviceModeTWS = 99
};

# pragma mark LXBluetoothDeviceSupportedFunction
typedef NS_ENUM(NSUInteger, LXBluetoothDeviceSupportedFunction)
{
    LXBluetoothDeviceSupportedFunctionDefault,
    /**
     * 蓝牙设备名字修改。
     */
    LXBluetoothDeviceSupportedFunctionBluetoothNameModification,
    /**
     A2DP回连。
     */
    LXBluetoothDeviceSupportedFunctionA2DPReverseConnection
};

typedef NS_ENUM(NSUInteger, LXBluetoothDeviceSupportedColorLampFunction)
{
    LXBluetoothDeviceSupportedColorLampFunctionDefault,
    /**
     * 冷暖白
     */
    LXBluetoothDeviceSupportedColorLampFunctionColdWarmFun ,
    /**
     彩灯亮度调节。
     */
    LXBluetoothDeviceSupportedColorLampFunctionBrightnessAdjustment ,
    /**
     开机设置。
     */
    LXBluetoothDeviceSupportedColorLampFunctionSettings,
    
    /**
     RF433分组功能
     */
    LXBluetoothDeviceSupportedColorLampFunctionRF433subGroup ,
    
    /**
     2.4G分组功能
     */
    LXBluetoothDeviceSupportedColorLampFunction24GsubGroup
};


typedef NS_ENUM(NSUInteger, LXBluetoothDeviceCommunicationCommandType)
{
    LXBluetoothDeviceCommunicationCommandTypeDefault,
    /**
     * 设备被动反馈，就是APP主动查询设备返回的结果。
     */
    LXBluetoothDeviceCommunicationCommandTypeDeviceFeedbackPassivity = 2,
    
    /**
     * 设备主动反馈，就是设备状态发生变化，通知APP。
     */
    LXBluetoothDeviceCommunicationCommandTypeDeviceFeedbackInitiative = 4
};


typedef NS_ENUM(NSUInteger, LXBluetoothDeviceCustomEQMode)
{
    LXBluetoothDeviceCustomEQModeDefault,
    LXBluetoothDeviceCustomEQModeNormal,
    LXBluetoothDeviceCustomEQModeJazz,
    LXBluetoothDeviceCustomEQModePop,
    LXBluetoothDeviceCustomEQModeClassic,
    LXBluetoothDeviceCustomEQModeSoft,
    LXBluetoothDeviceCustomEQModeDBB,
    LXBluetoothDeviceCustomEQModeRock,
    LXBluetoothDeviceCustomEQModeUser
};



//******************
typedef NS_ENUM(NSUInteger, LXBluetoothDeviceA2DPConnectionControlType)
{
    LXBluetoothDeviceA2DPConnectionControlTypeConnect,
    LXBluetoothDeviceA2DPConnectionControlTypeDisconnect
};


// 设备支持EQ的情况, 分为不支持, 支持标准EQ, 支持自定义EQ三种
typedef enum {
    LXEQSupportTypeNone       = 0,
    LXEQSupportTypeStandard    = 1,
    LXEQSupportTypeCustom   = 2
}LXEQSupportType;


@protocol LXBlueDeviceDelegate <NSObject>

@required
/*!
 *  @method SLfoundPeripheral:advertisementData:
 *
 *  @param peripheral 蓝牙设备对象
 *  @param advertisementData 包含蓝牙设备广播信息或者蓝牙搜索回应数据的字典容器。
 *
 *  @abstract 搜索蓝牙时返回的蓝牙设备信息。
 *
 *  @seealso scanStart
 */
-(void)bluetoothDevicePeripheral:(CBPeripheral *)peripheral didDiscoverWithBroadcastData:(NSDictionary *)data;
/*!
 *  @method SLconnectedPeripheral:
 *
 *  @param peripheral 蓝牙设备对象
 *
 *  @abstract 连接蓝牙时返回已经连接上的蓝牙设备信息。
 *
 *  @seealso connect:
 */
-(void)bluetoothDevicePeripheralDidConnect:(CBPeripheral*) peripheral;

@optional
/*!
 *  @method SLdisconnectedPeripheral:
 *
 *  @param peripheral 蓝牙设备对象
 *
 *  @abstract 断开蓝牙时返回已经断开的蓝牙设备信息。
 *
 *  @seealso disconnect:
 */
-(void)bluetoothDevicePeripheralDidDisconnect:(CBPeripheral*) peripheral;
/*!
 *  @method SLdisconnectedPeripheral:initiative:
 *
 *  @param peripheral 蓝牙设备对象
 *  @param onInitiative 是否用户主动断开连接
 *
 *  @abstract 断开蓝牙时返回已经断开的蓝牙设备信息。
 *
 *  @seealso disconnect:
 */
-(void)bluetoothDevicePeripheral:(CBPeripheral*) peripheral didDisconnectWhetherInitiative:(BOOL)initiative;

@end

@protocol LXBluetoothDeviceFunManagerDelegate<NSObject>
/*
 * 返回的是否支持某种设备自定义功能。返回的字典中key是 LXBluetoothDeviceSupportedFunction,value 如果是1表示支持这种功能，如果是0表示不支持这种功能。
 */
- (void)bluetoothDeviceSupportedFunctionStatusDidReceive:(NSDictionary*)result;

/*
 * 返回的是否支持某种设备自定义功能。返回的字典中key是 LXBluetoothDeviceSupportedFunction,value 如果是1表示支持这种功能，如果是0表示不支持这种功能。
 */
- (void)bluetoothDeviceSupportedColorLampFunctionStatusDidReceive:(NSDictionary*)result;

/**
 *  是否支持冷暖白
 *
 *  @return
 */
-(void)bluetoothDeviceColorLampSupportWarm:(BOOL)isSupport;

/**
 *查询是否支持设备彩色亮度调节
 */
-(void)bluetoothDeviceColorLampIsSupportBrightness:(BOOL) isSupport;

@end


/**
 *  SLGlobalDelegate, 全局状态监听回调
 */
@protocol LXBluetoothDeviceManagerDelegate <NSObject>

//-(void)bluetoothDeviceManagerWithVoltage:(int)voltage;

/**
 *  fun
 *
 *  @param isWarm               是否支持冷暖白
 *  @param isBrightness        是否支持彩灯直接亮度调节
 *  @param isBootStatusSetting 是否支持开灯设置
 *  @param isRF433             是否支持RF433
 *  @param is24G               是否支持2.4g
 */
-(void)bluetoothDeviceManagerFunWithIsSupportWarm:(BOOL)isWarm
                     isSupportBrightnessAdjustmen:(BOOL)isBrightness
                      isSupportBootStatusSettings:(BOOL)isBootStatusSetting
                           isSupportRF433subGroup:(BOOL) isRF433
                             isSupport24GsubGroup:(BOOL)is24G
                            isSupportModifyDevice:(BOOL)isSupportModifyDevice
                                    isSupportA2dp:(BOOL)isSupportA2dp;


/*!
 *  @method SLmanagerReady
 *
 *  @abstract {@link GlobalManager}对象准备就绪
 */
-(void)bluetoothDeviceManagerIsReady;
/*!
 *  @method SLsoundEffectChanged:
 *
 *  @param mode 音效模式
 *
 *  @abstract 音箱音效模式变化
 *
 *  @seealso SoundEffect
 */
-(void)bluetoothDeviceEQDidChangeState:(UInt32)eqMode;
/*!
 *  @method SLeqModeChanged:
 *
 *  @param mode EQ模式
 *
 *  @abstract EQ模式变化
 *
 *  @seealso EQMode
 */
-(void)bluetoothDeviceDAEDidChangeState:(UInt32)daeMode;
/*!
 *  @method SLdaeModeChangedWithVBASS:andTreble:
 *
 *  @param vbassEnable 虚拟低音音效使能状态
 *  @param trebleEnable 高音增强音效使能状态
 *
 *  @abstract DAE音效模式变化
 */
-(void)bluetoothDeviceDAEModeDidChangeStateWithVBass:(BOOL)vBassEnable andTreble:(BOOL)trebleEnable;
/*!
 *  @method SLbatteryChanged:charging:
 *
 *  @param battery 电池电量状态
 *  @param charging 充放电状态
 *
 *  @abstract 音箱电池电量或充放电状态变化
 */
-(void)bluetoothDeviceBatteryDidChangeState:(UInt32)battery charging:(BOOL)charging;
/*!
 *  @method SLvolumeChanged:max:min:isMute:
 *
 *  @param current 当前音量
 *  @param max 支持的最大音量
 *  @param min 支持的最小音箱
 *  @param mute 静音状态
 *
 *  @abstract 音箱静音及音量状态变化
 */
-(void)bluetoothDeviceVolumeDidChangeState:(UInt32)current max:(UInt32)max min:(UInt32)min isMute:(BOOL)mute;
/*!
 *  @method SLmodeChanged:
 *
 *  @param mode 功能模式
 *
 *  @abstract 音箱功能模式变化
 *
 *  @seealso FuncMode  LXBluetoothDeviceModeTWS = 99
 */
-(void)bluetoothDeviceModeDidChangeState:(UInt32)mode;
/*!
 *  @method SLhotplugCardChanged:
 *
 *  @param visibility 卡状态
 *
 *  @abstract 音箱外置卡插拔状态变化
 */
-(void)bluetoothDeviceTFCardPlugInDidChangeState:(BOOL)state;
/*!
 *  @method SLhotplugUhostChanged:
 *
 *  @param visibility U盘状态
 *
 *  @abstract 音箱外置U盘插拔状态变化
 */
-(void)bluetoothDeviceUHostPlugInDidChangeState:(BOOL)state;
/*!
 *  @method SLlineinChanged:
 *
 *  @param visibility linein线状态
 *
 *  @abstract 音箱Linein连接线插拔状态变化
 */
-(void)bluetoothDeviceLineInPlugInDidChangeState:(BOOL)state;
/*!
 *  @method SLdialogMessageArrived:messageID:
 *
 *  @param type 对话框类型
 *  @param messageId 对话框信息序号
 *
 *  @abstract 显示音箱对话框
 *
 *  @seealso DialogType
 */
-(void)bluetoothDeviceDialogMessageDidArriveWithType:(UInt32)type andMessageID:(UInt32)messageId;
/*!
 *  @method SLtoastMessageArrived:
 *
 *  @param messageId 提示信息序号
 *
 *  @abstract 显示音箱提示信息
 *
 *  @seealso
 */
-(void)bluetoothDeviceDialogMessageDidArriveWithMessageID:(UInt32)messageId;
/*!
 *  @method SLdialogCancel
 *
 *  @abstract 取消音箱提示信息
 */
-(void)bluetoothDeviceDialogDidCancel;
/*!
 *  @method customCommandArrived:param1:param2:others:
 *
 *  @param cmdKey 自定义命令
 *  @param arg1 命令参数一
 *  @param arg2 命令参数二
 *  @param data 其他命令数据
 *
 *  @abstract 自定义命令回调
 *
 *  @seealso buildKey:cmdID:
 *
 *  @discussion 示例代码:
 *
 *      -(void)SLcustomCommandArrived:(UInt32)cmdKey param1:(UInt32)arg1 param2:(UInt32)arg2 others:(NSData*)data {
 *
 *      if (cmdKey == [appDele.globalManager buildKey:ANS cmdID:0x80]) {
 *
 *          //收到自定义命令回调，处理返回信息
 *
 *      }
 */
-(void)bluetoothDeviceCustomCommandDidArriveWithKey:(UInt32)commandKey andParam1:(UInt32)arg1 andParam2:(UInt32)arg2 andOthers:(NSData*)data;

- (void)bluetoothDeviceA2DPConnectionStatus:(BOOL)connection;



- (void)bluetoothDeviceA2DPConnectionStatusDidUpdateWithControlType:(LXBluetoothDeviceA2DPConnectionControlType)type whetherSuccessful:(BOOL)successful;

/**
 *  返回修改设备名字
 *
 *  @param isSuccess 是否成功
 */
- (void)bluetoothDeviceModifyDeviceName:(BOOL)isSuccess;

/**
 * 主动查询设备电压，或者设备电压变化的时候，主动返回。如果返回的是130，实际电压就是 13V.
 **/
- (void)bluetoothDeviceVoltageDidReceive:(int)voltageValue;

/**
 * 设备返回的当前状态
 * @param commandType     LXBluetoothDeviceCommunicationCommandTypeDeviceFeedbackPassivity 设备被动反馈，就是APP主动查询设备返回的结果。 LXBluetoothDeviceCommunicationCommandTypeDeviceFeedbackInitiative 设备主动反馈，就是设备状态发生变化，通知APP。
 * @param eqMode 设备模式。
 * @param values 如果设备模式是user，那么此处是长度为7的数组。
 **/
- (void)bluetoothDeviceCustomEQModeDidReceiveWithCommandType:(LXBluetoothDeviceCommunicationCommandType)commandType eqMode:(LXBluetoothDeviceCustomEQMode)eqMode params:(int[])values;

/*
 * 返回的是否支持某种设备自定义功能。返回的字典中key是 LXBluetoothDeviceSupportedFunction,value 如果是1表示支持这种功能，如果是0表示不支持这种功能。
 */
- (void)bluetoothDeviceSupportedFunctionStatusDidReceive:(NSDictionary*)result;


/**
 *  设置设备最大音量
 *
 *  @param maxVolume 返回的最大音量值
 *  @param control 是设置还是查询 YES为设置 NO为查询
 *
 */
- (void)bluetoothDeviceMaxVolumeReceive:(int)maxVolume isControl:(BOOL)control;

/**
 * 设备返回的修改FM情况
 * @param band    修改的频道数值
 * @param type    修改类型(删除或增加)
 * @param success 是否修改成功(YES成功 NO失败)
 **/
- (void)bluetoothDeviceModifyFMBandReceive:(int)band modifyType:(LXModifyFMBandType)type isSuccess:(BOOL)success;



/**
 * 设置查询Bcoon状态回调
 * @param on      开关 YES是开 NO是关
 * @param control 是否是控制
 * @param success 控制是否成功
 */
- (void)bluetoothDeviceiBeaconStateReceivedWithOn:(BOOL)on isControl:(BOOL)control isSuccess:(BOOL)success;

/**
 * 查询设置iBcoon的信息的回调

 * @param uuid  收到的 UUID值
 * @param major 收到的 Major值
 * @param minor 收到的 Minor值
 */
- (void)bluetoothDeviceiBeaconInfoReceivedWithUUID:(NSString *)uuid majorValue:(int)major minorValue:(int)minor isControl:(BOOL)control isSuccess:(BOOL)success;

/**
 * 设置设备恢复出厂设置的回调
 
 * @param success  是否成功 yes成功 no失败
 */
- (void)bluetoothDeviceeRestoreFactorySettingsReceivedWithSuccess:(BOOL)success;


@end



@interface LXBluetoothDeviceManager : NSObject<ConnectDelegate,GlobalDelegate,GlobalManager>

#pragma mark -----------------1.获取单例-----------------

+(LXBluetoothDeviceManager *)sharedInstance;


#pragma mark -----------------2.蓝牙相关的Manager-----------------
/**
 *  是否支持冷暖白
 */
@property (nonatomic,assign) BOOL supportColdWarmFun;

/**
 *  是否支持彩灯亮度调节
 */
@property (nonatomic,assign) BOOL supportBrightnessAdjustmentFun;

/**
 *  是否支持开机设置
 */
@property (nonatomic,assign) BOOL supportBootStatusSettingsFun;

/**
 *  是否支持RF433分组功能
 */
@property (nonatomic,assign) BOOL supportRF433suBgroupFun;

/**
 *  是否支持24G分组功能
 */
@property (nonatomic,assign) BOOL support24GsuBgroupFun;

/**
 *  是否支持修改设备名
 */
@property (nonatomic,assign) BOOL supportModifyDevice;

/**
 *  是否支持a2dp连接
 */
@property (nonatomic,assign) BOOL supportA2dp;
/**
 *  蓝牙连接器：负责蓝牙设备的搜索，连接，断开
 */
@property (nonatomic,strong)   BluzDevice         *bluzDeviceConnector;
@property (nonatomic,weak) id<LXBlueDeviceDelegate> blueDeviceDelegate;

@property (nonatomic,assign) BOOL connected;
/**
 *  搜索到的蓝牙设备数组，里面放LMBluetoothDeviceEntry
 */
@property (nonatomic,strong) NSMutableArray *bluetoothConnector_deviceBeanArray;

/**
 *  当前已连接的设备的LMBluetoothDeviceEntry
 */
@property (nonatomic,strong) LXBluetoothDeviceEntry *bluetoothConnector_connectedBluetoothDeviceEntry;




/**
 *  蓝牙媒体Manager，负责获取：m_GlobalManager，m_CardMusicManager，m_RadioManager，m_AlarmManager，m_AuxManager
 */
@property (nonatomic,strong)   BluzManager        *bluzManager;
/**
 *  蓝牙全局Manager，负责蓝牙设备的全局性操作：volume设置，EQ设置，自定义命令发送，切换蓝牙设备工作mode
 */
@property (nonatomic,weak) id<GlobalManager>   globalManager;

@property (nonatomic,weak) id<LXBluetoothDeviceManagerDelegate> slGlobalDelegate;
@property (nonatomic,weak) id<LXBluetoothDeviceFunManagerDelegate> lxFunManagerDelegate;

/**
 *  自定义命令key：在slGlobalDelegate初始化完成时自动初始化
 */
@property (nonatomic,assign)  int   global_cmdKey;

/**
 *  点读笔相关的代理，使用点读笔需要设置
 */
@property (nonatomic,weak) id<SLBluetoothDeviceReadingPenDelegate> slBluetoothDeviceReadingPenDelegate;

/**
 *  小猪班克相关的代理，使用小猪班克设备需要设置
 */
@property (nonatomic,weak) id<LXBluetoothDevicePiggyBankDelegate> LXBluetoothDevicePiggyBankDelegate;

/**
 *  LEDPanel相关的代理，使用LEDPanel设备需要设置
 */
@property (nonatomic,weak) id<LXBluetoothDeviceLEDPanelDelegate> LXBluetoothDeviceLEDPanelDelegate;

/**
 *  OBD相关的代理，使用点读笔需要设置
 */
@property (nonatomic,weak) id<LXBluetoothDeviceOBDManagerDelegate> lxBluetoothDeviceOBDManagerDelegate;

/**
 *  车载MP3代理。
 */
@property (nonatomic,weak) id<LXBluetoothDeviceFMSenderManagerDelegate> lxBluetoothDeviceFMSenderManagerDelegate;

/**
 *  H音箱音效相关的代理，设置音效需要设置
 */
@property (nonatomic,weak) id<CGColorLightDelegate> cgColorLightDelegate;

/**
 *  T系列音箱相关的代理，设置音效需要设置
 */
@property (nonatomic,weak) id<CGSoundBoxDelegate> cgSoundBoxDelegate;

/**
 * 蓝牙闹钟的代理。lXAlarmCustomDelegate
 */
@property (nonatomic, weak) id<CGBluetoothDeviceAlarmClockManagerDelegate> cgBluetoothDeviceAlarmClockManagerDelegate;

/**
 * 自定义蓝牙闹钟的代理。
 */
@property (nonatomic, weak) id<lXAlarmCustomDelegate> lxAlarmCustomDelegate;


/**
 *  当前蓝牙工作模式：见FuncMode
 */
@property (nonatomic,assign) UInt32 global_currentMode;
/**
 *  当前音量
 */
@property (nonatomic,assign) UInt32 global_currentVolume;
/**
 *  最大音量
 */
@property (nonatomic,assign) UInt32 global_maxVolume;
/**
 *  最小音量
 */
@property (nonatomic,assign) UInt32 global_minVolume;
/**
 *  是否静音
 */
@property (nonatomic,assign) BOOL   global_isMute;
/**
 *  当前电池电量
 */
@property (nonatomic,assign) UInt32 global_currentBattery;
/**
 *  TF卡是否可用
 */
@property (nonatomic,assign) BOOL   global_isTFAvaiable;
/**
 *  U盘是否可用
 */
@property (nonatomic,assign) BOOL   global_isUhostAvaiable;
/**
 *  外音是否可用（AUX就是Linein）
 */
@property (nonatomic,assign) BOOL   global_isLineinAvaiable;

/**
 *  检验chipsID的随机数
 */
@property (nonatomic,assign)  int   global_randomNumber4CheckChipsID;
/**
 *  自定义命令的设备id
 */
@property (nonatomic,assign)  int   global_BTDeviceID;
/**
 *  设备的mac(mac地址不区分大小写)地址过滤set:
 *     1.set中没有Object则不做mac地址过滤
 *     2.set中有Object，则mac地址前缀在set中的才会显示
 *     3.增加mac地址过滤例子：[[LMBluetoothManager sharedInstance].global_deviceMacFilterMutableSet addObject:@"C9:3"]，mac地址前缀为C9:3/c9:3才显示
 */
@property (nonatomic,strong) NSMutableSet *global_deviceMacFilterMutableSet;


/**
 *  是否支持OTA升级
 */
@property (nonatomic, assign) BOOL   supportOTA;

/**
 *  新的接口 是否支持设备重命名
 */
@property (nonatomic, assign) BOOL   supportDeviceRenameNew;
/**
 *  新的接口 是否支持ble自动回连
 */
@property (nonatomic, assign) BOOL   supportAutobleReconnectNew;
/**
 *  新的接口 是否支持脱机闹钟
 */
@property (nonatomic, assign) BOOL   supportOfflineAlarmNew;

/**
 *  当前的固件版本
 */
@property (nonatomic, copy) NSString *firmwareVersion;

/**
 *  设备id
 */
@property (nonatomic, copy) NSString *deviceID;

/**
 *  支持EQ类型 分不支持/标准/自定义 默认为标准EQ
 */
@property (nonatomic, assign) LXEQSupportType   supportEQtype;;

/**
 *  固件主控型号
 */
@property (nonatomic, copy) NSString *masterControlType;



#pragma mark ----------------3.蓝牙连接成功后初始化 bluzManager -----------------------
/**
 *  初始化 bluzManager ,需要在蓝牙连接成功后调用
 *
 *  @return 初始化成功返回YES
 */
- (BOOL)initBluetoothDeviceManager;

#pragma mark -------4.初始化 SLglobalManager、CGMusicManager、CGMusicManager、CGAuxManager、CGAlarmManager------------
/**
 *  初始化 globalManager, 需要在bluzManager初始化完成之后调用
 *
 *  @return 初始化成功返回YES
 */
- (BOOL)initBluetoothDeviceManagerWithDelegate:(id<LXBluetoothDeviceManagerDelegate>)delegate;

/**
 *  获取CGMusicManager的方法
 *
 *  @param delegate CGMusicDelegate 代理
 *
 *  @return CGMusicManager
 */
-(LXBluetoothDeviceMusicManager *)getLXBluetoothDeviceMusicManagerWithDelegate:(id<CGMusicDelegate>)delegate;

/**
 *  获取CGRadioManager的方法
 *
 *  @param delegate CGRadioDelegate 代理
 *
 *  @return CGRadioManager
 */
-(LXBluetoothDeviceRadioManager *)getLXBluetoothDeviceRadioManagerWithDelegate:(id<CGRadioDelegate>)delegate;
/**
 *  获取CGAuxManager的方法
 *
 *  @param delegate CGAuxDelegate 代理
 *
 *  @return CGAuxManager
 */
-(LXBluetoothDeviceAuxManager *)getLXBluetoothDeviceAuxManagerWithDelegate:(id<CGAuxDelegate>)delegate;

/**
 *  获取CGAlarmManager的方法
 *
 *  @param delegate CGAlarmDelegate 代理
 *
 *  @return CGAlarmManager
 */
-(LXBluetoothDeviceAlarmManager *)getLXBluetoothDeviceAlarmManagerWithDelegate:(id<CGAlarmDelegate>)delegate;

/**
 *  获取CGColorLightManager
 *
 *  @param delegate CGColorLightDelegate
 *
 *  @return CGColorLightManager
 */
- (LXBluetoothDeviceColorLampManager*)getLXBluetoothDeviceColorLampManagerWithDelegate:(id<CGColorLightDelegate>)delegate;

/**
 *  获取CGSoundBoxManager
 *
 *  @param delegate CGSoundBoxDelegate
 *
 *  @return CGSoundBoxManager
 */
- (LXBluetoothDeviceSoundBoxManager*)getLXBluetoothSoundBoxManagerWithDelegate:(id<CGSoundBoxDelegate>)delegate;

/**
 *  获取CGSoundBoxManager
 *
 *  @param delegate CGSoundBoxDelegate
 *
 *  @return CGSoundBoxManager
 */
- (LXBluetoothDeviceAlarmClockManager*)getLXBluetoothDeviceAlarmClockManagerWithDelegate:(id<CGBluetoothDeviceAlarmClockManagerDelegate>)delegate;

- (LXBluetoothDeviceReadingPenManager*)getLXBluetoothDeviceReadingPenManagerWithDelegate:(id<SLBluetoothDeviceReadingPenDelegate>)delegate;

// 获取小猪班克的代理和manager
- (LXBluetoothDevicePiggyBankManager *)getLXBluetoothDevicePiggyBankManagerWithDelegate:(id<LXBluetoothDevicePiggyBankDelegate>)delegate;

// 获取LEDPanel代理和manager
- (LXBluetoothDeviceLEDPanelManager *)getLXBluetoothDeviceLEDPanelManagerWithDelegate:(id<LXBluetoothDeviceLEDPanelDelegate>)delegate;

- (LXBluetoothDeviceOBDManager*)getLXBluetoothDeviceOBDManagerWithDelegate:(id<LXBluetoothDeviceOBDManagerDelegate>)delegate;

- (LXBluetoothDeviceFMSenderManager*)getLXBluetoothDeviceFMSenderManagerWithDelegate:(id<LXBluetoothDeviceFMSenderManagerDelegate>)delegate;

#pragma mark ----------------5.蓝牙连接相关的操作-----------------------
/*!
 *  @method setConnectDelegate:
 *
 *  @param delegate 蓝牙设备搜索及连接协议
 *
 *  @abstract 设置蓝牙设备搜索及连接协议。
 *
 *  @seealso ConnectDelegate
 */
-(void)setLXBluetoothDeviceDelegate:(id<LXBlueDeviceDelegate>) delegate;

/*!
 *  @method getBluetoothState
 *
 *  @abstract 获取蓝牙状态。
 *
 *  @seealso BluetoothState
 */
-(NSInteger)bluetoothDeviceState;

-(NSInteger)getBluetoothState;

/*!
 *  @method scanStop
 *
 *  @abstract 停止搜索周围蓝牙设备。
 */
-(void)stopScan;

/*!
 *  @method addMacFilterString
 *
 *  @abstract 添加mac地址过滤，需要在scanStart函数之前调用，mac地址过滤才生效
 *
 *  @seealso foundPeripheral:advertisementData:
 */
- (void)setMacAddressFilterPrefix:(NSString*)macFilter;
/**
 *  设置当前设备的类型
 *
 *  @param deviceType 详见enum LXDeviceType
 */
- (void)setDeviceType:(LXDeviceType )deviceType;
/*!
 *  @method scanStart
 *
 *  @abstract 开始搜索周围的蓝牙设备。
 *
 *  @seealso foundPeripheral:advertisementData:
 */

-(void)startScan;
/*!
 *  @method connect:
 *
 *  @param peripheral 蓝牙设备对象
 *
 *  @abstract 主动连接设定的蓝牙设备。
 *
 *  @seealso connectedPeripheral:
 */
-(void)connect:(CBPeripheral*)peripheral;
/*!
 *  @method disconnect:
 *
 *  @param peripheral 蓝牙设备对象
 *
 *  @abstract 主动断开当前已经连接的蓝牙设备。
 *
 *  @seealso disconnectedPeripheral:
 */
-(void)disconnect:(CBPeripheral*)peripheral;
/*!
 *  @method setAppForeground:
 *
 *  @param foreground 应用前后台状态
 *
 *  @abstract 通知iBluz应用当前的前、后台状态
 *
 *  @discussion 在后台时iBluz不进行BLE的数据收发，用以优化音箱资源开销。
 */
-(void)setAppForeground:(BOOL)foreground;
/*!
 *  @method close
 *
 *  @abstract 关闭并清理<code>BluzDevice</code>类对象。
 */
-(void)close;


#pragma mark --------------6、全局控制接口 globalManager 初始化成功后调用--------------------

/*!
 *  @method setSystemTime:
 *
 *  @param time 待同步的系统时间及日期。可以为nil，为nil时自动同步iOS Device当前时间
 *
 *  @abstract 同步指定时间和日期到设备端
 */
-(void)setSystemTime:(NSDate *)time;

/*!
 *  @method isFeatureSupport:
 *
 *  @param offset 偏移量
 *
 *  @return 是否支持该功能
 *
 *  @abstract 根据特定offset判断音箱是否支持相应功能
 *
 *  @seealso FeatureSupport
 */
-(BOOL)isFeatureSupport:(UInt32)offset;
/*!
 *  @method getMusicFolder
 *
 *  @return 特殊目录列表
 *
 *  @abstract 获取音箱特殊目录
 */
-(NSMutableArray *)getMusicFolder;
/*!
 *  @method setVolume:
 *
 *  @param volume 音量值
 *
 *  @abstract 设置音箱音量
 */
-(void)setVolume:(UInt32)volume;
/*!
 *  @method switchMute
 *
 *  @abstract 设置音箱静音状态
 */
-(void)switchMute;
/*!
 *  @method setMode:
 *
 *  @param mode 功能模式
 *
 *  @abstract 切换音箱的功能模式
 *
 *  @seealso FuncMode
 */
-(void)setMode:(UInt32)mode;
/*!
 *  @method setEQMode:
 *
 *  @param mode EQ模式
 *
 *  @abstract 设置音箱的EQ模式
 *
 *  @seealso EQMode
 */
-(void)setEQMode:(UInt32)mode;
/*!
 *  @method setEQParam:
 *
 *  @param values EQ各频点值
 *
 *  @abstract 设置用户EQ的各个频点值
 */
-(void)setEQParam:(int[])values;
/*!
 *  @method setSoundEffect:eqMode:userEQParam:vbassState:trebleState:
 *
 *  @param effect 音效模式
 *  @param eq EQ模式
 *  @param values 用户EQ频点值
 *  @param vbassEnable 虚拟低音音效使能状态
 *  @param trebleEnable 高音增强音效使能状态
 *
 *  @abstract 设置音箱的音效模式和参数
 *
 *  @seealso SoundEffect
 *  @seealso EQMode
 */
-(void)setSoundEffect:(UInt32)effect eqMode:(UInt32)eq userEQParam:(int[])values vbassState:(BOOL)vbassEnable trebleState:(BOOL)trebleEnable;
/*!
 *  @method setDialogTimeout:
 *
 *  @param timeout 超时时间
 *
 *  @abstract 设置对话框的超时时间
 */
-(void)setDialogTimeout:(UInt32)timeout;
/*!
 *  @method dialogResponse:
 *
 *  @param response 按键序号
 *
 *  @abstract 通知音箱用户点击的按键序号
 *
 *  @seealso DialogAnswer
 */
-(void)dialogResponse:(UInt32)response;
/*!
 *  @method sendCustomCommand:param1:param2:others:
 *
 *  @param cmdKey 命令号
 *  @param arg1 参数一
 *  @param arg2 参数二
 *  @param data 其他参数
 *
 *  @abstract 发送用户自定义命令
 *
 *  @seealso buildKey:cmdID:
 *
 *  @discussion 示例代码:
 *
 *      int key = [appDele.globalManager buildKey:QUE cmdID:0x80];
 *
 *      if (key != -1) {
 *
 *         [appDele.globalManager sendCustomCommand:key param1:0 param2:0 others:nil];
 *
 *      }
 *
 */
-(void)sendCustomCommand:(int)cmdKey param1:(UInt32)arg1 param2:(UInt32)arg2 others:(NSData*)data;
/*!
 *  @method buildKey:cmdID:
 *
 *  @param cmdType 命令类型
 *  @param cmdId 命令号
 *
 *  @return 自定义命令,-1为无效命令
 *
 *  @abstract 生成自定义命令
 */
-(int)buildKey:(int)cmdType cmdID:(int)cmdId;

#pragma mark ------------7、获取蓝牙设备状态------------------

/**
 *  获取蓝牙设备电池电量
 *
 *  @return 电池电量
 */
- (UInt32)getBatteryLevel;

/**
 *  获取蓝牙设备SD卡插拔状态
 *
 *  @return 1表示有卡；0表示没卡。
 */
- (int)getCardState;

/**
 *  获取蓝牙设备lineIn线的插拔状态
 *
 *  @return 1表示已插入；0表示已拔出
 */
- (int)getLineInState;
/**
 *  获取蓝牙设备USB插入状态
 *
 *  @return 1表示已插入；0表示已拔出
 */
- (int)getUSBState;


- (void)checkChipsID ;

/**
 *  获取当前设备名称
 *
 *  @return 当前设备名称
 */
-(NSString*)getCurrentDeviceName;

/**
 *  获取当前的mac地址
 *
 *  @return 当前设备mac地址
 */
-(NSString*)getCurrentMacAddress;

- (void)getA2DPConnectionStatus;

- (void)enableA2DPConnection;

- (void)disableA2DPConnection;

/**
 * 获取设备当前的电压。备注：从 bluetoothDeviceVoltageDidReceive 回调方法中获取返回的结果。
 */
- (void)getCurrentVoltage;

/**
 *  重命设备的名字
 *
 *  @param modifyName 修改设备的名字
 */
-(void)modifyDeviceName:(NSString *)modifyName;

/**
 *  查询彩灯设备所支持的功能
 */
-(void)checkDeviceFun;

-(void)sendCustomCommand:(Byte[])byte length:(NSInteger)length;

//*******

/**
 * 设置自定义EQ模式，传入非User模式。
 **/
- (void)setCustomEQMode:(LXBluetoothDeviceCustomEQMode)mode;

/**
 * 设置自定义EQ模式，传入User模式，并且传入相关参数。
 */
- (void)setCustomEQWithMode:(LXBluetoothDeviceCustomEQMode)mode params:(int[])values;

/**
 * 获取当前自定义EQ的模式。
 */
- (void)getCurrentCustomEQMode;

/**
 * 获取支持设备功能的状态。
 */
- (void)getSupportedFunctionStatus;

- (NSString*)getSDKVersion;

/**
 *  查询是否支持EQ, 默认为支持标准EQ
 */
- (void)getDeviceSupportEQstatus;


/**
 *  查询固件主控型号
 */
- (void)getDeviceMasterControlType;

/**
 *  查询设备最大音量
 */
- (void)getDeviceMaxVolume;


/**
 *  设置设备最大音量
 *
 *  @param volume 最大音量值
 */
- (void)setDeviceMaxVolume:(int)volume;

/**
 * 修改FM频道(删除和增加) band的值范围为87500-108000
 * @param type    删除和增加
 * @param band  要修改的频道(float类型)
 *
 */
- (void)modifyFMBandWithType:(LXModifyFMBandType)type band:(int)band;


/**
 * 查询iBcoon信息
 */
- (void)getDeviceiBeaconInfomation;



/**
 * 设置iBcoon的信息
 * @param uuid  UUID值
 * @param major Major值
 * @param minor Minor值
 */
- (void)setDeviceiBeaconInfoWithUUID:(NSString *)uuid majorValue:(int)major minorValue:(int)minor;


/**
 * 查询iBcoon开关状态
 */
- (void)getDeviceiBeaconSwitchStates;



/**
 * 设置iBcoon设备开关
 * @param on 开关YES为开 NO为关
 */
- (void)setDeviceiBeaconSwitchOn:(BOOL)on;


/**
 * 设置设备恢复出厂设置
 */
- (void)setDeviceRestoreFactorySettings;

@end


