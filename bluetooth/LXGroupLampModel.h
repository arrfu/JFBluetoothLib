//
//  LXGroupLampModel.h
//  colorBluetoothLampV3
//
//  Created by lxz on 16/2/27.
//  Copyright © 2016年 TRP. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LXGroupLampModel : NSObject
//索引
@property(nonatomic,assign)int groupIndex;
@property(nonatomic,assign)int exist; //1存在，2不存在
@property(nonatomic,strong)NSString *groupName; //组名

@end
