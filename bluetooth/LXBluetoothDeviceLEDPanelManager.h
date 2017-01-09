//
//  LXBluetoothDeviceLEDPanelManager.h
//  blueTooth
//
//  Created by 李宏远 on 2016/10/22.
//  Copyright © 2016年 duluyang. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 全部屏幕灯开关状态
 */
typedef enum {
    LEDPanelLightStateOn = 1, // 打开
    LEDPanelLightStateOff = 2, // 关闭
}LEDPanelLightState;


/**
 绘制动画类型
 */
typedef enum {
    LEDPanelAnimateTypeAnimateDraw = 4, // 动画绘制
    LEDPanelAnimateTypeRollSubtitle = 5, // 滚动字幕
}LEDPanelAnimateType;


@protocol LXBluetoothDeviceLEDPanelDelegate <NSObject>


/**
 查询和设置全部屏幕灯开关状态的回调
 @param state   开关状态 LEDPanelLightState
 @param control 是否是控制(YES控制 NO查询)
 @param success 控制是否成功(YES成功 NO失败 查询时为NO)
 */
- (void)bluetoothDeviceLEDPanelAllScreenLightingStateReceive:(LEDPanelLightState)state isControl:(BOOL)control isControlSuccess:(BOOL)success;

@end

@interface LXBluetoothDeviceLEDPanelManager : NSObject





+ (LXBluetoothDeviceLEDPanelManager *)sharedInstance;


/**
 获取全部屏幕灯开关状态
 */
- (void)getAllScreenLightingState;



/**
 设置全屏幕开灯状态
 @param state 全屏幕开灯状态(开和关)
 */
- (void)setAllScreenLightingState:(LEDPanelLightState)state;


/**
 设置单点描绘
 @param xpoint x 轴坐标值 (0-25)
 @param ypoint y 轴坐标值 (0-16)
 */
- (void)setSingalPointDrawWithXPoint:(int)xpoint yPoint:(int)ypoint;



/**
 整张面板绘制
 @param pointsByte 面板点信息(50个长度的byte数组)
 */
- (void)setWholePanelDrawWithPanelPointsInfo:(Byte *)pointsByte;


/**
 动画绘制
 @param pointsByte   面板点信息(50个长度的byte数组)
 @param totalFrame   动画总帧数(1-N)
 @param currentFrane 当前帧数（第1-N）
 @param type         LEDPanelAnimateType 动画类型(动画绘制和 滚动字幕)
 */
- (void)setAnimateDrawWithPanelPointsInfo:(Byte *)pointsByte totalAnimateFrame:(int)totalFrame currentFrame:(int)currentFrane animateType:(LEDPanelAnimateType)type;

@end
