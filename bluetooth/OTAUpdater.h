#ifndef OTAUpdater_h
#define OTAUpdater_h

typedef enum {
    ErrorCodeFirmwareTooLarge = 0x1,
    ErrorCodeFirmwareMismatch,
    ErrorCodeVersionNameIllegal,
    ErrorCodeChecksumMismatch,
    ErrorCodeVersionModuleIllegal,
} ErrorCode;

@protocol SendDataDelegate <NSObject>
-(void)onDataSend:(NSData *)data;
@end

@protocol VersionDelegate <NSObject>
-(void)onCheckFWVersionSuccess:(NSString *)version;
-(void)onCheckFWVersionError:(int)errCode;
@end

@protocol UpdateDelegate <NSObject>
-(void)onUpdateProgress:(int)current max:(int)max;
-(void)onUpdateError:(int)errCode;
-(void)onUpdateComplete;
@end

@interface OTAUpdater : NSObject
/*!
 *  @method onDataReceive:
 *
 *  @param data retrive from accessory
 *  @return YES：if data is identified, NO: if data is ignored
 */
-(BOOL)onDataReceive:(NSData *)data;
-(BOOL)onDataReceive:(int)cmdKey param1:(int)param1 param2:(int)param2 others:(NSData *)params;
/*!
 *  @method initWithDelegate:delegate
 *
 *  @param delegate send data to accessory
 */
-(id)initWithDelegate:(id<SendDataDelegate>)delegate;
-(id)initWithDelegate:(id<SendDataDelegate>)delegate headVersion:(NSInteger)hVersion;
-(void)getFirmwareVersion:(id<VersionDelegate>)delegate;
-(NSString *)getFileVersion:(NSString *)path;
-(void)startUpdate:(id<UpdateDelegate>)delegate name:(NSString *)path;
-(void)startUpdate:(id<UpdateDelegate>)delegate name:(NSString *)path part:(int)partId;
-(void)confirmUpdateAndReboot;
/*!
 *  @method suspendUpdate
 *
 *  @abstract pause the OTA procedure
 */
-(void)suspendUpdate;
/*!
 *  @method cancelLastUpdate
 *
 *  @abstract remove the firmware already sent to accessory
 */
-(void)cancelLastUpdate;
@end

#endif /* OTAUpdater_h */
