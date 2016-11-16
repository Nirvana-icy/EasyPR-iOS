//
//  UIImage+DDAdditions.h
//  TestApp
//
//  Created by NOVA8OSSA on 15/7/1.
//  Copyright (c) 2015年 小卡科技. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (DDAdditions)

+ (UIImage *)screenShoot:(UIView *)view;

+ (UIImage *)imageWithRenderColor:(UIColor *)color renderSize:(CGSize)size;

- (UIImage *)scaleFitToSize:(CGSize)size;

- (UIImage *)scaleFillToSize:(CGSize)size;

-(UIImage*)getSubImage:(CGRect)rect;

-(UIImage*)scaleToSize:(CGSize)size;

@end
