//
//  VCOTAPresenter.h
//  BluetoothBox
//
//  Created by LiKuangkuang on 11/13/15.
//  Copyright © 2015 Actions. All rights reserved.
//

#ifndef VCOTAPresenter_h
#define VCOTAPresenter_h

#import "OTAUpdater.h"
#import "GlobalManager.h"

@protocol OTAPresenterDelegate <NSObject>
/**
 *  设置OTA文件路径
 *
 *  @param path   OTA文件路径
 *  @param partId 默认16
 */
-(void)setUpgradeFile:(NSString *)path part:(int)partId;

/**
 *  开始升级
 */
-(void)startUpgrade;

/**
 *  取消升级方法
 */
-(void)cancelUpgrade;

/**
 *  重置升级(默认有断点续传)
 */
-(void)reboot;

@end


@protocol OTAControllerDelegate <NSObject>

@optional
/**
 *  当前固件版本
 *
 *  @param version 版本号
 */
-(void)onCurrentVersion:(NSString *)version;

@optional
/**
 *  要升级的固件版本
 *
 *  @param version 版本号
 */
-(void)onUpgradeVersion:(NSString *)version;

@optional
/**
 *  当前发送到固件升级包的进度 和升级包的总大小
 *
 *  @param current 当前的进度
 *  @param max     总的进度
 */
-(void)onProgress:(int)current max:(int)max;

@optional
/**
 *  OTA升级完成的回调
 */
-(void)onComplete;

@optional
/**
 *  升级出现错误
 *
 *  @param errCode 具体错误码, 详见ErrorCode
 */
-(void)onError:(int)errCode;
@end

@interface OTAPresenter : NSObject<OTAPresenterDelegate, UpdateDelegate, SendDataDelegate, VersionDelegate>
-(void)setDelegate:(id<OTAControllerDelegate>)delegate;
-(void)setManager:(id<GlobalManager>)manager;
@end

#endif /* VCOTAPresenter_h */
