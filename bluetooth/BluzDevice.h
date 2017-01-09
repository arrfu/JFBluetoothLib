/*!
 *  @header BluzDevice.h
 *
 *  @abstract 蓝牙BLE设备扫描及连接对象
 *
 *  @author Actions Semi.
 */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>

/*!
 *  @const  CharacteristicWriteTypeKey
 *
 *  @discussion 指定以哪种方式往CBCharacteristic写数据.
 *
 *  @see    CharacteristicWriteType
 *
 */
extern NSString * const CharacteristicWriteTypeKey;
/*!
 *  @enum CharacteristicWriteType
 *
 *  @abstract 往CBCharacteristic写数据的方式。
 *
 *  @constant CharacteristicWriteWithResponse       写数据时需要回应（性能一般，但保证数据送达）。
 *  @constant CharacteristicWriteWithoutResponse    写数据时不需要回应（性能最优，但不保证数据不被丢失）。
 *
 */
typedef enum {
    CharacteristicWriteWithResponse = 0,
    CharacteristicWriteWithoutResponse,
}CharacteristicWriteType;
/*!
 *  @enum BluetoothState
 *
 *  @abstract 蓝牙设备状态。
 *
 *  @constant BluetoothStateUnknown       未知状态。
 *  @constant BluetoothStateResetting     状态丢失。
 *  @constant BluetoothStateUnsupported   蓝牙设备不支持BLE协议。
 *  @constant BluetoothStateUnauthorized  应用未获得蓝牙设备使用权限。
 *  @constant BluetoothStatePoweredOff    蓝牙设备关闭。
 *  @constant BluetoothStatePoweredOn     蓝牙设备打开。
 *
 */
typedef enum {
    BluetoothStateUnknown = 0,
    BluetoothStateResetting,
    BluetoothStateUnsupported,
    BluetoothStateUnauthorized,
    BluetoothStatePoweredOff,
    BluetoothStatePoweredOn,
}BluetoothState;

/*!
 *  @protocol TimeoutDelegate
 *
 *  @abstract 声明命令超时协议(应用无需处理).
 */
@protocol TimeoutDelegate;

/*!
 *  @protocol ConnectDelegate
 *
 *  @abstract 蓝牙BLE搜索及连接协议.
 */
@protocol ConnectDelegate <NSObject>

@required
/*!
 *  @method foundPeripheral:advertisementData:
 *
 *  @param peripheral 蓝牙设备对象
 *  @param advertisementData 包含蓝牙设备广播信息或者蓝牙搜索回应数据的字典容器。
 *
 *  @abstract 搜索蓝牙时返回的蓝牙设备信息。
 *
 *  @discussion 请及时保存<i>peripheral</i>引用，系统随时可能将其释放。
 *
 *  @seealso scanStart
 */
-(void)foundPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData;
/*!
 *  @method connectedPeripheral:
 *
 *  @param peripheral 蓝牙设备对象
 *
 *  @abstract 连接蓝牙时返回已经连接上的蓝牙设备信息。
 *
 *  @seealso connect:
 */
-(void)connectedPeripheral:(CBPeripheral*) peripheral;

@optional
/*!
 *  @method disconnectedPeripheral:
 *
 *  @param peripheral 蓝牙设备对象
 *
 *  @abstract 断开蓝牙时返回已经断开的蓝牙设备信息。
 *
 *  @seealso disconnect:
 */
-(void)disconnectedPeripheral:(CBPeripheral*) peripheral;
/*!
 *  @method disconnectedPeripheral:initiative:
 *
 *  @param peripheral 蓝牙设备对象
 *  @param onInitiative 是否用户主动断开连接
 *
 *  @abstract 断开蓝牙时返回已经断开的蓝牙设备信息。
 *
 *  @seealso disconnect:
 */
-(void)disconnectedPeripheral:(CBPeripheral*) peripheral initiative:(BOOL)onInitiative;

@end


extern NSString * const KeyWriteServiceUUID;
extern NSString * const KeyWriteCharacteristicUUID;
extern NSString * const KeyReadServiceUUID;
extern NSString * const KeyIndicateCharacteristicUUID;
extern NSString * const KeyReadCharacteristicUUID;
/*!
 *  @class BluzDevice
 *
 *  @abstract 负责蓝牙搜索、连接等操作的对象
 */
@interface BluzDevice : NSObject<CBCentralManagerDelegate,CBPeripheralDelegate,TimeoutDelegate>

/*!
 *  @method init
 *
 *  @abstract 初始化蓝牙设备。
 */
-(id)init;
/*!
 *  @method initWithOptions:
 *
 *  @param options 蓝牙设备初始化参数
 *
 *  @abstract 带参数初始化蓝牙设备。
 *
 *  @seealso    CharacteristicWriteTypeKey
 *  @seealso    CBCentralManagerOptionShowPowerAlertKey
 *	@seealso	CBCentralManagerOptionRestoreIdentifierKey
 */
- (id)initWithOptions:(NSDictionary *)options;
+(void)setUUID:(NSDictionary *)uuids;
/*!
 *  @method setConnectDelegate:
 *
 *  @param delegate 蓝牙设备搜索及连接协议
 *
 *  @abstract 设置蓝牙设备搜索及连接协议。
 *
 *  @seealso ConnectDelegate
 */
-(void)setConnectDelegate:(id<ConnectDelegate>) delegate;
/*!
 *  @method getBluetoothState
 *
 *  @abstract 获取蓝牙状态。
 *
 *  @seealso BluetoothState
 */
-(NSInteger)getBluetoothState;
/*!
 *  @method scanStop
 *
 *  @abstract 停止搜索周围蓝牙设备。
 */
-(void)scanStop;
/*!
 *  @method scanStart
 *
 *  @abstract 开始搜索周围的蓝牙设备。
 *
 *  @seealso foundPeripheral:advertisementData:
 */
-(void)scanStart;
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

@end
