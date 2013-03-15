//
//  PhotoView.m
//  liuym_photo
//
//  Created by liuym  on 13-3-15.
//  Copyright (c) 2013年 liuym . All rights reserved.
//

#define offsetX    2.5f
#define offsetY    2.5f
#define btnWidth   offsetX * 2
#define btnHeight  offsetY * 2

#import "PhotoView.h"

@interface PhotoView(){
    CGPoint startP;
}

@property (nonatomic, strong) UIButton *leftUpBtn;
@property (nonatomic, strong) UIButton *rightUpBtn;
@property (nonatomic, strong) UIButton *leftDownBtn;
@property (nonatomic, strong) UIButton *rightDownBtn;


@end

@implementation PhotoView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
        [self initButton:frame];
    }
    return self;
}

-(void)initButton:(CGRect)frame
{
    CGRect rect = CGRectMake( 0, 0, btnWidth, btnHeight);
    
    rect.origin = CGPointMake(frame.origin.x, frame.origin.y);
    _leftUpBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    _leftUpBtn.frame = rect;
    _leftUpBtn.center = rect.origin;
    
    NSLog(@"rect = %@", NSStringFromCGRect(rect));
    rect.origin = CGPointMake(frame.origin.x + frame.size.width - btnWidth, frame.origin.y);
    _rightUpBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    _rightUpBtn.frame = rect;
    NSLog(@"rect = %@", NSStringFromCGRect(rect));
    rect.origin = CGPointMake(frame.origin.x , frame.origin.y + frame.size.height - btnHeight);
    _leftDownBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    _leftDownBtn.frame = rect;    
    NSLog(@"rect = %@", NSStringFromCGRect(rect));
    rect.origin = CGPointMake(frame.origin.x + frame.size.width - btnWidth , frame.origin.y + frame.size.height - btnHeight);
    _rightDownBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    _rightDownBtn.frame = rect;
    
    NSLog(@"rect = %@", NSStringFromCGRect(rect));
    [self addSubview:_leftDownBtn];
    [self addSubview:_rightDownBtn];
    [self addSubview:_leftUpBtn];
    [self addSubview:_rightUpBtn];
}

// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    NSLog(@"rect = %@", NSStringFromCGRect(rect));
    // Drawing code
    
    CGRect whiteRect = CGRectMake(rect.origin.x + offsetX, rect.origin.y + offsetY, rect.size.width - offsetX * 2, rect.size.height - offsetY * 2);
    
    CGPoint pStart[4], pEnd[4];
    CGFloat width = whiteRect.size.width / 3.0f;
    CGFloat height = whiteRect.size.height / 3.0f;
    pStart[0] = CGPointMake(whiteRect.origin.x + width, whiteRect.origin.y);
    pStart[1] = CGPointMake(whiteRect.origin.x + width * 2, whiteRect.origin.y);
    pStart[2] = CGPointMake(whiteRect.origin.x , whiteRect.origin.y + height);
    pStart[3] = CGPointMake(whiteRect.origin.x , whiteRect.origin.y + height * 2);
    
    pEnd[0] = CGPointMake(whiteRect.origin.x + width, whiteRect.origin.y + whiteRect.size.height);
    pEnd[1] = CGPointMake(whiteRect.origin.x + width * 2, whiteRect.origin.y + whiteRect.size.height);
    pEnd[2] = CGPointMake(whiteRect.origin.x + whiteRect.size.width, whiteRect.origin.y + height);
    pEnd[3] = CGPointMake(whiteRect.origin.x + whiteRect.size.width, whiteRect.origin.y + height * 2);
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextBeginPath(context);
    //draw white rect
    CGContextMoveToPoint(context, whiteRect.origin.x, whiteRect.origin.y);
    CGContextSetLineWidth(context, 2);
    CGContextAddRect(context, whiteRect);
    [[UIColor whiteColor] setStroke];
    CGContextStrokePath(context);
    CGFloat lengths[] = {5,5};
    CGContextSetLineWidth(context, 0.8);
    CGContextSetLineDash(context, 0, lengths, 2);
    for(int i = 0; i < 4 ; i++){
        CGContextMoveToPoint(context, pStart[i].x, pStart[i].y);
        CGContextAddLineToPoint(context, pEnd[i].x, pEnd[i].y);
    }
    
    [[UIColor whiteColor] setStroke];
    CGContextStrokePath(context);
}

-(BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event
{
    return NO;
}

/*-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    CGPoint point = [[touches anyObject] locationInView:self.superview];
    startP = point;
    NSLog(@"touch began view point = %@", NSStringFromCGPoint(point));
}

-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    CGPoint endP = [[touches anyObject] locationInView:self.superview];
    if([[touches allObjects] count] > 1){
        return;
    }
    CGFloat x = endP.x - startP.x;
    CGFloat y = endP.y - startP.y;
    startP = endP;
    
    CGRect rect = self.frame;
    rect.origin.x = rect.origin.x + x;
    rect.origin.y = rect.origin.y + y;
    self.frame = rect;
}*/


@end
