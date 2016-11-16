//
//  UIImage+DDAdditions.m
//  TestApp
//
//  Created by NOVA8OSSA on 15/7/1.
//  Copyright (c) 2015年 小卡科技. All rights reserved.
//

#import "UIImage+DDAdditions.h"

@implementation UIImage (DDAdditions)

+ (UIImage *)screenShoot:(UIView *)view {
    
    UIGraphicsBeginImageContextWithOptions(view.bounds.size, view.opaque, 0.);
    [view.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return image;
}

+ (UIImage *)imageWithRenderColor:(UIColor *)color renderSize:(CGSize)size {
    
    UIImage *image = nil;
    UIGraphicsBeginImageContextWithOptions(size, YES, 0.);
    [color setFill];
    UIRectFill(CGRectMake(0, 0, size.width, size.height));
    image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return image;
}

- (UIImage *)scaleFitToSize:(CGSize)size {
    
    CGFloat scaleRate = MIN(size.width / self.size.width, size.height / self.size.height);
    return [self scaleImageToSize:size rate:scaleRate];
}

- (UIImage *)scaleFillToSize:(CGSize)size {
    
    CGFloat scaleRate = MAX(size.width / self.size.width, size.height / self.size.height);
    return [self scaleImageToSize:size rate:scaleRate];
}

- (UIImage *)scaleImageToSize:(CGSize)size rate:(CGFloat)scaleRate {
    
    UIImage *image = nil;
    CGSize renderSize = CGSizeMake(self.size.width * scaleRate, self.size.height * scaleRate);
    CGFloat startX = size.width * 0.5 - renderSize.width * 0.5;
    CGFloat startY = size.height * 0.5 - renderSize.height * 0.5;
    
    CGImageAlphaInfo info = CGImageGetAlphaInfo(self.CGImage);
    BOOL opaque = (info == kCGImageAlphaNone) || (info == kCGImageAlphaNoneSkipFirst) || (info == kCGImageAlphaNoneSkipLast);
    
    UIGraphicsBeginImageContextWithOptions(size, opaque, 0.);
    UIColor *backgroundColor = opaque ? [UIColor whiteColor] : [UIColor clearColor];
    [backgroundColor setFill];
    UIRectFillUsingBlendMode(CGRectMake(0, 0, size.width, size.height), kCGBlendModeNormal);
    
    [self drawInRect:CGRectMake(startX, startY, renderSize.width, renderSize.height)];
    image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return image;
}

//截取部分图像
-(UIImage*)getSubImage:(CGRect)rect
{
    CGImageRef subImageRef = CGImageCreateWithImageInRect(self.CGImage, rect);
    CGRect smallBounds = CGRectMake(0, 0, CGImageGetWidth(subImageRef), CGImageGetHeight(subImageRef));
    
    UIGraphicsBeginImageContext(smallBounds.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextDrawImage(context, smallBounds, subImageRef);
    UIImage* smallImage = [UIImage imageWithCGImage:subImageRef];
    UIGraphicsEndImageContext();
    
    return smallImage;
}

//等比例缩放
-(UIImage*)scaleToSize:(CGSize)size
{
    CGFloat width = CGImageGetWidth(self.CGImage);
    CGFloat height = CGImageGetHeight(self.CGImage);
    
    float verticalRadio = size.height*1.0/height;
    float horizontalRadio = size.width*1.0/width;
    
    float radio = 1;
    if(verticalRadio>1 && horizontalRadio>1)
    {
        radio = verticalRadio > horizontalRadio ? horizontalRadio : verticalRadio;
    }
    else
    {
        radio = verticalRadio < horizontalRadio ? verticalRadio : horizontalRadio;
    }
    
    width = width*radio;
    height = height*radio;
    
    int xPos = (size.width - width)/2;
    int yPos = (size.height-height)/2;
    
    // 创建一个bitmap的context
    // 并把它设置成为当前正在使用的context
    UIGraphicsBeginImageContext(size);
    
    // 绘制改变大小的图片
    [self drawInRect:CGRectMake(xPos, yPos, width, height)];
    
    // 从当前context中创建一个改变大小后的图片
    UIImage* scaledImage = UIGraphicsGetImageFromCurrentImageContext();
    
    // 使当前的context出堆栈
    UIGraphicsEndImageContext();
    
    // 返回新的改变大小后的图片
    return scaledImage;
}

@end
