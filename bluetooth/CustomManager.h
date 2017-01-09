
/*!
 *  @protocol CustomDelegate
 *
 *  @discussion {@link CustomManager}对象的代理需遵循 <code>CustomDelegate</code>协议.
 */
@protocol CustomDelegate <NSObject>

/*!
 *  @method managerReady:
 *
 *  @param mode 音箱当前的模式
 *
 *  @abstract {@link CustomManager}对象准备就绪
 *
 *  @seealso FuncMode
 */
-(void)managerReady:(UInt32)mode;

@end

/*!
 *  @protocol CustomManager
 *
 *  @discussion 用户自定义模式控制接口，通过{@link BluzManager}的接口来获取。
 */
@protocol CustomManager <NSObject>

@end
