//
//  PhotoViewController.m
//  liuym_photo
//
//  Created by liuym  on 13-3-15.
//  Copyright (c) 2013年 liuym . All rights reserved.
//

#import "PhotoViewController.h"
#import "PhotoView.h"
@interface PhotoViewController ()<UIScrollViewDelegate>{
    BOOL endDrag;
}

@property (strong, nonatomic) IBOutlet UIScrollView *scrollView;
@property (strong, nonatomic) IBOutlet UIImageView  *imageView;

@end

@implementation PhotoViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.scrollView.contentSize = CGSizeMake(320, 200);
    [self.scrollView setMinimumZoomScale:0.75];
    [self.scrollView setMaximumZoomScale:2.0];
    PhotoView *view = [[PhotoView alloc] initWithFrame:CGRectMake(0, 100, 320, 200)];
    view.center = self.view.center;
    view.backgroundColor = [UIColor clearColor];
    //view.frame = CGRectMake(100, 100, 200, 200);
    [self.view addSubview:view];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma -
#pragma UIScrollViewDelegate Methods

- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
{
    return self.imageView;
}

-(void)scrollViewDidZoom:(UIScrollView *)scrollView
{
    
}

-(void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
{
    endDrag = NO;
    NSLog(@"start contentoffset frame = %@", NSStringFromCGPoint(self.scrollView.contentOffset));
}

-(void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate
{
    endDrag = YES;
    NSLog(@"end contentoffset frame = %@", NSStringFromCGPoint(self.scrollView.contentOffset));
}

-(void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    NSLog(@"contentoffset frame = %@", NSStringFromCGPoint(self.scrollView.contentOffset));
    if(endDrag){
        [self.scrollView setContentOffset:CGPointMake(5.5, 37) animated:YES];
        endDrag = NO;
    }
}

@end
